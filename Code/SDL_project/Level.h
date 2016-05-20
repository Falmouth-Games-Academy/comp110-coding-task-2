#pragma once
#include "Cell.h"


class Level
{
public:
	Level();
	~Level();

	int getCellSize() { return cellSize; }

	std::vector<std::vector<std::shared_ptr<Cell>>> grid;

	void makeGrid(int Window_Width, int Window_Height);


protected:

	int cellSize = 50;
};

