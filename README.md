# comp110-coding-task-2

This is the repository for COMP110 Coding Task 2.
Please fork it and check in your code and other material as detailed in the assignment brief.
#Proposal:  
###The component that will be created:
The game component I intend to make is an AI for the characters in the game. After some research I've decided to try and use a finite-state machine where the characters will have a series of states they can be in. The states will be:  
* Controlled by user: this will be where the player has told them where to go and they are moving to that room
* Wandering around: after they've been in a room for a certain amount of time they will wander around the room/explore
* Running from fire: If there's a fire in the room they'll move away from it or into another room if possible
* Oxygen deprived: If they oxygen level in the room is too low they'll move slower

###Key user stories;
![Trello board](https://raw.githubusercontent.com/MaddieK19/comp110-coding-task-2/master/Trello%20board.PNG)

###Existing game the component will integrate into
This component will be integrated into the characters in the COMP150 game.

#### [Code is under the Character AI branch of the COMP150 game.](https://github.com/Wozzarick/Desktop_game/tree/Character-AI)

#Sprint 1:
![End of sprint 1](https://raw.githubusercontent.com/MaddieK19/comp110-coding-task-2/master/Trello%20board%20and%20cards/Sprint%201%20complete.PNG)  
The character can now transition between the idle, dead and player controlled states. The code for changing to the fire or wandering states is there but as those states do not work the character cannot transition into them.

#Sprint 2:
![End of sprint 2](https://raw.githubusercontent.com/MaddieK19/comp110-coding-task-2/master/Trello%20board%20and%20cards/Sprint%202%20complete.PNG)  
The character can now wander around a room if the player does not move it for a few seconds. The wandering state was meant to be used for other NPCs but as we didn't have enough time to implement other characters the main character will now wander around. I started working on a base for the character reacting to fire however fire was cut from the game so a fire related character state wasn't needed so I removed it.
