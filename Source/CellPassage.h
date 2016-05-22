//! Class for passages.
/*!
  This class represents the passage of the cells.
  It inherits from CellEdge and implements the method
  for setting the sprite.
*/

#pragma once
#include "CellEdge.h"

class PatientGame;

class CellPassage :
	public CellEdge
{
public:
	//! Constructor for the CellPassafe.
	/*!
	This is the constructor for the cell passages. It calls back to the
	CellEdge constructor and also sets up the sprite and its window
	position for rendering.
	*/
	CellPassage(Directions::Direction direction, std::shared_ptr<LevelCell> cell, PatientGame* game);

	//! This method returns whether the edge is a wall.
	/*!
	  This method returns a bool indicating whether the edge is a wall.
	  CellPassage is not a wall, so should return false.
	*/
	bool isWall() { return false; }
	
	//! This method returns whether the edge is a door.
	/*!
	  This method returns a bool indicating whether the edge is a door.
	  CellPassage is not a door, so should return false.
	*/
	bool isDoor() { return false; }

	//! This method returns whether the edge is a passage.
	/*!
	This method returns a bool indicating whether the edge is a passage.
	if is a passage, should return true.
	*/
	bool isPassage() { return true; }

private:
	//! Initialises the sprite.
	/*!
	  This method sets the sprite to nullptr, as a
	  passage does not require any visualisation.
	*/
	void initialiseSprite(PatientGame* game);
};

