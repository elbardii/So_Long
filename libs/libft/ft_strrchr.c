/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:55:11 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/18 02:27:38 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
		len--;
	}
	if (s[0] == (char)c)
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
int main(void)
{
    const char *test1 = "Hello, World!";
    const char *test2 = "abcdefabcdef";
    const char *test3 = "Only one a";
    const char *test4 = "";

    printf("Last occurrence of 'o' in \"%s\": %s\n", 
	test1, ft_strrchr(test1, 'o'));
    printf("Last occurrence of 'f' in \"%s\": %s\n",
	 test2, ft_strrchr(test2, 'f'));


    return 0;
}
*/