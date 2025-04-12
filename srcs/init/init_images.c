/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:00:00 by ismail            #+#    #+#             */
/*   Updated: 2025/04/12 06:26:15 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <errno.h>
#include <string.h>

/**
 * @brief Clean up already loaded images in case of error
 * 
 * @param game The game structure
 * @param stage Which stage of loading failed (determines what to free)
 */
static void	cleanup_loaded_images(t_game *game, int stage)
{
	if (stage >= 5 && game->img_player.img)
		mlx_destroy_image(game->mlx, game->img_player.img);
	if (stage >= 4 && game->img_exit.img)
		mlx_destroy_image(game->mlx, game->img_exit.img);
	if (stage >= 3 && game->img_collectible.img)
		mlx_destroy_image(game->mlx, game->img_collectible.img);
	if (stage >= 2 && game->img_wall.img)
		mlx_destroy_image(game->mlx, game->img_wall.img);
	if (stage >= 1 && game->img_empty.img)
		mlx_destroy_image(game->mlx, game->img_empty.img);
}

/**
 * @brief Verify that an image has the correct dimensions
 * 
 * @param img The image to check
 * @param expected_size The expected size (should match TILE_SIZE)
 * @return int 1 if valid, 0 if invalid
 */
static int	verify_image_dimensions(t_img *img, int expected_size)
{
	return (img->width == expected_size && img->height == expected_size);
}

/**
 * @brief Convert an integer to a string
 * 
 * @param num The integer to convert
 * @param str The string buffer to write to
 */
static void	ft_itoa_simple(int num, char *str)
{
	int	i;
	int	temp;
	int	len;

	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	temp = num;
	len = 0;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	i = len - 1;
	str[len] = '\0';
	while (num > 0)
	{
		str[i--] = (num % 10) + '0';
		num /= 10;
	}
}

/**
 * @brief Load an XPM image file into a t_img structure with error handling
 * 
 * @param game The game structure
 * @param img Pointer to the image structure to fill
 * @param path Path to the XPM file
 * @param name Human-readable name of the texture (for error messages)
 * @return int 1 if successful, 0 if failed
 */
static int	load_image(t_game *game, t_img *img, char *path, char *name)
{
	// Check if file exists and is readable
	int fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_error("Error: Cannot open file ");
		ft_putstr_error(path);
		ft_putstr_error(" (");
		ft_putstr_error(strerror(errno));
		ft_putstr_error(")\n");
		return (0);
	}
	close(fd);
	
	// Initialize to NULL to help with error checking
	img->img = NULL;
	
	// Load the XPM file
	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->width, &img->height);
	if (!img->img)
	{
		// Using ft_putstr_error for stderr output
		ft_putstr_error("Error: Failed to load ");
		ft_putstr_error(name);
		ft_putstr_error(" texture from ");
		ft_putstr_error(path);
		ft_putstr_error("\n");
		return (0);
	}
	
	// Get image data
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
								&img->line_length, &img->endian);
	
	// Verify dimensions
	if (!verify_image_dimensions(img, TILE_SIZE))
	{
		char	width_str[12];
		char	height_str[12];
		char	tile_str[12];
		
		// Convert dimensions to strings
		ft_itoa_simple(img->width, width_str);
		ft_itoa_simple(img->height, height_str);
		ft_itoa_simple(TILE_SIZE, tile_str);
		
		// Using ft_putstr_error for stderr output
		ft_putstr_error("Error: ");
		ft_putstr_error(name);
		ft_putstr_error(" texture dimensions (");
		ft_putstr_error(width_str);
		ft_putstr_error("x");
		ft_putstr_error(height_str);
		ft_putstr_error(") don't match TILE_SIZE (");
		ft_putstr_error(tile_str);
		ft_putstr_error(")\n");
		
		mlx_destroy_image(game->mlx, img->img);
		img->img = NULL;
		return (0);
	}
	
	return (1);
}

/**
 * @brief Load all game images with robust error handling
 * 
 * @param game The game structure
 * @return int 1 if successful, 0 if failed
 */
int	init_images(t_game *game)
{
	int	stage;
	char *base_path = "/home/ismail/Cursus42/So_Long/";
	char floor_path[100];
	char wall_path[100];
	char collectible_path[100];
	char exit_path[100];
	char player_path[100];

	// Create absolute paths for all assets
	ft_strlcpy(floor_path, base_path, 100);
	ft_strlcat(floor_path, "assets/sprites/floor.xpm", 100);
	
	ft_strlcpy(wall_path, base_path, 100);
	ft_strlcat(wall_path, "assets/sprites/wall.xpm", 100);
	
	ft_strlcpy(collectible_path, base_path, 100);
	ft_strlcat(collectible_path, "assets/sprites/collectible.xpm", 100);
	
	ft_strlcpy(exit_path, base_path, 100);
	ft_strlcat(exit_path, "assets/sprites/exit.xpm", 100);
	
	ft_strlcpy(player_path, base_path, 100);
	ft_strlcat(player_path, "assets/sprites/player.xpm", 100);

	stage = 0;
	
	// Load game sprites from assets folder with progressive error handling
	if (!load_image(game, &game->img_empty, floor_path, "floor"))
		return (0);
	stage = 1;
	
	if (!load_image(game, &game->img_wall, wall_path, "wall"))
	{
		cleanup_loaded_images(game, stage);
		return (0);
	}
	stage = 2;
	
	if (!load_image(game, &game->img_collectible, collectible_path, "collectible"))
	{
		cleanup_loaded_images(game, stage);
		return (0);
	}
	stage = 3;
	
	if (!load_image(game, &game->img_exit, exit_path, "exit"))
	{
		cleanup_loaded_images(game, stage);
		return (0);
	}
	stage = 4;
	
	if (!load_image(game, &game->img_player, player_path, "player"))
	{
		cleanup_loaded_images(game, stage);
		return (0);
	}
	
	return (1);
}