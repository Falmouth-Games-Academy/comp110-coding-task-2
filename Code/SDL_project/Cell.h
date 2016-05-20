#pragma once
#include "Texture.h"

class Cell
{
public:
	Cell();
	Cell(int x, int y);
	~Cell();
	
	// Getter functions
	int getX() { return x; }
	int getY() { return y; }
	int getOxygenLevel() { return oxygenLevel; }
	
	// Setter functions
	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }
	int setOxygenLevel(int newOxygenLevel) { return oxygenLevel = newOxygenLevel; }

	bool isOxygenated = false;
	bool isRoom = false;
	bool isDoor = false;
	int oxygenLevel = 100;

private:
	int x = 0, y = 0;
};