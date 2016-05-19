#pragma once
#include "CharacterState.h"
#include "IdleState.h"
#include "DeadState.h"
#include "Suffocating.h"

// The character moves based on the keyboard input 
class PlayerControlledState :
	public CharacterState
{
	
public:
	PlayerControlledState();
	~PlayerControlledState();

	void update(Character& character, const Uint8* keyboardState);
};

