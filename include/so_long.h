/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/13 17:12:03 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_images
{
	void		*wall;
	void		*floor;
	void		*player;
	void		*exit;
	void		*coin;
}				t_images;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_width;
	int			map_height;
	int			collectibles;
	int			exit_count;
	int			player_count;
	int			player_x;
	int			player_y;
	int			tile_size;
	int			moves;
	int			coins;
	t_images	img;
}				t_game;

/* File checking functions */
int				check_file_extension(char *str);

/* Map reading and validation */
char			*read_map_file(char *file, t_game *game);
void			validate_map_structure(t_game *game);
void			check_valid_path(t_game *game);

/* Flood fill and path validation utilities */
void			allocate_map_copy(char ***map_copy, t_game *game);
void			flood_fill(char **map, int x, int y, t_game *game);
int				is_valid_position(int x, int y, t_game *game, char **map);
void			find_player_position(t_game *game);
void			check_path_results(t_game *game, char **map, int coins,
					int exit_found);

/* Rendering functions */
void			load_game_images(t_game *game);
void			render_map(t_game *game);
void			render_tile(t_game *game, char tile, int x, int y);

/* Memory management and error handling */
void			exit_with_error(char *message, t_game *game);
void			exit_with_cleanup(char *message, t_game *game);
void			free_map_copy(char **map_copy, int height);
void			free_map(char **map);
void			destroy_images(t_game *game);

/* Game initialization */
void			initialize_variables(t_game *game);

/* Player movement and game logic */
int				handle_keypress(int keycode, t_game *game);
int				exit_game(t_game *game);
void			exit_game_with_cleanup(t_game *game);
void			move_player(t_game *game, int x_offset, int y_offset);
void			process_move_result(t_game *game, int new_x, int new_y);
void			update_player_position(t_game *game, int new_x, int new_y);
void			complete_game(t_game *game);

/* Custom printf function - kept as is */
int				ft_printf(const char *format, ...);

#endif