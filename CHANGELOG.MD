###March 11th
* Added character class

###March 17th
* Character renders on screen

###March 20th
* Added keyboard controls to character

##March 24th
* Added MainCharacter class which inherits from Character
* Characters no longer move off screen
* Character checks that a cell is a room before moving on to it
* Character can no longer diagonally

###March 31st
* Added CharacterState class
* Character now has a shared pointer to CharacterState
* Added IdleState

###April 1st
* Added DeadState
* Added MovingState
* Added FireState
* Added PlayerControlledState
* Added LowOxygenState

###April 6th
* Character can transition from Idle to Dead

###April 11th
* Character can transition between IdleState and PlayerControlledState

###April 13th
* Added GameControlledState

###April 19th
* Cell checkers now work in states instead of SpaceGame

###April 20th
* Character can now wander around the room

###April 21st
* Removed GameControlledState

###April 29th
* getSurroundingCells function gets cells around characters to check if they're a valid move

###May 10th
* Character can move at different speeds

###May 12th 
* Character runs from fire
* Character can't move through doors in WanderingState

###May 16th
* Removed FireState
* Renamed states to have move appropriate names

###May 20th
* Combined wanderAroundRoom and moveCharacter




