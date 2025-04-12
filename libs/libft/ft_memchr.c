/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:54:14 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/07 14:32:07 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memchr - Locates the first occurrence of a byte in memory.
 * @s: Pointer to the memory area.
 * @c: Byte to search for.
 * @n: Number of bytes to search.
 *
 * Return: Pointer to the matching byte, or NULL if the byte is not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n < 1)
		return (NULL);
	if (*(unsigned char *)s != (unsigned char)c)
		return (ft_memchr(s + 1, c, n - 1));
	return ((void *)s);
}

/*
int main()
{
    const char *str = "Hello, World!";
    
    // Find the first 'o' in the string
    char *result = memchr(str, 'o', strlen(str));
    if (result != NULL) {
    printf("Found 'o' at position: %ld\n", result - str);
    } else {
    printf("'o' not found in the string\n");
    }
}
*/