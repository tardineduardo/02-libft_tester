/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/28 17:46:22 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	ft_isalnum(int c);

typedef	struct
{
	int		input;
	char	*comment;
	int		result;
	int		expected;
} test;

void	test_ft_isalnum(int input, char *comment, int expected, int result, int *counter)
{
	if ((result == 0) && (expected == 0))
	{
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	}
	else if ((result != 0) && (expected != 0))
	{
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	}
	else if ((result == 0 && expected != 0) || (result != 0 && expected == 0))
	{
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
		(*counter)++;
	}

	printf("Input: %d \t Expected: %d \t Output: %d \t(%s)\n", input, expected, result, comment);

}

int	main(void)
{
	int		fail_counter = 0;
	int		*counter = &fail_counter;
	test	tests[4];

	tests[0].input = -1;
    tests[0].comment = "smaller than ascii range";
    tests[0].result = ft_isalnum(tests[0].input);
    tests[0].expected = isalnum(tests[0].input);

    tests[1].input = 0;
    tests[1].comment = "zero";
    tests[1].result = ft_isalnum(tests[1].input);
    tests[1].expected = isalnum(tests[1].input);

    tests[2].input = 127;
    tests[2].comment = "bigger ascii number";
    tests[2].result = ft_isalnum(tests[2].input);
    tests[2].expected = isalnum(tests[2].input);

    tests[3].input = 178;
    tests[3].comment = "non-standard ASCII value";
    tests[3].result = ft_isalnum(tests[3].input);
    tests[3].expected = isalnum(tests[3].input);

    tests[4].input = 'a';
    tests[4].comment = "lowercase letter";
    tests[4].result = ft_isalnum(tests[4].input);
    tests[4].expected = isalnum(tests[4].input);

    tests[5].input = 'Z';
    tests[5].comment = "uppercase letter";
    tests[5].result = ft_isalnum(tests[5].input);
    tests[5].expected = isalnum(tests[5].input);

    tests[6].input = '5';
    tests[6].comment = "number";
    tests[6].result = ft_isalnum(tests[6].input);
    tests[6].expected = isalnum(tests[6].input);
	
	printf(">>>>> TESTING FT_isalnum\n");

	int a = 0;
	while (a < 7)
	{
		test_ft_isalnum(tests[a].input, tests[a].comment, tests[a].result, tests[a].expected, counter);
		a++;
	}

	if (fail_counter > 0)
		ft_save_results("ft_isalnum: FAIL"); 
	else
		ft_save_results("ft_isalnum: OK");

	printf("\n");
	return (0);
}