/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:30:00 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/11 11:30:00 by isel-bar         ###   ########.fr       */
/*                                                                              */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Checks if the requested move is valid
 * 
 * @param game Game structure pointer
 * @param new_x New x coordinate
 * @param new_y New y coordinate
 * @return int 1 if move is valid, 0 otherwise
 */
int	check_collision(t_game *game, int new_x, int new_y)
{
	char	cell;

	cell = game->map.grid[new_y][new_x];
	if (cell == WALL)
		return (0);
	if (cell == EXIT && game->map.collected != game->map.collectibles)
		return (0);
	return (1);
}

/**
 * @brief Handles picking up collectibles and reaching the exit
 * 
 * @param game Game structure pointer
 * @param new_x New x coordinate
 * @param new_y New y coordinate
 */
static void	handle_game_events(t_game *game, int new_x, int new_y)
{
	char	*moves_str;

	if (game->map.grid[new_y][new_x] == COLLECTIBLE)
	{
		game->map.collected++;
		game->map.grid[new_y][new_x] = EMPTY;
	}
	else if (game->map.grid[new_y][new_x] == EXIT && 
			game->map.collected == game->map.collectibles)
	{
		ft_putstr("\nCongratulations! You won in ");
		moves_str = ft_itoa(game->player.moves);
		ft_putstr(moves_str);
		free(moves_str);
		ft_putstr(" moves!\n");
		close_game(game);
	}
}

/**
 * @brief Display the number of moves in the terminal
 * 
 * @param game Game structure pointer
 */
static void	display_moves(t_game *game)
{
	char	*moves_str;

	// Clear the current line with spaces
	ft_putstr("\r                     \r");
	ft_putstr("Moves: ");
	moves_str = ft_itoa(game->player.moves);
	ft_putstr(moves_str);
	free(moves_str);
}

/**
 * @brief Updates the position of the player
 * 
 * @param game Game structure pointer
 * @param dx Delta x (change in x coordinate)
 * @param dy Delta y (change in y coordinate)
 */
void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (check_collision(game, new_x, new_y))
	{
		game->map.grid[game->player.y][game->player.x] = EMPTY;
		handle_game_events(game, new_x, new_y);
		game->player.x = new_x;
		game->player.y = new_y;
		game->map.grid[new_y][new_x] = PLAYER;
		game->player.moves++;
		display_moves(game);
		render_game(game);
	}
}