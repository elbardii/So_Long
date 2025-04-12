/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:38:09 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/17 19:09:56 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isalpha - Checks if a character is alphabetic.
 * @c: The character to check.
 *
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
int main(void)
{
    // Test 1: Uppercase letters
    printf("Testing uppercase letters:\n");
    printf("'A' (ft_isalpha): %d\n", ft_isalpha('A'));
    printf("'A' (isalpha)   : %d\n", isalpha('A'));
    printf("'Z' (ft_isalpha): %d\n", ft_isalpha('Z'));
    printf("'Z' (isalpha)   : %d\n\n", isalpha('Z'));
    
    return (0);
}
*/