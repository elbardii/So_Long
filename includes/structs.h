/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/11 05:13:25 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/**
 * @brief Error code enumerations for consistent error handling
 * Each value corresponds to a specific type of error
 */
typedef enum e_error_code
{
	ERR_CODE_ARGS,          /* Invalid command line arguments */
	ERR_CODE_FILE,          /* File access or read error */
	ERR_CODE_MAP_INVALID,   /* General map validity error */
	ERR_CODE_MAP_NOT_RECT,  /* Map is not rectangular */
	ERR_CODE_MAP_NOT_CLOSED, /* Map is not surrounded by walls */
	ERR_CODE_MAP_MISSING_CHAR, /* Map is missing required elements */
	ERR_CODE_MLX,           /* MiniLibX error */
	ERR_CODE_NO_PATH,       /* No valid path in map */
	ERR_CODE_EXTENSION,     /* Invalid file extension */
	ERR_CODE_MEMORY,        /* Memory allocation error */
	ERR_CODE_IMAGE          /* Image loading or creation error */
}	t_error_code;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		exits;
	int		players;
	int		collected;
}				t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_img		img_empty;
	t_img		img_wall;
	t_img		img_collectible;
	t_img		img_exit;
	t_img		img_player;
	int			game_over;
	int			win_width;
	int			win_height;
}				t_game;

#endif