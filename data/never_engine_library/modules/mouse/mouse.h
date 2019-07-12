#ifndef MOUSE_H_INCLUDED
#define MOUSE_H_INCLUDED

#include "../../utils/screen_scaler.hpp"

class Ne_mouse {
private:
    int mouse_x;
    int mouse_y;
    int button;
    bool single_click;
    int single_click_button;
public:
    Ne_mouse() {
        mouse_x = 0;
        mouse_y = 0;
        button = 0;
        single_click = false;
    }
    int get_mouse_x() {
        return mouse_x;
    }
    int get_mouse_y() {
        return mouse_y;
    }
    void set_mouse(int x, int y) {
        mouse_x = x;
        mouse_y = y;
    }
    void set_button(int button) {
        this->button = button;
    }
    int get_button() {
        return button;
    }
    bool get_single_click() {
        return single_click;
    }
    void set_single_click(bool click) {
        single_click = click;
    }
    void read_single_click_button(){
        if(single_click) {
            single_click_button = button;
            single_click = false;
            return;
        }
        single_click_button = 0;
    }
    bool single_button_click(int button) {
        if(single_click_button == button) {
            return true;
        }
        return false;
    }
    bool button_clicked(int button) {
        if(this->button == button){
            return true;
        }
        return false;
    }
};

Ne_mouse * ne_mouse;
#endif // MOUSE_H_INCLUDED
