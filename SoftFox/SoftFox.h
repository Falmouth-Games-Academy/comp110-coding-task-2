#pragma once

#include "resource.h"
#include "Physics.h"

class SoftFox
{
public:

	//Sam Wills Coding Task two start
	static const int gravity = 9; ///Gravity force on player
	static const int upForce = gravity; ///Reactive force on player
	static const int jumpHeight = 20; ///Set player jump height
	static const int platformSpriteCollisionAdjustment = 24;
	//Sam Wills Coding Task two end

private:
	//Sam Wills Coding Task two start
	Uint32 start = 0;

	void sideCollision();
	Physics* physics;

	void hasFoxTouchedPlatform(); ///Check if player is touching a platform and cancel gravity using upforce if true
	void jumping(); ///Allows player to do a single jump for a certain amount of time
	void isFoxInWindow(); ///Check if player is in game window and resets player position if not

	bool jump;
	bool hasJumped;
	bool playerCollision;
	//Sam Wills Coding Task two end
};
