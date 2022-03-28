/* -*- mode: c++ -*-
 * Kaleidoscope-GhostInTheFirmware -- Let the keyboard write for you!
 * Copyright (C) 2017, 2018  Keyboard.io, Inc
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdint.h>  // for uint16_t

#include "kaleidoscope/KeyAddr.h"               // for KeyAddr
#include "kaleidoscope/event_handler_result.h"  // for EventHandlerResult
#include "kaleidoscope/plugin.h"                // for Plugin

namespace kaleidoscope {
namespace plugin {
class GhostInTheFirmware : public kaleidoscope::Plugin {
 public:
  struct GhostKey {
    KeyAddr addr;
    uint16_t press_time;
    uint16_t delay;
  };
  static const GhostKey *ghost_keys;

  GhostInTheFirmware(void) {}

  static void activate(void);

  EventHandlerResult afterEachCycle();

 private:
  static bool is_active_;
  static uint16_t current_pos_;
  static uint16_t start_time_;
};

}  // namespace plugin
}  // namespace kaleidoscope

extern kaleidoscope::plugin::GhostInTheFirmware GhostInTheFirmware;
