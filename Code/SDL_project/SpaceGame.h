#pragma once

#include "Texture.h"
#include "Level.h"
#include "Map.h"
//! The main class
/*!
This is the main class where the game is laoded and run. 
*/
class SpaceGame
{
public:
	//! A constructor
	SpaceGame();
	//! A deconstructor
	~SpaceGame();

	//! 
	void run();
	
	//! The window width 
	static const int WINDOW_WIDTH = 800;
	//! The window height
	static const int WINDOW_HEIGHT = 800;
	//! Coordinates of the mouse 
	int mouse_X, mouse_Y;

private:
	//! Pointer to the window that the game will be rendered in
	SDL_Window* window;
	//" Pointer to the renderer
	SDL_Renderer* renderer;

	// Textures for game objects
	//! For cells that are a room
	Texture roomCell;
	//! For the Character
	Texture characterTex;
	//! For door cells
	Texture doorTexture;
	//! To show the oxygen level in a room
	Texture oxygenTex;
	//! To show the character health
	Texture healthBar;
	//! Label for character health
	Texture healthText;
	//! To show the oxygen level
	Texture oxygenBar;
	//! Label for oxygen level
	Texture oxygenText;
	//! This will display when the player fails to win	
	Texture gameOver;
	//!will display over the background when the player fails to win
	Texture gameOverText;
	//! Is the texture for the win background
	Texture winTexture;
	//! Is the texture for the win text
	Texture winText;
	//! Is the texture for the goal
	Texture goalTexture;
	//! Whether the game is running or not
	bool running;
};

