/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:54:39 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/08 18:59:40 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ret;

	len = ft_strlen(s);
	ret = ft_calloc(len + 1, sizeof(char));
	if (ret != NULL)
		ft_memmove(ret, s, len);
	return (ret);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char *original = "Hello";
    char *copy = ft_strdup(original);

    printf("Original string: %s\n", original);
    printf("Copied string: %s\n", copy);

    free(copy); // Don't forget to free the dynamically allocated memory!
    return 0;
}
*/