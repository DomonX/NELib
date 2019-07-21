#ifndef MAP_CONTROLLER_HPP_INCLUDED
#define MAP_CONTROLLER_HPP_INCLUDED

#include "map.hpp"

template<class T>
class Ne_map_controller {
public:
    Ne_map<T> * mainmap;
    Ne_map_controller() {
        this->mainmap = new Ne_map<T>();
    }
};


#endif // MAP_CONTROLLER_HPP_INCLUDED
