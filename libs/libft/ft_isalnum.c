/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:01:48 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/17 04:39:51 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isalnum - Checks if a character is alphanumeric.
 * @c: The character to check.
 *
 * Return: 1 if the character is alphanumeric, 0 otherwise.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
int main(void)
{
    // Test 1: Alphabetic characters
    printf("Testing alphabetic characters:\n");
    printf("'A' (ft_isalnum): %d\n", ft_isalnum('A'));
    printf("'A' (isalnum)   : %d\n", isalnum('A'));
    printf("'z' (ft_isalnum): %d\n", ft_isalnum('z'));
    printf("'z' (isalnum)   : %d\n\n", isalnum('z'));

    // Test 2: Numeric characters
    printf("Testing numeric characters:\n");
    printf("'0' (ft_isalnum): %d\n", ft_isalnum('0'));
    printf("'0' (isalnum)   : %d\n", isalnum('0'));
    printf("'9' (ft_isalnum): %d\n", ft_isalnum('9'));
    printf("'9' (isalnum)   : %d\n\n", isalnum('9'));

    // Test 3: Special characters
    printf("Testing special characters:\n");
    printf("'$' (ft_isalnum): %d\n", ft_isalnum('$'));
    printf("'$' (isalnum)   : %d\n", isalnum('$'));
    printf("' ' (ft_isalnum): %d\n", ft_isalnum(' '));
    printf("' ' (isalnum)   : %d\n\n", isalnum(' '));

    // Test 4: Extended ASCII and control characters
    printf("Testing extended ASCII and control characters:\n");
    printf("127 (ft_isalnum): %d\n", ft_isalnum(127));
    printf("127 (isalnum)   : %d\n", isalnum(127));
    printf("0 (ft_isalnum)  : %d\n", ft_isalnum(0));
    printf("0 (isalnum)     : %d\n", isalnum(0));

    return (0);
}
*/