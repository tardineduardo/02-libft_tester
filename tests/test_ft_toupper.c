/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:43:51 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	ft_toupper(int c);

void	test_ft_toupper(int c, char *comment)
{
	int	result = ft_toupper(c);
	int	expected = toupper(c);

	if (result == expected) 
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	else
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);

	printf("Input: <\"%d\"> (%s) | Expected: %d | Output: %d \n", c, comment, expected, result);

}

int	main(void)
{
	printf(">>>>> TESTING FT_TOUPPER\n");
	test_ft_toupper('a', "Lowercase 'a'");
	test_ft_toupper('z', "Lowercase 'z'");
	test_ft_toupper('A', "Uppercase 'A'");
	test_ft_toupper('Z', "Uppercase 'Z'");
	test_ft_toupper('0', "Digit '0'");
	test_ft_toupper('9', "Digit '9'");
	test_ft_toupper('@', "Symbol '@'");
	test_ft_toupper('[', "Symbol '['");
	test_ft_toupper('`', "Symbol '`'");
	test_ft_toupper('{', "Symbol '{'");
	test_ft_toupper('\0', "Null character");
	test_ft_toupper('\t', "Tab character");
	test_ft_toupper('\x80', "Extended ASCII 128");
	test_ft_toupper('\xFF', "Extended ASCII 255");
	test_ft_toupper('.', "Period");
	test_ft_toupper(',', "Comma");
	test_ft_toupper('-', "Dash");
	test_ft_toupper('!', "Exclamation mark");
	printf("\n");

	return (0);
}