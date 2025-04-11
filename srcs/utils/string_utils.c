/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:00:00 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/11 08:46:54 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Convert an integer to a string (malloc'ed)
 * 
 * @param n The integer to convert
 * @return char* The string representation of the integer
 */
char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = (num <= 0);
	if (num < 0)
		num = -num;
	while (n != 0 && ++len)
		n /= 10;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

/**
 * @brief Joins two strings (second string is freed)
 * 
 * @param s1 First string
 * @param s2 Second string (will be freed)
 * @return char* Joined string (malloc'ed)
 */
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	free(s1);
	return (joined);
}

/**
 * @brief Joins two strings
 * 
 * @param s1 First string
 * @param s2 Second string
 * @return char* Joined string (malloc'ed)
 */
char	*ft_strjoin_custom(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}