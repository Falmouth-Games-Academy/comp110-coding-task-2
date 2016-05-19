#pragma once
#include "CharacterState.h"
#include "DeadState.h"
#include "IdleState.h"

// The character moves differently depending on the oxygen level
class Suffocating :
	public CharacterState
{
public:
	Suffocating();
	~Suffocating();

	void update(Character& character, const Uint8* keyboardState);

	int acceptableOxygenLevel = 50, dangeroursOxygenLevel = 20;
};

