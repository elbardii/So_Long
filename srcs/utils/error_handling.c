/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/11 05:13:25 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* 
 * Note: The ft_strlen function is kept here even though it's also in ft_printf
 * since other files might rely on it directly from here
 */

/**
 * @brief Calculates the length of a string
 * 
 * @param str String to measure
 * @return size_t Length of the string
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * @brief Prints a string to standard output using ft_printf
 * 
 * @param str String to print
 */
void	ft_putstr(char *str)
{
	if (str)
		ft_printf("%s", str);
}

/**
 * @brief Prints a string to standard error
 * This function maintains direct write to stderr since ft_printf
 * normally writes to stdout
 * 
 * @param str String to print
 */
void	ft_putstr_error(char *str)
{
	if (str)
		write(2, str, ft_strlen(str));
}

/**
 * @brief Frees all resources used by the game
 * 
 * @param game Game structure pointer
 */
void	free_resources(t_game *game)
{
	int	i;

	if (!game)
		return ;

	// Free map grid
	if (game->map.grid)
	{
		i = 0;
		while (i < game->map.height)
		{
			if (game->map.grid[i])
				free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
		game->map.grid = NULL;
	}

	// Free MLX images if they exist
	if (game->mlx)
	{
		// Destroy all loaded images with null check
		if (game->img_empty.img)
			mlx_destroy_image(game->mlx, game->img_empty.img);
		if (game->img_wall.img)
			mlx_destroy_image(game->mlx, game->img_wall.img);
		if (game->img_collectible.img)
			mlx_destroy_image(game->mlx, game->img_collectible.img);
		if (game->img_exit.img)
			mlx_destroy_image(game->mlx, game->img_exit.img);
		if (game->img_player.img)
			mlx_destroy_image(game->mlx, game->img_player.img);
		
		 // Mark all image pointers as NULL after freeing
		game->img_empty.img = NULL;
		game->img_wall.img = NULL;
		game->img_collectible.img = NULL;
		game->img_exit.img = NULL;
		game->img_player.img = NULL;
		
		// Destroy window if it exists
		if (game->win)
		{
			mlx_destroy_window(game->mlx, game->win);
			game->win = NULL;
		}
		
		// Destroy MLX instance
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

/**
 * @brief Get string representation of error code
 * 
 * @param error_code Error code enum value
 * @return char* String representing the error
 */
char	*get_error_message(t_error_code error_code)
{
	if (error_code == ERR_CODE_ARGS)
		return (ERR_USAGE);
	else if (error_code == ERR_CODE_FILE)
		return (ERR_FILE);
	else if (error_code == ERR_CODE_MAP_INVALID)
		return (ERR_MAP_INVALID);
	else if (error_code == ERR_CODE_MAP_NOT_RECT)
		return (ERR_MAP_NOT_RECT);
	else if (error_code == ERR_CODE_MAP_NOT_CLOSED)
		return (ERR_MAP_NOT_CLOSED);
	else if (error_code == ERR_CODE_MAP_MISSING_CHAR)
		return (ERR_MAP_MISSING_CHAR);
	else if (error_code == ERR_CODE_MLX)
		return (ERR_MLX);
	else if (error_code == ERR_CODE_NO_PATH)
		return (ERR_NO_PATH);
	else if (error_code == ERR_CODE_EXTENSION)
		return (ERR_EXTENSION);
	else if (error_code == ERR_CODE_MEMORY)
		return (ERR_MEMORY);
	else if (error_code == ERR_CODE_IMAGE)
		return (ERR_IMAGE);
	else
		return ("Unknown error");
}

/**
 * @brief Logs error message to stderr with additional context
 * 
 * @param error_code Error code enum value
 * @param context Additional context info (can be NULL)
 */
void	log_error(t_error_code error_code, char *context)
{
	char	*error_msg;
	
	error_msg = get_error_message(error_code);
	ft_putstr_error("Error: ");
	ft_putstr_error(error_msg);
	if (context)
	{
		ft_putstr_error(" - ");
		ft_putstr_error(context);
	}
	ft_putstr_error("\n");
}

/**
 * @brief Displays error message and exits with error status
 * 
 * @param game Game structure pointer (can be NULL)
 * @param error_message Error message to display
 */
void	error_exit(t_game *game, char *error_message)
{
	ft_putstr_error(error_message);
	ft_putstr_error("\n");
	if (game)
		free_resources(game);
	exit(1);
}

/**
 * @brief Handle error with enum code and exit
 * 
 * @param game Game structure pointer (can be NULL)
 * @param error_code Error code enum value
 * @param context Additional context info (can be NULL)
 */
void	handle_error(t_game *game, t_error_code error_code, char *context)
{
	log_error(error_code, context);
	if (game)
		free_resources(game);
	exit(1);
}

/**
 * @brief Check for error condition and handle if true
 * 
 * @param game Game structure pointer (can be NULL)
 * @param condition Error condition to check
 * @param error_code Error code to use if condition is true
 * @param context Additional context info (can be NULL)
 * @return int Returns 1 if error was handled, 0 otherwise
 */
int	check_error(t_game *game, int condition, t_error_code error_code, char *context)
{
	if (condition)
	{
		handle_error(game, error_code, context);
		return (1);
	}
	return (0);
}