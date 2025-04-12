/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:15:25 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/10 10:57:03 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*s3;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (s3 == NULL)
		return (NULL);
	ft_memmove(s3, s1, len1);
	ft_memmove(s3 + len1, s2, len2);
	return (s3);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test_case(const char *s1, const char *s2, const char *test_name)
{
    char *result = ft_strjoin(s1, s2);
    printf("\n=== Test Case: %s ===\n", test_name);
    printf("s1: %s\n", s1 ? s1 : "NULL");
    printf("s2: %s\n", s2 ? s2 : "NULL");
    printf("Result: %s\n", result ? result : "NULL");
    if (result)
        free(result);
}
int main(void)
{
    // Test case 1: Normal case with two strings
    test_case("Hello, ", "World!", "Normal strings");
    
    // // Test case 2: First string NULL
    // test_case(NULL, "World!", "First string NULL");
    
    // // Test case 3: Second string NULL
    // test_case("Hello, ", NULL, "Second string NULL");
    
    // // Test case 4: Both strings NULL
    // test_case(NULL, NULL, "Both strings NULL");
    
    // // Test case 5: Empty strings
    // test_case("", "", "Empty strings");
    
    // // Test case 6: One empty string
    // test_case("Hello", "", "First string normal, second empty");
    // test_case("", "World", "First string empty, second normal");
    
    // // Test case 7: Strings with special characters
    // test_case("Hello\n", "\tWorld", "Strings with special characters");
    // // Test case 8: Long strings
    // test_case("This is a very long strin");
    return (0);
}
*/