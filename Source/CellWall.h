//! Class for walls.
/*!
  This class represents the wall of the cells.
  It inherits from CellEdge and implements the method
  for setting the sprite.
*/

#pragma once
#include "CellEdge.h"

class PatientGame;

class CellWall :
	public CellEdge
{
public:
	//! Constructor for the CellWall.
	/*!
	This is the constructor for the cell walls. It calls back to the
	CellEdge constructor and also sets up the sprite and its window
	position for rendering.
	*/
	CellWall(Directions::Direction direction, std::shared_ptr<LevelCell> cell, PatientGame* game);

};

