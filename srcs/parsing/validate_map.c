/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/10 09:51:10 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Checks if the file has a .ber extension
 * 
 * @param filename The filename to check
 * @return int 1 if valid, 0 if invalid
 */
int	check_ber_extension(char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)  /* At minimum: "x.ber" */
		return (0);
	if (filename[len - 4] != '.' || filename[len - 3] != 'b'
		|| filename[len - 2] != 'e' || filename[len - 1] != 'r')
		return (0);
	return (1);
}

/**
 * @brief Checks if the map is surrounded by walls
 * 
 * @param map The map to check
 * @return int 1 if valid, 0 if invalid
 */
static int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if ((i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
				&& map->grid[i][j] != WALL)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Checks if the map contains only valid characters
 * and counts the number of players, exits, and collectibles
 * 
 * @param game The game structure containing the map
 * @return int 1 if valid, 0 if invalid
 */
static int	check_characters(t_game *game)
{
	int	i;
	int	j;

	game->map.players = 0;
	game->map.exits = 0;
	game->map.collectibles = 0;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.grid[i][j] == PLAYER)
			{
				game->player.x = j;
				game->player.y = i;
				game->map.players++;
			}
			else if (game->map.grid[i][j] == EXIT)
				game->map.exits++;
			else if (game->map.grid[i][j] == COLLECTIBLE)
				game->map.collectibles++;
			else if (game->map.grid[i][j] != EMPTY && game->map.grid[i][j] != WALL)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Checks if the map contains the required elements
 * 
 * @param map The map to check
 * @return int 1 if valid, 0 if invalid
 */
static int	check_elements(t_map *map)
{
	if (map->players != 1)
		return (0);
	if (map->exits != 1)
		return (0);
	if (map->collectibles < 1)
		return (0);
	return (1);
}

/**
 * @brief Creates a copy of the map for flood fill algorithm
 * 
 * @param game The game structure containing the map
 * @return char** Copy of the map or NULL if allocation fails
 */
static char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = (char **)malloc(sizeof(char *) * game->map.height);
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		map_copy[i] = (char *)malloc(sizeof(char) * (game->map.width + 1));
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		j = 0;
		while (j < game->map.width)
		{
			map_copy[i][j] = game->map.grid[i][j];
			j++;
		}
		map_copy[i][j] = '\0';
		i++;
	}
	return (map_copy);
}

/**
 * @brief Frees a map copy
 * 
 * @param map_copy Map copy to free
 * @param height Height of the map
 */
static void	free_map_copy(char **map_copy, int height)
{
	int	i;

	if (!map_copy)
		return ;
	i = 0;
	while (i < height)
	{
		if (map_copy[i])
			free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

/**
 * @brief Recursive flood fill algorithm to check if all
 * collectibles and exit are reachable
 * 
 * @param map_copy Map copy to flood fill
 * @param y Current y coordinate
 * @param x Current x coordinate
 * @param game Game structure
 * @param collectibles Pointer to count of collectibles found
 * @param exit_found Pointer to exit found flag
 */
static void	flood_fill(char **map_copy, int y, int x, t_game *game, 
					int *collectibles, int *exit_found)
{
	// If out of bounds, wall, or already visited, return
	if (y < 0 || y >= game->map.height || x < 0 || x >= game->map.width
		|| map_copy[y][x] == WALL || map_copy[y][x] == 'V')
		return ;

	// Found a collectible
	if (map_copy[y][x] == COLLECTIBLE)
		(*collectibles)++;

	// Found the exit
	if (map_copy[y][x] == EXIT)
		*exit_found = 1;

	// Mark as visited
	map_copy[y][x] = 'V';

	// Explore in all four directions
	flood_fill(map_copy, y - 1, x, game, collectibles, exit_found); // Up
	flood_fill(map_copy, y + 1, x, game, collectibles, exit_found); // Down
	flood_fill(map_copy, y, x - 1, game, collectibles, exit_found); // Left
	flood_fill(map_copy, y, x + 1, game, collectibles, exit_found); // Right
}

/**
 * @brief Checks if there is a valid path from player to all collectibles and exit
 * 
 * @param game The game structure containing the map
 * @return int 1 if valid, 0 if invalid
 */
int	check_path(t_game *game)
{
	char	**map_copy;
	int		collectibles;
	int		exit_found;

	map_copy = copy_map(game);
	if (!map_copy)
		return (0);

	collectibles = 0;
	exit_found = 0;

	// Start flood fill from player position
	flood_fill(map_copy, game->player.y, game->player.x, game, 
		&collectibles, &exit_found);
	
	// Free the map copy
	free_map_copy(map_copy, game->map.height);

	// Check if all collectibles and exit are reachable
	if (collectibles != game->map.collectibles || !exit_found)
		return (0);

	return (1);
}

/**
 * @brief Main function to validate the map
 * 
 * @param game The game structure containing the map
 * @return int 1 if valid, 0 if invalid
 */
int	validate_map(t_game *game)
{
	// Check if the map is surrounded by walls
	if (!check_walls(&game->map))
	{
		ft_putstr_error(ERR_MAP_NOT_CLOSED);
		return (0);
	}

	// Check if the map contains only valid characters
	if (!check_characters(game))
	{
		ft_putstr_error(ERR_MAP_INVALID);
		return (0);
	}

	// Check if the map contains the required elements
	if (!check_elements(&game->map))
	{
		ft_putstr_error(ERR_MAP_MISSING_CHAR);
		return (0);
	}

	// Check if there is a valid path to all collectibles and exit
	if (!check_path(game))
	{
		ft_putstr_error(ERR_NO_PATH);
		return (0);
	}

	// Initialize collected count to 0
	game->map.collected = 0;

	return (1);
}