## Components:
Role Component:
This is an abstract class and serves as the base class for all the specific roles (like Thief, Warrior, Mage, etc.).
Dependencies:
It depends on its subclasses (i.e., the specific roles such as Thief, Warrior, etc.), which inherit its properties (such as health, strength, agility, etc.) and define additional specific behavior.
Team Component:
A Team is composed of Role objects (e.g., Player 1, Player 2, Player 3). The team is responsible for managing the collection of players.
Dependencies:
A Battle consists of two teams (e.g., Team 1 vs. Team 2). The battle logic involves actions like attacking, starting the battle, etc.
Dependencies:
It depends on the Team component because each team is involved in the battle.
Each team is composed of Player objects, which the battle interacts with for player-specific actions (like attacking and using abilities).
Gameplay Component:
The Gameplay component handles the overall game flow.
Dependencies:
It depends on the Battle and GameReloader because it manages those classes.

GameReloader component:
is a class that responds for a file saving/ loading/ reloading.
Dependencies:
No dependencies) This is an independent class)

