#Worksheet 6

##Flowchart  
The flowchart below shows the process that leads to the characters in the game changing between the idle, wandering and moving to user set destination states.
![Flowchart](https://raw.githubusercontent.com/MaddieK19/comp110-coding-task-2/master/Worksheet%206/WS6%20-%20Flowchart.png)

The flowchart shows that if the character enters the dead state the game ends, if the character is alive it continues.  
The character starts in the idle state where it doesn't move, the program then checks for user input if there is none it then adds to the timer and if the timer is greater than 5 the character moves into the wandering state. The wandering state also checks for player input. If there is player input it checks to see if the player has chosen a room that is oxygenated, if the room isn't oxygenated the character returns to its previous state. If the room is oxygenated the character moves to that room. The program then checks to see if the character is at the end point of the level. If it is the level ends if not the program loops back to check if the character is alive. 

##Pseudocode  
The pseudocode below outlines part of the process that takes place when the character is near a fire. The character class will have a function that creates a list of nearby cells, it will then check those cells to see if any of them are on fire and the character will move away.

```
Get list of neighbour cells ( current cell/cell the character is on ):
  above cell = current cell's Y + cellsize
  below cell = current cell's Y - cellsize
  right cell = current cell's X + cellsize
  left cell = current cell's X - cellsize
  Add them all to a list of neighbour cells
  return the list


For cells in neighbour cells list:
  If cell is on fire
    return true
  Else
    return false

(moving)
```
  

##UML Diagrams: 
####Use-case diagram

####Class diagram  
![Class diagram](https://raw.githubusercontent.com/MaddieK19/comp110-coding-task-2/master/Worksheet%206/WS6%20Class%20diagram.png)

####State diagram  
![State diagram](https://raw.githubusercontent.com/MaddieK19/comp110-coding-task-2/master/Worksheet%206/WS6%20State%20Machine.png)

####Sequence diagram
