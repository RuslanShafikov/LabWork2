
# System Architecture Description

## General Description

This system represents a game with battles between 2 teams with  players. Each team consists of 3 players, each of whom has a specific role that affects their abilities in battle. The game supports saving and loading the game state, as well as starting a new game.

## Key System Components

1. **Player** – a class representing a player, which includes a role (e.g., Mage, Warrior) and state (health, attack, etc.).
2. **Team** – a class representing a team consisting of three players.
3. **Battle** – a class managing the battle between two teams.
4. **GameStatus** – a class managing the game's state, including saving, loading, and starting (exiting) the game.
5. **Role** – an abstract class for different roles in the game with specific bonuses (e.g., strength for Warrior, agility for Assassin).
