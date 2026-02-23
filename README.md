# RNode Firmware — NeoPixel Edition

A fork of the [RNode Firmware CE (Community Edition)](https://github.com/liberatedsystems/RNode_Firmware_CE) with added NeoPixel status indicator support for ESP32-based boards like the LilyGO LoRa32 v2.1.

The NeoPixel lights up on boot and on every data transfer (RX/TX), giving you an at-a-glance visual indicator that your node is alive and actively relaying traffic.

<p align="center">
  <img src="images/rnode-neopixel-closeup.png" width="60%" alt="RNode with NeoPixel lit during boot">
</p>

## Boot Sequence

When the device powers on, the NeoPixel lights up purple and stays lit while the firmware initializes. The OLED display cycles through hardware init, device checks, and version info — all while the NeoPixel confirms the node is alive.

<p align="center">
  <img src="images/rnode-boot-init.png" width="32%" alt="Hardware init">
  <img src="images/rnode-boot-checks.png" width="32%" alt="Device checks passed">
  <img src="images/rnode-boot-version.png" width="32%" alt="Firmware version display">
</p>

Once checks pass, the device is ready and the NeoPixel remains lit for 60 seconds before turning off. Any RX or TX activity re-triggers it.

<p align="center">
  <img src="images/rnode-ready.png" width="45%" alt="RNode ready with NeoPixel indicator">
</p>

## What's Changed

The upstream firmware already has NeoPixel support for some boards (e.g. NRF52-based RAK4631). This fork extends it to **ESP32-based boards** (specifically the LilyGO LoRa32 v2.1) and adds a **timed activity indicator** so the LED stays lit for a configurable duration after each event:

| Event | Default Color | Default Duration |
|-------|--------------|-----------------|
| Boot  | Purple (128, 0, 128) | 60 seconds |
| RX (receive) | White (255, 255, 255) | 30 seconds |
| TX (transmit) | Blue (0, 0, 255) | 30 seconds |

After the timeout, the LED turns off automatically. Any new activity resets the timer.

### NeoPixel Pin

On ESP32 boards, the NeoPixel data pin defaults to **GPIO 13** (GPIO 12 is a strapping pin and can cause boot issues). You can override this at compile time:

```cpp
#define PIN_NEOPIXEL 13
```

## Configuration

All NeoPixel parameters can be overridden with `#define` before including `Config.h` (or passed as build flags):

```cpp
// Timeouts (milliseconds)
#define NP_BOOT_TIMEOUT_MS 60000
#define NP_RX_TIMEOUT_MS   30000
#define NP_TX_TIMEOUT_MS   30000

// Boot color (RGB 0-255)
#define NP_BOOT_R 128
#define NP_BOOT_G 0
#define NP_BOOT_B 128

// Receive color
#define NP_RX_R 255
#define NP_RX_G 255
#define NP_RX_B 255

// Transmit color
#define NP_TX_R 0
#define NP_TX_G 0
#define NP_TX_B 255
```

## Building

This firmware uses the same build system as the upstream RNode Firmware CE. You need [arduino-cli](https://arduino.github.io/arduino-cli/) installed.

```bash
# Install dependencies (ESP32 core, libraries, etc.)
make prep-esp32

# Build for LilyGO LoRa32 v2.1
make firmware-lora32_v21
```

See the upstream [build documentation](Documentation/BUILDING.md) for full details on all supported targets.

## Supported Hardware

This fork is tested on the **LilyGO LoRa32 v2.1** with an external NeoPixel on GPIO 13. It should work on any ESP32-based RNode board with a WS2812/NeoPixel connected to the configured pin.

For the full list of boards supported by the base firmware, see the upstream [RNode Firmware CE](https://github.com/liberatedsystems/RNode_Firmware_CE).

## Upstream

Based on [RNode Firmware CE](https://github.com/liberatedsystems/RNode_Firmware_CE) by Jacob Eva / [Liberated Embedded Systems](https://liberatedsystems.co.uk), which is itself a community fork of the [original RNode Firmware](https://github.com/markqvist/RNode_Firmware) by Mark Qvist.

## License

GNU General Public License v3.0 — see [LICENSE](LICENSE) for details.
