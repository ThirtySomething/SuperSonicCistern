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
#include "hc-sr04.h"

#include <Arduino.h>

//******************************************************************************
void hcsr04_setup(int pinTrigger, int pinEcho)
{
    pinMode(pinTrigger, OUTPUT);
    pinMode(pinEcho, INPUT);
}

//******************************************************************************
int hcsr04_read(int timeToWait, int pinTrigger, int pinEcho)
{
    int duration = 0;
    int distance = 0;

    digitalWrite(pinTrigger, LOW);
    delayMicroseconds(3);
    digitalWrite(pinTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrigger, LOW);

    duration = pulseIn(pinEcho, HIGH);
    distance = (int)((duration / 2.0) / 29.1);
    delay(timeToWait);

    return distance;
}

//******************************************************************************
int hcsr04_read_average(int measurements, int timeToWait, int pinTrigger, int pinEcho)
{
    long total = 0L;
    int average = 0;

    for (int i = 0; i < measurements; i++)
    {
        total += hcsr04_read(timeToWait, pinTrigger, pinEcho);
    }

    average = (int)(total / (measurements * 1.0));
    return average;
}
