#ifndef RESOLUTION_HPP_INCLUDED
#define RESOLUTION_HPP_INCLUDED

#include "resolution_controller.hpp"

class Ne_resolution {
public:
    vector<Ne_resolution_controller *> resolutions;
    void add_resolution(int width, int height) {
        resolutions.push_back(new Ne_resolution_controller(width,height));
    }
    void apply_resolution(int index, ALLEGRO_DISPLAY * target) {
        if(index >= resolutions.size()){
            return;
        }
        resolutions.at(index)->apply_resolution(target);
        resolutions.at(index)->window_center(target);
    }
};

Ne_resolution * ne_resolutions;

#endif // RESOLUTION_HPP_INCLUDED
