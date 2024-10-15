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
    inline void swallow(int voltage){
        Intake_mtr.move(voltage);
    }
};