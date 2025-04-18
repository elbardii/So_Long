/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/16 21:47:11 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Loads all game images from texture files */
void	load_game_images(t_game *game)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->tile_size, &game->tile_size);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->tile_size, &game->tile_size);
	game->img.player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&game->tile_size, &game->tile_size);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->tile_size, &game->tile_size);
	game->img.coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm",
			&game->tile_size, &game->tile_size);
	if (!game->img.wall || !game->img.floor || !game->img.player
		|| !game->img.exit || !game->img.coin)
		exit_with_cleanup("Failed to load textures", game);
}

/* Renders a single tile at the specified position */
void	render_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, x, y);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor, x, y);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img.player, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.coin, x, y);
}

/* Renders the entire map to the game window */
void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_tile(game, game->map[y][x], x * game->tile_size,
				y * game->tile_size);
			x++;
		}
		y++;
	}
}

/* Validates that all collectibles and exit are reachable */
void	check_valid_path(t_game *game)
{
	char	**map_copy;

	find_player_position(game);
	allocate_map_copy(&map_copy, game);
	flood_fill(map_copy, game->player_x, game->player_y, game);
	free_map_copy(map_copy, game->map_height);
}

/* Performs a complete game cleanup and exits with error */
void	exit_game_with_cleanup(t_game *game)
{
	if (game->mlx)
	{
		destroy_images(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	free(game);
	exit(1);
}
