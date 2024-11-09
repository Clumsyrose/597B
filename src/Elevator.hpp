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
        elevator_mtr.move_relative(discelevator,90);
    }
    };  