#include "so_long.h"

static void load_textures(t_game *game)
{
    game->wall_img = load_xpm_image(game, "assets/wall.xpm");
    game->empty_img = load_xpm_image(game, "assets/empty.xpm");
    game->collectible_img = load_xpm_image(game, "assets/collectible.xpm");
    game->exit_img = load_xpm_image(game, "assets/exit.xpm");
    game->player_img = load_xpm_image(game, "assets/player.xpm");
}

static void render_tile(t_game *game, int x, int y, char tile)
{
    void *img;

    if (tile == '1')
        img = game->wall_img;
    else if (tile == '0')
        img = game->empty_img;
    else if (tile == 'C')
        img = game->collectible_img;
    else if (tile == 'E')
        img = game->exit_img;
    else if (tile == 'P')
        img = game->player_img;
    else
        return;
    
    put_image_to_window(game, img, x, y);
}

void render_game(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            render_tile(game, x, y, game->map.grid[y][x]);
            x++;
        }
        y++;
    }
}

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        close_game(game);
    else if (game->state == GAME_PLAYING)
    {
        int dx = 0;
        int dy = 0;
        
        if (keycode == KEY_W)
            dy = -1;
        else if (keycode == KEY_A)
            dx = -1;
        else if (keycode == KEY_S)
            dy = 1;
        else if (keycode == KEY_D)
            dx = 1;
            
        if (dx != 0 || dy != 0)
            move_player(game, dx, dy);
    }
    return (0);
}

static int handle_focus(int focus, t_game *game)
{
    if (focus == 0) // Window lost focus
    {
        game->state = GAME_PAUSED;
        ft_printf("Game paused - Window lost focus\n");
    }
    else // Window gained focus
    {
        game->state = GAME_PLAYING;
        ft_printf("Game resumed\n");
        render_game(game);
    }
    return (0);
}

static int handle_expose(t_game *game)
{
    render_game(game);
    return (0);
}

int init_game(t_game *game, char *map_file)
{
    // Initialize game structure
    ft_memset(game, 0, sizeof(t_game));
    
    if (!parse_map(map_file, &game->map))
        return (0);
    
    // Initialize MLX
    init_mlx(game);
    
    // Initialize game state
    game->state = GAME_PLAYING;
    game->player.moves = 0;
    game->player.collected = 0;
    
    // Find player position
    int x, y;
    for (y = 0; y < game->map.height; y++)
    {
        for (x = 0; x < game->map.width; x++)
        {
            if (game->map.grid[y][x] == 'P')
            {
                game->player.pos.x = x;
                game->player.pos.y = y;
                break;
            }
        }
    }
    
    // Load textures
    load_textures(game);
    
    // Initial render
    render_game(game);
    
    ft_printf("Game started! Collect all items to open the exit.\n");
    ft_printf("Controls: W, A, S, D for movement, ESC to quit\n");
    
    return (1);
}

int close_game(t_game *game)
{
    if (game)
    {
        cleanup_mlx(game);
        free_map(&game->map);
    }
    exit(0);
    return (0);
} 