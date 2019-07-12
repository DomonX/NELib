#ifndef SPRITE_METADATA_HPP_INCLUDED
#define SPRITE_METADATA_HPP_INCLUDED

class Ne_sprite_metadata {
public:
    int sprite_x;
    int sprite_y;
    double seconds_per_frame;
    int current_animation_counter;
    int current_animation_frame;
    int current_direction;
    int position_x;
    int position_y;

    Ne_sprite_metadata() {
        sprite_x = 1;
        sprite_y = 1;
        seconds_per_frame = 1;
        current_animation_counter = 0;
        current_animation_frame - 0;
        current_direction = 0;
        position_x = 0;
        position_y = 0;
    }
};

#endif // SPRITE_METADATA_HPP_INCLUDED
