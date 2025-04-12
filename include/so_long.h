/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/12 12:09:53 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h> 						      // Necessary for MLX functions
# include "libft.h"                           // Include libft header
# include "../libs/get_next_line/get_next_line.h" // Include get_next_line header
# include <fcntl.h>                           // Necessary for open
# include <stdlib.h>                          // Necessary for malloc, free
# include <unistd.h>                          // Necessary for write, close
# include <stdarg.h>
# include <stdio.h>						  // for ft_printf

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

int				ft_check_name(char *str);
char			*read_map(char *file, t_game *game);
void			validate_map(t_game *game);
void			check_valid_path(t_game *game);
//** flood_fill and utils **//
void			allocate_map_copy(char ***map_copy, t_game *game);
void			flood_fill(char **map, int x, int y, t_game *game);
int				is_valid_position(int x, int y, t_game *game, char **map);
void			ft_check_position(t_game *game);
void			check_result(t_game *game, char **map, int coins,
					int exit_found);

//** rendring**/
void			ft_load_images(t_game *game);
void			render_map(t_game *game);
void			render_tile(t_game *game, char tile, int x, int y);

//**free and exit fun **//
void			error_exit(char *message, t_game *game);
void			error2_exit(char *message, t_game *game);
void			free_map_copy(char **map_copy, int height);
void			free_map(char **map);
void			destroy_images(t_game *game);

//** variable initial **//
void			ft_init_var(t_game *game);

//** moving_player**//
int				key_handler(int keycode, t_game *game);
int				exit_game(t_game *game);
void			exit2_game(t_game *game);
void			move_player(t_game *game, int x_offset, int y_offset);
void			check_move_result(t_game *game, int new_x, int new_y);
void			update_player_position(t_game *game, int new_x, int new_y);
void			win_game(t_game *game);

//** ft_printf **//
int				ft_printf(const char *format, ...);

#endif