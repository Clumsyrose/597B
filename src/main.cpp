#include "main.h"
#include "drivetrain.hpp"
#include "Elevator.hpp"
#include "Intake.hpp"
#include "StakeHolder.hpp"
using namespace pros;
DriveTrain dt;
Elevator el;
Intake in;
StakeHolder stakeh;
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "GANG DOES THE PROGRAM WORK?");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	Controller master(CONTROLLER_MASTER);
	int stakeET = 0;
	while (true) {
	//tankdrive
		dt.tankDrive(master.get_analog(ANALOG_LEFT_Y), master.get_analog(ANALOG_RIGHT_Y));

	//elevator controls
		if (master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			el.upwards(80);
		} else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
			el.upwards(-80);
		} else {
			el.upwards(0);
		}

	//intake controls
		if (master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
			in.swallow(127);
		} else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
			in.swallow(-100);
		} else {
			in.swallow(0);
		}

	//pneumatics holder
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B) && (millis() - stakeET > 500)){
			stakeh.open(); stakeET = millis();
		}
	}
}