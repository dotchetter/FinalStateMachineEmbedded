# FinalStateMachineEmbedded



### What it does

This project is the result of an attempt to develop function-pointer-managing-final-statemachine,
which makes it easier to develop code with transitions between states in embedded systems.

It can map up to `128` functions as states, and due to memory restrictions on small devices, these are static arrays.

The StateMachine allows you to outsource the order of states and which is next in line. At the end of an implementation, the main loop could look like this:

```c
void loop()
{
    mystateMachine.next()();
}
```

... and yes, that is supposed to be `()()` like that.



### How to use it

The StateMachine allows you to kick it back and let it handle the state alternation for you. 
After you've instantiated it and given it function pointers with Enum's to bind them, you can simply call the `next()` method which will give you a pointer to the function for the state next in line.

The **StateMachine** will automatically revert to the idle function where you have code that read sensors, send things to WiFi or whatever else. Recursion is also taken care of - no risk of a function assigning itself as next in line - it's not allowed to.

Inside of a state function you can ask the **StateMachine** instance which state it is in at the moment, if it is not evident. You cannot however alter the state manually outside of the `main method` which is defined upon instantiation.



### Chained states

You can "chain" a state with another one, when it is added to the StateMachine. This only goes for one more link however, not a series of states in a row. This is so to prevent stack overflow or recursion somewhere in the state transition.

When you want to chain another state after a certain one has exhausted, it is simply passed as an additional optional argument when the `addState()` method is called.

**Do observe though**, that for a chained state to be added, it must first be added separately with the `addState()` method as any other. It cannot be added for the first time as a chained state.



### Here's an example:

```c
#include "StateMachine.h"
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

```



