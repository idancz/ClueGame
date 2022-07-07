# ClueGame
The classic board game Clue implemented in C++


# Program description
##Game Algorithm:
1. First the program creates the murder envelope and stores it in hidden Vector.
2. The number of players is determined by the user's choice between 3-6.
3. Card decks are created for the players randomly.
4. Each player selects the character he wants to play with. 
5. The baord shows up with the selected characters and each player gets cards pack.
6. The order
7. The game begine:
   - The board controls the characters, the rooms and the game flow for all players.
   - Each turn a check that not everyone has lost yet is made (incorrect accusation leads to a loss).
     the players position is cheked and then the player is geven option to choose a move according to his position.
   - The players options are:
     - Roll the dice
     - Accuse
     - Show evidence book     
   - Players can move their character in the board according to the dice resuls as follows:
     - w = up
     - s = down
     - d = right
     - a = left
   - When player is in a room he can make a suggestion about the murder (at this specific room).
     and if he is in a corner room he can use a secret passage.
     If the suggestion was correct the players will reveal one cards from their pack, which will also be marked in the evidence book. 
   - A win in the game is when a player places a correct accusation.
   - A loos in the game is when a player makes a wrong accusation.
   - Another option for ending the game is when all player have made a wrong cahrge.
   - After every round the game can be saved and exit.
