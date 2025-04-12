/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:55:20 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/18 02:39:25 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>
int main(void)
{
    char test1 = 'a';
    char test2 = 'z';
    char test3 = 'A';
    char test4 = 'Z';
    char test5 = '!';
    char test6 = 'm';

    printf("'%c' converted to uppercase: '%c'\n", test1, ft_toupper(test1));
    printf("'%c' converted to uppercase: '%c'\n", test2, ft_toupper(test2));
    printf("'%c' converted to uppercase: '%c'\n", test3, ft_toupper(test3));
    printf("'%c' converted to uppercase: '%c'\n", test4, ft_toupper(test4));
    printf("'%c' converted to uppercase: '%c'\n", test5, ft_toupper(test5));
    printf("'%c' converted to uppercase: '%c'\n", test6, ft_toupper(test6));
    return 0;
}
*/