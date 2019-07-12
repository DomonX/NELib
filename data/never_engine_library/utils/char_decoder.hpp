#ifndef CHAR_DECODER_HPP_INCLUDED
#define CHAR_DECODER_HPP_INCLUDED

#include "../modules/keyboard/keycodes.hpp"
#include "../modules/keyboard/keyboard.hpp"

/// @todo (DomonX#1#07/07/19): Add all missing chars to decoder
/// @todo (DomonX#1#07/07/19): Add info

char ne_get_char(int code) {
    if(code == NE_KEY_LSHIFT){
        return -1;
    }
    if(code == NE_KEY_SPACE){
        return ' ';
    }
    if(code == NE_KEY_BACKSPACE){
        return -1;
    }
    if(ne_keyboard.key_clicked(NE_KEY_LSHIFT)){
        if(code == NE_KEY_0) return ')';
        if(code == NE_KEY_1) return '!';
        if(code == NE_KEY_2) return '@';
        if(code == NE_KEY_3) return '#';
        if(code == NE_KEY_4) return '$';
        if(code == NE_KEY_5) return '%';
        if(code == NE_KEY_6) return '^';
        if(code == NE_KEY_7) return '&';
        if(code == NE_KEY_8) return '*';
        if(code == NE_KEY_9) return '(';
        return al_keycode_to_name(code)[0];
    }
    if(code >= 1 && code <= 39) {
        return tolower(al_keycode_to_name(code)[0]);
    }
    return -1;
}

#endif // CHAR_DECODER_HPP_INCLUDED
