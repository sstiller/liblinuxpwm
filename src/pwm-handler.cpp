/* -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*-  */
/*
 * pwm-handler.cpp
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

#include "pwm-handler.h"

// public

void PwmHandler::updateDevices()
{
  // TODO: Add implementation here
}

int PwmHandler::getNumDevices()
{
  // TODO: Add implementation here
}

std::shared_ptr<PwmPin> PwmHandler::getPwmPin(unsigned int localPinId)
{
  // TODO: Add implementation here
}

/** Old pin with same ID will be deleted
 * TODO: What about hw? Check if pin with same hw IDs exists, check use cnt, return error if > 1?
 */
std::shared_ptr<PwmPin> PwmHandler::createPwmPin(unsigned int localPinId, uint8_t deviceId, uint8_t pinId)
{
  // TODO: Add implementation here
}





