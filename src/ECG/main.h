#ifndef MAIN_H
#define MAIN_H

#include "Arduino.h"
#include <SPI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"

#define SERIAL_BAUD_RATE 115200

/**
 * AD8232 Settings
 */ 
#define LO_POSITIVE 3
#define LO_NEGATIVE 4
#define AD8232_INPUT A0

/**
 * Adafruit Bluefruit UART Settings
 */
int32_t hrmServiceId;
int32_t hrmMeasureCharId;
int32_t hrmLocationCharId;
boolean success;

#define BUFSIZE                        128   // Size of the read buffer for incoming data
#define VERBOSE_MODE                   true  // If set to 'true' enables debug output
#define BLUEFRUIT_SWUART_RXD_PIN       9    // Required for software serial!
#define BLUEFRUIT_SWUART_TXD_PIN       10   // Required for software serial!
#define BLUEFRUIT_UART_CTS_PIN         11   // Required for software serial!
#define BLUEFRUIT_UART_RTS_PIN         8    // Optional, set to -1 if unused
#define BLUEFRUIT_UART_MODE_PIN        12    // Set to -1 if unused

#ifdef Serial1    // this makes it not complain on compilation if there's no Serial1
  #define BLUEFRUIT_HWSERIAL_NAME      Serial1
#endif

SoftwareSerial bluefruitSS = SoftwareSerial(BLUEFRUIT_SWUART_TXD_PIN, BLUEFRUIT_SWUART_RXD_PIN);
Adafruit_BluefruitLE_UART ble(bluefruitSS, BLUEFRUIT_UART_MODE_PIN, BLUEFRUIT_UART_CTS_PIN, BLUEFRUIT_UART_RTS_PIN);

#endif //MAIN_H