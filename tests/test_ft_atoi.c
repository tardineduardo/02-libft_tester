/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:21:26 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:49:46 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test_ft_atoi(char *nptr, char *comment)
{
	int	result = ft_atoi(nptr);
	int	expected = atoi(nptr);

	if (result == expected) 
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	else
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);

	printf("ft_strlen > Input: <\"%s\"> (%s) | Expected: %d | Output: %d \n", nptr, comment, expected, result);

}

int	main(void)
{
	printf(">>>>> TESTING FT_ATOI\n");
	test_ft_atoi("Twinkle twinkle little star...", "Normal string");
	test_ft_atoi("", "Empty string");
	test_ft_atoi("1", "String with one numeric char");
	test_ft_atoi("+35", "String with plus sign");
	test_ft_atoi("  ", "String with only spaces");
	test_ft_atoi("-9384", "String with minus sign");
	test_ft_atoi("   84", "String with trailing spaces at the beginning");
	test_ft_atoi("84   ", "String with trailing spaces at the end");
	test_ft_atoi(" 84  ", "String with trailing spaces at both ends");

	printf("\n");

	return (0);
}