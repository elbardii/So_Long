#include "so_long.h"

static int is_valid_move(t_game *game, int new_x, int new_y)
{
    // Check if move is within map bounds
    if (new_x < 0 || new_x >= game->map.width || new_y < 0 || new_y >= game->map.height)
        return (0);
    
    // Check for wall collision
    if (game->map.grid[new_y][new_x] == '1')
        return (0);
    
    return (1);
}

static void handle_collectible(t_game *game, int x, int y)
{
    if (game->map.grid[y][x] == 'C')
    {
        game->map.grid[y][x] = '0';
        game->player.collected++;
        ft_printf("Collectibles: %d/%d\n", game->player.collected, game->map.collectibles);
        
        // Check if all collectibles are gathered
        if (game->player.collected == game->map.collectibles)
        {
            ft_printf("All collectibles gathered! Exit is now open.\n");
            update_game_state(game);
        }
    }
}

static void handle_exit(t_game *game, int x, int y)
{
    if (game->map.grid[y][x] == 'E')
    {
        if (game->player.collected == game->map.collectibles)
        {
            game->state = GAME_WON;
            ft_printf("Congratulations! You won in %d moves!\n", game->player.moves);
            close_game(game);
        }
        else
        {
            ft_printf("You need to collect all items before exiting!\n");
        }
    }
}

void move_player(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;

    // Don't process moves if game is not in playing state
    if (game->state != GAME_PLAYING)
        return;
    
    new_x = game->player.pos.x + dx;
    new_y = game->player.pos.y + dy;
    
    if (!is_valid_move(game, new_x, new_y))
        return;
    
    // Update player position
    game->map.grid[game->player.pos.y][game->player.pos.x] = '0';
    game->player.pos.x = new_x;
    game->player.pos.y = new_y;
    game->map.grid[new_y][new_x] = 'P';
    
    // Handle collectible or exit
    handle_collectible(game, new_x, new_y);
    handle_exit(game, new_x, new_y);
    
    // Update move count
    game->player.moves++;
    ft_printf("Moves: %d\n", game->player.moves);
    
    // Redraw the game
    render_game(game);
}

void update_game_state(t_game *game)
{
    if (game->player.collected == game->map.collectibles)
    {
        // Exit is now accessible
        ft_printf("Exit is now accessible!\n");
    }
} 