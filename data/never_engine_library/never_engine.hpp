#ifndef NEVER_ENGINE_HPP_INCLUDED
#define NEVER_ENGINE_HPP_INCLUDED

// ------------------------
// NeverEngine Core Library
// ------------------------
// Type: Initializer
// Module: None
// Used in: App
// Required: None
// Utils: None
// Has Metadata : No
// Run method: None
// ------------------------
// Version Added: 1.1 Alpha
// Version Modified: 1.1 Alpha
// ------------------------
// Initializer of all NeverEngine
// Modules etc. in library
// ------------------------

// Config

#include "ne_structures.hpp"

// Modules

#include "modules/sprite/sprite.hpp"
#include "modules/keyboard/keyboard.hpp"
#include "modules/resolution/resolution.hpp"
#include "modules/time/time.hpp"

#include "modules/keyboard/keycodes.hpp"
#include "modules/mouse/mouse.h"
#include "modules/button/button.hpp"

#include "modules/keyboard/input_buffer.hpp"

#include "modules/textinput/textinput.hpp"

#include "modules/font/font.hpp"

#include "modules/character/character_controller.hpp"
#include "modules/character/character.hpp"

#include "modules/map/map.hpp"
#include "modules/map/map_controller.hpp"

// Utils

#include "utils/mouse_between_square.hpp"
#include "utils/char_decoder.hpp"
#include "utils/screen_scaler.hpp"

#endif // NEVER_ENGINE_HPP_INCLUDED
