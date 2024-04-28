/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:21:26 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/28 15:48:30 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"   //  <<--------------- ADD LIBRARIES TO THE HEADER FILE

int	ft_atoi(char *c); //  <<----------- --- DECLARE THE FUNCTION TO BE TESTED

typedef	struct        //  <<--------------- UPDATE VARIBALES AND TYPES NEEDED
{
	char	*input;
	char	*comment;
	int		result;
	int		expected;
} test;

void	test_ft_atoi(char* input, char *comment, int expected, int result, int *counter) //  <<-- UPDATE
{

	// UPDATADE THE LOGIC TO FIT YOUR TEST'S NEEDS.

	if (result == expected)
	{
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	}
	else
	{
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
		(*counter)++;
	}

	// UPDATE VARIABLES AND TYPES

	printf("Input: \"%s\" | Expected: %d | Output: %d | (%s)\n", input, expected, result, comment);

}

// FIRST, UPDATE THE STRUCT DECLARATION ON TOP OF PAGE
// YOU MIGHT NEED MORE VARIABLES AND OTHER DATA TYPES
// EDIT THE PARAMETERS OF THE FUNCTION INSIDE THE LOOP BELOW 

int	main(void)
{
	int		fail_counter = 0;
	int		*counter = &fail_counter;
	test	tests[8];											//UPDATE HERE TOO!

	tests[0].input = "Star";
	tests[0].comment = "Normal string";
	tests[0].result = ft_atoi(tests[0].input);
	tests[0].expected = atoi(tests[0].input);

	tests[1].input = "";
	tests[1].comment = "Empty string";
	tests[1].result = ft_atoi(tests[0].input);
	tests[1].expected = atoi(tests[0].input);

	tests[2].input = "1";
	tests[2].comment = "One numeric char";
	tests[2].result = ft_atoi(tests[0].input);
	tests[2].expected = atoi(tests[0].input);

	tests[3].input = "+35";
	tests[3].comment = "One plus sign";
	tests[3].result = ft_atoi(tests[0].input);
	tests[3].expected = atoi(tests[0].input);

	tests[4].input = "  ";
	tests[4].comment = "Only spaces";
	tests[4].result = ft_atoi(tests[0].input);
	tests[4].expected = atoi(tests[0].input);

	tests[5].input = "-9384";
	tests[5].comment = "Minus sign";
	tests[5].result = ft_atoi(tests[0].input);
	tests[5].expected = atoi(tests[0].input);

	tests[6].input = "   84";
	tests[6].comment = "Trailing spaces";
	tests[6].result = ft_atoi(tests[0].input);
	tests[6].expected = atoi(tests[0].input);

	tests[7].input = "84   ";
	tests[7].comment = "Trailing spaces";
	tests[7].result = ft_atoi(tests[0].input);
	tests[7].expected = atoi(tests[0].input);

	tests[7].input = " 84  ";
	tests[7].comment = "Trailing spaces";
	tests[7].result = ft_atoi(tests[0].input);
	tests[7].expected = atoi(tests[0].input);

	printf(">>>>> TESTING ft_atoi\n");

	int a = 0;
	while (a < 8) 		//<<<------------------------UPDATE HERE!
	{
		test_ft_atoi(tests[a].input, tests[a].comment, tests[a].result, tests[a].expected, counter); //UPDATE HERE!
		a++;
	}

	if (fail_counter > 0)
		ft_save_results("ft_atoi: FAIL"); 		//<<<------------------------UPDATE FT HERE! DON'T CHANGE STRING.
	else
		ft_save_results("ft_atoi: OK");			//<<<------------------------UPDATE FT HERE! DON'T CHANGE STRING.

	printf("\n");
	return (0);
}
