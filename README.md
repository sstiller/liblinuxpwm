# liblinuxpwm

A simple library for setting PWM pins on linux devices.

The library is based on C++11.
For nicer development, a virtual PWM pin class was added.
You can use this library to control RC servos or speed controllers or set the brightness and colour of connected LEDs.
Currently this library only supports PWM pins with a PWM driver connected to it.

I use it for controlling a tracked vehicle with a RaspberryPi.

## If you want to add something, here are some tasks:
* Support for Linux LED devices.
That should be very easy to add.
* Support for Linux GPIO pins.
Should be based on threads or boost::asio.
