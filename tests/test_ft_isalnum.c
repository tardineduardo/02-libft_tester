/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:17:27 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	ft_isalnum(int c)

void	test_ft_isalnum(int c, char *comment)
{
	int	result = ft_isalnum(c);
	int	expected = isalnum(c);

	if ((result == 0) && (expected == 0)) 
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	else if ((result != 0) && (expected != 0))
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	else if ((result == 0 && expected != 0) || (result != 0 && expected == 0))
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);

	printf(" Input: < %c > (%s) | Expected: %d | Output: %d \n", c, comment, expected, result);
}

int	main(void)
{
	printf(">>>>> TESTING FT_ISDIGIT\n");

	// ASCII Control Characters
	test_ft_isalnum('\0', "null character");       // ASCII 0
	test_ft_isalnum('\n', "newline");             // ASCII 10
	test_ft_isalnum('\r', "carriage return");     // ASCII 13
	test_ft_isalnum('\t', "horizontal tab");      // ASCII 9

	// ASCII Non-Printable Characters
//	test_ft_isalnum('\x1F', "unit separator");    // ASCII 31
//	test_ft_isalnum('\x7F', "delete");            // ASCII 127

	// ASCII Printable Characters
	test_ft_isalnum(' ', "space");                // ASCII 32
	test_ft_isalnum('!', "exclamation mark");     // ASCII 33
	test_ft_isalnum('~', "tilde");                // ASCII 126

	// ASCII Digits
	test_ft_isalnum('0', "digit");                // ASCII 48
	test_ft_isalnum('1', "digit");                // Continued for each digit...
	test_ft_isalnum('2', "digit");
	test_ft_isalnum('3', "digit");
	test_ft_isalnum('4', "digit");
	test_ft_isalnum('5', "digit");
	test_ft_isalnum('6', "digit");
	test_ft_isalnum('7', "digit");
	test_ft_isalnum('8', "digit");
	test_ft_isalnum('9', "digit");                // ASCII 57

	// ASCII Uppercase Letters
	test_ft_isalnum('A', "uppercase letter");     // ASCII 65
	test_ft_isalnum('Z', "uppercase letter");     // ASCII 90

	// ASCII Lowercase Letters
	test_ft_isalnum('a', "lowercase letter");     // ASCII 97
	test_ft_isalnum('z', "lowercase letter");     // ASCII 122

	// Non-ASCII Characters (Beyond ASCII range)
	test_ft_isalnum(128, "extended ASCII");       // Extended ASCII
	test_ft_isalnum(255, "extended ASCII");       // Maximum Extended ASCII
	test_ft_isalnum(-1, "negative int");          // Testing negative values
	test_ft_isalnum(-532300, "large negative int");

	// Unicode Characters (well beyond ASCII)
//	test_ft_isalnum(0x0394, "Greek Capital Letter Delta");  // Unicode example
//	test_ft_isalnum(0x4F60, "CJK Character (你)");          // CJK Unicode example

	printf("\n");

	return (0);
}