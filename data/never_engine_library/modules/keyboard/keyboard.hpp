#ifndef KEYBOARD_HPP_INCLUDED
#define KEYBOARD_HPP_INCLUDED

#include "../../config/config.hpp"
#include "stdlib.h"
#include "cstdio"

class Ne_keyboard_controller{
    private:
        bool keys_clicked[226];
        bool keys_down[226];
    public:
        void keyboard_cleanup(){
            al_get_keyboard_state(&keyboard);
            clear_keyboard();
        }
        bool key_clicked(int key){
            if(al_key_down(&keyboard,key)){
                return true;
            }
            return false;
        }
        bool key_down(int key){
            if(keys_down[key]){
                return true;
            }
            if(al_key_down(&keyboard,key) && keys_clicked[key] == false){
                keys_clicked[key] = true;
                keys_down[key] = true;
                return true;
            }
            return false;
        }
        bool key_down_absolute(int key){
             if(al_key_down(&keyboard,key) && keys_clicked[key] == false){
                keys_clicked[key] = true;
                keys_down[key] = true;
                return true;
            }
            return false;
        }
        void clear_keyboard(){
            for(int i = 0; i < 226; i++){
                clear_key(i);
            }
        }
        void clear_key(int key){
            keys_down[key] = false;
            if(!al_key_down(&keyboard,key)){
                keys_clicked[key] = false;
            }
        }
};

Ne_keyboard_controller ne_keyboard;

#endif // KEYBOARD_HPP_INCLUDED
