#include "stdafx.h"
#include "WanderingState.h"

WanderingState::WanderingState()
{
}

WanderingState::~WanderingState()
{
}

void WanderingState::update(Character& character, const Uint8* keyboardState)
{
	character.setSpeed(character.wanderSpeed);
	// Moves character in randomly chosen direction
	character.wanderAroundRoom();	

	// Character enters dead state when health reaches 0
	if (character.health == 0)
	{
		character.state = std::make_shared<DeadState>();
	}
	// If the oxygen goes beneath 50 the character speed reduces
	else if (character.getOxygenLevel(character.getX(), character.getY()) < 40)
	{
		character.state = std::make_shared<Suffocating>();
		//Change to have a low oxygen speed
		character.setSpeed(character.suffocatingSpeed);
	}
	//If the user presses WASD the character will move accordingly
	else if (keyboardState[SDL_SCANCODE_W] || keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_S] || keyboardState[SDL_SCANCODE_D])
	{
		character.state = std::make_shared<PlayerControlledState>();
		character.moveCharacter(keyboardState);
	}
	character.setSpeed(character.walkSpeed);
}
