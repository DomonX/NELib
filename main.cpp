

#include "data/never_engine_library/modules/game/run.hpp"

using namespace std;

int main() {

    ne_init();

    Ne_image * img = new Ne_image("backtest.png");
    Ne_animation * anim = new Ne_animation("animation.png",50,50,4,0.1);
    Ne_sprite * spr = new Ne_sprite("char.png",4,4,0,0,0.1);
    Ne_button * btn = new Ne_button(50,50,"button.png",true);
    Ne_font * font = new Ne_font("font1.ttf");
    Ne_text_input * in = new Ne_text_input(200,200,"text.png",font,30,al_map_rgb(255,255,255));

    Ne_character_controller * chara = new Ne_character_controller(7);
    chara->set_diagonally(true);
    Ne_character * my_char = new Ne_character(chara,spr);

    ne_resolutions->add_resolution(1000,500);
    ne_resolutions->apply_resolution(0,window);
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
            cout << ne_mouse->get_mouse_x() << endl;
            bool moved = false;
            if(btn->is_clicked()) {
                Ne_resolution_controller::toogle_windowed(window);
            }
            ne_in_game_time->fly_time();
            img->run();
            my_char->run();
            btn->run();
        }

    }

    return 0;
}
