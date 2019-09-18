/*
Copyright 2017 Danny Nguyen <danny@keeb.io>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


#define USE_I2C

#undef RGBLED_NUM
#define RGBLED_NUM 12
#define RGBLIGHT_SPLIT {6, 6}
#define RGBLIGHT_ANIMATIONS
//#define RGBLIGHT_EFFECT_BREATHING
//#define RGBLIGHT_SINGLE_STATIC
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

// Encoder support
/* 
Don't need to define the number of encoders or pads because the Iris config does it for you
#define NUMBER_OF_ENCODERS 1
#define ENCODERS_PAD_A { B12 }
#define ENCODERS_PAD_B { B13 }
*/
#define ENCODER_RESOLUTION 1

#define BREATHING_PERIOD 6