/* Copyright 2019 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* RGB stuff */
#define RGB_DI_PIN D3
#ifdef  RGB_DI_PIN
  #define RGBLED_NUM 11
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 255
  #define RGBLIGHT_SLEEP

  #define RGBLIGHT_LAYERS
  #define RGBLIGHT_MAX_LAYERS 4
#endif

/* Combos for a more UwU typing experience */
#define COMBO_COUNT 6
#define COMBO_TERM  50

/* Mouse keys: use the 3-speed mode */
#define MK_3_SPEED
#define MK_C_OFFSET_0 4
#define MK_C_OFFSET_1 16
#define MK_C_OFFSET_2 32

