/* -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*-  */
/*
 * virtual-pwm-pin.cpp
 * Copyright (C) 2016 Sandro Stiller <sandro.stiller@gmx.de>
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

//stl
#include <iostream>

// local includes
#include "virtual-pwm-pin.h"

int VirtualPwmPin::virtualPinCnt = 0;

VirtualPwmPin::VirtualPwmPin()
: enabled(false)
{
  virtualPinCnt++;
  virtualPinId = virtualPinCnt;
  
  std::cout << __func__ << "() virtual pin " << virtualPinId << " created." << std::endl;
}

VirtualPwmPin::~VirtualPwmPin()
{
  std::cout << __func__ << "() virtual pin " << virtualPinId << " deleted." << std::endl;
}

void VirtualPwmPin::setPeriod(uint32_t newValue)
{
  std::cout << __func__ << "(" << newValue << ") of pin " << virtualPinId << " called." << std::endl;
}

void VirtualPwmPin::setDutyCycle(uint32_t newValue)
{
  std::cout << __func__ << "(" << newValue << ") of pin " << virtualPinId << " called." << std::endl;
}

void VirtualPwmPin::setEnabled(bool newEnabled)
{
  std::cout << __func__ << "(" << newEnabled << ") of pin " << virtualPinId << " called." << std::endl;
  enabled = newEnabled;
}

bool VirtualPwmPin::isEnabled() const
{
  std::cout << __func__ << "() of pin " << virtualPinId << " called. Returning " << enabled << std::endl;
  return(enabled);
}

