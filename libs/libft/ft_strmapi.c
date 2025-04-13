/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:17:27 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/13 17:51:15 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	pos;

	if (!s || !f)
		return (0);
	result = ft_strdup(s);
	pos = 0;
	while (result && s[pos])
	{
		result[pos] = f(pos, s[pos]);
		pos++;
	}
	return (result);
}
