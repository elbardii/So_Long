/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:30:00 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/11 08:41:29 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Joins two strings and frees the first one
 * 
 * @param s1 First string (will be freed)
 * @param s2 Second string
 * @return char* New joined string or NULL if allocation fails
 */
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
	{
		result = ft_strdup(s1);
		free(s1);
		return (result);
	}
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}