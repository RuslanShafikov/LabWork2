## Class Diagram Description:
The Class Diagram represents the structure of the system in terms of its objects, their attributes, and methods. In this case, the class diagram will define how different classes and roles (with their attributes and behavior) interact within the system.

Classes and Relationships:
Class Player:

Attributes:
Role role: A reference to the Role class, indicating the player's role.
bool isAI: A boolean indicating whether the player is an AI.
Relationships:
A Player is associated with a Role (via the role attribute), implying that the role can vary for each player.
Class Team:

Attributes:
Player 1, Player 2, Player 3: Represents three players in the team. The Team class contains multiple Player objects.
Relationships:
A Team has an aggregation relationship with Player, as a team is composed of players.
Class Gameplay:

Methods:
startGame(): Starts the game.
SaveGame(): Saves the game's current state.
LoadGame(): Loads a previously saved game.
Relationships:
No direct relationships to other classes in this simplified version, but it interacts with the Battle, Player, and Team classes in the game's flow.
Class Battle:

Attributes:
Team 1, Team 2: Represents two teams involved in the battle.
Methods:
startBattle(): Starts the battle between the two teams.
attack(Player A): Performs an attack on a specific player.
Relationships:
A Battle contains two Team objects (team 1 and team 2).
It uses Player objects (via attack(Player A)).
Abstract Class Role:

Attributes:

Agility, Strength, Intelligence, Health, CritChance: Basic attributes with default values.
Subclasses (Specialized roles):

Thief: +2 Agility. Can steal the opponent move
Warrior: +2 Strength. Has a special superb attack when he is about to die
Mage: +2 Intelligence. Can create Magic shield reducing the damage
Archer: +1 Agility, 20% chance for critical hit.
Knight: +1 Strength, increased Health.
Shaman: +1 Intelligence, 20% chance for stun attack.
Necromancer: +1 Intelligence, ability to resurrect a dead teammate.
Assassin: +1 Agility, +1 Strength, can choose targets without restrictions.
Druid: Ability to hide with a 20% chance to avoid attacks.
Enchantress: 30% chance to charm opponents and reduce their stats. 
Has a special class attack with a chance to disable her lover.
Alchemist: +1 Intelligence, can create healing potions or explosive potions.
Monk: +1 Agility, 75% chance for a critical first attack, 5% chance to dodge attacks.
Gladiator: +1 Strength, 100% chance to deal a fatal blow when the opponent’s health is below 50%.
Sorcerer: +1 Intelligence, 10% chance for a double magical attack.
Doctor: Restores 20 health points per turn.
Relationships:

All specific roles (e.g., Thief, Warrior, etc.) inherit from the Role class, representing different player archetypes with unique abilities.
Methods in Roles:

Some roles have specific methods like arise(), Assasinate(), hide(), charm(), heal(), etc., which define their unique actions during the game.
Class Diagram Visualization:
Inheritance:
The various roles (Thief, Warrior, Mage, etc.) inherit from the abstract Role class.
Aggregation:
The Team class has a relationship with multiple Player objects.
The Battle class contains Team objects.
Methods:
Classes like Battle and Gameplay have methods that define behavior for starting the game, saving/loading the game, and performing actions like attacking or starting the battle.
