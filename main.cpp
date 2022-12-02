R_speed = 0
L_speed = 0

def when_started1():
    global R_speed, L_speed
    R_wheel.spin(FORWARD)
    L_Wheel.spin(FORWARD)
    R_wheel.set_velocity(0, PERCENT)
    L_Wheel.set_velocity(0, PERCENT)
    roller.set_velocity(100, PERCENT)
    R_wheel.set_stopping(BRAKE)
    L_Wheel.set_stopping(BRAKE)
    while True:
        if controller_1.buttonX.pressing():
            roller.spin(FORWARD)
            R_speed = 40
            L_speed = 20
        elif controller_1.buttonB.pressing():
            roller.spin(REVERSE)
            R_speed = 40
            L_speed = 20
        else:
            roller.stop()
            if controller_1.buttonUp.pressing():
                R_speed = 30
                L_speed = 30
            elif controller_1.buttonDown.pressing():
                R_speed = -30
                L_speed = -30
            elif controller_1.buttonLeft.pressing():
                R_speed = 30
                L_speed = -30
            elif controller_1.buttonRight.pressing():
                R_speed = -30
                L_speed = 30
            else:
                R_speed = controller_1.axis3.position() - controller_1.axis1.position()
                L_speed = controller_1.axis3.position() + controller_1.axis1.position()
        R_wheel.set_velocity(R_speed, PERCENT)
        L_Wheel.set_velocity(L_speed, PERCENT)
        wait(5, MSEC)

when_started1()
