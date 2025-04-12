/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:54:48 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/18 02:04:45 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i + 1 < size && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
// int main(void)
// {
//     char src[] = "Hello, World!";
//     char dst[20];
//     size_t size = sizeof(dst); 

//     size_t copied_length = ft_strlcpy(dst, src, size);

//     printf("Source: \"%s\"\n", src);
//     printf("Destination: \"%s\"\n", dst);
//     printf("Length of source string: %d\n", copied_length);

//     return 0;
// }