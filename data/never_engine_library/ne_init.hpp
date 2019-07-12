#ifndef NE_INIT_HPP_INCLUDED
#define NE_INIT_HPP_INCLUDED

    // ------------------------
    // NeverEngine Core Library
    // ------------------------
    // Type: Initializer
    // Module: None
    // Used in: App
    // Required: ?
    // Utils: ?
    // Has Metadata : No
    // Run method: None
    // ------------------------
    // Version Added: 1.1 Alpha
    // Version Modified: 1.1 Alpha
    // ------------------------
    // Initialize Allegro library
    // in way that will work with
    // NeverEngine library
    // ------------------------

#include "never_engine.hpp"

void ne_init() {
    srand(time(NULL));
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_image_addon();
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    window = al_create_display(
      ne_config->default_screen_width,
      ne_config->default_screen_height
      );
    al_set_window_title(
      window,
      ne_config->project_title.c_str()
      );

    Ne_resolution_controller::toogle_windowed(window);

    ne_resolutions = new Ne_resolution();
    ne_in_game_time = new Ne_time(ne_config->day_time);
    ne_mouse = new Ne_mouse();
    ne_timer = al_create_timer(1.0/ne_config->frames_per_second);
    ne_event_queue = al_create_event_queue();

    al_register_event_source(ne_event_queue, al_get_timer_event_source(ne_timer));
    al_register_event_source(ne_event_queue, al_get_mouse_event_source());
}

void ne_start_timer() {
    al_start_timer(ne_timer);
}

#endif // NE_INIT_HPP_INCLUDED
