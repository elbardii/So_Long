#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef enum e_game_state
{
    GAME_PLAYING,
    GAME_WON,
    GAME_PAUSED
} t_game_state;

typedef struct s_position
{
    int x;
    int y;
} t_position;

typedef struct s_map
{
    char    **grid;
    int     width;
    int     height;
    int     collectibles;
    int     exit;
    int     player;
} t_map;

typedef struct s_player
{
    t_position  pos;
    int         moves;
    int         collected;
} t_player;

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

// Map parsing functions
int     parse_map(char *filename, t_map *map);
void    free_map(t_map *map);
int     validate_map(t_map *map);

// Game functions
int     init_game(t_game *game, char *map_file);
void    render_game(t_game *game);
int     handle_keypress(int keycode, t_game *game);
int     close_game(t_game *game);
void    update_game_state(t_game *game);

// Player functions
void    move_player(t_game *game, int dx, int dy);
int     check_collision(t_game *game, int x, int y);

// Utils
void    error_exit(char *message);
void    *load_image(t_game *game, char *path);
void    ft_printf(const char *format, ...);

#endif 