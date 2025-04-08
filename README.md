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

- `src/` - Source files
- `include/` - Header files
- `maps/` - Map files
- `obj/` - Object files (created during compilation)
