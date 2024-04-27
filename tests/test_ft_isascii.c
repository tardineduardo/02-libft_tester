/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:17:27 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	ft_isascii(int c);

void	test_ft_isascii(int c, char *comment)
{
	int	result = ft_isascii(c);
	int	expected = isascii(c);

	if ((result == 0) && (expected == 0)) 
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	else if ((result != 0) && (expected != 0))
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	else if ((result == 0 && expected != 0) || (result != 0 && expected == 0))
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);

	printf("ft_isascii > Input: < %c > (%s) | Expected: %d | Output: %d \n", c, comment, expected, result);

}

int	main(void)
{
	printf(">>>>> TESTING FT_ISASCII\n");

	test_ft_isascii(-1, "smaller than ascii range");
	test_ft_isascii(0, "zero");
	test_ft_isascii(127, "bigger ascii number");
    test_ft_isascii(178, "bigger than ascii range");
	printf("\n");

	return (0);
}