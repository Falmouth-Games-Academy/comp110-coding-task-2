// SoftFox.cpp : Defines the entry point for the application.
//

#include "SoftFox.h"

	//Thomas Easterbrook Coding Task two start
	hunterSpriteRight = new Texture("..\\Sprites\\hunterRight.png");
	hunterSpriteLeft = new Texture("..\\Sprites\\hunterLeft.png");
	hunterSprite = hunterSpriteLeft; //Sets default sprite direction


	hunterX = tileSize * level->getVillianX() + tileSize/2;
	hunterY = tileSize * level->getVillianY() + tileSize/2;

		hunterSprite->render(renderer, hunterX, hunterY + spriteAdjustmentHunterSize, tileSize, tileSize);

		
		hunterMovement();
		hasFoxTouchedHunter();

void SoftFox::hunterMovement()
{
	if (hunterDirection < 0) //hunter is set to minus one in header so it checks next if
	{
		if (level->isWall(hunterX / tileSize - 1, hunterY / tileSize + 1) && ///hunter checking walls so he can walk in that direction
			(!level->isWall(hunterX / tileSize - 1, hunterY / tileSize))) //while the bottom left block is wall and no wall next to hunter
		{
			hunterX -= 2; //move left
			hunterSprite = hunterSpriteLeft;
		}
		else
		{
			hunterDirection = 1; // else hunter turns around
		}
	}
	else
	{
		if (level->isWall(hunterX / tileSize + 1, hunterY / tileSize + 1) &&
			(!level->isWall(hunterX / tileSize + 1, hunterY / tileSize))) // while the bottom right block is wall and no wall next to hunter
		{
			hunterX += 2; //move right
			hunterSprite = hunterSpriteRight; ///change sprite to make it look like the hunter is moving in that direction
		}
		else
		{
			hunterDirection = -1; //loops hunter back to the start
		}
	}
}

void SoftFox::hasFoxTouchedHunter()
{
	SDL_Rect hunterBox = { hunterX - SPRITE_SIZE / 2, hunterY - SPRITE_SIZE / 2 + spriteAdjustmentHunterSize, SPRITE_SIZE, SPRITE_SIZE }; 
	SDL_Rect playerBox = { playerX - SPRITE_SIZE / 2, playerY - SPRITE_SIZE / 2, SPRITE_SIZE - 70, SPRITE_SIZE - 70 }; ///putting a box around the fox and hunter so that player resets on contact
	if (physics -> isCollision (hunterBox, playerBox))//if collision occurs
	{
		resetPlayer(); // this is not my function it was written by another person i just cal it to reset player
	}
}
//Thomas Easterbrook Coding Task two end
