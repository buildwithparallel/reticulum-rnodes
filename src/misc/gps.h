#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

#define GPS_INTERVAL 5000 // ms

unsigned long last_gps = 0;
TinyGPSPlus gps;
SoftwareSerial gps_s(PIN_GPS_RX, PIN_GPS_TX);
