#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

class Ne_character {
private:
    Ne_character_controller * controller;
    Ne_sprite * sprite;
    bool full_animation_mode;
    bool animation_started;
public:
    Ne_character(Ne_character_controller * controller, Ne_sprite * sprite) {
        this->controller = controller;
        this->sprite = sprite;
        full_animation_mode = false;
        animation_started = false;
    }
    void set_animation_mode(bool is_full_animation_active) {
        this->full_animation_mode = is_full_animation_active;
    }

    // Animation Types
    bool run_full_animation(int x, int y) {
        if(animation_started && sprite->metadata->finished_animation){
            animation_started = false;
            sprite->metadata->finished_animation = false;
        }
        if(!controller->run()->has_moved() && !animation_started ){
            sprite->rest();
            return true;
        }else{
            animation_started = true;
        }
        return false;
    }

    bool run_non_full_animation(int x, int y) {
        if(!controller->run()->has_moved()){
            sprite->rest();
            return true;
        }
        return false;
    }

    void apply_movement() {
        if(full_animation_mode) {
            if(run_full_animation(controller->get_x(),controller->get_y())){
                return;
            }
        }
        if(!full_animation_mode){
            if(run_non_full_animation(controller->get_x(),controller->get_y())){
                return;
            }
        }
    }

    // Run methods
    void run() {
        Ne_character_controller_info * result = controller->run();
        if(result->has_moved()) {
            apply_movement();
        }
        sprite->metadata->current_direction = controller->facing;
        sprite->run(controller->get_x(),controller->get_y());
        return;
    }

    void run(int x, int y) {
        if(full_animation_mode) {
            if(run_full_animation(x,y)){
                return;
            }
        }
        if(!full_animation_mode){
            if(run_non_full_animation(x,y)){
                return;
            }
        }
        sprite->metadata->current_direction = controller->facing;
        sprite->run(x,y);
        return;
    }

};

#endif // CHARACTER_HPP_INCLUDED
