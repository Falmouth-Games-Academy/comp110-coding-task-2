#pragma once
class Coordinates
{
public:
	Coordinates(int x, int y);
	~Coordinates();
	int getX() { return x; }
	int getY() { return y; }

	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }


private:
	int x, y;
};

