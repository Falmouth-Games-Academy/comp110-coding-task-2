#pragma once

#include "resource.h"
#include "Level.h"
#include "Texture.h"
#include "Physics.h"
#include "Hunter.h"

class SoftFox
{
public:
	SoftFox();
	~SoftFox();

	//Thomas Easterbrook Coding Task two start
	int getHunterX() { return hunterX; }
	int getHunterY() { return hunterY; }
	//Thomas Easterbrook Coding Task two end


private:
	//Thomas Easterbrook Coding Task two start
	Texture* hunterSpriteRight; //player sprite faces right
	Texture* hunterSpriteLeft; //player sprite faces left
	Texture* hunterSprite;
	//Thomas Easterbrook Coding Task two end

	//Thomas Easterbrook Coding Task two start
	void hunterMovement();
	void hasFoxTouchedHunter();
	int hunterDirection = -1;
	int hunterX, hunterY;
	//Thomas Easterbrook Coding Task two end

};
