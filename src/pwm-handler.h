/* -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*-  */
/*
 * pwm-handler.h
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

#ifndef _PWM_HANDLER_H_
#define _PWM_HANDLER_H_

// stl
#include <vector>
#include <memory>
#include <map>

// forward
class PwmHandler;

// local includes
#include "pwm-pin.h"

class PwmHandler
{
public:
  void updateDevices();
  int getNumDevices();
  std::shared_ptr<PwmPin> getPwmPin(unsigned int localPinId);
   /** Old pin with same ID will be deleted
    * TODO: What about hw? Check if pin with same hw IDs exists, check use cnt, return error if > 1?
    */
  std::shared_ptr<PwmPin> createPwmPin(unsigned int localPinId, uint8_t deviceId, uint8_t pinId);
  

private:
  std::map<unsigned int, std::shared_ptr<PwmPin> > pinMap;

};

#endif // _PWM_HANDLER_H_

