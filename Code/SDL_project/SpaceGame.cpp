#include "stdafx.h"
#include "SpaceGame.h"
#include "InitialisationError.h"
#include "Cell.h"
#include "Level.h"
#include "MainCharacter.h"
#include "IdleState.h"
#include "Oxygen.h"

SpaceGame::SpaceGame()
	: roomCell("Resources\\Room_Cell1.png"),
	characterTex("Resources\\crew2.png"),
	doorTexture("Resources\\door_sprite.png"),
	oxygenTex("Resources\\oxygen.png"),
	healthBar("Resources\\health.png"),
	healthText("Resources\\healthText.png"),
	oxygenBar("Resources\\oxygenBar.png"),
	oxygenText("Resources\\oxygenText.png")
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw InitialisationError("SDL_Init failed");
	}
	window = SDL_CreateWindow("COMP150 Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		throw InitialisationError("SDL_CreateWindow failed");
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		throw InitialisationError("SDL_CreateRenderer failed");
	}
}


SpaceGame::~SpaceGame()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void SpaceGame::run()
{
	// Level generation
	Level room;
	room.makeGrid(WINDOW_WIDTH, WINDOW_HEIGHT);
	Map mapLoader;
	mapLoader.generateMap(room);
	
	Oxygen oxygen;
	
	MainCharacter characterOne;
	//Character needs a pointer to the room to get the state
	characterOne.currentRoom = std::make_shared<Level>(room);
	//Character starts in Idle state
	characterOne.state = std::make_shared<IdleState>();

	running = true;

	while (running)
	{
		// Handle events
		SDL_Event ev;
		if (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
			case SDL_QUIT:
				running = false;
				break;

			default:
				break;
			}
		}//End pollevent if

		// Checks the keyboard for input
		const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
		// Checks and updates the character state
		characterOne.state->update(characterOne, keyboardState);
		
		// Rendering process:
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		int cellSize = room.getCellSize();

		// Adds and removes oxygen based on mouse click
		int mouse_X, mouse_Y;
		if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			oxygen.addOxygen(mouse_X, mouse_Y, cellSize, room);
		}

		else if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			oxygen.removeOxygen(mouse_X, mouse_Y, cellSize, room);
		}
		oxygen.update(cellSize, room);
		
		for (int x = 0; x < room.grid.size(); x++)
		{
			for (int y = 0; y < room.grid[x].size(); y++)
			{
				int xPos = x * cellSize + cellSize / 2;
				int yPos = y * cellSize + cellSize / 2;
				
				// Checks if the cell is a room
				if (room.grid[x][y]->isRoom)
				{
					roomCell.render(renderer, xPos, yPos, cellSize, cellSize);
					oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
					if (room.grid[x][y]->oxygenLevel == 0)
					{
						oxygenTex.alterTransparency(256);
					}
					else
					{
						oxygenTex.alterTransparency(100 - room.grid[x][y]->oxygenLevel);
					}
				}
				// Checks if the cell is a door
				if (room.grid[x][y]->isDoor)
				{
					doorTexture.render(renderer, xPos, yPos, cellSize, cellSize);
					oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
					if (room.grid[x][y]->oxygenLevel == 0)
					{
						oxygenTex.alterTransparency(256);
					}
					else
					{
						oxygenTex.alterTransparency(100 - room.grid[x][y]->oxygenLevel);
					}
				}
				// Does not render a cell if it isn't part of a room
			} //End for Y loop
		}//End for X loop

		if (characterOne.isAlive)
		{
			characterTex.render(renderer, characterOne.getX(), characterOne.getY(), characterOne.getSize(), characterOne.getSize());
		}			
		
		characterTex.render(renderer, characterOne.getX(), characterOne.getY(), characterOne.getSize(), characterOne.getSize());
		
		// Renders the health and oxygen bar
		healthBar.render(renderer, WINDOW_WIDTH , 25, characterOne.health * 10, 25);
 		healthBar.alterTransparency(150);
		healthText.render(renderer, 750, 25, 73, 22);
		oxygenBar.render(renderer, WINDOW_WIDTH, 50, 1000, 25);
		oxygenBar.alterTransparency(150);
		oxygenText.render(renderer, 750, 50, 73, 22);
		
		SDL_RenderPresent(renderer);
	}// End while running
}
