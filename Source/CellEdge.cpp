#include "stdafx.h"
#include "CellEdge.h"
#include "Directions.h"
#include "LevelCell.h"


CellEdge::CellEdge(Directions::Direction direction, std::shared_ptr<LevelCell> cell)
	: direction(direction),
	containingCell(cell)
{
}

void CellEdge::render(SDL_Renderer* renderer)
{
	if (sprite)
	{
		sprite->render(renderer, centre);
	}
}