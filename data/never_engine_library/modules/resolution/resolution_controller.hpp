#ifndef RESOLUTION_CONTROLLER_HPP_INCLUDED
#define RESOLUTION_CONTROLLER_HPP_INCLUDED

#include "../../config/config.hpp"

using namespace std;

class Ne_resolution_controller {
private:
    int screen_width;
    int screen_height;
public:
    Ne_resolution_controller(int x, int y){
        screen_width = x;
        screen_height = y;
    }
    int get_height(){
        return screen_height;
    }
    int get_width(){
        return screen_width;
    }
    void apply_resolution(ALLEGRO_DISPLAY * target){
        ALLEGRO_MONITOR_INFO minfo;
        al_get_monitor_info(0,&minfo);
        int desktop_width = minfo.x2 - minfo.x1;
        int desktop_height = minfo.y2 - minfo.y1;
        if(screen_width > desktop_width || screen_height > desktop_height){
            return;
        }
        ne_config->current_screen_width = screen_width;
        ne_config->current_screen_height = screen_height;
        al_resize_display(target,screen_width,screen_height);
    }
    void window_center(ALLEGRO_DISPLAY * target){
        ALLEGRO_MONITOR_INFO minfo;
        al_get_monitor_info(0,&minfo);
        int desktop_width = minfo.x2 - minfo.x1;
        int desktop_height = minfo.y2 - minfo.y1;
        int width = al_get_display_width(target);
        int height = al_get_display_height(target);
        al_set_window_position(target,(desktop_width-width)/2,(desktop_height-height)/2);
    }
    static void toogle_windowed(ALLEGRO_DISPLAY * target){
        al_set_display_flag(target, ALLEGRO_FULLSCREEN_WINDOW, !(al_get_display_flags(target) & ALLEGRO_FULLSCREEN_WINDOW));
    }
};

#endif // RESOLUTION_CONTROLLER_HPP_INCLUDED
