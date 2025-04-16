/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/16 01:45:31 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Handles error case for empty lines in map file */
static void	handle_empty_line(int fd, char *line, char *buffer, t_game *game)
{
	get_next_line(-1);
	free(line);
	free(buffer);
	close(fd);
	exit_with_error("Invalid map: empty line detected", game);
}

/* Validates memory allocation for buffer in map reading */
static void	validate_buffer(char *buffer, char *tmp, char *line, t_game *game)
{
	if (!buffer)
	{
		free(tmp);
		free(line);
		exit_with_error("Memory allocation failed", game);
	}
}

/* Reads map file and converts it to a string */
char	*read_map_file(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	*buffer;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_with_error("Failed to open file", game);
	buffer = ft_strdup("");
	if (!buffer)
		exit_with_error("Memory allocation failed", game);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) == 1 && line[0] == '\n')
			handle_empty_line(fd, line, buffer, game);
		tmp = buffer;
		buffer = ft_strjoin(tmp, line);
		validate_buffer(buffer, tmp, line, game);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (buffer);
}
