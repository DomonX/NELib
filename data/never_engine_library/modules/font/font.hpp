#ifndef FONT_HPP_INCLUDED
#define FONT_HPP_INCLUDED

#include "../../config/config.hpp"
#include "../../utils/screen_scaler.hpp"

class Ne_font {
private:
    vector <ALLEGRO_FONT *> sizes;
public:
    Ne_font(const char * path) {
        for(int i = 1; i < ne_config->fonts_max_size; i++) {
            sizes.push_back(al_load_font(path,i,0));
        }
    }
    ALLEGRO_FONT * get_font(int font_size){
        font_size = ne_get_screen_scale() * font_size;
        if(font_size > ne_config->fonts_max_size) {
            font_size = ne_config->fonts_max_size;
        }
        if(font_size < 1) {
            font_size = 1;
        }
        return sizes.at(font_size);
    }
};

#endif // FONT_HPP_INCLUDED
