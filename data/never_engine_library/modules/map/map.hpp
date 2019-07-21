#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

//#include "../../../never_engine_extends/ne_extends.hpp"
//#include "../../../never_engine_library/config/config.hpp"

template <class T>
class Ne_map {
private:
    vector < vector < T > > tiles;
public:
    Ne_map<T>() {
        this->tiles.resize(0);
    }
    void add_tile(int x, int y, T tile){
        if(tiles.size() <= x) {
            tiles.resize(x+1);
        }
        if(tiles.at(x).size() <= y) {
            tiles.at(x).resize(y+1);
        }
        tiles.at(x).at(y) = tile;
    }
    T get_tile(int x, int y) {
        if(tiles.size() <= x) {
            cout << "NE Error: Map out of range" << endl;
            return NULL;
        }
        if(tiles.at(x).size() <= y) {
            cout << "NE Error: Map out of range" << endl;
            return NULL;
        }
        return tiles.at(x).at(y);
    }
    void delete_tile(int x, int y) {
        if(tiles.size() <= x) {
            cout << "NE Error: Map out of range" << endl;
            return NULL;
        }
        if(tiles.at(x).size() <= y) {
            cout << "NE Error: Map out of range" << endl;
            return NULL;
        }
        tiles.at(x).at(y) = NULL;
    }
};

#endif // MAP_HPP_INCLUDED
