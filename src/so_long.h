/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2024/02/01 12:00:00 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# define TILE_SIZE 32
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

/**
 * @brief Game states
 */
typedef enum e_game_state
{
    GAME_PLAYING,
    GAME_PAUSED,
    GAME_WON,
    GAME_LOST
} t_game_state;

/**
 * @brief Position structure
 */
typedef struct s_position
{
    int x;
    int y;
} t_position;

/**
 * @brief Player structure
 */
typedef struct s_player
{
    t_position pos;
    int moves;
    int collected;
} t_player;

/**
 * @brief Map structure
 */
typedef struct s_map
{
    char    **grid;
    int     width;
    int     height;
    int     collectibles;
    int     exits;
    int     players;
} t_map;

/**
 * @brief Main game structure
 */
typedef struct s_game
{
    void        *mlx;
    void        *win;
    t_map       map;
    t_player    player;
    t_game_state state;
    void        *wall_img;
    void        *empty_img;
    void        *collectible_img;
    void        *exit_img;
    void        *player_img;
} t_game;

// Game functions
int     init_game(t_game *game, char *map_file);
int     close_game(t_game *game);
void    render_game(t_game *game);
int     handle_keypress(int keycode, t_game *game);

// Map functions
int     parse_map(char *file, t_map *map);
void    free_map(t_map *map);
int     validate_map(t_map *map);

// Player functions
void    move_player(t_game *game, int dx, int dy);

// MLX utilities
void    init_mlx(t_game *game);
void    cleanup_mlx(t_game *game);
void    *load_xpm_image(t_game *game, char *path);
void    put_image_to_window(t_game *game, void *img, int x, int y);

// Utility functions
void    cleanup_game(t_game *game);
void    error_exit(char *message);
void    cleanup_and_exit(t_game *game, char *message);
void    *safe_malloc(size_t size);
void    *safe_calloc(size_t count, size_t size);
void    safe_free(void **ptr);

#endif 