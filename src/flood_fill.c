/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/13 17:24:58 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Creates a copy of the map for path-finding algorithm */
void	allocate_map_copy(char ***map_copy, t_game *game)
{
	int	i;

	*map_copy = malloc(sizeof(char *) * game->map_height);
	if (!*map_copy)
		exit_with_error("Memory allocation failed", game);
	i = 0;
	while (i < game->map_height)
	{
		(*map_copy)[i] = malloc(sizeof(char) * (game->map_width + 1));
		if (!(*map_copy)[i])
			exit_with_error("Memory allocation failed", game);
		ft_strlcpy((*map_copy)[i], game->map[i], game->map_width + 1);
		i++;
	}
}

/* Finds the player's position in the map */
void	find_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
}

/* Checks if a position is valid for the flood fill algorithm */
int	is_valid_position(int x, int y, t_game *game, char **map)
{
	return (y >= 0 && x >= 0 && y < game->map_height && x < game->map_width
		&& map[y][x] != '1' && map[y][x] != 'X');
}

/* Validates the path-finding results */
void	check_path_results(t_game *game, char **map, int coins, int exit_found)
{
	if (coins != game->collectibles || !exit_found)
	{
		free_map_copy(map, game->map_height);
		exit_with_cleanup("No valid path to collect all items and reach exit", 
			game);
	}
}

/* Recursive flood fill algorithm to check valid paths */
void	flood_fill(char **map, int x, int y, t_game *game)
{
	static int	coins = 0;
	static int	exit_found = 0;

	/* Reset static variables on initial call (player position) */
	if (x == game->player_x && y == game->player_y && map[y][x] != 'X')
	{
		coins = 0;
		exit_found = 0;
	}

	if (!is_valid_position(x, y, game, map))
		return ;
	if (map[y][x] == 'E')
	{
		exit_found = 1;
		return ;
	}
	if (map[y][x] == 'C')
		coins++;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
	if (x == game->player_x && y == game->player_y)
		check_path_results(game, map, coins, exit_found);
}
