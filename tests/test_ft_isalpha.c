/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:17:27 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	ft_isalpha(int c);

void	test_ft_isalpha(int c, char *comment)
{
	int	result = ft_isalpha(c);
	int	expected = isalpha(c);

	if ((result == 0) && (expected == 0)) 
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	else if ((result != 0) && (expected != 0))
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	else if ((result == 0 && expected != 0) || (result != 0 && expected == 0))
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);

	printf("ft_isalpha > Input: < %c > (%s) | Expected: %d | Output: %d \n", c, comment, expected, result);

}

int	main(void)
{
	printf(">>>>> TESTING FT_ISALPHA\n");

	test_ft_isalpha('a', "lowercase");
	test_ft_isalpha('2', "digit");
	test_ft_isalpha('&', "punctuation");
	printf("\n");

	return (0);
}
