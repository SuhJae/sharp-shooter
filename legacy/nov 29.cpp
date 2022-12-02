// Code that will move the robot forward at a 10% of the maximum speed.
// Used when rotating the roller to keep tension
void myblockfunction_full_foward();

float control_L, control_R;

void myblockfunction_full_foward() {
    back_R.setVelocity(10.0, percent);
    front_R.setVelocity(10.0, percent);
    front_L.setVelocity(10.0, percent);
    back_L.setVelocity(10.0, percent);
}

// code that will be executed on the start button
int whenStarted1() {
    // intialize the motors
    roller.setVelocity(60.0, percent);
    back_R.setVelocity(0.0, percent);
    front_R.setVelocity(0.0, percent);
    front_L.setVelocity(0.0, percent);
    back_L.setVelocity(0.0, percent);
    front_R.setStopping(brake);
    front_L.setStopping(brake);
    back_R.setStopping(brake);
    back_L.setStopping(brake);
    front_R.spin(forward);
    front_L.spin(forward);
    back_R.spin(forward);
    back_L.spin(forward);

    // listen for the controller event
    while (true) {
        // if statment for the roller handling (Highest priority)
        if (Controller1.ButtonX.pressing()) {
            myblockfunction_full_foward();
            roller.spin(forward);
        } else if (Controller1.ButtonB.pressing()) {
            myblockfunction_full_foward();
            roller.spin(reverse);
        } else {

            // listen for the precision movement. (arrow button) (2nd priority)
            if (Controller1.ButtonUp.pressing()) {
                back_R.setVelocity(30.0, percent);
                front_R.setVelocity(30.0, percent);
                front_L.setVelocity(30.0, percent);
                back_L.setVelocity(30.0, percent);
            } else if (Controller1.ButtonDown.pressing()) {
                back_R.setVelocity(-30.0, percent);
                front_R.setVelocity(-30.0, percent);
                front_L.setVelocity(-30.0, percent);
                back_L.setVelocity(-30.0, percent);
            } else if (Controller1.ButtonLeft.pressing()) {
                back_R.setVelocity(30.0, percent);
                front_R.setVelocity(30.0, percent);
                front_L.setVelocity(-30.0, percent);
                back_L.setVelocity(-30.0, percent);
            } else if (Controller1.ButtonRight.pressing()) {
                back_R.setVelocity(-30.0, percent);
                front_R.setVelocity(-30.0, percent);
                front_L.setVelocity(30.0, percent);
                back_L.setVelocity(30.0, percent);
            
            // if no button is pressed, check the joystick (3rd priority)
            } else {
                roller.stop();
                control_L = Controller1.Axis3.position() + Controller1.Axis1.position();
                control_R = Controller1.Axis3.position() - Controller1.Axis1.position();
                back_R.setVelocity(control_R, percent);
                front_R.setVelocity(control_R, percent);
                front_L.setVelocity(control_L, percent);
                back_L.setVelocity(control_L, percent);
            }
        }
    wait(5, msec);
    // Sleep the task for a short amount of time to prevent wasted resources.
    // could be commented out if maximum responsiveness is needed.
    }
    return 0;
}

// code that will be executed on the start button
int main() {
    // post event registration

    // set default print color to black
    printf("\033[30m");

    // wait for rotation sensor to fully initialize
    wait(30, msec);

    whenStarted1();
}