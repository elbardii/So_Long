/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:17:01 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/18 04:10:35 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_itoa - Converts an integer to a string.
 * @n: The integer to convert.
 *
 * Return: A pointer to the resulting string, or NULL if allocation fails.
 */

char	*ft_itoa(int n)
{
	int		i;
	char	dst[12];

	dst[11] = 0;
	i = 10;
	while (n || (i == 10))
	{
		dst[i--] = "9876543210123456789"[9 + n % 10];
		if (-10 < n && n < 0)
			dst[i--] = '-';
		n = n / 10;
	}
	return (ft_strdup(dst + i + 1));
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main()
// {
//     // Test various numbers
//     int test_number = 150;
//         char *result = ft_itoa(test_number);
//         printf("Number: %d -> String: %s\n", test_number, result);
//     return 0;
// }