#include "stdafx.h"
#include "Character.h"

Character::Character()
{
}


Character::~Character()
{
}

// Checks keyboard input and moves character accordinly
void Character::moveCharacter(const Uint8* keyboardState)
{	 
	// If the W key is pressed and the character will move up as long as it won't be moved off screen
	if (keyboardState[SDL_SCANCODE_W] && getY() - getSpeed() > 0 && isCellARoom(getX(), getY() - getSpeed()))
	{ 
		setY(getY() - getSpeed());
	}
	else if (keyboardState[SDL_SCANCODE_S] && getY() + getSpeed() < 800 && isCellARoom(getX(), getY() + getSpeed())) 
	{
		setY(getY() + getSpeed());
	}
	else if (keyboardState[SDL_SCANCODE_A] && getX() + getSpeed() > 0 && isCellARoom(getX() - getSpeed(), getY()))
	{
		setX(getX() - getSpeed());
	}
	else if (keyboardState[SDL_SCANCODE_D] && getX() + getSpeed() < 800 && isCellARoom(getX() + getSpeed(), getY()))
	{
		setX(getX() + getSpeed());
	}
}

// If the player doesn't move the character it will start to move around the room in randomly selected directions
void Character::wanderAroundRoom()
{ 
	if (direction == 0 && getY() + getSpeed() < 800 - getSize() && canWanderInRoom(getX(), getY() + getSpeed()))
	{//Up
		setY(getY() + getSpeed());		
	}
	else if (direction == 1 && (getY() + getSpeed()) > 0 + getSize() && canWanderInRoom(getX(), getY() - getSpeed()))
	{//Down
		setY(getY() - getSpeed());
	}
	else if (direction == 2 && (getX() + getSpeed()) < 800 - getSize() && canWanderInRoom(getX() + getSpeed(), getY()))
	{//Right
		setX(getX() + getSpeed());
	}
	else if (direction == 3 && (getX() - getSpeed()) > 0 && canWanderInRoom(getX() - getSpeed(), getY()))
	{//Left
		setX(getX() - getSpeed());
	}
	//If the character can't move in the current direction it randomly selects a new one
	else
	{
		direction = rand() % 4;
	}
}

// Checks to see if a cell is a room
bool Character::isCellARoom(int x, int y)
{
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->isRoom;
}

// Checks to see if a cell is a room
bool Character::isCellADoor(int x, int y)
{
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->isDoor;
}

// Character can only wander around a room and can't go through door
bool Character::canWanderInRoom(int x, int y)
{ 
	if (isCellARoom(x, y) && !isCellADoor(x, y) )
	{
		return true;
	}
	else
		return false;
}

// Gets the oxygen level of the specified cell
int Character::getOxygenLevel(int x, int y)
{
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->oxygenLevel;
}

