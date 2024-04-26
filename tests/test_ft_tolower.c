/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/24 10:28:10 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c);

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void	test_ft_tolower(int c, char *comment)
{
	int result = ft_tolower(c);
	int expected = tolower(c);

	if (result == expected) 
		printf(ANSI_COLOR_GREEN "[[[PASS]]] " ANSI_COLOR_RESET);
	else
		printf(ANSI_COLOR_RED "[[[FAIL]]] " ANSI_COLOR_RESET);

	printf("Input: <\"%d\"> (%s) | Expected: %d | Output: %d \n", c, comment, expected, result);

}

int	main(void)
{
	printf(">>>>> TESTING FT_TOlower\n");
	test_ft_tolower('a', "Lowercase 'a'");
	test_ft_tolower('z', "Lowercase 'z'");
	test_ft_tolower('A', "Uppercase 'A'");
	test_ft_tolower('Z', "Uppercase 'Z'");
	test_ft_tolower('0', "Digit '0'");
	test_ft_tolower('9', "Digit '9'");
	test_ft_tolower('@', "Symbol '@'");
	test_ft_tolower('[', "Symbol '['");
	test_ft_tolower('`', "Symbol '`'");
	test_ft_tolower('{', "Symbol '{'");
	test_ft_tolower('\0', "Null character");
	test_ft_tolower('\t', "Tab character");
	test_ft_tolower('\x80', "Extended ASCII 128");
	test_ft_tolower('\xFF', "Extended ASCII 255");
	test_ft_tolower('.', "Period");
	test_ft_tolower(',', "Comma");
	test_ft_tolower('-', "Dash");
	test_ft_tolower('!', "Exclamation mark");
	printf("\n");

	return (0);
}