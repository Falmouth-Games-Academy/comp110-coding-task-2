#pragma once
#include"Level.h"

class CharacterState; //forward declartion I think

//!  The abstract character class 
/*!
  This class is the base for the main character and the NPC. It contains all the functions
  needed to make the character move and react to different states.
*/
class Character
{//Abstract character class that the other types of character will inherit from
public:
	//! A constructor
	Character();
	//! A destructor
	~Character();
		
	//Getter methods
	//! Function that gets the characters X value
	int getX() { return x; }
	//! Function that gets the characters Y value
	int getY() { return y; }
	//! Function that gets the characters size
	int getSize() { return size; }
	//! Function that gets the characters speed
	int getSpeed() { return speed; }

	//Setter methods
	//! Function that sets the characters X value
	int setX(int newX) { return x = newX; }
	//! Function that sets the characters Y value
	int setY(int newY) { return y = newY; }
	//! Function that sets the characters speed
	int setSpeed(int newSpeed) { return speed = newSpeed; }
	
	//! Shared pointer to the Level loaded in SpaceGame */
	std::shared_ptr<Level> currentRoom;

	//Cell checking functions
	//! Checks whether a cell is a room
	bool isCellARoom(int x, int y);
	//! Checks whether a cell is a door
	bool isCellADoor(int x, int y);
	//! Checks whether a cell is a room but not a door
	bool canWanderInRoom(int x, int y);
	//! Gets the oxygen level of a given room
	int getOxygenLevel(int x, int y);

	//! Moves the character depending on the player's input
	void moveCharacter(const Uint8* keyboardState);
	//! If the user doesn't input a move for a given time the character will wander around
	void wanderAroundRoom();
	
	//! An shared pointer to the character's state.
	std::shared_ptr<CharacterState> state;
	
	//! A double for the character's health
	double health = 100;
	//! Boolean for whether character is alive
	bool isAlive = true; 
	//! Integer for the direction
	/*!
		Direction is used to decide the diretion the character 
		will move in when in the wandering state
	*/
	int direction = 1;
	//! Integer to store time
	/*! 
		Timer is used to count how long the character has been in the Idle state
	*/
	double timer = 0;
	//! Integers for the different movement speeds
	/*!
		The possible speeds for the character to move at
	*/
	int suffocatingSpeed = 1, wanderSpeed = 2, walkSpeed = 3, runSpeed = 3;

private:
	//! Integers for the character's X and Y position
	int x = 50, y = 50;
	//! Integer for the character size 
	/*!
		The size of the character sprite when rendered
	*/
	int size = 50;
	//! Integer for the characters current
	/*!
		The character's current speed
	*/
	int speed = 3; 
};

