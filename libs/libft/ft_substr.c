/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:14:12 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/18 02:34:40 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (s_len - start < len)
		len = s_len - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (sub == NULL)
		return (NULL);
	if (len > 0)
		ft_memmove(sub, s + start, len);
	return (sub);
}
/*
int main(void)
{

    const char *test1 = "Hello, World!";
    const char *test2 = "abcdef";
 
    char *result1 = ft_substr(test1, 7, 5);
    char *result2 = ft_substr(test2, 2, 10);

    printf("Substring of \"%s\" starting at 7 for 5 characters:
	 \"%s\"\n", test1, result1);
    printf("Substring of \"%s\" starting at 2 for 10 characters:
	 \"%s\"\n", test2, result2);
    return 0;
}
*/