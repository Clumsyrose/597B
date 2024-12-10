#pragma once
#include <sys/_types.h>

namespace Constants {
    //right drivetrain
    static constexpr unsigned char rd1_p = 4; //Front right drivetrain port near intake
    static constexpr unsigned char rd2_p = 16; //Middle right drivetrain port
    static constexpr unsigned char rd3_p = 2; //End right drivetrain port near elevator

    //left drivetrain
    static constexpr unsigned char ld1_p = 20; // Front Left drivetrain port near intake
    static constexpr unsigned char ld2_p = 9; // Middle Left drivetrain port
    static constexpr unsigned char ld3_p = 7; // End Left drivetrain port near elevator

    //Elevator
    static constexpr unsigned char Elevator_p = 1;
    //Intake
    static constexpr unsigned char Intake_p =8;
    //stakeHolder port
    static constexpr unsigned char StakeHolder_p = 'A';
}