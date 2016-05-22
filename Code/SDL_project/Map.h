#pragma once
#include "Level.h"


//!  The Class that handlles the creation of rooms
/*!
	This class modifies the level class to make patterns out of the cells and turn them into rooms using all of it's various functions.
*/
class Map
{
public:
	//! A Constructor
	Map();
	//! A Deconstructor
	~Map();

	//! Generates a random integer.
	int random(int smallestValue, int largestValue);

	//! Loads in a map from a txt file.
	void LoadMap(std::string filename, Level room);
	
	//! Randomly generates a map and modifies the level.
	void generateMap(Level level);

private:
	//! Used to store room locations
	std::vector<std::vector<std::vector<std::shared_ptr<Cell>>>> roomVector;

	//! Used to place rooms in the generate map function
	/*!
		Uses four seperate direction's to place rooms more easily later n = north, e = east, s = south, w = west.
	*/
	bool generateRoom(Level level, int size, int entranceX, int entranceY, char direction); 

};


