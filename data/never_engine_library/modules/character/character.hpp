#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

class Ne_character {
private:
    Ne_character_controller * controller;
    Ne_sprite * sprite;
public:
    Ne_character(Ne_character_controller * controller, Ne_sprite * sprite) {
        this->controller = controller;
        this->sprite = sprite;
    }
    void run() {
        if(!controller->run()){
            sprite->rest();
            sprite->run(controller->get_x(),controller->get_y());
            return;
        }
        sprite->metadata->current_direction = controller->facing;
        sprite->run(controller->get_x(),controller->get_y());
        return;
    }

};

#endif // CHARACTER_HPP_INCLUDED
