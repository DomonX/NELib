#include "data/never_engine_library/modules/game/run.hpp"
#include "data/never_engine_extends/ne_extends.hpp"

using namespace std;

int main() {

    ne_init();

    ne_resolutions->add_resolution(1600,900);
    ne_resolutions->apply_resolution(0,window);

    Ne_sprite * characterSprite = new Ne_sprite("char.png",4,4,0,0,0.1);
    Ne_sprite * characterSprite2 = new Ne_sprite("char.png",4,4,200,200,0.1);
    characterSprite->metadata->loop_aniamtion = false;
    characterSprite2->metadata->loop_aniamtion = false;
    Ne_character_controller * characterController = new Ne_character_controller(10);
    Ne_character_controller * characterController2 = new Ne_character_controller(10);
    characterController2->apply_settings(NE_KEY_W,NE_KEY_S,NE_KEY_A,NE_KEY_D);
    characterController->set_diagonally(true);
    characterController->set_movement_mode(false);
    characterController2->set_diagonally(true);
    characterController2->set_movement_mode(false);
    Ne_character * character = new Ne_character(characterController,characterSprite);
    Ne_character * character2 = new Ne_character(characterController2,characterSprite2);

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
            if(characterController->position_y > characterController2->position_y){
                character2->run();
                character->run();
            }else{
                character->run();
                character2->run();
            }
        }

    }

    return 0;
}
