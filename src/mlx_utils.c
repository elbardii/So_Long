#include "so_long.h"

void init_mlx(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        cleanup_and_exit(game, "Failed to initialize MLX");
    
    // Set up window
    game->win = mlx_new_window(game->mlx, 
        game->map.width * TILE_SIZE, 
        game->map.height * TILE_SIZE, 
        "So Long!");
    if (!game->win)
        cleanup_and_exit(game, "Failed to create window");
    
    // Set up event hooks
    mlx_hook(game->win, 2, 1L<<0, handle_keypress, game);
    mlx_hook(game->win, 17, 0, close_game, game);
    mlx_hook(game->win, 9, 1L<<21, handle_expose, game);
    mlx_hook(game->win, 15, 1L<<16, handle_focus, game);
}

void cleanup_mlx(t_game *game)
{
    if (game->wall_img)
        mlx_destroy_image(game->mlx, game->wall_img);
    if (game->empty_img)
        mlx_destroy_image(game->mlx, game->empty_img);
    if (game->collectible_img)
        mlx_destroy_image(game->mlx, game->collectible_img);
    if (game->exit_img)
        mlx_destroy_image(game->mlx, game->exit_img);
    if (game->player_img)
        mlx_destroy_image(game->mlx, game->player_img);
    
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
}

void *load_xpm_image(t_game *game, char *path)
{
    void    *img;
    int     width;
    int     height;

    img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
    if (!img)
        cleanup_and_exit(game, "Failed to load texture");
    if (width != TILE_SIZE || height != TILE_SIZE)
        cleanup_and_exit(game, "Texture size mismatch");
    return (img);
}

void put_image_to_window(t_game *game, void *img, int x, int y)
{
    mlx_put_image_to_window(game->mlx, game->win, img, 
        x * TILE_SIZE, y * TILE_SIZE);
} 