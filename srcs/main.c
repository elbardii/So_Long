/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/12 06:44:54 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Initializes game structure with default values
 * 
 * @param game Game structure pointer
 */
static void	init_struct(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.collectibles = 0;
	game->map.exits = 0;
	game->map.players = 0;
	game->map.collected = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.moves = 0;
	game->game_over = 0;
	game->win_width = WIN_WIDTH;
	game->win_height = WIN_HEIGHT;
}

/**
 * @brief Main entry point for the game
 * 
 * @param argc Argument count
 * @param argv Argument vector
 * @return int Exit status
 */
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit(NULL, ERR_USAGE);
	if (!check_ber_extension(argv[1]))
		error_exit(NULL, ERR_EXTENSION);
	init_struct(&game);
	if (init_game(&game, argv[1]) == -1)
		return (1);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, 17, 1L << 17, close_game, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}