# COMP110 Coding Task 2 - Game Component

A changelog of this project is located in CHANGELOG.md, giving an overview offeature implementation and major bug fixes.

## Location
This project is being developed in the Group Desktop Game [Level Generation Branch](https://github.com/NecroReindeer/comp150-desktop-game/tree/level-generation). 

Classses and methods that are specifically a part of the level generation process are as follows:
###Relevent classes and methods

####Level
* generateMaze()
* createCharacter()
* placeExit()
* clearLevel()
* getRandomCoordinatesInRoom()

####Maze
* Everything

####MazeGenerationManager
* Everything

####Room
* Everything

####LevelCell
* LevelCell()
* allEdgesInitialised()
* getRandomUninitialisedDirection()
* getBiasedUninitialisedDirection()
* getEdge()
* assignRoom()
* initialisedEdge()

##Trello Board
###Sprint 1
![Sprint 1](https://github.com/NecroReindeer/comp110-coding-task-2/blob/master/Trello/Sprint%201.png)


###Sprint 2
![Sprint 2](https://github.com/NecroReindeer/comp110-coding-task-2/blob/master/Trello/Sprint%202.png)


###Sprint 3
![Sprint 3](https://github.com/NecroReindeer/comp110-coding-task-2/blob/master/Trello/Sprint%203.png)


##Proposal
I intend to create a procedural level generator for our COMP150 game.
It will include:
* Generating the level layout so that it is appropriate for the game, that is, a maze of rooms that isn't overly complicated
* Placing Doctors and Guards in appropriate positions
* Placing the exit in an appropriate position
* Placing collectable items in appropriate positions
* Placing doors and locked doors in appropriate positions
* Ensuring that keycards are placed on the correct side of locked doors

###Proposal Trello Board
Note that the user stories will be made more specific as we develop and playtest the game

![Initial Trello Board](https://github.com/NecroReindeer/comp110-coding-task-2/blob/master/Trello/Proposal.png)
