#include "stdafx.h"
#include "Map.h"


void Map::LoadMap(std::string filename, Level room)
//(filename, grid to load into) loads map from text file into grid
{
	//loop through the file
	std::ifstream mapFile(filename);
	std::vector<std::string> map;
	while (!mapFile.eof())
	{
		//make a vector containing all the lines in the file
		std::string line;
		std::getline(mapFile, line);
		map.push_back(line);
	}
	//loop through the cells on display
	for (int x = 0; x < room.grid.size(); x++)
	{
		for (int y = 0; y < room.grid[0].size(); y++)
		{
			//checks if the character exhists
			if (x < map.size() && y < map[x].size())
			{
				//checks if the character is a wall
				if (map[x][y] == '#')
				{
					room.grid[x][y]->isRoom = false;
				}

				else if (map[x][y] == 'D')
				{
					room.grid[x][y]->isDoor = true;
					room.grid[x][y]->isRoom = true;
				}
			}
			//closes off smaller levels
			else
			{
				room.grid[x][y]->isRoom = false;
			}
		}
	}
}

int Map::random(int smallestValue, int largestValue)
{
	std::srand(time(nullptr));
	return (rand() % (largestValue - smallestValue)) + smallestValue;
}

int roundToNearestWhole(double number) 
{
	if (number + 0.5 >= int(number) + 1)
	{
		return int(number) + 1;
	}
	else
	{
		return int(number);
	}
}

bool Map::generateRoom(Level level, int size, int entranceX, int entranceY, char direction)  //Direction n = north, e = east, s = south, w = west.
{
	std::vector<std::vector<std::shared_ptr<Cell>>> room;
	double topLeftX;
	double topLeftY;
	if (direction == 'n')
	{
		topLeftX = entranceX - roundToNearestWhole(size / 2);
		topLeftY = entranceY - size;
	}
	else if (direction == 's')
	{
		topLeftX = entranceX - roundToNearestWhole(size / 2);
		topLeftY = entranceY + 1;
	}
	else if (direction == 'e')
	{
		topLeftX = entranceX + 1;
		topLeftY = entranceY - roundToNearestWhole(size / 2);
	}
	else
	{
		topLeftX = entranceX - size;
		topLeftY = entranceY - roundToNearestWhole(size / 2);
	}

	for (int x = topLeftX; x < topLeftX + size; x++)
	{
		if (x < 0 || x >= level.grid.size())   									//Detects if the room goes out the level horizontally
		{
			return false;
		}
		std::vector<std::shared_ptr<Cell>> column;
		for (int y = topLeftY; y < topLeftY + size; y++)
		{
			if (y < 0 || y >= level.grid[0].size())								//Detects if the room goes out the level vertically
			{
				return false;
			}
			if (level.grid[x][y]->isRoom == true)
			{
				return false;
			}
			column.push_back(level.grid[x][y]);
		}
		room.push_back(column);
	}
	int oxygenLevel;
	if (roomVector.empty()) 
	{
		oxygenLevel = 100;
	}
	else
	{
		oxygenLevel = random(0, 100);
	}

	for (int x = 0; x < room.size(); x++)										//Gives all the cells in the room it's properties
	{
		for (int y = 0; y < room[0].size(); y++)
		{
			room[x][y]->oxygenLevel = oxygenLevel;
			room[x][y]->isRoom = true;
		}
	}
	roomVector.push_back(room);
	return true;
}

void Map::generateMap(Level level)
{
	std::srand(time(nullptr));
	//Clear a starting room(room 0)

	generateRoom(level, 3, 1, -1, 's');
	bool thereIsSpace = true;
	int roomBase = 0;

	std::vector<int> randomSizes;

	randomSizes.push_back(2);
	randomSizes.push_back(3);
	randomSizes.push_back(4);
	randomSizes.push_back(5);

	std::vector<int> randomDirections;

	randomDirections.push_back(0);
	randomDirections.push_back(1);
	randomDirections.push_back(2);
	randomDirections.push_back(3);

	while (thereIsSpace)                                                                        //loop that makes sure to make rooms until impossible
	{
		std::random_shuffle(randomSizes.begin(), randomSizes.end());
		std::random_shuffle(randomDirections.begin(), randomDirections.end());

		for (int sizeIterator = 0; sizeIterator < randomSizes.size(); sizeIterator++)			//loop that trys all sizes																//loop for adding a room
		{
			int size = randomSizes[sizeIterator];

			for (int DirectionIterator = 0; DirectionIterator < randomDirections.size(); DirectionIterator++)//loop that trys all directions																//loop for adding a room
			{
				std::random_shuffle(randomSizes.begin(), randomSizes.end());
				int direction = randomDirections[DirectionIterator];

				if (direction == 0)																//north
				{
					int north = roomVector[roomBase][0][0]->getY();
					if (north > 0)
					{
						bool safe = true;
						int yOfDoor = roomVector[roomBase][0][0]->getY() - 1;
						int xStart = roomVector[roomBase][0][0]->getX();
						int halfRoomSize = roundToNearestWhole(roomVector[roomBase].size() / 2);
						int xOfDoor = xStart + halfRoomSize;
						if (xOfDoor >= 16 || xOfDoor < 0 || yOfDoor >= 16 || yOfDoor < 0)
						{
							safe = false;
						}
						if (safe)
						{
							if (level.grid[xOfDoor][yOfDoor]->isRoom == false)
							{
								if (generateRoom(level, size, xOfDoor, yOfDoor, 'n'))
								{
									level.grid[xOfDoor][yOfDoor]->isRoom = true;
									level.grid[xOfDoor][yOfDoor]->isDoor = true;
								}
							}
						}
					}
				}
				else if (direction == 1)														//east
				{
					int east = roomVector[roomBase][0][0]->getY();
					if (east < level.grid.size())
					{	
						bool safe = true;
						int xSize = roomVector[roomBase].size();
						int xOfDoor = roomVector[roomBase][0][0]->getX() + xSize;
						int yStart = roomVector[roomBase][0][0]->getY();
						int halfRoomSize = roundToNearestWhole(roomVector[roomBase][0].size() / 2);
						int yOfDoor = yStart + halfRoomSize;
						if (xOfDoor >= 16 || xOfDoor < 0 || yOfDoor >= 16 || yOfDoor < 0)
						{
							safe = false;
						}
						if (safe)
						{
							if (level.grid[xOfDoor][yOfDoor]->isRoom == false)
							{
								if (generateRoom(level, size, xOfDoor, yOfDoor, 'e'))
								{
									level.grid[xOfDoor][yOfDoor]->isRoom = true;
									level.grid[xOfDoor][yOfDoor]->isDoor = true;
								}
							}
						}
					}
				}
				else if (direction == 2)														//south
				{
					int south = roomVector[roomBase][0].size() + roomVector[roomBase][0][0]->getY() + 1;
					if (south < level.grid[0].size())
					{
						bool safe = true;
						int yOfDoor = roomVector[roomBase][0].size() + roomVector[roomBase][0][0]->getY();
						int xStart = roomVector[roomBase][0][0]->getX();
						int halfRoomSize = roundToNearestWhole(roomVector[roomBase].size() / 2);
						int xOfDoor = xStart + halfRoomSize;
						if (xOfDoor >= 16 || xOfDoor < 0 || yOfDoor >= 16 || yOfDoor < 0)
						{
							safe = false;
						}
						if (safe)
						{
							if (level.grid[xOfDoor][yOfDoor]->isRoom == false)
							{
								if (generateRoom(level, size, xOfDoor, yOfDoor, 's'))
								{
									level.grid[xOfDoor][yOfDoor]->isRoom = true;
									level.grid[xOfDoor][yOfDoor]->isDoor = true;
								}
							}
						}
					}
				}
				else																			//west
				{
					int west = roomVector[roomBase].size() + roomVector[roomBase][0][0]->getX() + 1;
					if (west < level.grid.size())
					{
						bool safe = true;
						int xSize = roomVector[roomBase].size();
						int xOfDoor = roomVector[roomBase][0][0]->getX() - 1;
						int yStart = roomVector[roomBase][0][0]->getY();
						int halfRoomSize = roundToNearestWhole(roomVector[roomBase][0].size() / 2);
						int yOfDoor = yStart + halfRoomSize;
						if (xOfDoor >= 16 || xOfDoor < 0 || yOfDoor >= 16 || yOfDoor < 0)
						{
							safe = false;
						}
						if (safe)
						{
							if (level.grid[xOfDoor][yOfDoor]->isRoom == false)
							{
								if (generateRoom(level, size, xOfDoor, yOfDoor, 'w'))
								{
									level.grid[xOfDoor][yOfDoor]->isRoom = true;
									level.grid[xOfDoor][yOfDoor]->isDoor = true;
								}
							}
						}
					}
				}
			}
		}
		roomBase++;
		if (roomBase  >= roomVector.size())
		{
			thereIsSpace = false;
		}
	}
}
Map::Map()
{
}

Map::~Map()
{
}
