/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:17:27 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	ft_strlen(char *c);

void	test_ft_strlen(char* c, int expected, char *comment)
{
	int	result = ft_strlen(c);

	if (result == expected) 
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	else
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);

	printf("ft_strlen > Input: <\"%s\"> (%s) | Expected: %d | Output: %d \n", c, comment, expected, result);

}

int	main(void)
{
	printf(COLOR_BLUE ">TESTING ft_strlen------------------------------------------------------------------------\n" COLOR_RESET);
	test_ft_strlen("batatinha quando nasce...", 25, "Normal string");
	test_ft_strlen("", 0, "Empty string");
	test_ft_strlen("1", 1, "String with one char");
    test_ft_strlen("  ", 2, "String with only spaces");
    test_ft_strlen("hello\0world", 5, "String with null terminator in the middle");
    test_ft_strlen(NULL, 0, "NULL");
	test_ft_strlen("", 0, "Empty string");
	printf("\n\n");


	return (0);
}