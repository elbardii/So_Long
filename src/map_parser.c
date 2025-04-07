#include "so_long.h"

static int get_map_size(char *filename, t_map *map)
{
    int     fd;
    char    *line;
    int     width;
    int     height;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (error_exit("Failed to open map file"), 0);
    
    height = 0;
    width = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (height == 0)
            width = ft_strlen(line) - 1; // -1 to exclude newline
        else if (ft_strlen(line) - 1 != width)
        {
            free(line);
            close(fd);
            return (error_exit("Map is not rectangular"), 0);
        }
        height++;
        free(line);
    }
    close(fd);
    
    if (width < 3 || height < 3)
        return (error_exit("Map is too small"), 0);
    
    map->width = width;
    map->height = height;
    return (1);
}

static int allocate_map_grid(t_map *map)
{
    int i;

    map->grid = (char **)safe_malloc(sizeof(char *) * map->height);
    
    i = 0;
    while (i < map->height)
    {
        map->grid[i] = (char *)safe_malloc(sizeof(char) * (map->width + 1));
        i++;
    }
    return (1);
}

static void free_map_grid(t_map *map)
{
    int i;

    if (!map->grid)
        return;
    
    i = 0;
    while (i < map->height)
    {
        safe_free((void **)&map->grid[i]);
        i++;
    }
    safe_free((void **)&map->grid);
}

static int fill_map_grid(char *filename, t_map *map)
{
    int     fd;
    char    *line;
    int     i;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (error_exit("Failed to open map file"), 0);
    
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_strlcpy(map->grid[i], line, map->width + 1);
        free(line);
        i++;
    }
    close(fd);
    return (1);
}

static int validate_map_elements(t_map *map)
{
    int x;
    int y;

    map->collectibles = 0;
    map->exit = 0;
    map->player = 0;
    
    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->grid[y][x] == 'C')
                map->collectibles++;
            else if (map->grid[y][x] == 'E')
                map->exit++;
            else if (map->grid[y][x] == 'P')
                map->player++;
            else if (map->grid[y][x] != '0' && map->grid[y][x] != '1')
                return (error_exit("Invalid character in map"), 0);
            x++;
        }
        y++;
    }
    
    if (map->collectibles < 1)
        return (error_exit("Map must contain at least one collectible"), 0);
    if (map->exit != 1)
        return (error_exit("Map must contain exactly one exit"), 0);
    if (map->player != 1)
        return (error_exit("Map must contain exactly one player"), 0);
    return (1);
}

static int validate_walls(t_map *map)
{
    int x;
    int y;

    // Check top and bottom walls
    x = 0;
    while (x < map->width)
    {
        if (map->grid[0][x] != '1' || map->grid[map->height - 1][x] != '1')
            return (error_exit("Map must be enclosed by walls"), 0);
        x++;
    }
    
    // Check side walls
    y = 0;
    while (y < map->height)
    {
        if (map->grid[y][0] != '1' || map->grid[y][map->width - 1] != '1')
            return (error_exit("Map must be enclosed by walls"), 0);
        y++;
    }
    return (1);
}

static t_position find_player_position(t_map *map)
{
    t_position pos;
    int x;
    int y;

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->grid[y][x] == 'P')
            {
                pos.x = x;
                pos.y = y;
                return (pos);
            }
            x++;
        }
        y++;
    }
    pos.x = -1;
    pos.y = -1;
    return (pos);
}

static int flood_fill(t_map *map, int x, int y, int *collectibles, int *exit)
{
    if (x < 0 || x >= map->width || y < 0 || y >= map->height)
        return (0);
    if (map->grid[y][x] == '1')
        return (0);
    if (map->grid[y][x] == 'C')
        (*collectibles)++;
    if (map->grid[y][x] == 'E')
        *exit = 1;
    
    map->grid[y][x] = '1';
    
    flood_fill(map, x + 1, y, collectibles, exit);
    flood_fill(map, x - 1, y, collectibles, exit);
    flood_fill(map, x, y + 1, collectibles, exit);
    flood_fill(map, x, y - 1, collectibles, exit);
    
    return (1);
}

static int validate_path(t_map *map)
{
    t_map      temp_map;
    t_position player_pos;
    int        collectibles;
    int        exit;
    int        i;

    // Create a copy of the map for flood fill
    temp_map.width = map->width;
    temp_map.height = map->height;
    if (!allocate_map_grid(&temp_map))
        return (0);
    
    i = 0;
    while (i < map->height)
    {
        ft_strlcpy(temp_map.grid[i], map->grid[i], map->width + 1);
        i++;
    }
    
    player_pos = find_player_position(&temp_map);
    collectibles = 0;
    exit = 0;
    
    flood_fill(&temp_map, player_pos.x, player_pos.y, &collectibles, &exit);
    
    // Clean up
    i = 0;
    while (i < temp_map.height)
    {
        free(temp_map.grid[i]);
        i++;
    }
    free(temp_map.grid);
    
    return (collectibles == map->collectibles && exit == 1);
}

int parse_map(char *filename, t_map *map)
{
    if (!get_map_size(filename, map))
        return (0);
    
    if (!allocate_map_grid(map))
        return (0);
    
    if (!fill_map_grid(filename, map))
        return (free_map(map), 0);
    
    if (!validate_map_elements(map))
        return (free_map(map), 0);
    
    if (!validate_walls(map))
        return (free_map(map), 0);
    
    if (!validate_path(map))
        return (free_map(map), error_exit("No valid path to exit or collectibles"), 0);
    
    return (1);
}

void free_map(t_map *map)
{
    free_map_grid(map);
    map->width = 0;
    map->height = 0;
    map->collectibles = 0;
    map->exit = 0;
    map->player = 0;
} 