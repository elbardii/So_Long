/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:45:00 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/12 05:53:18 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Renders the proper image based on the map content at position (x, y)
 * 
 * @param game Game structure pointer
 * @param x X coordinate
 * @param y Y coordinate
 */
static void	render_tile(t_game *game, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = x * TILE_SIZE;
	pos_y = y * TILE_SIZE;
	if (game->map.grid[y][x] == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall.img, 
			pos_x, pos_y);
	else if (game->map.grid[y][x] == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible.img, 
			pos_x, pos_y);
	else if (game->map.grid[y][x] == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit.img, 
			pos_x, pos_y);
	else if (game->map.grid[y][x] == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->img_player.img, 
			pos_x, pos_y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_empty.img, 
			pos_x, pos_y);
}

/**
 * @brief Renders the entire map
 * 
 * @param game Game structure pointer
 */
void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}

/**
 * @brief Renders game information on the window
 * 
 * @param game Game structure pointer
 */
static void	render_info(t_game *game)
{
	char	*moves_str;
	char	*collected_str;
	char	*total_str;
	char	*display;

	moves_str = ft_itoa(game->player.moves);
	collected_str = ft_itoa(game->map.collected);
	total_str = ft_itoa(game->map.collectibles);
	
	display = ft_strjoin_custom("Moves: ", moves_str);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, display);
	free(display);
	
	display = ft_strjoin_custom("Collected: ", collected_str);
	display = ft_strjoin_free(display, "/");
	display = ft_strjoin_free(display, total_str);
	mlx_string_put(game->mlx, game->win, 10, 40, 0xFFFFFF, display);
	
	free(moves_str);
	free(collected_str);
	free(total_str);
	free(display);
}

/**
 * @brief Renders the entire game state
 * 
 * @param game Game structure pointer
 */
void	render_game(t_game *game)
{
	render_map(game);
	render_info(game);
}