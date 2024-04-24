/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/24 17:15:36 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr);


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void	test_ft_atoi(char *nptr, char *comment)
{
	int	result = ft_atoi(nptr);
	int	expected = atoi(nptr);

	if (result == expected) 
		printf(ANSI_COLOR_GREEN "[[[PASS]]] " ANSI_COLOR_RESET);
	else
		printf(ANSI_COLOR_RED "[[[FAIL]]] " ANSI_COLOR_RESET);

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