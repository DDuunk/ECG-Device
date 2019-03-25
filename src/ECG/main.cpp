#include "main.h"

void error(const __FlashStringHelper*err) {
    Serial.println(err);
    while (1);
}

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);

    pinMode(LO_POSITIVE, INPUT);
    pinMode(LO_NEGATIVE, INPUT);

    Serial.println(F("Adafruit Bluefruit Command <-> Data Mode Example"));
    Serial.println(F("------------------------------------------------"));
    /* Initialise the module */
    Serial.print(F("Initialising the Bluefruit LE module: "));

    if (!ble.begin(VERBOSE_MODE)) {
        error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
    }
    Serial.println(F("OK!"));

    /* Perform a factory reset to make sure everything is in a known state */
    Serial.println(F("Performing a factory reset: "));
    if (!ble.factoryReset()) {
      error(F("Couldn't factory reset"));
    }

    /* Disable command echo from Bluefruit */
    ble.echo(false);

    Serial.println("Requesting Bluefruit info:");
    /* Print Bluefruit information */
    ble.info();

    Serial.println(F("Please use Adafruit Bluefruit LE app to connect in UART mode"));
    Serial.println(F("Then Enter characters to send to Bluefruit"));

    ble.verbose(false);  // debug info is a little annoying after this point!

    // Set module to DATA mode
    Serial.println(F("Switching to DATA mode!"));
    ble.setMode(BLUEFRUIT_MODE_DATA);
}

void loop() {
    if((digitalRead(LO_POSITIVE) == 1) || (digitalRead(LO_NEGATIVE) == 1)) {
        Serial.println(F("!"));
        delay(1000);
    } else {
        Serial.print(F("Updating HRM value to "));
        Serial.print((analogRead(AD8232_INPUT)));
        Serial.println("\r");
        Serial.println(F(" BPM"));
        
       ble.print((analogRead(AD8232_INPUT)));
       ble.println();
    }
    delay(1);
}