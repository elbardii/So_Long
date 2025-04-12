/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/12 11:08:57 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int	ft_check_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 5)
		return (1);
	if (ft_strncmp(str + len - 4, ".ber", 4) != 0 || str[len - 5] == '/')
		return (1);
	return (0);
}

void	ft_init_var(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->collectibles = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_count = 0;
	game->coins = 0;
	game->player_count = 0;
	game->tile_size = 64;
	game->moves = 0;
}
