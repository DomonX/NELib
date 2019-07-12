#ifndef TEXTINPUT_HPP_INCLUDED
#define TEXTINPUT_HPP_INCLUDED

#include "../keyboard/input_buffer.hpp"
#include "../../utils/text.hpp"
#include "../font/font.hpp"

/// @todo (DomonX#1#07/07/19): Add visible cursor

/// @todo (DomonX#1#07/07/19): Add font wrapping and/or text cutting option

class Ne_text_input{
private:
    int position_x;
    int position_y;
    int width;
    int height;
    Ne_image * view;
    bool focus;
    Ne_input_buffer * buffer;
    bool visible;
    Ne_font * font;
    int font_size;
    ALLEGRO_COLOR color;

public:
    Ne_text_input(int x, int y, const char * bitmap_path, Ne_font * font, int font_size, ALLEGRO_COLOR color) {
        position_x = x;
        position_y = y;
        view = new Ne_image(bitmap_path);
        width = view->get_width();
        height = view->get_height();
        visible = true;
        focus = true;
        this->font = font;
        this->color = color;
        this->font_size = font_size;
        view->metadata->position_x = position_x;
        view->metadata->position_y = position_y;
        buffer = new Ne_input_buffer();
    }
    void run() {
        if(visible) {
            view->draw_image();
            ne_draw_text(font->get_font(font_size),color,position_x+5,position_y+5,buffer->value);
        }
        if(focus) {
            buffer->run();
        }
    }

};

#endif // TEXTINPUT_HPP_INCLUDED
