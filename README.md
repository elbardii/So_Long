# so_long

A simple 2D game where you need to collect all collectibles and reach the exit, created using MiniLibX.

## Requirements

- MiniLibX library
- X11 development libraries
- GCC compiler
- Make

## Installation

1. Clone this repository
2. Make sure you have MiniLibX installed
3. Run `make` to compile the project

## Usage

Run the game with a map file:
```bash
./so_long maps/test.ber
```

## Map Format

The map should be a .ber file with the following characters:
- '1' for walls
- '0' for empty space
- 'P' for player starting position
- 'C' for collectibles
- 'E' for exit

The map must be:
- Rectangular
- Surrounded by walls
- Have at least one collectible
- Have exactly one player and one exit
- Have a valid path to collect all collectibles and reach the exit

## Controls

- Arrow keys to move the player
- ESC or close window to quit

## Project Structure

```
so_long/
├── include/
│   └── so_long.h      # Main header file with structures and function declarations
├── src/
│   └── main.c         # Main program entry point
├── maps/              # Directory for map files (.ber)
├── textures/          # Directory for game textures
├── Makefile          # Build system
└── README.md         # Project documentation
```

## Directory Contents

### include/
- `so_long.h`: Contains all necessary structures, macros, and function declarations
  - Game structures (t_game, t_img)
  - Function prototypes for game logic
  - Required header includes

### src/
- `main.c`: Program entry point
  - Argument handling
  - Game initialization
  - Main game loop setup

### maps/
- Contains .ber map files
- Map format:
  - '1' for walls
  - '0' for empty space
  - 'P' for player
  - 'C' for collectibles
  - 'E' for exit

### textures/
- Will contain game textures
- Recommended formats: .xpm or .png
- Suggested textures:
  - player.xpm
  - wall.xpm
  - collectible.xpm
  - exit.xpm
  - background.xpm

## Build System

The Makefile includes:
- NAME rule (so_long)
- all rule
- clean rule
- fclean rule
- re rule
- Proper dependency handling
- MiniLibX linking
