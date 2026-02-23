#line 1 "/Users/refactored/Code/Ad_Hoc/RNode_Firmware_CE/Config.h"
// Copyright (C) 2024, Mark Qvist

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "ROM.h"
#include "Boards.h"

#ifndef CONFIG_H
	#define CONFIG_H

	#define MAJ_VERS  0x01
	#define MIN_VERS  0x4b

	#define MODE_HOST 0x11
	#define MODE_TNC  0x12

	#define CABLE_STATE_DISCONNECTED 0x00
	#define CABLE_STATE_CONNECTED    0x01
	uint8_t cable_state = CABLE_STATE_DISCONNECTED;

    #define MAX_INTERFACES 12
	
	#define BT_STATE_NA        0xff
	#define BT_STATE_OFF       0x00
	#define BT_STATE_ON        0x01
	#define BT_STATE_PAIRING   0x02
	#define BT_STATE_CONNECTED 0x03
	uint8_t bt_state = BT_STATE_NA;
	uint32_t bt_ssp_pin = 0;
	bool bt_ready = false;
	bool bt_enabled = false;
	bool bt_allow_pairing = false;

	#define M_FRQ_S 27388122
	#define M_FRQ_R 27388061
	bool console_active = false;
	bool modems_installed = false;

	#define MTU   	   508
	#define SINGLE_MTU 255
	#define HEADER_L   1
	#define MIN_L	   1
	#define CMD_L      64

	#define eeprom_addr(a) (a+EEPROM_OFFSET)

    #define PA_OUTPUT_RFO_PIN      0
    #define PA_OUTPUT_PA_BOOST_PIN 1

	// MCU independent configuration parameters
	const long serial_baudrate  = 115200;

  // NeoPixel activity indicator (when HAS_NP == true)
  // Set these to any RGB values you want (0-255).
  #ifndef NP_RX_TIMEOUT_MS
    #define NP_RX_TIMEOUT_MS 30000
  #endif
  #ifndef NP_TX_TIMEOUT_MS
    #define NP_TX_TIMEOUT_MS 30000
  #endif
  #ifndef NP_BOOT_TIMEOUT_MS
    #define NP_BOOT_TIMEOUT_MS 60000
  #endif

  #ifndef NP_BOOT_R
    #define NP_BOOT_R 128
    #define NP_BOOT_G 0
    #define NP_BOOT_B 128
  #endif
  #ifndef NP_RX_R
    #define NP_RX_R 255
    #define NP_RX_G 255
    #define NP_RX_B 255
  #endif
  #ifndef NP_TX_R
    #define NP_TX_R 0
    #define NP_TX_G 0
    #define NP_TX_B 255
  #endif

	// SX1276 RSSI offset to get dBm value from
	// packet RSSI register
	const int  rssi_offset = 157;

	// Operational variables
	bool community_fw  = true;
	bool hw_ready      = false;
	bool disp_ready    = false;
	bool pmu_ready     = false;
	bool promisc       = false;
	bool implicit      = false;
	bool memory_low    = false;
	uint8_t implicit_l = 0;

	uint8_t op_mode   = MODE_HOST;
	uint8_t model     = 0x00;
	uint8_t hwrev     = 0x00;

    int     current_rssi    = -292;
	int		last_rssi		= -292;
	uint8_t last_rssi_raw   = 0x00;
	uint8_t last_snr_raw	= 0x80;
	uint8_t seq[INTERFACE_COUNT];
	uint16_t read_len[INTERFACE_COUNT];

    bool serial_in_frame = false;

    FIFOBuffer packet_rdy_interfaces;

    uint8_t packet_rdy_interfaces_buf[MAX_INTERFACES];

	// Incoming packet buffer
	uint8_t pbuf[MTU];

	// KISS command buffer
	uint8_t cmdbuf[CMD_L];

	// LoRa transmit buffer
	uint8_t tbuf[MTU];

	uint32_t stat_rx		= 0;
	uint32_t stat_tx		= 0;

	bool stat_signal_detected   = false;
	bool stat_signal_synced     = false;
	bool stat_rx_ongoing        = false;
	bool dcd                    = false;
	bool dcd_led                = false;
	bool dcd_waiting            = false;
	long dcd_wait_until         = 0;
	uint16_t dcd_count          = 0;
	uint16_t dcd_threshold      = 2;

	uint32_t last_status_update = 0;
	uint32_t last_dcd = 0;

    uint32_t last_rx = 0;
    uint32_t last_tx = 0;

    // Power management
    #define BATTERY_STATE_UNKNOWN     0x00
    #define BATTERY_STATE_DISCHARGING 0x01
    #define BATTERY_STATE_CHARGING    0x02
    #define BATTERY_STATE_CHARGED     0x03
    bool battery_installed = false;
    bool battery_indeterminate = false;
    bool external_power = false;
    bool battery_ready = false;
    float battery_voltage = 0.0;
    float battery_percent = 0.0;
    uint8_t battery_state = 0x00;
    uint8_t display_intensity = 0xFF;
    uint8_t display_addr = 0xFF;
    volatile bool display_updating = false;
    bool display_blanking_enabled = false;
    bool display_diagnostics = true;    
    bool device_init_done = false;
    bool eeprom_ok = false;
    bool firmware_update_mode = false;

	// Boot flags
	#define START_FROM_BOOTLOADER 0x01
	#define START_FROM_POWERON    0x02
	#define START_FROM_BROWNOUT   0x03
	#define START_FROM_JTAG       0x04

    // Subinterfaces
    // select interface 0 by default
    uint8_t interface = 0;
    RadioInterface* selected_radio;
    RadioInterface* interface_obj[INTERFACE_COUNT];
    RadioInterface* interface_obj_sorted[INTERFACE_COUNT];
#endif
