#include "stdafx.h"
#include "CellDoor.h"
#include "PatientGame.h"


CellDoor::CellDoor(Directions::Direction direction, std::shared_ptr<LevelCell> cell, PatientGame* game)
	: CellEdge(direction, cell)
{
	initialiseSprite(game);
	initialisePosition();
}