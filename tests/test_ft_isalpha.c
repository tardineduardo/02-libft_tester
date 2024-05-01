
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/29 18:51:10 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int ft_isalpha(int c);

typedef struct
{
    int input;
    char *comment;
    int result;
} Test;

// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
    int expected = isalpha(test.input);
	if ((test.result == 0) && (expected == 0))
	{
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	}
	else if ((test.result != 0) && (expected != 0))
	{
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	}
	else
	{
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
		(*fail_count)++;
	}

    printf("Input: %d \t Expected: %d \t Output: %d \t(%s)\n", test.input, expected, test.result, test.comment);
}

#define NUM_TESTS 20

int main(void)
{
    int fail_counter = 0;

    Test tests[NUM_TESTS] = {
    {-1, "negative integer (invalid ASCII)", ft_isalpha(-1)},
    {0, "NULL character (ASCII)", ft_isalpha(0)},
    {65, "uppercase letter A (ASCII)", ft_isalpha('A')},
    {90, "uppercase letter Z (ASCII)", ft_isalpha('Z')},
    {97, "lowercase letter a (ASCII)", ft_isalpha('a')},
    {122, "lowercase letter z (ASCII)", ft_isalpha('z')},
    {127, "delete character (ASCII)", ft_isalpha(127)},
    {178, "superscript two (ISO-8859-1)", ft_isalpha(178)},  // Not an alphabet character; should remain unchanged
    {192, "À uppercase A with grave (ISO-8859-1)", ft_isalpha(192)},
    {214, "Ö uppercase O with diaeresis (ISO-8859-1)", ft_isalpha(214)},
    {222, "Þ uppercase Thorn (ISO-8859-1)", ft_isalpha(222)},
    {223, "ß lowercase sharp S (ISO-8859-1)", ft_isalpha(223)},  // Already lowercase; should remain unchanged
    {224, "à lowercase a with grave (ISO-8859-1)", ft_isalpha(224)},  // Already lowercase; should remain unchanged
    {246, "ö lowercase o with diaeresis (ISO-8859-1)", ft_isalpha(246)},  // Already lowercase; should remain unchanged
    {255, "ÿ lowercase y with diaeresis (ISO-8859-1)", ft_isalpha(255)},  // Already lowercase; should remain unchanged
    {304, "İ uppercase I with dot above (Latin Extended-A)", ft_isalpha(304)},  // Turkish specific character
    {321, "Ł uppercase L with stroke (Latin Extended-A)", ft_isalpha(321)},
    {0x3B1, "Greek small letter alpha (Unicode, not ISO-8859-1)", ft_isalpha(0x3B1)},  // Unicode character; should remain unchanged
    {0x660, "Arabic-Indic digit zero (Unicode, not ISO-8859-1)", ft_isalpha(0x660)},  // Unicode character; should remain unchanged
    {0x1F600, "Emoji (grinning face) (Unicode)", ft_isalpha(0x1F600)}  // Unicode emoji; should remain unchanged
	};


	printf(COLOR_BLUE ">TESTING ft_isalpha------------------------------------------------------------------------\n" COLOR_RESET);
    printf("Comparing ft_isalpha (result) with isalpha/ctype.h (expected).\n");

	printf("As long the expected and the result values are non-zero, it's a PASS.\n");

	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);


	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_isalpha: FAIL");
    else
        ft_save_results("ft_isalpha: OK");


    printf("\n");
    return (0);
}
