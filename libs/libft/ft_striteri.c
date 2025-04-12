/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:21:27 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/16 22:21:16 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s && f && s[i++])
		f(i - 1, s + i - 1);
}
/*
#include <stdio.h>
void rot_1(unsigned int i, char *c)
{
    if (*c <= 'Z' && *c >= 'A')
        *c = (((*c - 'A' + 1) % 26) + 'A');
    if (*c <= 'z' && *c >= 'a')
        *c = (((*c - 'a' + 1) % 26) + 'a');
}

int main()
{
    char s[] = "ZaBCDEF";
   ft_striteri(s, rot_1);
    printf("%s\n", s);
}
*/
/*
void to_uppercase(unsigned int index, char *c)
{
    (void)index;  
    *c = toupper(*c);  
}
int main()
{
    char str[] = "hello world"; 
    ft_striteri(str, to_uppercase);
    printf("Modified string: %s\n", str);
    return 0;
}
*/