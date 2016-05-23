// SoftFox.cpp : Defines the entry point for the application.
//

#include "SoftFox.h"

void SoftFox::run() //Worked on in group
{
	////Sam Wills coding task two start
	//Set all default boolean
	jump = false;
	hasJumped = false;
	playerCollision = false;
	//Sam Wills coding task two end		

	{
		////Sam Wills coding task two start
		jumping();
		hasFoxTouchedPlatform();
		sideCollision();
		isFoxInWindow();
		//Sam Wills coding task two end			
	}
}

////Sam Wills coding task two start	
///resets player position if player outside of screen window
void SoftFox::isFoxInWindow()
{
	if (playerX > WINDOW_WIDTH || playerX < 0 || playerY > WINDOW_HEIGHT || playerY < 0 - screenHeightSpriteAdjument)
	{
		resetPlayer(); //Worked on as group
	}
}
//Sam Wills coding task two end	

//Sam Wills coding task two start
///Get the collision for the player with the platform
void SoftFox::hasFoxTouchedPlatform()
{
	///Set player collision box
	int playerXPos = playerX - SPRITE_SIZE / 2 + spriteAdjustmentPlayerSize;
	int playerYPos = playerY + spriteAdjustmentPlayerSize;
	int playerWidth = SPRITE_SIZE / 2;
	int playerHeight = playerSpriteGroundCollision;
	SDL_Rect playerBox = { playerXPos, playerYPos, playerWidth, playerHeight }; //create box for player

	///Set gravity for player
	playerY += gravity;

	///Find platform x,y coordinates
	for (int y = 0; y < level->getHeight(); y++) //goes through height of level txt doc for coordinate 	
	{
		for (int x = 0; x < level->getWidth(); x++) //goes through width of level txt doc for coordinate
		{
			if (level->isWall(x, y)) //if coordinates are wall
			{
				///Set platform collision box
				int platformX = tileSize * x; //translate coordinates to screen
				int platformY = tileSize * y; //translate coordinates to screen
				int platformWidth = tileSize;
				int platformHeight = tileSize;
				SDL_Rect platformBox = { platformX, platformY, platformWidth, platformHeight }; //create box for platform

				///Check collisions with reactive force for player Y gravity
				if (physics->isCollision(platformBox, playerBox)) //if the platform and player collide
				{
					playerY -= upForce; //show force for collision
					jump = false; //for bool jump mechanic
					hasJumped = false; //for bool jump mechanic
					playerCollision = true; //for other player detection

					return;
				}
			}
		}
	}
}

///Controls reactive force for player movement left and right
void SoftFox::sideCollision()
{
	///Set player collision box
	int playerXSide = playerX - SPRITE_SIZE / 2 + spriteAdjustmentPlayerSize;
	int playerYSide = playerY + spriteAdjustmentPlayerSize;
	int playerWidthSide = SPRITE_SIZE / 2;
	int playerHeightSide = SPRITE_SIZE / 2 - spriteAdjustmentPlayerSize * 2;
	SDL_Rect playerBoxSide = { playerXSide, playerYSide, playerWidthSide, playerHeightSide }; //create box for player

	///Find platform x,y coordinates
	for (int y = 0; y < level->getHeight(); y++) //goes through height of level txt doc for coordinate
	{
		for (int x = 0; x < level->getWidth(); x++) //goes through width of level txt doc for coordinate
		{
			if (level->isWall(x, y)) //if coordinates are wall
			{
				///Set platform collision box
				int platformXSide = tileSize * x; //translate coordinates to screen
				int platformYSide = tileSize * y + platformSpriteCollisionAdjustment; //translate coordinates to screen
				int platformWidthSide = tileSize;
				int platformHeightSide = tileSize;
				SDL_Rect platformBoxSide = { platformXSide, platformYSide, platformWidthSide, platformHeightSide }; //create box for platform
				
				///Check collisions with reactive force depending on keyboard press
				if (physics->isCollision(platformBoxSide, playerBoxSide))
				{
					///Check if right pressed
					if (keyboardState[SDL_SCANCODE_RIGHT])
					{
						playerX -= PLAYER_MOVEMENT_SPEED; //move the player in left direction to cancel movement
						return;
					}
					///Check if left pressed
					else if (keyboardState[SDL_SCANCODE_LEFT])
					{
						playerX += PLAYER_MOVEMENT_SPEED; //move the player in right direction to cancel movement
						return;
					}

				}
			}
		}
	}
}

///The player can jump using the up arrow
void SoftFox::jumping()
{
	///Check if the up jump button hasn't been pressed to allow player to jump
	if (!jump)
	{
		///If up arrow pressed
		if (keyboardState[SDL_SCANCODE_UP])
		{
			playerY -= jumpHeight; //make sprite move up
			start = SDL_GetTicks(); //set time to ticks
			jump = true;
		}
	}
	///Check if the jump button is still being pressed
	else if (jump && !hasJumped)
	{
		///If up arrow pressed
		if (keyboardState[SDL_SCANCODE_UP])
		{
			playerY -= jumpHeight; //make sprite move up
			Uint32 jumpTime = SDL_GetTicks() - start; //set jumpTime to the time length of the jump
			
			///Restrict jump time to 100 milliseconds until jump reset
			if (jumpTime > 100)
			{
				jump = false; //Stop the player jumping
				hasJumped = true; //Must reset to false by platform to jump again
			}
		}
		else
		{
			hasJumped = true;
		}
	}
}
//Sam Wills coding task two end