/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*-  */
/*
 * linux-pwm-pin.h
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

#ifndef _LINUX_PWM_PIN_H_
#define _LINUX_PWM_PIN_H_

// stl
#include <string>
#include <cstdio>

// local includes
#include "pwm-pin.h"

class LinuxPwmPin : public PwmPin
{
public:
  LinuxPwmPin() = delete;
  LinuxPwmPin(uint8_t deviceId, uint8_t pinId);
  ~LinuxPwmPin();
  
  virtual void setPeriod(uint32_t newValue) override;
  virtual void setDutyCycle(uint32_t newValue) override;
  virtual void setEnabled(bool newEnabled = true) override;
  virtual bool isEnabled() const override;
   
private:
  void setExported(bool exported);
  void openFiles();
  void closeFiles();
  bool directoryExists(const std::string& fileName);
   
  uint8_t deviceId;
  uint8_t pinId;
  bool enabled;
  std::string devicePath;
  std::string pinPath;

  FILE* periodFile;
  FILE* dutyCycleFile;
  FILE* enabledFile;
   
};

#endif // _LINUX_PWM_PIN_H_

