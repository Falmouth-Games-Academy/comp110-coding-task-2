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
};

