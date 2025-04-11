/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/10 09:19:39 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <errno.h>

/**
 * @brief Free the map grid memory
 * 
 * @param grid Map grid to free
 * @param height Number of rows to free
 */
static void	free_grid(char **grid, int height)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (i < height)
	{
		if (grid[i])
			free(grid[i]);
		i++;
	}
	free(grid);
}

/**
 * @brief Get line from file descriptor
 * 
 * @param fd File descriptor to read from
 * @param line Pointer to store the read line
 * @return int 1 if line was read, 0 if EOF, -1 if error
 */
static int	get_next_line(int fd, char **line)
{
	char	buffer[2];
	char	*temp;
	char	*current_line;
	int		bytes_read;
	int		i;

	if (fd < 0 || !line)
		return (-1);
	current_line = malloc(1);
	if (!current_line)
		return (-1);
	current_line[0] = '\0';
	i = 0;
	while ((bytes_read = read(fd, buffer, 1)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (buffer[0] == '\n')
			break ;
		temp = malloc(i + 2);
		if (!temp)
		{
			free(current_line);
			return (-1);
		}
		if (i > 0)
			temp = memcpy(temp, current_line, i);
		temp[i++] = buffer[0];
		temp[i] = '\0';
		free(current_line);
		current_line = temp;
	}
	if (bytes_read < 0)
	{
		free(current_line);
		return (-1);
	}
	*line = current_line;
	return (bytes_read > 0 || i > 0);
}

/**
 * @brief Add a new line to the map grid
 * 
 * @param map Map structure to update
 * @param new_line Line to add
 * @return int 1 if successful, 0 if error
 */
static int	add_line_to_grid(t_map *map, char *new_line)
{
	char	**new_grid;
	int		i;

	if (!new_line || *new_line == '\0')
		return (0);
	new_grid = malloc(sizeof(char *) * (map->height + 2));
	if (!new_grid)
		return (0);
	i = 0;
	while (i < map->height)
	{
		new_grid[i] = map->grid[i];
		i++;
	}
	new_grid[i] = new_line;
	new_grid[i + 1] = NULL;
	if (map->grid)
		free(map->grid);
	map->grid = new_grid;
	if (map->width == 0)
		map->width = ft_strlen(new_line);
	else if ((int)ft_strlen(new_line) != map->width)
		return (0);
	map->height++;
	return (1);
}

/**
 * @brief Validate the map dimensions
 * 
 * @param map Map structure to validate
 * @return int 1 if valid, 0 if invalid
 */
static int	validate_map_dimensions(t_map *map)
{
	if (map->height < 3 || map->width < 3)
		return (0);
	return (1);
}

/**
 * @brief Custom memcpy implementation
 * 
 * @param dst Destination buffer
 * @param src Source buffer
 * @param n Number of bytes to copy
 * @return void* Pointer to destination buffer
 */
static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dst && !src)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/**
 * @brief Read a map file into memory
 * 
 * @param game Game structure containing the map
 * @param map_path Path to the map file
 * @return int 1 if successful, specific error code if error
 */
int	read_map_file(t_game *game, char *map_path)
{
	int		fd;
	char	*line;
	int		status;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (errno);
	
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	
	while ((status = get_next_line(fd, &line)) > 0)
	{
		if (!add_line_to_grid(&game->map, line))
		{
			free(line);
			free_grid(game->map.grid, game->map.height);
			game->map.grid = NULL;
			game->map.width = 0;
			game->map.height = 0;
			close(fd);
			return (-1); // Custom error code for non-rectangular map
		}
	}
	close(fd);
	
	if (status < 0)
	{
		free_grid(game->map.grid, game->map.height);
		game->map.grid = NULL;
		game->map.width = 0;
		game->map.height = 0;
		return (-2); // Custom error code for read error
	}
	
	if (!validate_map_dimensions(&game->map))
	{
		free_grid(game->map.grid, game->map.height);
		game->map.grid = NULL;
		game->map.width = 0;
		game->map.height = 0;
		return (-3); // Custom error code for invalid dimensions
	}
	
	return (1); // Success
}

/**
 * @brief Main function to parse a map file
 * 
 * @param game Game structure to update
 * @param map_path Path to the map file
 * @return int 1 if successful, 0 if error
 */
int	parse_map(t_game *game, char *map_path)
{
	int	result;

	if (!map_path)
		error_exit(game, ERR_USAGE);
	
	if (!check_ber_extension(map_path))
		error_exit(game, ERR_EXTENSION);
	
	result = read_map_file(game, map_path);
	if (result != 1)
	{
		if (result == ENOENT)
			error_exit(game, "Error: File not found");
		else if (result == EACCES)
			error_exit(game, "Error: Permission denied");
		else if (result == -1)
			error_exit(game, ERR_MAP_NOT_RECT);
		else if (result == -2)
			error_exit(game, "Error: Failed to read map file");
		else if (result == -3)
			error_exit(game, "Error: Map dimensions too small");
		else
			error_exit(game, ERR_FILE);
	}
	
	if (!validate_map(game))
		error_exit(game, ERR_MAP_INVALID);
	
	return (1);
}