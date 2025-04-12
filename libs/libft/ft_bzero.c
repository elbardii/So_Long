/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:53:53 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/17 04:34:51 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_bzero - Zeroes out a memory area.
 * @s: The memory area to zero out.
 * @n: The number of bytes to set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int main(void)
{
    // Test 1: Regular string
    char str1[] = "Hello World";
    printf("Before ft_bzero: %s\n", str1);
    ft_bzero(str1, 5);
    printf("After ft_bzero (5 bytes): ");
    for (int i = 0; i < 11; i++)
        printf("%d ", str1[i]); // Print ASCII values to see zeroes
    printf("\n\n");

    // Test 2: Test with zeroing entire string
    char str2[] = "Testing";
    printf("Before ft_bzero: %s\n", str2);
    ft_bzero(str2, strlen(str2));
    printf("After ft_bzero (full string): ");
    for (int i = 0; i < 7; i++)
        printf("%d ", str2[i]);
    printf("\n\n");

    // Test 3: Test with array of integers
    int arr[] = {1, 2, 3, 4, 5};
    printf("Before ft_bzero: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");
    ft_bzero(arr, sizeof(int) * 2); // Zero out first two integers
    printf("After ft_bzero (2 integers): ");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return (0);
}
*/