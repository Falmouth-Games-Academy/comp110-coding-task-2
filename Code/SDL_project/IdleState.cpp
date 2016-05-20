#include "stdafx.h"
#include "IdleState.h"

IdleState::IdleState()
{
}

IdleState::~IdleState()
{
}

// Checks and updates character state
void IdleState::update(Character& character, const Uint8* keyboardState)
{
	// Idle state is for the start and the a for when the character has just stopped being controlled by the player
	timer = timer + (1 / FRAME_RATE); 
	
	// Character dies when the health reaches 0
	if (character.health == 0)
	{
		character.state = std::make_shared<DeadState>();
		character.isAlive = false;
	}
	// If the oxygenLevel in a cell is beneath 50 the character changes to the Suffocating state
	else if (character.getOxygenLevel(character.getX(), character.getY()) < 40)
	{
		character.state = std::make_shared<Suffocating>();
		// Character move speed is reduced 
		character.setSpeed(character.suffocatingSpeed); 
	}
	// If the user has pressed WASD the character enters the PlayerControlledState
	else if (keyboardState[SDL_SCANCODE_W] || keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_S] || keyboardState[SDL_SCANCODE_D])
	{
		character.state = std::make_shared<PlayerControlledState>();
		// Character moves based on keyboard input
		character.moveCharacter(keyboardState);
	}
	// If the character is in the Idle state for too long it changes to the WanderingState
	else if (timer > END_IDLE_TIME)
	{ 
		character.state = std::make_shared<WanderingState>();
		// Character will move in a randomly selected direction
		character.wanderAroundRoom();
	}
}
