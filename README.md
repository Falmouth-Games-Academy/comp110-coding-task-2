# comp110-coding-task-2

##The game component I am going to create:

I am going attempt to design the environment AI for our comp150 game.
This will include:

+ The way in which fire will transverse the rooms and cells in the game. 
+ How oxygen will behave.

###Fire
I am planning on designing the fire like a cellular automaton that passes from cell to cell and expands if there is oxygen in the room and depletes if there is a lack of oxygen. 

###Oxygen

For the oxygen I plan on designing it like a fluid, so the oxygen will flow around the level, from cell to cell like a liquid. The player can then reduce the oxygen in a room and move it to another room.

##Initial Trello Board User Stories:

![text](https://raw.githubusercontent.com/Alli1223/comp110-coding-task-2/master/Trello%20Board/Screenshot%202016-03-22%2015.54.05.png "First trello board")

##Flowchart for the fire system:

![text](https://raw.githubusercontent.com/Alli1223/Worksheet-6/master/Flowchart/Fire_Flowchart.png "Flowchart")

##UML Diagram for oxygen system

###UML Use Case Diagram:
![UML](https://raw.githubusercontent.com/Alli1223/Worksheet-6/master/UML%20diagrams/Use_Case%20Diagram.png "UML Use Case")

###UML State Diagram:
![UML](https://raw.githubusercontent.com/Alli1223/Worksheet-6/master/UML%20diagrams/Simple%20State%20Diagram.png "State Diagram")



##Fire AI Pseudo Code

```
IF room has oxygen



IF cell is empty 
	IF cell contains oxygen
		small random chance to spawn fire every frame
		set cell state to be on fire
		IF cell runs out of oxygen
			Set cell state to empty
		END IF
	END IF
END IF

```

___

The code for the coding task 2 is under the ""Enviroment_AI"" and the "oxygen" branch of the desktop game.