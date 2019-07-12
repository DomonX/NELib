#ifndef ANIMATION_METADATA_HPP_INCLUDED
#define ANIMATION_METADATA_HPP_INCLUDED

    // ------------------------
    // NeverEngine Core Library
    // ------------------------
    // Type: Metadata
    // Module: Ne_animation
    // Used in: Ne_sprite
    // Required: Ne_image, Ne_config
    // Utils: screen_scaler
    // Has Metadata : No
    // Run method: None
    // ------------------------
    // Version Added: 1.1 Alpha
    // Version Modified: 1.1 Alpha
    // ------------------------
    // Default meta data configuration
    // can be overwrite in module
    // ------------------------

class Ne_animation_metadata {
public:
    int animation_frames;
    double seconds_per_frame;
    int current_animation_counter;
    int current_animation_frame;
    int position_x;
    int position_y;

    Ne_animation_metadata() {
        animation_frames = 1;
        double seconds_per_frame = 1;
        current_animation_counter = 0;
        current_animation_frame = 0;
        position_x = 0;
        position_y = 0;
    }
};

#endif // ANIMATION_METADATA_HPP_INCLUDED
