# So_Long

A simple 2D game created as part of the 42 curriculum where you control a character who needs to collect all items and reach an exit to win. Built using the MiniLibX graphics library, this project focuses on window management, event handling, and basic game mechanics.

![So_Long Game](assets/sprites/preview.png)

## Game Overview

In "So_Long", you navigate a character through a map filled with collectibles, walls, and an exit. The objective is to:
- Collect all collectibles scattered throughout the map
- Reach the exit once all collectibles are gathered
- Avoid unnecessary moves to achieve the best possible score

## Requirements

- MiniLibX library
- X11 development libraries (xorg, xorg-dev, X11 and XShm extensions)
- GCC compiler
- Make

## Installation

### 1. Clone this repository
```bash
git clone https://github.com/yourusername/so_long.git
cd so_long
```

### 2. Install MiniLibX dependencies
For Debian/Ubuntu:
```bash
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

For Fedora/CentOS:
```bash
sudo dnf install gcc make xorg-x11-server-devel libXext-devel
```

For macOS (with Homebrew):
```bash
brew install xquartz
```

### 3. Install MiniLibX
The MiniLibX library is included in this repository. To install it:
```bash
cd minilibx-linux
./configure
make
cd ..
```

### 4. Compile the game
```bash
make
```

## How to Play

1. Launch the game with a valid map file:
```bash
./so_long maps/valid_simple.ber
```

2. Controls:
   - **W or ↑**: Move up
   - **A or ←**: Move left
   - **S or ↓**: Move down
   - **D or →**: Move right
   - **ESC**: Quit the game

3. Game Rules:
   - The player can move in four directions: up, down, left, and right
   - The player cannot move through walls
   - Each movement counts as one step and is displayed in the terminal
   - Collect all collectibles before reaching the exit
   - The game ends when all collectibles are collected and the player reaches the exit

## Map Format

Maps are defined in `.ber` files with the following symbols:
- **1**: Wall
- **0**: Empty space
- **P**: Player starting position (only one allowed)
- **C**: Collectible
- **E**: Exit (only one allowed)

Example of a valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

Map requirements:
- Must be rectangular
- Must be surrounded by walls ('1')
- Must contain exactly one player ('P')
- Must contain exactly one exit ('E')
- Must contain at least one collectible ('C')
- Must have a valid path allowing the player to collect all collectibles and reach the exit

## Error Handling

The game performs several checks on the provided map:
- File extension must be `.ber`
- Map must be rectangular
- Map must be enclosed by walls
- Map must contain exactly one player and one exit
- Map must contain at least one collectible
- Map must have a valid path to all collectibles and the exit

## Project Structure

```
so_long/
├── assets/             # Game assets
│   ├── sprites/        # Character and object sprites
│   └── textures/       # Wall, floor, and other textures
├── includes/           # Header files
│   ├── so_long.h       # Main header
│   └── structs.h       # Data structures
├── libs/               # Libraries
│   ├── ft_printf/      # Custom printf implementation
│   └── libft/          # Custom C library
├── maps/               # Map files
├── minilibx-linux/     # MiniLibX library
├── srcs/               # Source code
│   ├── game/           # Game logic
│   ├── init/           # Initialization functions
│   ├── parsing/        # Map parsing
│   ├── render/         # Rendering functions
│   └── utils/          # Utility functions
│   └── main.c          # Main entry point
├── Makefile            # Build system
└── README.md           # Project documentation
```

## Screenshots

![Gameplay](assets/sprites/gameplay.png)
![Win Screen](assets/sprites/win.png)

## Credits

- Game developed as part of the 42 curriculum
- MiniLibX library by 42 School
- Sprites and textures from [source/attribution if applicable]

## License

This project is licensed under the terms of the MIT license.
