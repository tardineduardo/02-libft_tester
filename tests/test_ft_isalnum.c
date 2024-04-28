/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/28 16:43:09 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	ft_isalnum(int c);

void	test_ft_isalnum(int c, char *comment, int *counter)
{
	int	result = ft_isalnum(c);
	int	expected = isalnum(c);

	if ((result == 0) && (expected == 0)) 
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	else if ((result != 0) && (expected != 0))
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	else if ((result == 0 && expected != 0) || (result != 0 && expected == 0))
	{
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
		(*counter)++;
	}

	printf(" Input: < %c > (%s) | Expected: %d | Output: %d \n", c, comment, expected, result);
}

int	main(void)
{
	int		fail_counter = 0;
	int		*counter = &fail_counter;

	printf(">>>>> TESTING FT_ISALNUM\n");

	// ASCII Control Characters
	test_ft_isalnum('\0', "null character", counter);       // ASCII 0
	// test_ft_isalnum('\n', "newline", counter);             // ASCII 10
	// test_ft_isalnum('\r', "carriage return", counter);     // ASCII 13
	test_ft_isalnum('\t', "horizontal tab", counter);      // ASCII 9

	// ASCII Non-Printable Characters
	test_ft_isalnum('\x1F', "unit separator", counter);    // ASCII 31
	test_ft_isalnum('\x7F', "delete", counter);            // ASCII 127

	// ASCII Printable Characters
	test_ft_isalnum(' ', "space", counter);                // ASCII 32
	test_ft_isalnum('!', "exclamation mark", counter);     // ASCII 33
	test_ft_isalnum('~', "tilde", counter);                // ASCII 126

	// ASCII Digits
	test_ft_isalnum('0', "digit", counter);                // ASCII 48
	test_ft_isalnum('1', "digit", counter);                // Continued for each digit...
	test_ft_isalnum('2', "digit", counter);
	test_ft_isalnum('3', "digit", counter);
	test_ft_isalnum('4', "digit", counter);
	test_ft_isalnum('5', "digit", counter);
	test_ft_isalnum('6', "digit", counter);
	test_ft_isalnum('7', "digit", counter);
	test_ft_isalnum('8', "digit", counter);
	test_ft_isalnum('9', "digit", counter);                // ASCII 57

	// ASCII Uppercase Letters
	test_ft_isalnum('A', "uppercase letter", counter);     // ASCII 65
	test_ft_isalnum('Z', "uppercase letter", counter);     // ASCII 90

	// ASCII Lowercase Letters
	test_ft_isalnum('a', "lowercase letter", counter);     // ASCII 97
	test_ft_isalnum('z', "lowercase letter", counter);     // ASCII 122

	// Non-ASCII Characters (Beyond ASCII range)
	test_ft_isalnum(128, "extended ASCII", counter);       // Extended ASCII
	test_ft_isalnum(255, "extended ASCII", counter);       // Maximum Extended ASCII
	test_ft_isalnum(-1, "negative int", counter);          // Testing negative values
	test_ft_isalnum(-532300, "large negative int", counter);

	// Unicode Characters (well beyond ASCII)
	test_ft_isalnum(0x0394, "Greek Capital Letter Delta", counter);  // Unicode example
	test_ft_isalnum(0x4F60, "CJK Character (你)", counter);          // CJK Unicode example

	if (fail_counter > 0)
		ft_save_results("ft_isalnum: FAIL"); 		//<<<------------------------UPDATE FT HERE! DON'T CHANGE STRING.
	else
		ft_save_results("ft_isalnum: OK");			//<<<------------------------UPDATE FT HERE! DON'T CHANGE STRING.

	printf("\n");

	return (0);
}