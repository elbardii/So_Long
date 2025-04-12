/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/12 12:11:48 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_empty_line(int fd, char *line, char *buffer, t_game *game)
{
    get_next_line(-1);
    free(line);
    free(buffer);
    close(fd);
    error_exit("Invalid map: empty line detected", game);
}

void	buffer_check(char *buffer, char *tmp, char *line, t_game *game)
{
    if (!buffer)
    {
        free(tmp);
        free(line);
        error_exit("Memory allocation failed", game);
    }
}

char	*read_map(char *file, t_game *game)
{
    int		fd;
    char	*line;
    char	*buffer;
    char	*tmp;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        error_exit("Failed to open file", game);
    buffer = ft_strdup("");
    if (!buffer)
        error_exit("Memory allocation failed", game);
    line = get_next_line(fd);
    while (line)
    {
        if (line[0] == '\n' && line[1] == '\0')
            check_empty_line(fd, line, buffer, game);
        tmp = buffer;
        buffer = ft_strjoin(tmp, line);
        buffer_check(buffer, tmp, line, game);
        free(line); // Free the line after processing
        line = get_next_line(fd);
    }
    close(fd);
    return (buffer);
}
