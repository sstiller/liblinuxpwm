/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*-  */
/*
 * linuxpwmtest.cpp
 * Copyright (C) 2016 Sandro Stiller <sandro@sagichnicht.de>
 *
 * liblinuxpwm is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * liblinuxpwm is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// C
#include <unistd.h> // sleep

// stl
#include <iostream>
#include <system_error>

// local includes
#include "../src/linux-pwm-pin.h"

int main(void)
{
  try{
    LinuxPwmPin pin(0, 1);
    pin.setPeriod(20000000);
    pin.setDutyCycle(1000000);
    pin.setEnabled(true);
    while(1)
    {
      sleep(1);
      pin.setDutyCycle(1000000);
      sleep(1);
      pin.setDutyCycle(1500000);
      sleep(1);
      pin.setDutyCycle(2000000);
    }
  }catch(std::system_error& exc) {
    std::cerr << "1 " << exc.code().message() << std::endl;
    std::cerr << "1 " << exc.what() << std::endl;
    return(1);
  }catch(std::exception& exc)
  {
    std::cerr << "2 " << exc.what() << std::endl;
    return(2);
  }
  
  return(0);
}