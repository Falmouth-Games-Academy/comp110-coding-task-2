#include "stdafx.h"
#include "CellWall.h"
#include "Directions.h"
#include "PatientGame.h"


CellWall::CellWall(Directions::Direction direction, std::shared_ptr<LevelCell> cell, PatientGame* game)
	: CellEdge(direction, cell)
{
	initialiseSprite(game);
	initialisePosition();
}




