/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:16:36 by isel-bar          #+#    #+#             */
/*   Updated: 2025/04/12 19:16:07 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char sep)
{
	int	flag;
	int	count;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (*str != sep && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == sep && flag != 0)
			flag = 0;
		str++;
	}
	return (count);
}

static int	get_word_len(const char *str, char sep)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != sep)
		len++;
	return (len);
}

static char	*get_next_word(const char *str, char sep)
{
	char	*word;
	int		len;
	int		i;

	while (*str == sep && *str)
		str++;
	len = get_word_len(str, sep);
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(const char *str, char sep)
{
	char	**result;
	int		i;
	int		flag;

	if (!str)
		return (NULL);
	result = malloc((count_words(str, sep) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	flag = 1;
	while (*str)
	{
		if (*str != sep && flag == 1)
		{
			flag = 0;
			result[i] = get_next_word(str, sep);
			if (!result[i++])
				return (free_array(result));
		}
		else if (*str == sep && flag == 0)
			flag = 1;
		str++;
	}
	return (result[i] = NULL, result);
}