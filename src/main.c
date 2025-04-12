/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/12 11:43:04 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

static void	initialize_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error2_exit("Failed to initialize MLX", game);
}

static void	create_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map_width * game->tile_size,
			game->map_height * game->tile_size, "So Long");
	if (!game->win)
		error2_exit("Failed to create window", game);
}

void	win_game(t_game *game)
{
	ft_printf("Congratulations! You won in %d moves!\n", game->moves + 1);
	exit_game(game);
}

static void	call_func(t_game *game)
{
	validate_map(game);
	initialize_game(game);
	create_window(game);
	ft_load_images(game);
	render_map(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	char	*map;
	char	**split;

	if (argc != 2)
		return (write(2, "Error\nUsage: ./so_long <map_file.ber>\n", 38), 1);
	if (ft_check_name(argv[1]) == 1)
		return (write(2, "Error\nfile name invalid\n", 24), 1);
	game = malloc(sizeof(t_game));
	if (!game)
		error_exit("Memory allocation failed", game);
	ft_init_var(game);
	map = read_map(argv[1], game);
	split = ft_split(map, '\n');
	free(map);
	game->map = split;
	if (!split || !split[0])
		error2_exit("Invalid or empty map", game);
	call_func(game);
	mlx_hook(game->win, 2, 1L << 0, key_handler, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
