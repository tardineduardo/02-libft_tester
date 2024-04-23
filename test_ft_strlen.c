/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/23 21:38:23 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(int c);

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void	test_ft_strlen(char* c, int expected, char *comment)
{
	int	result = ft_strlen(c);

	if (result == expected) 
		printf(ANSI_COLOR_GREEN "[[[PASS]]] " ANSI_COLOR_RESET);
	else
		printf(ANSI_COLOR_RED "[[[FAIL]]] " ANSI_COLOR_RESET);

	printf("ft_strlen > Input: <\"%s\"> (%s) | Expected: %d | Output: %d \n", c, comment, expected, result);

}

int	main(void)
{
	printf(">>>>> TESTING FT_STRLEN\n");
	test_ft_strlen("batatinha quando nasce...", 25, "Normal string");
	test_ft_strlen("", 0, "Empty string");
	test_ft_strlen("1", 1, "String with one char");
	test_ft_strlen(NULL, 0, "Null string pointer");
    test_ft_strlen("\n", 1, "String with newline character");
    test_ft_strlen("  ", 2, "String with only spaces");
    test_ft_strlen("hello\0world", 5, "String with null terminator in the middle");


	return (0);
}