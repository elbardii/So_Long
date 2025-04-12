/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/12 11:09:11 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

static int	is_rectangular(t_game *game)
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

static int	is_walled(t_game *game)
{
	int	x;
	int	y;
	int	last_col;
	int	last_raw;

	x = 0;
	last_col = game->map_width - 1;
	last_raw = game->map_height - 1;
	while (x < game->map_width)
	{
		if (game->map[0][x] != '1' || game->map[last_raw][x] != '1')
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

static int	ft_check_var(t_game *game)
{
	if (game->player_count != 1)
		error2_exit("player must be exactly 1", game);
	if (game->collectibles < 1)
		error2_exit("there is less than 1 collectible", game);
	if (game->exit_count != 1)
		error2_exit("exit must be exactly one", game);
	return (1);
}

static int	validate_objects(t_game *game)
{
	int	x;
	int	y;

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
	return (ft_check_var(game));
}

void	validate_map(t_game *game)
{
	if (!is_rectangular(game))
		error2_exit("Map not rectangular", game);
	if (!is_walled(game))
		error2_exit("Map not walled", game);
	if (!validate_objects(game))
		error2_exit("Invalid object counts or invalid characters in map", game);
	check_valid_path(game);
}
