/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:17:27 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	ft_isdigit(int c);

void	test_ft_isdigit(int c, char *comment)
{
	int	result = ft_isdigit(c);
	int	expected = isdigit(c);

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

	test_ft_isdigit(' ', "space");
	test_ft_isdigit('a', "lowercase letter");
    test_ft_isdigit('9', "digit");
	test_ft_isdigit('8', "digit");
	test_ft_isdigit('7', "digit");
	test_ft_isdigit('6', "digit");
	test_ft_isdigit('5', "digit");
	test_ft_isdigit('4', "digit");
	test_ft_isdigit('3', "digit");
	test_ft_isdigit('2', "digit");
	test_ft_isdigit('1', "digit");
	test_ft_isdigit('0', "digit");
	test_ft_isdigit(-1, "negative int");
	test_ft_isdigit(-532300, "negative int");
	printf("\n");

	return (0);
}