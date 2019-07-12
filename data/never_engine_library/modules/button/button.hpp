#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "../../utils/mouse_between_square.hpp"
#include "../mouse/mouse.h"
#include "../image/image.hpp"

class Ne_button {
private:
    int position_x;
    int position_y;
    int width;
    int height;
    Ne_image * view;
    bool click;
    bool single_mode;
    bool handle_single_mode() {
        double scale = ne_get_screen_scale();
        if(mouse_over_button() && ne_mouse->single_button_click(1)) {
            click = true;
        }else{
            click = false;
        }
    }
    bool handle_pressure_mode() {
        double scale = ne_get_screen_scale();
        if(mouse_over_button() && ne_mouse->button_clicked(1)) {
            click = true;
        }else{
            click = false;
        }
    }
    bool mouse_over_button() {
        double scale = ne_get_screen_scale();
        if(
         ne_mouse_between(
          position_x-view->get_image_shift_if_aligned_x(width,scale)/scale,
          position_y-view->get_image_shift_if_aligned_y(height,scale)/scale,
          position_x+width-view->get_image_shift_if_aligned_x(width,scale)/scale,
          position_y+height-view->get_image_shift_if_aligned_y(height,scale)/scale
         )
        ) {
            return true;
        }
        return false;
    }
public:
    bool visible;
    Ne_button(int x, int y, int w, int h, bool mode) {
        position_x = x;
        position_y = y;
        width = w;
        height = h;
        visible = false;
        Ne_image * view = NULL;
        single_mode = mode;
        click = false;
    }
    Ne_button(int x, int y, const char * bitmap_path, bool mode) {
        position_x = x;
        position_y = y;
        view = new Ne_image(bitmap_path);
        width = view->get_width();
        height = view->get_height();
        visible = true;
        view->metadata->position_x = position_x;
        view->metadata->position_y = position_y;
        single_mode = mode;
        click = false;
    }
    bool is_clicked() {
        return click;
    }
    void run(){
        if(visible){
            view->draw_image();
        }
        if(single_mode) {
            handle_single_mode();
        }
        if(!single_mode) {
            handle_pressure_mode();
        }

    }
};

#endif // BUTTON_HPP_INCLUDED
