
# System Architecture Description

## General Description

This system represents a game with battles between 2 teams with  players. Each team consists of 3 players, each of whom has a specific role that affects their abilities in battle. The game supports saving and loading the game state, as well as starting a new game.

## Key System Components

1. **Team** – a class representing a team consisting of three players.
2. **Battle** – a class managing the battle between two teams.
3. **Gameplay** – a class managing the game's state,
4.  **GameReloader** including saving, loading, and starting (exiting) the game.
5. **Role** – an abstract class for different roles in the game with specific bonuses (e.g., strength for Warrior, agility for Assassin).

## Game Mechanics

The player has an ability to choose a team of 3 from suggested roles. The other team will be formed to resist him. The task is to win the other team. 

When the Game starts the player has an ability to choose what to do with his team depending on his roles. He can create an attacking team. More defensive one to exhaust the enemy. Maybe even with team with great agility so opponent could not have a chance to hit him. Or he can try to use more balanced approach.

The player for instance can choose to attack other team using basic Player attack. He can as well try the roles special abilities out. For this he can enter some special commands like basic attack, heal etc..

The game ends when 1 of the Team is completely dead)
