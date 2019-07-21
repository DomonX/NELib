#ifndef CHARACTER_CONTROLLER_INFO_HPP_INCLUDED
#define CHARACTER_CONTROLLER_INFO_HPP_INCLUDED

class Ne_character_controller_info{
public:
    double moved_down;
    double moved_left;
    double moved_right;
    double moved_up;
    Ne_character_controller_info() {
        moved_down = 0;
        moved_left = 0;
        moved_right = 0;
        moved_up = 0;
    }
    bool has_moved() {
        if(moved_down || moved_left || moved_right || moved_up) {
            return true;
        }
        return false;
    }
};

#endif // CHARACTER_CONTROLLER_INFO_HPP_INCLUDED
