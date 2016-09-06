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
};

