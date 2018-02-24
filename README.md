# liblinuxpwm

A simple library for setting PWM pins on linux devices.

The library is based on C++11.
For nicer development, a virtual PWM pin class was added.
You can use this library to
* control RC servos or speed controllers
* set the brightness and colour of connected LEDs
* Play music by setting the frequency (and duty cycle to 50 % every time). Works pretty good.

Currently this library only supports PWM pins with a PWM driver connected to it.

I mainly use it for controlling a tracked vehicle with a RaspberryPi.

## If you want to add something, here are some tasks:
* Add support for Linux LED devices.
That should be very easy to do.
* Add support for Linux GPIO pins.
Should be based on threads or boost::asio.

