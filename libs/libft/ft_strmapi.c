/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:17:27 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/16 20:39:02 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *result;
    unsigned int pos;

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
/*
#include <stdio.h>
char rot_1(unsigned int i, char c)
{
    if (c <= 'Z' && c >= 'A')
        return (((c - 'A' + 1) % 26) + 'A');
    if (c <= 'z' && c >= 'a')
        return (((c - 'a' + 1) % 26) + 'a');
    return (c);
}

int main()
{
    char s[] = "ZaBCDEF";
    char *result = ft_strmapi(s, rot_1);
    printf("%s\n", result);
}
*/
// Test functions to pass to ft_strmapi
/*
char test_uppercase(unsigned int i, char c)
{
    (void)i; // Unused parameter
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int main(void)
{
    // Test : Basic uppercase conversion
    char *str1 = "hello";
    char *result1 = ft_strmapi(str1, test_uppercase);
    printf("Test 1 (uppercase): \n");
    printf("Input: %s\n", str1);
    printf("Output: %s\n", result1);
    printf("Expected: HELLO\n\n");
    free(result1);


    return (0);
}
*/
