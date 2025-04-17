/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/16 22:00:36 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Initializes the MLX library for graphics */
static void	init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_with_cleanup("Failed to initialize MLX", game);
}

/* Creates the game window with appropriate dimensions */
static void	create_game_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map_width * game->tile_size,
			game->map_height * game->tile_size, "So Long");
	if (!game->win)
		exit_with_cleanup("Failed to create window", game);
}

/* Displays win message and exits the game with success */
void	complete_game(t_game *game)
{
	ft_printf("Congratulations! You won in %d moves!\n", game->moves + 1);
	exit_game(game);
}

/* Sets up the game by validating the map and initializing graphics */
static void	setup_game(t_game *game)
{
	validate_map_structure(game);
	init_graphics(game);
	create_game_window(game);
	load_game_images(game);
	render_map(game);
}

/* Main function - entry point of the program */
int	main(int argc, char **argv)
{
	t_game	*game;
	char	*map;
	char	**split;

	if (argc != 2)
		return (write(2, "Error\nUsage: ./so_long <map_file.ber>\n", 39), 1);
	if (check_file_extension(argv[1]) == 1)
		return (write(2, "Error\nInvalid file format. Use .ber file\n", 41), 1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (write(2, "Error\nMemory allocation failed\n", 31), 1);
	initialize_variables(game);
	map = read_map_file(argv[1], game);
	split = ft_split(map, '\n');
	free(map);
	game->map = split;
	if (!split || !split[0])
		exit_with_cleanup("Map is empty or contains invalid data", game);
	setup_game(game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
