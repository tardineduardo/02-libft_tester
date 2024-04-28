/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:17:27 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	ft_tolower(int c);

void	test_ft_tolower(int c, char *comment)
{
	int result = ft_tolower(c);
	int expected = tolower(c);

	if (result == expected) 
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	else
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);

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