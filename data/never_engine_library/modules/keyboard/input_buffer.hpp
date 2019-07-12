#ifndef INPUT_BUFFER_HPP_INCLUDED
#define INPUT_BUFFER_HPP_INCLUDED

#include "keyboard.hpp"
#include "keycodes.hpp"
#include "../../utils/char_decoder.hpp"
#include "../../config/config.hpp"

#include <cstring>

using namespace std;

/// @todo (DomonX#1#07/07/19): Add backspace holding option

class Ne_input_buffer {
private:
    int pointer;
    void check_if_key_is_clicked() {
        if(ne_keyboard.key_down(NE_KEY_BACKSPACE)){
            erase_char();
        }
        if(ne_keyboard.key_down(NE_KEY_LEFT)){
            dec_pointer();
        }
        if(ne_keyboard.key_down(NE_KEY_RIGHT)){
            inc_pointer();
        }
        for(int i = 0; i < 226; i++){
            if(ne_keyboard.key_down(i)){
                char ch = ne_get_char(i);
                if(ch != -1){
                    value.insert(pointer+1,1,ch);
                    pointer++;
                }
            }
        }
    }

    void erase_char(){
        if(value.size() <= 0 || pointer == -1){
            return;
        }
        value = value.erase(pointer,1);
        dec_pointer();
    }

    void add_char(char ch) {
        value += ch;
        inc_pointer();
    }

    void dec_pointer(){
        if(pointer > -1){
            pointer--;
        }
    }

    void inc_pointer(){
        int csize = value.size()-1;
        if(pointer < csize){
            pointer++;
        }
    }
public:
    string value;
    Ne_input_buffer() {
        value.resize(0);
        value = "";
        pointer = -1;
    }
    void run() {
        check_if_key_is_clicked();
    }
};

#endif // INPUT_BUFFER_HPP_INCLUDED
