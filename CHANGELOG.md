##19/05/2016
* Fixed bug where some large rooms would still not have three doors

##17/05/2016
* All rooms now have at least three doors, if they are more than 3 cells big

##16/05/2016
* NPCs no longer spawn in single cell rooms

##03/05/2016
* One NPC now spawns in each room
* Guards spawn in corridors and doctors spawn in rooms

##28/04/2016
* Maze generation is now managed by a separate class
* Doors always spawn if the room has reached a specified maximum size
* Corridors now have a tendency to be straight and less expansive

##27/04/2016
* Rooms know which cells they have in them

##25/04/2016
* Doors have a random chance to be locked
* Experimental corridors are now created

##21/04/2016
* Cell edges can now be retrieved by passing a direction
* Can check if edges are walls or not
* Can now convert between grid and window coordinates

##22/03/2016
* Level now regenerates when players coordinates match the exit

##20/03/2016
* NPCs can no longer start in the same position as the player

##17/03/2016
* Player now inherits from Character class
* Player starting grid position is now defined by Player class

##16/03/2016
* All classes now use VectorXY for position instead of separate x and y integers

##15/03/2016
* Made multiple doctors and guards spawn in random positions

##09/03/2016
* Exit is now generated on the top or right edge
* All classes now use smart pointers where appropriate 
* Code in all classes has been tidied up and documented 

##07/03/2016
* Code in Level class has now been tidied up and documented

##06/03/2016
* A maze of rooms is now generated using Growing Tree Algorithm

##03/03/2016
* A grid of cells is now generated

