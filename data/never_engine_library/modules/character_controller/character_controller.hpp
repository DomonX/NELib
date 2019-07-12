#ifndef CHARACTER_CONTROLLER_HPP_INCLUDED
#define CHARACTER_CONTROLLER_HPP_INCLUDED

#include "../keyboard/keycodes.hpp"
#include "../keyboard/keyboard.hpp"

class Ne_character_controller {

private:
    double position_x;
    double position_y;
    bool allow_diagonally;
    bool single_click;
    int key_down;
    int key_up;
    int key_left;
    int key_right;
    double speed;
public:
    int facing;
    Ne_character_controller() {
        apply_settings(NE_KEY_UP,NE_KEY_DOWN,NE_KEY_LEFT,NE_KEY_RIGHT);
        position_x = 0;
        position_y = 0;
        speed = 0;
        single_click = false;
        allow_diagonally = false;
    }
    Ne_character_controller(double speed) {
        apply_settings(NE_KEY_UP,NE_KEY_DOWN,NE_KEY_LEFT,NE_KEY_RIGHT);
        position_x = 0;
        position_y = 0;
        this->speed = speed;
        single_click = false;
        allow_diagonally = false;
    }
    Ne_character_controller(double x, double y, double speed) {
        apply_settings(NE_KEY_UP,NE_KEY_DOWN,NE_KEY_LEFT,NE_KEY_RIGHT);
        position_x = x;
        position_y = y;
        this->speed = speed;
        single_click = false;
        allow_diagonally = false;
    }
    void apply_settings(double up, double down, double left, double right) {
        key_up = up;
        key_down = down;
        key_left = left;
        key_right = right;
    }
    bool single_click_controller() {
        bool moving_down = false;
        bool moving_up = false;
        bool moving_right = false;
        bool moving_left = false;
        if(ne_keyboard.key_down(key_down)) {
            moving_down = true;
        }
        if(ne_keyboard.key_down(key_up)) {
            moving_up = true;
        }
        if(ne_keyboard.key_down(key_right)) {
            moving_right = true;
        }
        if(ne_keyboard.key_down(key_left)) {
            moving_left = true;
        }
        if(moving_up && moving_down) {
            moving_up = false;
            moving_down = false;
        }
        if(moving_right && moving_left) {
            moving_left = false;
            moving_right = false;
        }
        if(!moving_down && !moving_up && !moving_right && !moving_left) {
            return false;
        }
        if(allow_diagonally) {
            move_diagonally(moving_up,moving_down,moving_right,moving_left);
        }
        if(!allow_diagonally) {
            move_simple(moving_up,moving_down,moving_right,moving_left);
        }
        return true;
    }
    bool holding_controller() {
        bool moving_down = false;
        bool moving_up = false;
        bool moving_right = false;
        bool moving_left = false;
        if(ne_keyboard.key_clicked(key_down)) {
            moving_down = true;
        }
        if(ne_keyboard.key_clicked(key_up)) {
            moving_up = true;
        }
        if(ne_keyboard.key_clicked(key_right)) {
            moving_right = true;
        }
        if(ne_keyboard.key_clicked(key_left)) {
            moving_left = true;
        }
        if(moving_up && moving_down) {
            moving_up = false;
            moving_down = false;
        }
        if(moving_right && moving_left) {
            moving_left = false;
            moving_right = false;
        }
        if(!moving_down && !moving_up && !moving_right && !moving_left) {
            return false;
        }
        if(allow_diagonally) {
            move_diagonally(moving_up,moving_down,moving_right,moving_left);
        }
        if(!allow_diagonally) {
            move_simple(moving_up,moving_down,moving_right,moving_left);
        }
        return true;
    }
    void move_diagonally(bool up, bool down, bool right, bool left) {
        if(right && up) {
            if(facing != 0 && facing != 1) {
                facing = 0;
            }
            position_x += speed/2*sqrt(2);
            position_y -= speed/2*sqrt(2);
            return;
        }
        if(right && down) {
            if(facing != 1 && facing != 2) {
                facing = 2;
            }
            position_x += speed/2*sqrt(2);
            position_y += speed/2*sqrt(2);
            return;
        }
        if(left && up) {
            if(facing != 0 && facing != 3) {
                facing = 0;
            }
            position_x -= speed/2*sqrt(2);
            position_y -= speed/2*sqrt(2);
            return;
        }
        if(left && down) {
            if(facing != 2 && facing != 3) {
                facing = 2;
            }
            position_x -= speed/2*sqrt(2);
            position_y += speed/2*sqrt(2);
            return;
        }
        move_simple(up,down,right,left);
    }
    void move_simple(bool up, bool down, bool right, bool left) {
        if(left) {
            facing = 3;
            position_x -= speed;
        }
        if(right) {
            facing = 1;
            position_x += speed;
        }
        if(up) {
            facing = 0;
            position_y -= speed;
        }
        if(down) {
            facing = 2;
            position_y += speed;
        }
    }
    bool run() {
        if(single_click) {
            return single_click_controller();
        }
        return holding_controller();
    }
    void change_speed(double speed) {
        this->speed = speed;
    }
    void set_diagonally(bool diagonally) {
        allow_diagonally = diagonally;
    }
    // Temporary
    double get_x() {
        return position_x;
    }
    double get_y() {
        return position_y;
    }
};

#endif // CHARACTER_CONTROLLER_HPP_INCLUDED
