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
	winTexture("Resources\\oxygenBar.png"),
	winText("Resources\\you_win.png"),
	oxygenBar("Resources\\oxygenBar.png"),
	oxygenText("Resources\\oxygenText.png"),
	gameOver("Resources\\health.png"),
	gameOverText("Resources\\game_over.png"),
	goalTexture("Resources\\goal.png"){
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
	characterOne.windowHeight = WINDOW_HEIGHT;
	characterOne.windowWidth= WINDOW_WIDTH;

	running = true;
	double timer = 0;

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
					oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel);
					roomCell.render(renderer, xPos, yPos, cellSize, cellSize);
					oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);

				}
				// Checks if the cell is a door
				if (room.grid[x][y]->isDoor)
				{
					oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel);
					doorTexture.render(renderer, xPos, yPos, cellSize, cellSize);
					oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
				}
				//Checks if the cell has the goal on it.
				if (room.grid[x][y]->isGoal)
				{
					oxygenTex.alterTransparency(room.grid[x][y]->oxygenLevel);
					roomCell.render(renderer, xPos, yPos, cellSize, cellSize);
					oxygenTex.render(renderer, xPos, yPos, cellSize, cellSize);
					goalTexture.render(renderer, xPos, yPos, cellSize, cellSize);
				}
				// Does not render a cell if it isn't part of a room
			} //End for Y loop
		}//End for X loop

		 // Renders the health and oxygen bar
		healthBar.render(renderer, WINDOW_WIDTH, 25, characterOne.health * 10, 25);
		healthBar.alterTransparency(150);
		healthText.render(renderer, 750, 25, 73, 22);
		oxygenBar.render(renderer, WINDOW_WIDTH, 50, oxygen.getOxygenReserves() / 2, 25);
		oxygenBar.alterTransparency(150);
		oxygenText.render(renderer, 750, 50, 73, 22);

		 // If the character has died the game over screen is displayed
		if (!characterOne.isAlive)
		{
			// Fades in a red background
			if (timer < 255)
			{				
				timer++;
				gameOver.alterTransparency(timer);
				gameOver.render(renderer, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, WINDOW_WIDTH, WINDOW_HEIGHT);
			}
			// Displays text
			else
			{
				gameOver.alterTransparency(255);
				gameOver.render(renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
				gameOverText.render(renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
			}
		}
		// If the character has reached the end the You Won screen is displayed
		if (characterOne.hasWon)
		{
			// Fades in a blue background
			if (timer < 255)
			{
				timer++;
				winTexture.alterTransparency(timer);
				winTexture.render(renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
			}
			// Displays text
			else
			{
				winTexture.alterTransparency(255);
				winTexture.render(renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
				winText.render(renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
				
			}
		}
		characterTex.render(renderer, characterOne.getX(), characterOne.getY(), characterOne.getSize(), characterOne.getSize());
		
		SDL_RenderPresent(renderer);
	}// End while running
}
