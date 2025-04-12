/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-bar <isel-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:15:57 by isel-bar          #+#    #+#             */
/*   Updated: 2024/11/14 13:14:55 by isel-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set, *s1) != NULL)
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len - 1]) != NULL)
		len--;
	return (ft_substr(s1, 0, len));
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// void test_case(const char *s1, const char *set, const char *test_name)
// {
//     char *result = ft_strtrim(s1, set);
//     printf("\n=== Test Case: %s ===\n", test_name);
//     printf("Original string: %s\n", s1 ? s1 : "NULL");
//     printf("Set to trim: %s\n", set ? set : "NULL");
//     printf("Result: %s\n", result ? result : "NULL");
//     if (result && result != s1)  // Only free if it's not the original string
//         free(result);
// }
// int main(void)
// {
//     // Test case 1: Normal case - trim spaces from both ends
//     // test_case("   Hello World   ", " ", "Trim spaces");
//     // Test case 2: Multiple characters to trim
//     test_case("...Hello World", ".", "Trim dots");
//     // // Test case 3: Mixed characters to trim
//     // test_case("...,,, Hello World...,,", ".,", "Trim multiple ");
//     // // Test case 4: String with nothing to trim
//     // test_case("Hello World", " ", "Nothing to trim");
//     // // Test case 5: Empty string
//     // test_case("", " ", "Empty string");
//     // // Test case 6: NULL string
//     // test_case(NULL, " ", "NULL string");
//     // // Test case 7: NULL set
//     // test_case("  Hello World  ", NULL, "NULL set");
//     // // Test case 8: Empty set
//     // test_case("####Hello World###", "", "Empty set");
//     // // Test case 9: String containing only characters to trim
//     // test_case("........", ".", "All characters to trim");
//     // // Test case 10: Complex trim set
//     // test_case("#@!Hello World!@#", "#@!", "Complex trim set");
//     // // Test case 11: Non-printing characters
//     // test_case("\t\nHello World\n\t", "\t\n", "Non-printing characters");
//     // // Test case 12: Long string with multiple trim points
//     // test_case("...Hello...World...Hello...World...", ".", "Long string ");
//     // // Test case 13: String with trim characters in middle
//     // test_case("...Hello...World...", ".", "Characters to trim in middle");
//     // // Test case 14: Case sensitivity test
//     // test_case("AaAHello WorldAaA", "A", "Case sensitivity");
//     return (0);
// }