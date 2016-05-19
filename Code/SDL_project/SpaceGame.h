#pragma once

#include "Texture.h"
#include "Level.h"
#include "Map.h"

class SpaceGame
{
public:
	SpaceGame();
	~SpaceGame();

	void run();
	
	// Window size
	static const int WINDOW_WIDTH = 800;
	static const int WINDOW_HEIGHT = 800;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	// Textures for game objects
	Texture roomCell;
	Texture characterTex;
	Texture doorTexture;
	Texture oxygenTex;
	Texture healthBar;
	Texture healthText;
	Texture oxygenBar;
	Texture oxygenText;

	bool running;
};

