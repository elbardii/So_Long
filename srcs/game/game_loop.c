/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:50:00 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/11 04:36:43 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Sets up the game loop with event hooks and initial rendering
 * 
 * @param game Game structure pointer
 * @return int Always returns 0
 */
int	game_loop(t_game *game)
{
	ft_putstr("Game started! Use WASD or arrow keys to move. Press ESC to quit.\n");
	ft_putstr("Moves: 0\r");
	
	render_game(game);
	
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	
	mlx_loop(game->mlx);
	return (0);
}