# SuperSonicCistern

Read and display the water level of a cistern.

## Hardware

- [16x2 LCD display (I2S)][16x2I2S]
- [Ardunio Uno board][AUno]
- [Super sonic sensor][HCSR04]

## Software

- [PlatformIO Plugin for Visual Studio Code][PIO]
- [Visual Studio Code][VSC]

## Remarks

This is my first attempt to use [PlatformIO][PIO] and [Visual Studio Code][VSC] as environment
for an Ardunio project. So I'm not too familiar with the features [PlatformIO][PIO] offers.
I've deleted the ```lib``` and the ```test``` folders and also ```.travis.yml``` as by now I don't need them.

All proposals to improve the project are welcome.

## ToDo's

Determine min and max value in cistern to not display only a distance in cm but
a concrete water level of the cistern itself.

[16x2I2S]: https://www.oddwires.com/16x2-lcd-display-with-i2c-interface/
[AUno]: https://store.arduino.cc/arduino-uno-rev3
[HCSR04]: https://www.amazon.de/HC-SR04-Entfernung-Messumformer-Ultraschall-Modul-Arduino/dp/B00BIZQWYE
[PIO]: https://platformio.org/
[VSC]: https://code.visualstudio.com/
