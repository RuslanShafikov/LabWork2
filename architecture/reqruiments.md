# System Requirements and Use Cases

## General System Reqruiments
Operating System
Ubuntu 20.04 LTS or newer (64-bit)
(Other Debian-based Linux distributions may work but are not officially supported.)

Compiler & Build Tools
GCC (GNU Compiler Collection) 9.4.0 or newer
-or-
Clang 12.0.0 or newer

C++ Standard: C++17 or newer

Build System: CMake (3.16+) or Make

## Hardware Requirements
CPU: Dual-core 1.5 GHz or higher

RAM: 512 MB minimum (1 GB recommended)

Terminal:

Supports UTF-8 encoding.

Minimum terminal size: 80x24 characters.

Supports ANSI escape codes for colors (e.g., gnome-terminal, konsole, xterm).

Input
Keyboard: Standard QWERTY keyboard with arrow keys.

Mouse: Not required

## General Game Requirements

1. The game must support two teams, each consisting of three players.
2. Each player must have a unique role with corresponding bonuses.
3. Battles between teams should take into account the players' characteristics, such as strength, agility, and intelligence.
4. The system must support saving and loading the game state.
5. The player should be able to start a new game.

## Use Cases

### Use Case 1: Creating a New Game
1. The player starts the game.
2. Two teams, each consisting of three players, are created.
3. Each player is assigned a role and receives corresponding characteristics.
4. The game begins.

### Use Case 2: Saving the Game
1. The player finishes a gaming session.
2. The system saves the current state of the game, including players, their characteristics, and team status.
3. The player can load the game at a later time.

### Use Case 3: Battle Between Teams
1. Two teams face off in battle.
2. Players take turns attacking each other based on their characteristics and special abilities.
3. The battle continues until one team wins.

### Use Case 4: Exit the Game
1. Player shoul be able to leave the game whenever he wants.
2. The Game data should be saved based on Player's choice. 
