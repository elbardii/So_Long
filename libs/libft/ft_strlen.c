/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:54:52 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/18 02:12:14 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
// int main(void)
// { 
//     const char *test1 = "Hello, World!";
//     const char *test2 = "";
//     const char *test3 = "42";
//     const char *test4 = "A very long string with spaces.";
//     printf("Length of \"%s\": %zu\n", test1, ft_strlen(test1));
//     printf("Length of \"%s\": %zu\n", test2, ft_strlen(test2));
//     printf("Length of \"%s\": %zu\n", test3, ft_strlen(test3));
//     printf("Length of \"%s\": %zu\n", test4, ft_strlen(test4));
//     return 0;
// }