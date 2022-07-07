# ClueGame
The classic board game Clue implemented in C++


# Program description
## Game Algorithm
1. First the program creates the murder envelope and stores it in a hidden Vector.
2. The number of players is determined by the user's choice between 3-6.
3. Card decks are created for the players randomly.
4. Each player selects the character he wants to play with. 
5. The board shows up with the selected characters and each player gets a card pack.
6. The order of the players' turns is determined randomly.
7. The game begins:
   - The board controls the characters, the rooms and the game flow for all players.
   - At each turn, a check that not everyone has lost yet is made (incorrect accusation leads to a loss).
     the player's position is checked and then the player is given the option to choose a move according to his position.
   - The player's options are:
     - Roll the dice
     - Accuse
     - Show evidence book     
   - Players can move their character on the board according to the dice result as follows:
     - W = up
     - S = down
     - D = right
     - A = left
   - When a player is in a room he can make a suggestion about the murder (in the current room).
     and if he is in a corner room he can use a secret passage.
     If the suggestion was correct the rest of the players will reveal one card from their pack, which will also be marked in the evidence book. 
   - A win in the game is when a player makes a correct accusation.
   - A loos in the game is when a player makes a wrong accusation.
   - Another option for ending the game is when all player have made a wrong accusation.
   - After every round the game can be saved and exit.
8. The previous game can be loaded
8. The game saves statistical information


## Game Menus
#### Main Menu
![image](https://user-images.githubusercontent.com/108329249/177800205-03311f54-96d0-47fa-a265-6083f0c3b893.png)

#### Characters Menu
![image](https://user-images.githubusercontent.com/108329249/177800424-c1f1eff2-8ac0-4507-9376-f4db10ba0dcb.png)

#### Board
![image](https://user-images.githubusercontent.com/108329249/177800709-4de42761-7268-48b4-8da8-cdc44e77f3f7.png)

#### Evidence Book
![image](https://user-images.githubusercontent.com/108329249/177801066-adc41e25-9e33-4d89-963f-d6712f8058cf.png)

#### Accusation Menu
![image](https://user-images.githubusercontent.com/108329249/177801283-bfaf4a6f-3d32-4e5a-aa84-979edd690d9d.png)

#### S.P Room Menu
![image](https://user-images.githubusercontent.com/108329249/177801938-4ed2af30-10d2-4df4-b55c-9c41ca912eea.png)

#### Movment Menu
![image](https://user-images.githubusercontent.com/108329249/177803852-91bb152f-69e3-4ffc-98fd-e2abc3db9247.png)





