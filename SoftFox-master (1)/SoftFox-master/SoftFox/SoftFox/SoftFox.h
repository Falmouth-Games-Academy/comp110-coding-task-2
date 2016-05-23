#pragma once

#include "Hunter.h"

class SoftFox
{
public:

	//Thomas Easterbrook Coding Task two start
	int getHunterX() { return hunterX; } //on these two lines sam change gethunter to getHunter as she spotted the mistake and i did not when i pushed it
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
