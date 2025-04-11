/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/11 05:13:25 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "../libs/ft_printf/ft_printf.h"
# include "structs.h"

/* Window settings */
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TILE_SIZE 32

/* Key codes */
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

/* Map characters */
# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

/* Error messages */
# define ERR_USAGE "Error: Usage: ./so_long <map.ber>"
# define ERR_FILE "Error: Cannot open map file"
# define ERR_MAP_INVALID "Error: Invalid map"
# define ERR_MAP_NOT_RECT "Error: Map must be rectangular"
# define ERR_MAP_NOT_CLOSED "Error: Map must be surrounded by walls"
# define ERR_MAP_MISSING_CHAR "Error: Map must have at least one P, one E, and one C"
# define ERR_MLX "Error: MLX initialization failed"
# define ERR_NO_PATH "Error: No valid path from player to exit or collectible"
# define ERR_EXTENSION "Error: Map file must have .ber extension"
# define ERR_MEMORY "Error: Memory allocation failed"
# define ERR_IMAGE "Error: Failed to load image"

/* Function prototypes */

/* init/ functions */
int		init_game(t_game *game, char *map_path);
void	init_window(t_game *game);
int		init_images(t_game *game);

/* parsing/ functions */
int		parse_map(t_game *game, char *map_path);
int		validate_map(t_game *game);
int		check_path(t_game *game);
int		check_ber_extension(char *filename);

/* game/ functions */
int		game_loop(t_game *game);
int		handle_keypress(int keycode, t_game *game);
void	move_player(t_game *game, int x, int y);
int		check_collision(t_game *game, int x, int y);
int		close_game(t_game *game);

/* render/ functions */
void	render_game(t_game *game);
void	render_map(t_game *game);

/* utils/ functions */
void	free_resources(t_game *game);
void	error_exit(t_game *game, char *error_message);
void	handle_error(t_game *game, t_error_code error_code, char *context);
int		check_error(t_game *game, int condition, t_error_code error_code, char *context);
void	log_error(t_error_code error_code, char *context);
char	*get_error_message(t_error_code error_code);
size_t	ft_strlen(const char *str);
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
void	count_collectibles(t_game *game);

#endif