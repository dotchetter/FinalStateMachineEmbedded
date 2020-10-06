#pragma once

/*/
Add desired states in this class, used later
when insatntiating a StateMachine to bind
with a function / method.
*/

enum class State
{
	IDLE,	// Default main state, editing requires modification of StateMachine.h row 80 col 57
	READ_PROXIMITY_SENSOR,
	STOP_MOTORS,
	CHECK_KEY_PRESS
};