/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*-  */
/*
 * pwm-pin.h
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

#ifndef _PWM_PIN_H_
#define _PWM_PIN_H_

// stl
#include <string>

class PwmPin
{
protected:
  PwmPin() = default;
public:  
  virtual void setPeriod(uint32_t newValue) = 0;
  virtual void setDutyCycle(uint32_t newValue) = 0;
  virtual void setEnabled(bool newEnabled = true) = 0;
  virtual bool isEnabled() const = 0;
};

#endif // _PWM_PIN_H_

