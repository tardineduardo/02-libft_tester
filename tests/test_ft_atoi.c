/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/24 17:00:17 by eduribei         ###   ########.fr       */
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
	int	result = ft_atoi(c);
	int	expected = atoi(c);

	if (result == expected) 
		printf(ANSI_COLOR_GREEN "[[[PASS]]] " ANSI_COLOR_RESET);
	else
		printf(ANSI_COLOR_RED "[[[FAIL]]] " ANSI_COLOR_RESET);

	printf("ft_strlen > Input: <\"%s\"> (%s) | Expected: %d | Output: %d \n", c, comment, expected, result);

}

int	main(void)
{
	printf(">>>>> TESTING FT_ATOI\n");
	test_ft_strlen("batatinha quando nasce...", "Normal string");
	test_ft_strlen("", "Empty string");
	test_ft_strlen("1", "String with one char");
	test_ft_strlen("  ", "String with only spaces");
	test_ft_strlen("-9384", "String with null terminator in the middle");
	printf("\n");


	return (0);
}