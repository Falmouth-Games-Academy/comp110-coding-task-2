//! Class for doors.
/*!
  This class represents the door of the cells.
  It inherits from CellEdge and implements the method
  for setting the sprite.
*/

#pragma once
#include "CellEdge.h"

class CellDoor :
	public CellEdge
{
public:
	//! Constructor for the door.
	/*!
	  This is the constructor for the door.
	  It assigns the door a direction and a cell, as
	  well as a pointer to the game.
	*/
	CellDoor(Directions::Direction direction, std::shared_ptr<LevelCell> cell, PatientGame* game);

	//! This method returns whether the edge is a wall.
	/*!
	  This method returns a bool indicating whether the edge is a wall.
	  CellDoor is not a wall, so should return false.
	*/
	bool isWall() { return false; }

	//! This method returns whether the edge is a door.
	/*!
	  This method returns a bool indicating whether the edge is a door.
	  CellDoor is a door, so should return true.
	*/
	bool isDoor() { return true; }

	//! This method returns whether the edge is a passage.
	/*!
	  This method returns a bool indicating whether the edge is a door.
	  CellDoor is not a passage, so should return false.
	*/
	bool isPassage() { return false; }

private:
	//! Initialises the sprite.
	/*!
	  This method sets the sprite to the door sprite of
	  the appropriate orientation.
	*/
	void initialiseSprite(PatientGame* game);
};

