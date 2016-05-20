#pragma once
#include "CharacterState.h"
#include "PlayerControlledState.h"

// The character will randomly move around the room without player input
class WanderingState :
	public CharacterState
{
public:
	WanderingState();
	~WanderingState();

	void update(Character& character, const Uint8* keyboardState);
};

