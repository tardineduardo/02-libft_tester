/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/23 21:30:51 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int c);

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void	test_ft_isalpha(int c, int expected, char *comment)
{
	int	result = ft_isalpha(c);

	if (result == expected) 
		printf(ANSI_COLOR_GREEN "[[[PASS]]] " ANSI_COLOR_RESET);
	else
		printf(ANSI_COLOR_RED "[[[FAIL]]] " ANSI_COLOR_RESET);

	printf("ft_isalpha > Input: <%c> (%s) | Expected: %d | Output: %d \n", c, comment, expected, result);

}

int	main(void)
{
	printf(">>>>> TESTING FT_ISALPHA\n");
	test_ft_isalpha('a', 0, "lowercase");
	test_ft_isalpha('2', 1, "digit");
	test_ft_isalpha('&', 1, "punctuation");
	return (0);
}
