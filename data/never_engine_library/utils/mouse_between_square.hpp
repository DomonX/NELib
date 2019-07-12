#ifndef MOUSE_BETWEEN_SQUARE_HPP_INCLUDED
#define MOUSE_BETWEEN_SQUARE_HPP_INCLUDED

#include "../config/config.hpp"

bool ne_mouse_between(int x, int y, int x2, int y2){
    int mouse_x = ne_mouse->get_mouse_x();
    int mouse_y = ne_mouse->get_mouse_y();
    if(mouse_x >= x && mouse_x <= x2 && mouse_y >= y && mouse_y <= y2) {
        return true;
    }else {
        return false;
    }
}

#endif // MOUSE_BETWEEN_SQUARE_HPP_INCLUDED
