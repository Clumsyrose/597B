#pragma once
#include <sys/_types.h>

namespace Constants {
    //right drivetrain
    static constexpr unsigned char rd1_p = 1; //Front right drivetrain port near intake
    static constexpr unsigned char rd2_p = 2; //Middle right drivetrain port
    static constexpr unsigned char rd3_p = 3; //End right drivetrain port near elevator

    //left drivetrain
    static constexpr unsigned char ld1_p = 11; // Front Left drivetrain port near intake
    static constexpr unsigned char ld2_p = 12; // Middle Left drivetrain port
    static constexpr unsigned char ld3_p = 13; // End Left drivetrain port near elevator

    //Elevator & Intake
    static constexpr unsigned char Intake_p = 20;
    static constexpr unsigned char Elevator_p = 10;
    
    //stakeHolder port
    static constexpr unsigned char StakeHolder_p = 'A';
}