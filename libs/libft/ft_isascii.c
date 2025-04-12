/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:46:13 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/17 19:10:07 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isascii - Checks if a character is part of the ASCII set.
 * @c: The character to check.
 *
 * Return: 1 if the character is ASCII, 0 otherwise.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
/*
int main(void)
{
    // Test 1: Standard ASCII characters
    printf("Testing standard ASCII characters:\n");
    printf("'A' (ft_isascii): %d\n", ft_isascii('A'));
    printf("'A' (isascii)   : %d\n", isascii('A'));
    printf("'z' (ft_isascii): %d\n", ft_isascii('z'));
    printf("'z' (isascii)   : %d\n\n", isascii('z'));
    
    return (0);
}
*/