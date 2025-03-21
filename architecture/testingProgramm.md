##Testing Plan for the Game:
#1. Unit Tests:
 Testing individual components like Player, Team, Battle, Role (and subclasses), and their methods.
Integration Tests: Testing the interaction between components, such as between Player and Role, Team and Player, Battle and Team.
Functional Tests: Testing the overall game flow, such as starting a game, saving/loading the game, and running a battle.
## Components to Be Tested
Player
Role assignment and attributes
Correct application of role-specific attributes
Role abilities
Team
Correct management of players
Correct interaction with Player
Battle
Correct setup and flow of a battle between two teams
Correct execution of actions like attacks and ability usage
Gameplay
Starting the game, saving, and loading the game
Interaction between teams, players, and battles during the game
## Testing Strategy
4.1. Unit Testing
Test Player Class:

Test Player Creation:
Ensure that a Player object is correctly created with a specific role (e.g., Warrior, Mage).
Verify the initial attributes of the Player match those defined by their Role.
Test Player Actions:
Verify that a Player can attack correctly.
Test player status ( health, isAI etc).
Verify that players perform actions automatically (if AI).
Test Role Class:

Test Role Attributes:
Verify that a Role has attributes like Agility, Strength, Intelligence, Health, and CritChance with correct default values.
Test Role Abilities:
Test role-specific methods (doubleMagicAttack() for Sorcerer, arise() for Necromancer).
Test Team Class:

Test Team Creation:
Verify that a Team contains exactly three Player objects.
Test Team Behavior:
Test methods that interact with players (SaveGame, LoadGame).
Ensure a team can correctly manage players' stats during a battle.
Test Battle Class:
Verify that a battle can be initialized with two teams.
Test that players can attack opponents in the battle.
Verify that players can use their role-specific abilities during battle (Assasinate() for Assassin, doubleMagicAttack() for Sorcerer).
Test Battle End:
Ensure the battle ends when one team has no players left or other game conditions are met.

Test Game Start:
Verify that the game can be started correctly.
Test Save/Load Game:
Test saving and loading the game state. Ensure that data (e.g., player stats, team states) is saved and restored properly.
Test Game Flow:
Verify that the gameplay flow is functioning correctly, including switching between battles, managing teams, and interacting with players.
4.2. Integration Testing
Ensure that a Player correctly inherits attributes and abilities from its assigned Role.
Test that role changes (e.g., if a Player changes roles during the game) reflect correctly in player stats and abilities.
Test Team and Player Integration:

Verify that a Team correctly manages and interacts with its Player objects.
Test that the team can correctly execute actions using players (e.g., calling the attack method on a Player in the team).
Test Battle and Team Integration:

Verify that a Battle can correctly access and interact with the Team objects.
Test that players within a team can execute actions against players from the opposing team during the battle.
4.3. Functional Testing

Test that the game properly saves and loads game states.
Ensure the player’s progress is maintained during game load/save operations.
Test Battle Mechanics:

Ensure that battles are functioning as expected:
Role-specific abilities should trigger correctly during battle.
Check that the battle ends when a team’s players are all defeated.

Test Player Role Functionality:

Ensure that each role's specific abilities work correctly (Assasinate() for Assassin, heal() for Doctor).
Ensure that AI-controlled players perform valid actions (attack, use abilities) based on their roles.
Test extreme values for player attributes (very low or high health, damage values).
## Timeline
Unit Testing. 23 March
Integration Testing:  24 March
Functional Testing: 25 March
Edge Case Testing: 26 March
