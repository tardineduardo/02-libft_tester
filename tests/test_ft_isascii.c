/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/25 10:22:35 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c);

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void	test_ft_isascii(int c, char *comment)
{
	int	result = ft_isascii(c);
	int	expected = isascii(c);

	if ((result == 0) && (expected == 0)) 
		printf(ANSI_COLOR_GREEN "[[[PASS]]] " ANSI_COLOR_RESET);
	else if ((result != 0) && (expected != 0))
		printf(ANSI_COLOR_GREEN "[[[PASS]]] " ANSI_COLOR_RESET);
	else if ((result == 0 && expected != 0) || (result != 0 && expected == 0))
		printf(ANSI_COLOR_RED "[[[FAIL]]] " ANSI_COLOR_RESET);

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