#pragma once
#include "Level.h"
#include "Cell.h"

class Oxygen
{
public:
	Oxygen();
	~Oxygen();

	void update(int cellSize, Level grid);
	void addOxygen(int mouseX, int mouseY, int cellSize, Level grid);
	void removeOxygen(int mouseX, int mouseY, int cellSize, Level grid);

	int cellX, cellY;
};