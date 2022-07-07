# ClueGame
The classic board game Clue implemented in C++


# Program description
Game Flow:
1. First the program creates the murder envelope and stores it in hidden Vector.
2. The number of players is determined by the user's choice.
3. Card decks are created for the players randomly.
4. Each player selects the character he wants to play with. 
5. The baord shows up with the selected characters and each player gets cards deck.
6. The order
7. The game begine:
   a. The board controls the characters, the rooms and the game flow for all players.
   b. Each turn a check that not everyone has lost yet is made (incorrect accusation leads to a loss).
      the players position is cheked and then the player is geven option to choose a move according to his position.
   c. The players options are:
      c.1. Roll dice
      c.2. Accuse
      c.3. Show evidence book
   d. When playher is in a room he can make a suggestion.
      and if he is in a corner room he can use a secret passage.
   e. 
