#ifndef TIME_HPP_INCLUDED
#define TIME_HPP_INCLUDED

/// @todo (DomonX#1#07/07/19): Add darkness algorythm variables to config


class Ne_time {
   public:
    double day_time;
    double current_time;

    Ne_time(double day_lenght){
        current_time = day_lenght/2.0 ;
        day_time = day_lenght;
    }

    void fly_time(){
        if(current_time > day_time){
            current_time = 0.0;
        }else{
            current_time++;
        }
    }

    double get_darkness(double scale){
        return get_darkness()*scale;
    }

    double get_darkness(){
        double darkness = pow((abs((current_time-0.1*day_time)-(day_time/2.0))),0.8)/(pow(day_time/2.0,0.8)) + 0.20;
        if(darkness > 1.0){
            darkness = 1.0;
        }
        return darkness;
    }

    int get_time(){
        double parter = day_time / (24.0*60.0);
        return current_time / parter;
    }
    int get_minutes(){
        return get_time()%60;
    }
    int get_hours(){
        return get_time()/60;
    }
};

Ne_time * ne_in_game_time;

#endif // TIME_HPP_INCLUDED
