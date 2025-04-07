#include "so_long.h"

static void init_game_data(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        error_exit("Failed to initialize MLX");
    
    game->win = mlx_new_window(game->mlx, 
        game->map.width * TILE_SIZE, 
        game->map.height * TILE_SIZE, 
        "So Long!");
    if (!game->win)
        error_exit("Failed to create window");
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        error_exit("Usage: ./so_long <map_file.ber>");
    
    if (!parse_map(argv[1], &game.map))
        error_exit("Failed to parse map");
    
    if (!validate_map(&game.map))
        error_exit("Invalid map");
    
    init_game_data(&game);
    
    // Load images
    game.wall_img = load_image(&game, "assets/wall.xpm");
    game.empty_img = load_image(&game, "assets/empty.xpm");
    game.collectible_img = load_image(&game, "assets/collectible.xpm");
    game.exit_img = load_image(&game, "assets/exit.xpm");
    game.player_img = load_image(&game, "assets/player.xpm");
    
    // Set up hooks
    mlx_hook(game.win, 2, 1L<<0, handle_keypress, &game);
    mlx_hook(game.win, 17, 0, close_game, &game);
    
    // Initial render
    render_game(&game);
    
    // Start game loop
    mlx_loop(game.mlx);
    
    return (0);
} 