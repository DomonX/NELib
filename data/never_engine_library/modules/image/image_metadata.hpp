#ifndef IMAGE_METADATA_HPP_INCLUDED
#define IMAGE_METADATA_HPP_INCLUDED

enum Ne_image_align_h {
    ne_h_align_left = 1,
    ne_h_align_center = 2,
    ne_h_align_right = 3
};

enum Ne_image_align_v {
    ne_v_align_top = 1,
    ne_v_align_center = 2,
    ne_v_align_down = 3
};

class Ne_image_metadata {
    public:
        int position_x;
        int position_y;
        Ne_image_align_h horizontal_align;
        Ne_image_align_v vertical_align ;
        double alpha;
        double scale;
        int flags;

        Ne_image_metadata(){
            position_x = 0;
            position_y = 0;
            horizontal_align = ne_h_align_left;
            vertical_align = ne_v_align_top;
            alpha = 1;
            scale = 0;
            flags = 0;
        }
};

#endif // IMAGE_METADATA_HPP_INCLUDED
