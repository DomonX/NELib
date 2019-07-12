#ifndef IMAGE_HPP_INCLUDED
#define IMAGE_HPP_INCLUDED

// ------------------------
// NeverEngine Core Library
// ------------------------
// Type: Module
// Module: Ne_image
// Used in: Ne_sprite, Ne_animation
// Required: Ne_config
// Utils: screen_scaler
// Has Metadata : Yes
// Run method: run()
// ------------------------
// Version Added: 1.1 Alpha
// Version Modified: 1.1 Alpha
// ------------------------
// Scalable allegro image
// Can be displayed in window
// ------------------------

#include "../../config/config.hpp"
#include "image_metadata.hpp"
#include "../../utils/screen_scaler.hpp"

using namespace std;

class Ne_image {
private:
    ALLEGRO_BITMAP* bitmap;
    void draw_image_scaled() {
        int width = al_get_bitmap_width(bitmap);
        int height = al_get_bitmap_height(bitmap);
        double scale = ne_get_screen_scale();
        al_draw_scaled_bitmap(
         bitmap,
         0,
         0,
         width,
         height,
         ne_get_x_pos_scale(metadata->position_x) - get_image_shift_if_aligned_x(width,scale),
         ne_get_y_pos_scale(metadata->position_y) - get_image_shift_if_aligned_y(height,scale),
         width*scale,
         height*scale,
         metadata->flags
         );
    }
    void draw_image_custom_scaled() {
        int width = al_get_bitmap_width(bitmap);
        int height = al_get_bitmap_height(bitmap);
        al_draw_scaled_bitmap(bitmap,
         0,
         0,
         width,
         height,
         ne_get_x_pos_scale(metadata->position_x) - get_image_shift_if_aligned_x(width,metadata->scale),
         ne_get_y_pos_scale(metadata->position_y) - get_image_shift_if_aligned_y(height,metadata->scale),
         width*metadata->scale,
         height*metadata->scale,
         metadata->flags
         );
    }
    void draw_image_alpha_scaled() {
        int width = al_get_bitmap_width(bitmap);
        int height = al_get_bitmap_height(bitmap);
        double scale = ne_get_screen_scale();
        al_draw_tinted_scaled_bitmap(
         bitmap,
         al_map_rgba_f(1,1,1,(float)metadata->alpha),
         0,
         0,
         width,
         height,
         ne_get_x_pos_scale(metadata->position_x) - get_image_shift_if_aligned_x(width,scale),
         ne_get_y_pos_scale(metadata->position_y) - get_image_shift_if_aligned_y(height,scale),
         width*scale,
         height*scale,
         metadata->flags
         );
    }
    void draw_image_alpha_custom_scaled(){
        int width = al_get_bitmap_width(bitmap);
        int height = al_get_bitmap_height(bitmap);
        al_draw_tinted_scaled_bitmap(bitmap,
         al_map_rgba_f(1,1,1,(float)metadata->alpha),
         0,
         0,
         width,
         height,
         ne_get_x_pos_scale(metadata->position_x) - get_image_shift_if_aligned_x(width,metadata->scale),
         ne_get_y_pos_scale(metadata->position_y) - get_image_shift_if_aligned_y(height,metadata->scale),
         width*metadata->scale,
         height*metadata->scale,
         metadata->flags
         );
    }
public:
    Ne_image_metadata * metadata;
    Ne_image(const char * bitmap_path) {
        this->bitmap = al_load_bitmap(bitmap_path);
        if(!bitmap) {
            cout << "NE Error: file " << bitmap_path << " cannot be found (IN: Ne_image constructor)" << endl;
        }
        this->metadata = new Ne_image_metadata();
    }

    Ne_image(ALLEGRO_BITMAP * bitmap) {
        this->bitmap = bitmap;
        this->metadata = new Ne_image_metadata();
    }

    void draw_image() {
        if(metadata->alpha == 1 && metadata->scale == 0){
            draw_image_scaled();
        }
        if(metadata->alpha == 1 && metadata->scale > 0){
            draw_image_custom_scaled();
        }
        if(metadata->alpha < 1 && metadata-> scale == 0){
            draw_image_alpha_scaled();
        }
        if(metadata->alpha < 1 && metadata-> scale > 0){
            draw_image_alpha_custom_scaled();
        }
    }

    int get_image_shift_if_aligned_x(int width, double scale) {
        if(metadata->horizontal_align == ne_h_align_left) {
            return 0;
        }
        if(metadata->horizontal_align == ne_h_align_center) {
            return width*scale/2;
        }
        if(metadata->horizontal_align == ne_h_align_right) {
            return width*scale;
        }
    }

    int get_image_shift_if_aligned_y(int height, double scale) {
        if(metadata->vertical_align == ne_v_align_top) {
            return 0;
        }
        if(metadata->vertical_align == ne_v_align_center) {
            return height*scale/2;
        }
        if(metadata->vertical_align == ne_v_align_down) {
            return height*scale;
        }
    }

    int get_width() {
        return al_get_bitmap_width(bitmap);
    }

    int get_height() {
        return al_get_bitmap_height(bitmap);
    }

    void run() {
        draw_image();
    }

    void run(int x, int y) {
        metadata->position_x = x;
        metadata->position_y = y;
        draw_image();
    }
};

#endif // IMAGE_HPP_INCLUDED
