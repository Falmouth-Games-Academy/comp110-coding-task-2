#pragma once
#include"CharacterState.h"
#include "DeadState.h"
#include "Suffocating.h"
#include"PlayerControlledState.h"
#include"WanderingState.h"

// The state the character is in when there is no danger and no player input
class IdleState: public CharacterState
{
public:
	IdleState();
	~IdleState();

	void update(Character& character, const Uint8* keyboardState);
	// Used to measure how long the character has been in the Idle state
	double timer = 0;
	// Used to add to the timer
	double FRAME_RATE = 60;
};

