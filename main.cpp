#include "data/never_engine_library/modules/game/run.hpp"
#include "data/never_engine_extends/ne_extends.hpp"

using namespace std;

int main() {

    ne_init();

    ne_resolutions->add_resolution(1600,900);
    ne_resolutions->apply_resolution(0,window);

    //Ne_map<Ne_image*> * mainMap = new Ne_map<Ne_image*>();
    Ne_sprite * characterSprite = new Ne_sprite("char.png",4,4,0,0,0.1);
    Ne_character_controller * characterController = new Ne_character_controller(10);
    characterController->set_diagonally(false);
    characterController->set_movement_mode(true);
    Ne_character * character = new Ne_character(characterController,characterSprite);
    character->set_animation_mode(true);
    //Ne_map_controller<Ne_image*> * mainMap = new Ne_map_controller<Ne_image*>();

    ne_start_timer();
    while(!ne_keyboard.key_down(NE_KEY_ESCAPE)){
        ne_run();

        if(ne_mouse_moved) {

        }

        if(ne_mouse_button_down) {

        }

        if(ne_mouse_button_up) {

        }

        if(ne_frame_tick) {
            ne_in_game_time->fly_time();
            character->run();
            //characterSprite->run();
        }

    }

    return 0;
}
