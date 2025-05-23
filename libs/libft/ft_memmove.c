/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:54:26 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/04 01:22:08 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst > src)
		i = len - 1;
	else
		i = 0;
	while (dst != src && ((dst > src && (int)i >= 0) || (dst < src && i < len)))
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if (dst > src)
			i--;
		else
			i++;
	}
	return (dst);
}
/*
int main()
{
	char src[] = "ABCDEFGHIJKL";
	char *dest = src + 3;
	ft_memmove(dest, src, 5);
	printf("%s\n",dest);
}
*/
