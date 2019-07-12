#ifndef SCREEN_SCALER_HPP_INCLUDED
#define SCREEN_SCALER_HPP_INCLUDED

    double ne_get_screen_scale(){
        double scale_y = (double)al_get_display_height(window)/ne_config->desired_screen_height;
        double scale_x = (double)al_get_display_width(window)/ne_config->desired_screen_width;
        return scale_x < scale_y ? scale_x : scale_y;
    }
    double ne_get_screen_reversed_scale(){
        return (double)ne_config->desired_screen_width/al_get_display_width(window);
    }
    int ne_get_screen_shift_x(){
        return (al_get_display_width(window)-ne_config->desired_screen_width*ne_get_screen_scale())/2;
    }
    int ne_get_screen_shift_y(){
        return (al_get_display_height(window)-ne_config->desired_screen_height*ne_get_screen_scale())/2;
    }
    int ne_get_x_pos_scale(int x){
        return x*ne_get_screen_scale() + ne_get_screen_shift_x();
    }
    int ne_get_y_pos_scale(int y){
        return y*ne_get_screen_scale() + ne_get_screen_shift_y();
    }

#endif // SCREEN_SCALER_HPP_INCLUDED
