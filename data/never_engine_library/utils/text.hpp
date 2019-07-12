#ifndef TEXT_HPP_INCLUDED
#define TEXT_HPP_INCLUDED

    // ------------------------
    // NeverEngine Core Library
    // ------------------------
    // Type: Utils
    // Module: None
    // Used in: ?
    // Required:
    // Utils: ?
    // Has Metadata : No
    // Run method: None
    // ------------------------
    // Version Added: 1.1 Alpha
    // Version Modified: 1.1 Alpha
    // ------------------------
    // Draws text in scaled position
    // ------------------------

/// @todo (DomonX#1#07/07/19): Add font scaling to utils instead of raw allegro font
/// @todo (DomonX#1#07/07/19): Add missing info

#include "screen_scaler.hpp"
#include "../modules/font/font.hpp"

using namespace std;

void ne_draw_text(ALLEGRO_FONT * font, ALLEGRO_COLOR color, int pos_x, int pos_y, const char * text) {
    al_draw_text(
      font,
      color,
      ne_get_x_pos_scale(pos_x),
      ne_get_y_pos_scale(pos_y),
      0,
      text
      );
}

void ne_draw_text(ALLEGRO_FONT * font, ALLEGRO_COLOR color, int pos_x, int pos_y, string text) {
    al_draw_text(
      font,
      color,
      ne_get_x_pos_scale(pos_x),
      ne_get_y_pos_scale(pos_y),
      0,
      text.c_str()
      );
}

#endif // TEXT_HPP_INCLUDED
