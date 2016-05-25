#pragma once

#include "stdafx.h"

class Physics
{
public:
	Physics();
	~Physics();

	bool isCollision(SDL_Rect& objectOne, SDL_Rect& objectTwo);

private:
	int x;
	int y;

};

