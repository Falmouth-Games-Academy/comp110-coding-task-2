#include "stdafx.h"
#include "Suffocating.h"

Suffocating::Suffocating()
{
}

Suffocating::~Suffocating()
{
}

void Suffocating::update(Character& character, const Uint8* keyboardState)
{
	if (!character.isAlive)
	{
		character.state = std::make_shared<DeadState>();
	}	
	// If oxygenLevel is below the dangeroursOxygenLevel the character loses health 
	else if (character.getOxygenLevel(character.getX(), character.getY()) < dangeroursOxygenLevel)
	{
		character.health = character.health - 0.1;
	}
	// If the oxygenLevel reaches acceptableOxygenLevel the character changes to the Idle state and speeds up again 
	else if (character.getOxygenLevel(character.getX(), character.getY()) > acceptableOxygenLevel)
	{
		character.state = std::make_shared<IdleState>();
		character.setSpeed(character.walkSpeed);
	}
	// The character can still move in the Suffocating state but speed is reduced
	if (keyboardState[SDL_SCANCODE_W] || keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_S] || keyboardState[SDL_SCANCODE_D])
	{
		character.state = std::make_shared<PlayerControlledState>();
		character.moveCharacter(keyboardState);
	}
}