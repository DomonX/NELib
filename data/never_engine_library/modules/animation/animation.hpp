#ifndef ANIMATION_HPP_INCLUDED
#define ANIMATION_HPP_INCLUDED

// ------------------------
// NeverEngine Core Library
// ------------------------
// Type: Module
// Module: Ne_animation
// Used in: Ne_sprite
// Required: Ne_image, Ne_config
// Utils: screen_scaler
// Has Metadata : Yes
// Run method: run()
// ------------------------
// Version Added: 1.1 Alpha
// Version Modified: 1.1 Alpha
// ------------------------
// Animated object on screen
// ------------------------

#include "../image/image.hpp"
#include "animation_metadata.hpp"

class Ne_animation {
private:
    vector < Ne_image * > frames_bitmaps;
public:
    Ne_animation_metadata * metadata;

    Ne_animation(const char * bitmap_path, int pos_x, int pos_y, int animation_frames, double seconds_per_frame) {
        metadata = new Ne_animation_metadata();
        metadata->position_x = pos_x;
        metadata->position_y = pos_y;
        metadata->animation_frames = animation_frames;
        metadata->seconds_per_frame = seconds_per_frame;

        ALLEGRO_BITMAP * temp = al_load_bitmap(bitmap_path);
        create_sub_bitmaps(temp);

    }

    Ne_animation(ALLEGRO_BITMAP * bitmap, int pos_x, int pos_y, int animation_frames, double seconds_per_frame) {
        metadata = new Ne_animation_metadata();
        metadata->position_x = pos_x;
        metadata->position_y = pos_y;
        metadata->animation_frames = animation_frames;
        metadata->seconds_per_frame = seconds_per_frame;

        create_sub_bitmaps(bitmap);
    }

    void add_animation_frame(ALLEGRO_BITMAP * part, int index) {
        if(frames_bitmaps.size() <= index) {
            return;
        }
        frames_bitmaps.at(index) = new Ne_image(part);
    }

    void create_sub_bitmaps(ALLEGRO_BITMAP * source) {
        int part_width = al_get_bitmap_width(source)/metadata->animation_frames;
        int part_height = al_get_bitmap_height(source);
        frames_bitmaps.resize(metadata->animation_frames);
        for(int i = 0; i < metadata->animation_frames; i++) {
            ALLEGRO_BITMAP * part = al_create_sub_bitmap(source,i*part_width,0,part_width,part_height);
            add_animation_frame(part,i);
        }
    }

    void tick_animation() {
        metadata->current_animation_counter++;
        int ticks_for_frame = ne_config->frames_per_second * metadata->seconds_per_frame;
        if(metadata->current_animation_counter >= ticks_for_frame) {
            metadata->current_animation_counter = 0;
            metadata->current_animation_frame++;
        }
        if(metadata->current_animation_frame >= metadata->animation_frames) {
            metadata->current_animation_frame = 0;
        }
    }

    void animate(int index) {
        if(frames_bitmaps.size() <= index) {
            return;
        }
        frames_bitmaps.at(index)->run(metadata->position_x,metadata->position_y);
    }

    void animate() {
        tick_animation();
        if(frames_bitmaps.size() <= metadata->current_animation_frame) {
            return;
        }
        frames_bitmaps.at(metadata->current_animation_frame)->run(metadata->position_x,metadata->position_y);
    }

    void rest() {
        metadata->current_animation_counter = 0;
        metadata->current_animation_frame = 0;
    }

    void run() {
        animate();
    }

    void run(int index) {
        animate(index);
    }

    void run(int x, int y) {
        metadata->position_x = x;
        metadata->position_y = y;
        animate();
    }

    void run(int x, int y, int index) {
        metadata->position_x = x;
        metadata->position_y = y;
        animate(index);
    }
};

#endif // ANIMATION_HPP_INCLUDED
