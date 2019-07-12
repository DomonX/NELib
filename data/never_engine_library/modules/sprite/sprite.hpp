#ifndef SPRITE_HPP_INCLUDED
#define SPRITE_HPP_INCLUDED

#include "../animation/animation.hpp"
#include "sprite_metadata.hpp"

class Ne_sprite {
private:
    vector <Ne_animation *> bitmaps;
public:
    Ne_sprite_metadata * metadata;
    Ne_sprite(const char * bitmap_path,
      int sprite_x,
      int sprite_y,
      int position_x,
      int position_y,
      double seconds_per_frame
      ){
        metadata = new Ne_sprite_metadata();

        metadata->sprite_x = sprite_x;
        metadata->sprite_y = sprite_y;
        metadata->position_x = position_x;
        metadata->position_y = position_y;
        metadata->seconds_per_frame = seconds_per_frame;

        ALLEGRO_BITMAP * temp = al_load_bitmap(bitmap_path);
        int part_width = al_get_bitmap_width(temp);
        int part_height = al_get_bitmap_height(temp)/sprite_y;
        bitmaps.resize(sprite_y);
        for(int i = 0; i < sprite_y; i++) {
            ALLEGRO_BITMAP * part = al_create_sub_bitmap(temp,
              0,
              part_height*i,
              part_width,
              part_height
              );
            bitmaps.at(i) = new Ne_animation(
              part,
              metadata->position_x,
              metadata->position_y,
              metadata->sprite_x,
              metadata->seconds_per_frame
              );
        }
    }

    void tick_animation() {
        metadata->current_animation_counter++;
        int ticks_for_frame = ne_config->frames_per_second * metadata->seconds_per_frame;
        if(metadata->current_animation_counter >= ticks_for_frame) {
            metadata->current_animation_counter = 0;
            metadata->current_animation_frame++;
        }
        if(metadata->current_animation_frame >= metadata->sprite_x) {
            metadata->current_animation_frame = 0;
        }
    }

    void animate() {
        tick_animation();
        if(metadata->sprite_x <= metadata->current_animation_frame) {
            return;
        }
        bitmaps.at(metadata->current_direction)->run(
                                                     metadata->position_x,
                                                     metadata->position_y,
                                                     metadata->current_animation_frame
                                                     );
    }

    void rest() {
        if(metadata->sprite_x <= metadata->current_animation_frame) {
            return;
        }
        metadata->current_animation_frame = 0;
        metadata->current_animation_counter = 0;
    }

    void set_direction(int direction) {
        if(direction >= metadata->sprite_y){
            return;
        }
        metadata->current_direction = direction;
    }

    void run() {
        animate();
    }

    void run(int x, int y) {
        metadata->position_x = x;
        metadata->position_y = y;
        animate();
    }

};

#endif // SPRITE_HPP_INCLUDED
