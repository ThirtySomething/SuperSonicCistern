//******************************************************************************
// Copyright 2019 ThirtySomething
//******************************************************************************
// This file is part of SuperSonicCistern.
//
// This code is licensed under MIT license (see LICENSE for details)
//******************************************************************************

//******************************************************************************
// System includes
//******************************************************************************
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <stdio.h>

//******************************************************************************
// Own includes
//******************************************************************************
#include "hc-sr04.h"

//******************************************************************************
// Global resources
//******************************************************************************
LiquidCrystal_I2C i2sLcdDisplay(0x27, 16, 2);

//******************************************************************************
// Constants used in program
//******************************************************************************
static const int pinTrigger = 13;
static const int pinEcho = 12;
static const int delta = 50;
static const int measurements = 500;

//******************************************************************************
// Setup of super sonic sensor and display
//******************************************************************************
void setup()
{
    hcsr04_setup(pinTrigger, pinEcho);
    i2sLcdDisplay.init();
    i2sLcdDisplay.backlight();

    // Write only once the headline on 1st row
    i2sLcdDisplay.setCursor(0,0);
    i2sLcdDisplay.print("Surface distance");
}

//******************************************************************************
// Main program in loop
//******************************************************************************
void loop()
{
    // Init buffer for output on display
    char buffer[16] = "\0";

    // Read average value of measurements
    int distance = hcsr04_read_average(measurements, delta, pinTrigger, pinEcho);
    // Fill buffer for display - the blanks ensure a cleanup of unused characters
    snprintf(buffer, 16, "%d cm                ", distance);

    // Write measurement value to display, 2nd row
    i2sLcdDisplay.setCursor(0,1);
    i2sLcdDisplay.print(buffer);
}
