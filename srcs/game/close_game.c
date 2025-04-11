/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:30:00 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/11 05:03:17 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Closes the game and properly exits
 * This function is called when the game ends normally or
 * when the user decides to quit (X button or ESC key)
 * 
 * @param game Game structure pointer
 * @return int Always returns 0
 */
int	close_game(t_game *game)
{
	if (game)
	{
		// Print final game stats before closing
		ft_printf("\nGame ended. Total moves: %d\n", game->player.moves);
		ft_printf("Collectibles: %d/%d\n", game->map.collected, game->map.collectibles);
		
		// Free all resources
		free_resources(game);
	}
	exit(0);
	return (0);
}