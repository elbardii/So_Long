/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:55:16 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/18 02:37:06 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>
int main(void)
{
    char test1 = 'A';
    char test2 = 'Z';
    char test3 = 'a';
    char test4 = 'z';
    char test5 = '!';
    char test6 = 'M';
    printf("'%c' converted to lowercase: '%c'\n", test1, ft_tolower(test1));
    printf("'%c' converted to lowercase: '%c'\n", test2, ft_tolower(test2));
    printf("'%c' converted to lowercase: '%c'\n", test3, ft_tolower(test3));
    printf("'%c' converted to lowercase: '%c'\n", test4, ft_tolower(test4));
    printf("'%c' converted to lowercase: '%c'\n", test5, ft_tolower(test5));
    printf("'%c' converted to lowercase: '%c'\n", test6, ft_tolower(test6));

    return 0;
}
*/