/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:54:10 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/17 19:08:46 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isprint - Checks if a character is printable (including space).
 * @c: The character to check.
 *
 * Return: 1 if the character is printable, 0 otherwise.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
int main(void)
{
    // Test 1: Regular printable characters
    printf("Testing regular printable characters:\n");
    printf("'a' (ft_isprint): %d\n", ft_isprint('a'));
    printf("'a' (isprint)   : %d\n", isprint('a'));
    printf("'Z' (ft_isprint): %d\n", ft_isprint('Z'));
    printf("'Z' (isprint)   : %d\n", isprint('Z'));
    printf("'0' (ft_isprint): %d\n", ft_isprint('0'));
    printf("'0' (isprint)   : %d\n\n", isprint('0'));

    return (0);
}
*/