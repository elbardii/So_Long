/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/13 17:24:58 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Checks if the map has a rectangular shape */
static int	is_rectangular_shape(t_game *game)
{
	int		i;
	size_t	first_line;

	first_line = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != first_line)
			return (0);
		i++;
	}
	game->map_width = (int)first_line;
	game->map_height = i;
	return (1);
}

/* Checks if the map is surrounded by walls */
static int	is_surrounded_by_walls(t_game *game)
{
	int	x;
	int	y;
	int	last_col;
	int	last_row;

	x = 0;
	last_col = game->map_width - 1;
	last_row = game->map_height - 1;
	while (x < game->map_width)
	{
		if (game->map[0][x] != '1' || game->map[last_row][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	while (y < game->map_height)
	{
		if (game->map[y][0] != '1' || game->map[y][last_col] != '1')
			return (0);
		y++;
	}
	return (1);
}

/* Validates required game objects: player, exit, collectibles */
static int	validate_object_counts(t_game *game)
{
	if (game->player_count != 1)
		exit_with_cleanup("Player must be exactly 1", game);
	if (game->collectibles < 1)
		exit_with_cleanup("There must be at least 1 collectible", game);
	if (game->exit_count != 1)
		exit_with_cleanup("Exit must be exactly 1", game);
	return (1);
}

/* Checks for valid map objects and counts them */
static int	count_map_objects(t_game *game)
{
	int	x;
	int	y;

	/* Reset all counter variables before counting */
	game->player_count = 0;
	game->collectibles = 0;
	game->exit_count = 0;
	
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (!ft_strchr("01CEP", game->map[y][x]))
				return (0);
			if (game->map[y][x] == 'P')
				game->player_count++;
			if (game->map[y][x] == 'C')
				game->collectibles++;
			if (game->map[y][x] == 'E')
				game->exit_count++;
			x++;
		}
		y++;
	}
	return (validate_object_counts(game));
}

/* Main map validation function that checks all requirements */
void	validate_map_structure(t_game *game)
{
	if (!is_rectangular_shape(game))
		exit_with_cleanup("Map must be rectangular", game);
	if (!is_surrounded_by_walls(game))
		exit_with_cleanup("Map must be surrounded by walls", game);
	if (!count_map_objects(game))
		exit_with_cleanup("Invalid characters found in map", game);
	check_valid_path(game);
}
