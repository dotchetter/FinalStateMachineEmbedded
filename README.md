#inclucde "StateMachine.h"
#include "States.h"  // Edit the enums in this file to match your desired states

// compiler contract, we will define these later
void blinkLed();
void startStepperMotor();
void stopStepperMotor();
void checkMotorTemp();
void stop();
void idle();

// Create a StateMachine
StateMachine sm = StateMachine(&idle, State::IDLE);

// Add all the states which correlates to our functions
sm.addState(&blinkLed, States::BLINK_LED);
sm.addState(&startStepperMotor, States::STOP_STEPPER_MOTOR)
sm.addState(&checkMotorTemp, States::CHECK_MOTOR_TEMP)
    
// A chained mapping of state - the last one will run after the first one exhausts
sm.addState(&startStepperMotor, States::START_STEPPER_MOTOR, States::STOP_STEPPER_MOTOR);

void blinkLed()
{
    // led blinking code
    sm.release();
}
void startStepperMotor()
{
    // start stepper motor code 
    sm.release();
}
void stopStepperMotor()
{
    // stop stepper motor code 
    sm.release();
}
void checkMotorTemp()
{
    // check motor temp code
    sm.release();
}

void idle()
{

	if (key1_pressed) // psuedo code
    {
        sm.transitionTo(State::BlinkLed);
    }
    else if (key2_pressed)
    {
    	sm.transitionTo(State::BLINK_LED);
    }
    /*
    	other code to perform during idle
    */
}


void loop()
{
    sm.next()();
}
