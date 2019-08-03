#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

class Ne_character {
private:
    Ne_character_controller * controller;
    Ne_sprite * sprite;
public:
    Ne_character(Ne_character_controller * controller, Ne_sprite * sprite) {
        this->controller = controller;
        this->controller->position_x = sprite->metadata->position_x;
        this->controller->position_y = sprite->metadata->position_y;
        this->sprite = sprite;
        this->sprite->metadata->finished_animation = true;
    }
    // Run methods
    void run() {
        run(controller->get_x(),controller->get_y());
    }

    void run(int x, int y) {
        Ne_character_controller_info * result = controller->run();
        if(!result->has_moved() && sprite->metadata->finished_animation) {
            sprite->rest();
        }
        if(result->has_moved()) {
            sprite->metadata->finished_animation = false;
        }
        sprite->metadata->current_direction = controller->facing;
        sprite->run(x,y);
        return;
    }

};

#endif // CHARACTER_HPP_INCLUDED
