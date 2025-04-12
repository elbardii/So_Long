/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:54:59 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/18 02:18:45 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0 || s1 == s2)
		return (0);
	while (n > 0 && *s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
// int main(void)
// {
//     const char *test1_s1 = "Hello, World!";
//     const char *test2_s2 = "Hello, World?";
//     printf("Comparison of \"%s\" and \"%s\" (n=5): %d\n", test1_s1, 
//     test2_s2, ft_strncmp(test1_s1, test2_s2, 5));
//     return 0;
// }