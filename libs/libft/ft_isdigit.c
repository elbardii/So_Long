/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:56:59 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/17 19:10:36 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isdigit - Checks if a character is a digit (0-9).
 * @n: The character to check.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int	ft_isdigit(int n)
{
	return (n >= '0' && n <= '9');
}
/*
int main(void)
{
    // Test 1: All digits 0-9
    printf("Testing all digits:\n");
    for (int i = '0'; i <= '9'; i++)
    {
        printf("'%c' (ft_isdigit): %d\n", i, ft_isdigit(i));
        printf("'%c' (isdigit)   : %d\n", i, isdigit(i));
    }
    printf("\n");

    // Test 2: Letters
    printf("Testing letters:\n");
    printf("'A' (ft_isdigit): %d\n", ft_isdigit('A'));
    printf("'A' (isdigit)   : %d\n", isdigit('A'));
    printf("'z' (ft_isdigit): %d\n", ft_isdigit('z'));
    printf("'z' (isdigit)   : %d\n\n", isdigit('z'));
    return (0);
}
*/