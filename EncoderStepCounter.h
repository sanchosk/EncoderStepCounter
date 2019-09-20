/*
    Arduino EncoderStepCounter library
    Copyright (C) 2019 Manuel Reimer <manuel.reimer@gmx.de>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef HalfStepEncoder_h
#define HalfStepEncoder_h

#include "Arduino.h"

enum EncoderType { HALF_STEP, FULL_STEP };

class EncoderStepCounter {
public:
  EncoderStepCounter(int aPin1, int aPin2, EncoderType aEncType = FULL_STEP);
  signed char getPosition();
  void setPosition(signed char aPosition);
  void reset();
  void tick();
  void begin();
private:
  // Arduino pins for polling
  int encoder_pin1;
  int encoder_pin2;

  // Attribute to remember which encoder type we have
  EncoderType encoder_type;

  // Enum for the direction
  enum EncDir { CW, CCW, UNKNOWN_DIR };

  // Attributes to remember some values for the CheckEncoderPos() method
  int lastpin1;
  int lastpin2;
  int lastfull;

  // Attributes to remember some values for the tick() method
  EncDir last_zero_dir;

  // Attribute for current position
  signed volatile char encoderpos;

  // Helper to get current encoder position
  bool CheckEncoderPos(int& aPosValue, EncDir& aDirection);
};

#endif
