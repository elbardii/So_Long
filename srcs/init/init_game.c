/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:40:00 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/11 04:36:43 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Initializes the map variables
 * 
 * @param game Game structure pointer
 */
static void	init_map_variables(t_game *game)
{
	game->map.collectibles = 0;
	game->map.collected = 0;
	game->map.exits = 0;
	game->map.players = 0;
	game->player.moves = 0;
	game->game_over = 0;
}

/**
 * @brief Finds and sets the player's initial position in the map
 * 
 * @param game Game structure pointer
 */
static void	set_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == PLAYER)
			{
				game->player.x = x;
				game->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

/**
 * @brief Counts the total number of collectibles in the map
 * 
 * @param game Game structure pointer
 */
void	count_collectibles(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == COLLECTIBLE)
				game->map.collectibles++;
			else if (game->map.grid[y][x] == EXIT)
				game->map.exits++;
			else if (game->map.grid[y][x] == PLAYER)
				game->map.players++;
			x++;
		}
		y++;
	}
}

/**
 * @brief Initializes the game by setting up the map and window
 * 
 * @param game Game structure pointer
 * @param map_path Path to the map file
 * @return int 0 on success, -1 on error
 */
int	init_game(t_game *game, char *map_path)
{
	init_map_variables(game);
	if (parse_map(game, map_path) == -1)
		return (-1);
	if (validate_map(game) == -1)
		return (-1);
	if (check_path(game) == -1)
		return (-1);
	count_collectibles(game);
	set_player_position(game);
	init_window(game);
	if (init_images(game) == -1)
		return (-1);
	return (0);
}