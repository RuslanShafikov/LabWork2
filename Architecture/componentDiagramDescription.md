## Components:
Role Component:
This is an abstract class and serves as the base class for all the specific roles (like Thief, Warrior, Mage, etc.).
Dependencies:
It depends on its subclasses (i.e., the specific roles such as Thief, Warrior, etc.), which inherit its properties (such as health, strength, agility, etc.) and define additional specific behavior.
Player Component:
A Player consists of a Role (either Thief, Warrior, etc.). The player has attributes like health, AI status, and the specific role they play.
Dependencies:
It depends on the Role component because each player must have a role, and the role provides their attributes and behavior.
Team Component:
A Team is composed of Player objects (e.g., Player 1, Player 2, Player 3). The team is responsible for managing the collection of players.
Dependencies:
It depends on the Player component because each team contains players, and each player has a specific role.
Battle Component:
A Battle consists of two teams (e.g., Team 1 vs. Team 2). The battle logic involves actions like attacking, starting the battle, etc.
Dependencies:
It depends on the Team component because each team is involved in the battle.
Each team is composed of Player objects, which the battle interacts with for player-specific actions (like attacking and using abilities).
Gameplay Component:
The Gameplay component handles the overall game flow (starting the game, saving the game, loading the game).
Dependencies:
It depends on the Battle, Team, and Player components for managing and interacting with the teams and players in the game.
