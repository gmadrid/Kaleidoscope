/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018-2022  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built on " __DATE__ " at " __TIME__
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-Qukeys.h"

#define MO(n) ShiftToLayer(n)
#define TG(n) LockLayer(n)

enum {
  MACRO_QWERTY,
  MACRO_VERSION_INFO
};

enum {
  QWERTY,
  COLEMAK,
  LOWER,
  UPPER,
  FUN,
};


#define Key_Exclamation LSHIFT(Key_1)
#define Key_At          LSHIFT(Key_2)
#define Key_Hash        LSHIFT(Key_3)
#define Key_Dollar      LSHIFT(Key_4)
#define Key_Percent     LSHIFT(Key_5)
#define Key_Caret       LSHIFT(Key_6)
#define Key_And         LSHIFT(Key_7)
#define Key_Star        LSHIFT(Key_8)
#define Key_Plus        LSHIFT(Key_Equals)
#define Key_LOWER       MO(LOWER)
#define Key_UPPER       MO(UPPER)


// These are the bottom "modifier" row for both QWERTY and COLEMAK. I want them to be the same both places but DRY.
#define MOD_ROW_LEFT  ,Key_Esc ,Key_Tab ,Key_LeftGui ,Key_LeftShift ,Key_Backspace ,Key_LeftControl
#define MOD_ROW_RIGHT       ,Key_LeftAlt  ,Key_Space ,MO(FUN)    ,Key_Minus ,Key_Quote  ,Key_Enter

#define NEW_MOD_ROW_LEFT  ,Key_LOWER ,Key_Esc ,Key_Tab ,Key_LeftGui ,Key_Backspace ,Key_LeftControl
#define NEW_MOD_ROW_RIGHT ,Key_LeftAlt ,Key_Space ,Key_Minus ,Key_Quote ,Key_LeftShift ,Key_UPPER


// Conceptually, a QWERTY and COLEMAK lower layer,
// - a LOWER key that is numbers and programmer's punctuation (with cursors?)
// - an UPPER key that is FKeys and movement keys (including cursors?)
// - a SPECIAL layer that overlays, but is full when both LOWER/UPPER are pressed. This is mainly for weird shit.
//   (e.g., querty/colemak switching, media keys)
//
// In order to switch back to the proper main layer, we have to stack them (and not move to them.)
// For that reason, all layers are basically full.


// clang-format off
KEYMAPS(
  [QWERTY] = KEYMAP_STACKED
  (
       Key_Q   ,Key_W   ,Key_E       ,Key_R         ,Key_T
      ,Key_A   ,Key_S   ,Key_D       ,Key_F         ,Key_G
      ,Key_Z   ,Key_X   ,Key_C       ,Key_V         ,Key_B, Key_Backtick
      NEW_MOD_ROW_LEFT

                     ,Key_Y     ,Key_U      ,Key_I     ,Key_O      ,Key_P
                     ,Key_H     ,Key_J      ,Key_K     ,Key_L      ,Key_Semicolon
       ,Key_Enter    ,Key_N     ,Key_M      ,Key_Comma ,Key_Period ,Key_Slash
       NEW_MOD_ROW_RIGHT
  ),

  [COLEMAK] = KEYMAP_STACKED
  (
       Key_Q   ,Key_W   ,Key_F       ,Key_P         ,Key_G
      ,Key_A   ,Key_R   ,Key_S       ,Key_T         ,Key_D
      ,Key_Z   ,Key_X   ,Key_C       ,Key_V         ,Key_B, Key_Backtick
      NEW_MOD_ROW_LEFT

                     ,Key_J     ,Key_L      ,Key_U     ,Key_Y      ,Key_Semicolon
                     ,Key_H     ,Key_N      ,Key_E     ,Key_I      ,Key_O
       ,Key_Enter    ,Key_K     ,Key_M      ,Key_Comma ,Key_Period ,Key_Slash
       NEW_MOD_ROW_RIGHT
  ),

  [LOWER] = KEYMAP_STACKED
  (
       Key_1 ,Key_2 ,Key_3 ,Key_4          ,Key_5
      ,XXX   ,XXX   ,XXX   ,Key_LeftParen  ,Key_RightParen
      ,XXX   ,XXX   ,XXX   ,XXX            ,XXX            ,XXX
      ,___   ,___   ,XXX   ,XXX            ,XXX            ,XXX

               ,Key_6   ,Key_7  ,Key_8            ,Key_9                ,Key_0
               ,Key_LeftBracket ,Key_RightBracket ,Key_LeftCurlyBracket ,Key_RightCurlyBracket ,Key_Equals
          ,___ ,Key_LeftArrow   ,Key_DownArrow    ,Key_UpArrow          ,Key_RightArrow        ,Key_Backslash
          ,XXX ,___             ,XXX              ,Key_Backtick         ,XXX                   ,LockLayer(FUN)
   ),

  [UPPER] = KEYMAP_STACKED
  (
       Key_F1         ,Key_F2 ,Key_F3 ,Key_F4  ,Key_F5
      ,XXX            ,XXX    ,XXX    ,XXX     ,XXX
      ,XXX            ,XXX    ,XXX    ,XXX     ,XXX    ,XXX
      ,LockLayer(FUN) ,XXX    ,XXX    ,XXX     ,XXX    ,XXX

               ,Key_F6         ,Key_F7       ,Key_F8      ,Key_F9         ,Key_F10
               ,Key_Home       ,Key_End      ,Key_PageUp  ,Key_PageDown   ,Key_F11
          ,XXX ,Key_LeftArrow ,Key_DownArrow ,Key_UpArrow ,Key_RightArrow ,Key_F12
          ,XXX ,XXX           ,XXX           ,XXX         ,XXX            ,___
   ),

  [FUN] = KEYMAP_STACKED
  (
       XXX            ,XXX    ,XXX    ,XXX     ,XXX
      ,XXX            ,XXX    ,XXX    ,XXX     ,XXX
      ,XXX            ,XXX    ,XXX    ,XXX     ,XXX    ,XXX
      ,LockLayer(FUN) ,XXX    ,XXX    ,XXX     ,XXX    ,XXX

               ,XXX            ,XXX           ,XXX         ,XXX            ,XXX
               ,Key_Home       ,Key_End       ,Key_PageUp  ,Key_PageDown   ,XXX
          ,XXX ,Key_LeftArrow  ,Key_DownArrow ,Key_UpArrow ,Key_RightArrow ,XXX
          ,XXX ,XXX            ,XXX           ,XXX         ,XXX            ,LockLayer(FUN)
   )
)
// clang-format on

KALEIDOSCOPE_INIT_PLUGINS(
  Qukeys
  );

void setup() {
  Kaleidoscope.setup();

  QUKEYS(
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 0), Key_LeftParen),
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 11), Key_RightParen),
  )
}

void loop() {
  Kaleidoscope.loop();
}
