/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/12 04:25:39 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Calculate window dimensions based on map size and create window
 * 
 * @param game The game structure
 */
void	init_window(t_game *game)
{
	int	screen_width;
	int	screen_height;

	// Initialize MLX connection
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(game, ERR_MLX);

	// Calculate window dimensions based on map size and tile size
	game->win_width = game->map.width * TILE_SIZE;
	game->win_height = game->map.height * TILE_SIZE;

	// Check if the window size exceeds screen resolution
	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	
	// Cap window size to screen resolution if needed
	if (game->win_width > screen_width)
		game->win_width = screen_width;
	if (game->win_height > screen_height)
		game->win_height = screen_height;

	// Create window with calculated dimensions
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, 
								"So Long");
	if (!game->win)
		error_exit(game, ERR_MLX);
}