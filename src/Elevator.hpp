#pragma once
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "Constants.hpp"
using namespace pros;
using namespace Constants;

class Elevator{
    public:
    //initialize motor
    Motor elevator_mtr = Motor(Elevator_p);
    Elevator(){
    elevator_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
    inline void upwards(int voltage){
        elevator_mtr.move(voltage);
    }

    inline void chain(int discelevator){
        elevator_mtr.move_relative(discelevator,127);
    }
    bool down = false;
    bool up = false;
    inline void toggle(){
        if (up == true) {
        elevator_mtr.move(127);
        } else if (down == true) {
        elevator_mtr.move(-127);
        }else {
        elevator_mtr.move(0);
        }
    }

    inline void toggle_down(){
        down=!down; 
        toggle();
    }

    inline void toggle_up(){
        up=!up;
        toggle();
    }
    }; 