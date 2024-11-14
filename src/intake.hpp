#pragma once
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "Constants.hpp"
using namespace pros;
using namespace Constants;

class Intake{
    public:
    //initialize motor
    Motor Intake_mtr = Motor(Intake_p);
    Intake(){
    Intake_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
    inline void inside(int voltage){
        Intake_mtr.move(voltage);
    }

    inline void bobwheel(int sucker){
        Intake_mtr.move_relative(sucker,127);
    }
    
    bool swollow = false;
    inline void toggle(){
        swollow =!swollow;
        if (swollow==true) {
            Intake_mtr.move(127);
        }else {
        Intake_mtr.move(0);
        }
    }
    };  