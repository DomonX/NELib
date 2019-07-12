#ifndef CONFIG_ALLEGRO_HPP_INCLUDED
#define CONFIG_ALLEGRO_HPP_INCLUDED

    #include <allegro5/allegro.h>
    #include <allegro5/allegro_image.h>
    #include <allegro5/allegro_font.h>
    #include <allegro5/allegro_ttf.h>
    #include <allegro5/allegro_primitives.h>

    ALLEGRO_TIMER * ne_timer;
    ALLEGRO_EVENT_QUEUE * ne_event_queue;
    ALLEGRO_EVENT ne_events;
    ALLEGRO_DISPLAY * window;
    ALLEGRO_KEYBOARD_STATE keyboard;

#endif // CONFIG_ALLEGRO_HPP_INCLUDED
