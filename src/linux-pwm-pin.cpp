/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*-  */
/*
 * linux-pwm-pin.cpp
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
#include <string.h> // memcpy
#include <cerrno>
#include <sys/stat.h>
#include <unistd.h> // usleep

// stl
#include <iostream>
#include <system_error>

// local includes
#include "linux-pwm-pin.h"


LinuxPwmPin::LinuxPwmPin(uint8_t deviceId, uint8_t pinId)
: deviceId(deviceId),
  pinId(pinId),
  enabled(false),
  devicePath("/sys/class/pwm/pwmchip"),
  periodFile(nullptr),
  dutyCycleFile(nullptr),
  enabledFile(nullptr)

{
  devicePath.append(std::to_string((int)deviceId));
  devicePath.push_back('/');
    
  pinPath = devicePath;
  pinPath.append("pwm");
  pinPath.append(std::to_string(pinId));
  pinPath.push_back('/');

  // enable channel
std::cout << __func__ << "():" << __LINE__ << std::endl;
  setExported(true);
std::cout << __func__ << "():" << __LINE__ << std::endl;
  openFiles();
std::cout << __func__ << "():" << __LINE__ << std::endl;
    
 
  // TODO: Add implementation here
    
  // if not already exported --> export
  // disable pin
  // 
}

LinuxPwmPin::~LinuxPwmPin()
{
  setExported(false);
}

void LinuxPwmPin::setPeriod(uint32_t newValue)
{
  std::cout << __func__ << "(" << newValue << ") called." << std::endl;
  rewind(periodFile);
  std::string valueString(std::to_string(newValue));
  size_t writtenBytes = fwrite(valueString.c_str(), valueString.size(), 1, periodFile);
  if(writtenBytes != 1) // 1 = number of blocks
  {
    throw std::system_error(errno, std::system_category(), "Failed to set period.");
  }
  fflush(periodFile);
}

void LinuxPwmPin::setDutyCycle(uint32_t newValue)
{
  std::cout << __func__ << "(" << newValue << ") called." << std::endl;
  rewind(dutyCycleFile);
  std::string valueString(std::to_string(newValue));
  size_t writtenBytes = fwrite(valueString.c_str(), valueString.size(), 1, dutyCycleFile);
  if(writtenBytes != 1) // 1 = number of blocks
  {
    throw std::system_error(errno, std::system_category(), "Failed to set DutyCycle.");
  }
  fflush(dutyCycleFile);
}

void LinuxPwmPin::setEnabled(bool newEnabled)
{
  //write
  std::cout << __func__ << "(" << newEnabled << ") called." << std::endl;
  rewind(enabledFile);
  int status = fputc((newEnabled?'1':'0'), enabledFile);
  if(status == EOF)
  {
    throw std::system_error(errno, std::system_category(), "Failed to set enabled.");
  }
  fflush(enabledFile);
  //read back
  rewind(enabledFile);
  int readByte = fgetc(enabledFile);
  if(readByte == EOF)
  {
    throw std::system_error(errno, std::system_category(), "Failed to read enabled.");
  }
  enabled = (readByte == '1');
}

bool LinuxPwmPin::isEnabled() const
{
  return(enabled);
}

// private
void LinuxPwmPin::setExported(bool exported)
{
  // throws on failure

  //TODO: check if already exported / removed
  
  if(! exported)
  {
    setEnabled(false);
    closeFiles();
  }

  std::string exportFileName(devicePath);
  exportFileName.append(exported ? "export" : "unexport");
  
  std::cout << __func__ << "() Write " << (int)pinId << " to " << exportFileName << std::endl;
  FILE* exportFile = fopen(exportFileName.c_str(), "w");
  if(!exportFile)
  {
    throw (std::system_error(errno, std::system_category(), "Failed to open (un)export file"));
  }
  
  int status = fprintf(exportFile, "%d", pinId);
  if(status < 0)
  {
    fclose(exportFile);
    throw (std::system_error(errno, std::system_category(), "Failed writing to (un)export file"));
  }
  fclose(exportFile);

  // wait some time for directory creation
  usleep(100000);
  
  if(! directoryExists(pinPath))
  {
    std::runtime_error("Directory for pin not existing");
  }
}


void LinuxPwmPin::openFiles()
{
std::cout << "init file " << (pinPath + "period") << std::endl;
  periodFile = fopen ((pinPath + "period").c_str(), "r+");
  if(!periodFile)
  {
    throw std::system_error(errno, std::system_category(), "Failed to open period file");
  }

std::cout << "init file " << (pinPath + "duty_cycle") << std::endl;
  dutyCycleFile = fopen ((pinPath + "duty_cycle").c_str(), "r+");
  if(!dutyCycleFile)
  {
    throw std::system_error(errno, std::system_category(), "Failed to open duty_cycle file");
  }

std::cout << "init file " << (pinPath + "enable") << std::endl;
  enabledFile = fopen ((pinPath + "enable").c_str(), "r+");
  if(!enabledFile)
  {
    throw std::system_error(errno, std::system_category(), "Failed to open enable file");
  }
}

void LinuxPwmPin::closeFiles()
{
  if(periodFile)
  {
    fclose(periodFile);
  }

  if(dutyCycleFile)
  {
    fclose(dutyCycleFile);
  }

  if(enabledFile)
  {
    fclose(enabledFile);
  }  
}

bool LinuxPwmPin::directoryExists(const std::string& fileName)
{
  struct stat statInfo;

  if(stat(fileName.c_str(), &statInfo ) != 0 )
  {
    return(false);
  }else if(statInfo.st_mode & S_IFDIR )
  {
    return(true);
  }
  return(false);
}
