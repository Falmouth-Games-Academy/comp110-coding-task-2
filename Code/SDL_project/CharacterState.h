#pragma once
#include"Character.h"
#include"Level.h"


class CharacterState
{
public:
	CharacterState();
	~CharacterState();

	// Used to time how long the characte has been in a state
	double timer = 0;
	// Maxmimum time that the character should be in the Idle state
	int END_IDLE_TIME = 2;

	// Used to check and update the character state 
	virtual void update(Character& character, const Uint8* keyboardState);
 };