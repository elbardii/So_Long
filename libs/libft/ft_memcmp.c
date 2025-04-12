/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:54:18 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/07 15:51:25 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n < 1 || s1 == s2)
		return (0);
	if (*(unsigned char *)s1 - *(unsigned char *)s2)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (ft_memcmp(s1 + 1, s2 + 1, n - 1));
}
/*
int main()
{
    int i = 1337;
    int j = 1337;
    printf("%d\n", ft_memcmp(&i, &j, 6));
}
*/