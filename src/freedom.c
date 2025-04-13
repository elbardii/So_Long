/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/13 17:18:08 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Properly deallocates a 2D map array */
void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/* Exits the program with an error message, minimal cleanup */
void	exit_with_error(char *message, t_game *game)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	if (game)
	{
		free(game);
		game = NULL;
	}
	exit(EXIT_FAILURE);
}

/* Exits with error message and performs full cleanup */
void	exit_with_cleanup(char *message, t_game *game)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit_game_with_cleanup(game);
}

/* Frees a temporary map copy used in validation */
void	free_map_copy(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

/* Properly destroys all loaded images */
void	destroy_images(t_game *game)
{
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.coin)
		mlx_destroy_image(game->mlx, game->img.coin);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
}
