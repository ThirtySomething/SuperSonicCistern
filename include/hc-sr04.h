//******************************************************************************
// Copyright 2019 ThirtySomething
//******************************************************************************
// This file is part of SuperSonicCistern.
//
// This code is licensed under MIT license (see LICENSE for details)
//******************************************************************************

//******************************************************************************
// Use a HC-SR04 super sonic sensor to read a distance.
//******************************************************************************

#ifndef HC_SR04_H
#define HC_SR04_H

/**
 * Setup of the sensor, means the trigger pin and the echo pin.
 * @params pinTrigger - The pin to trigger measurement.
 * @params pinEcho - The pin where to get notified on echo.
 */
void hcsr04_setup(int pinTrigger, int pinEcho);

/**
 * Read a measurement value in cm.
 * @params timeToWait - Time to wait until return.
 * @params pinTrigger - The pin to trigger measurement.
 * @params pinEcho - The pin where to get notified on echo.
 */
int hcsr04_read(int timeToWait, int pinTrigger, int pinEcho);

/**
 * Determine an average measurement value in cm.
 * @params measurements - Number of measurements for average value.
 * @params timeToWait - Time to wait between each measurement.
 * @params pinTrigger - The pin to trigger measurement
 * @params pinEcho - The pin where to get notified on echo.
 */
int hcsr04_read_average(int measurements, int timetowait, int pinTrigger, int pinEcho);

#endif // HC_SR04_H
