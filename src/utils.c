#include "so_long.h"

static void cleanup_game(t_game *game)
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
    free_map(&game->map);
}

void error_exit(char *message)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(message, 2);
    ft_putstr_fd("\n", 2);
    exit(1);
}

void cleanup_and_exit(t_game *game, char *message)
{
    if (game)
        cleanup_game(game);
    error_exit(message);
}

void *safe_malloc(size_t size)
{
    void *ptr;

    ptr = malloc(size);
    if (!ptr)
        error_exit("Memory allocation failed");
    return (ptr);
}

void *safe_calloc(size_t count, size_t size)
{
    void *ptr;

    ptr = calloc(count, size);
    if (!ptr)
        error_exit("Memory allocation failed");
    return (ptr);
}

void safe_free(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
}

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;

    if (!dstsize)
        return (ft_strlen(src));
    i = 0;
    while (src[i] && i < dstsize - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}

void ft_putstr_fd(char *s, int fd)
{
    if (!s)
        return;
    write(fd, s, ft_strlen(s));
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    static int pos = 0;
    static int size = 0;
    char *line;
    int i;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    
    line = NULL;
    i = 0;
    while (1)
    {
        if (pos >= size)
        {
            size = read(fd, buffer, BUFFER_SIZE);
            if (size <= 0)
                break;
            pos = 0;
        }
        
        if (buffer[pos] == '\n')
        {
            line = realloc(line, i + 2);
            if (!line)
                return (NULL);
            line[i] = '\n';
            line[i + 1] = '\0';
            pos++;
            return (line);
        }
        
        line = realloc(line, i + 1);
        if (!line)
            return (NULL);
        line[i] = buffer[pos];
        i++;
        pos++;
    }
    
    if (i > 0)
    {
        line = realloc(line, i + 1);
        if (!line)
            return (NULL);
        line[i] = '\0';
        return (line);
    }
    
    free(line);
    return (NULL);
} 