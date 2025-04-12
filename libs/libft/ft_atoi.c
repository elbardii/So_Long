/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:37:00 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/08 05:41:19 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int n)
{
	return (n >= '0' && n <= '9');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -sign;
	}
	number = 0;
	while (ft_isdigit(str[i]))
	{
		number = 10 * number;
		if (number < number / 10)
			return (-(sign > 0));
		number += str[i++] - '0';
	}
	return (sign * number);
}

#include <stdio.h>
#include <stdlib.h>  // Required for atoi

int main() {
   // Basic integer conversion
    const char *str1 = "123";
    int num1 = ft_atoi(str1);
    printf("String \"%s\" to integer: %d\n", str1, num1);  // Prints: 123
    
    // Handling negative numbers
    const char *str2 = "-2147483649";
    int num2 = ft_atoi(str2);
    printf("String \"%s\" to integer: %d\n", str2, num2);  // Prints: -456
    
    // // Leading whitespace is ignored
    const char *str3 = "  -2147483650";
    int num3 = ft_atoi(str3);
    printf("String \"%s\" to integer: %d\n", str3, num3);  // Prints: 789
    
    // // Invalid input examples
    printf("\"abc\" converts to: %d\n", atoi("abc"));      // Prints: 0
    printf("\"12.34\" converts to: %d\n", atoi("12.34"));  // Prints: 12
    printf("\"56abc\" converts to: %d\n", atoi("56abc"));  // Prints: 56
    
    // // Using the result in calculations
    int sum = ft_atoi("100") + atoi("200");
    printf("Sum: %d\n", sum);  // Prints: 300
    
    return 0;
}
