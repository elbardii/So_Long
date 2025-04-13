/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/13 17:12:03 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Updates player position after a valid move */
void	update_player_position(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}

/* Processes special tiles the player moves onto */
void	process_move_result(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
		game->coins++;
	if (game->map[new_y][new_x] == 'E' && game->collectibles == game->coins)
		complete_game(game);
}

/* Moves the player in the specified direction if possible */
void	move_player(t_game *game, int x_offset, int y_offset)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + x_offset;
	new_y = game->player_y + y_offset;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'E' && game->collectibles != game->coins)
		return ;
	process_move_result(game, new_x, new_y);
	update_player_position(game, new_x, new_y);
}

/* Cleans up resources and exits the game normally */
int	exit_game(t_game *game)
{
	if (game->mlx)
	{
		destroy_images(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
	free(game);
	exit(0);
	return (0);
}

/* Handles keyboard input during gameplay */
int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}
