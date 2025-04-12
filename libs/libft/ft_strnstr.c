/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:55:06 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/08 04:23:36 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;
	size_t	haystack_len;

	haystack_len = ft_strlen(haystack);
	if (len > haystack_len)
		len = haystack_len;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	i = 0;
	while (i + needle_len <= len)
	{
		if (ft_strncmp(haystack + i, needle, needle_len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    const char *haystack = "This is a simple example";
    const char *needle = "simple";
    
    // Search within the first 15 characters
    char *result = ft_strnstr(haystack, needle, 16);
    
    if (result) {
        printf("Found '%s' in the haystack: %s\n", needle, result);
    } else {
        printf("'%s' not found within the first 15 characters.\n", needle);
    }
    return 0;
}
*/