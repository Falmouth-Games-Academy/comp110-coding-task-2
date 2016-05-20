#pragma once
#include"CharacterState.h"
#include"Character.h"

// If the character runs out of health it enters the dead state
// The character can not leave the dead state
class DeadState: public CharacterState
{
public:
	DeadState();
	~DeadState();

	void update(Character& character, const Uint8* keyboardState);
};

