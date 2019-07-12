#ifndef RUN_HPP_INCLUDED
#define RUN_HPP_INCLUDED

#include "../../ne_init.hpp"

void ne_run(){
    al_wait_for_event(ne_event_queue, &ne_events);
    // Frame Tick
    if(ne_events.type == ALLEGRO_EVENT_TIMER){
        ne_mouse->read_single_click_button();
        ne_in_game_time->fly_time();
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
        ne_frame_tick = true;
    }else{
        ne_frame_tick = false;
    }
    // Mouse moved
    if(ne_events.type == ALLEGRO_EVENT_MOUSE_AXES){
        double shift_multiplier_x = ((double)ne_config->current_screen_width / 2 - ne_events.mouse.x)/(double)ne_config->current_screen_width;
        double shift_multiplier_y = ((double)ne_config->current_screen_height / 2 - ne_events.mouse.y)/(double)ne_config->current_screen_height;
        ne_mouse->set_mouse(
            ne_get_screen_reversed_scale()*(ne_events.mouse.x) - ne_get_screen_shift_x()*4*shift_multiplier_x,
            ne_get_screen_reversed_scale()*(ne_events.mouse.y) - ne_get_screen_shift_y()*4*shift_multiplier_y
        );
        ne_mouse_moved = true;
    }else{
        ne_mouse_moved = false;
    }
    // Mouse button down
    if(ne_events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        ne_mouse_button_down = ne_events.mouse.button;
        ne_mouse->set_button(ne_mouse_button_down);
        ne_mouse->set_single_click(true);
    }else {
        ne_mouse_button_down = 0;
    }
    // Mouse button up
    if(ne_events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        ne_mouse->set_button(0);
        ne_mouse_button_up = true;
    }else {
        ne_mouse_button_up = false;
    }
    ne_keyboard.keyboard_cleanup();
}

#endif // RUN_HPP_INCLUDED
