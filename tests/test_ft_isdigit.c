/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/29 21:31:31 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int ft_isdigit(int c);

typedef struct
{
    int input;
    char *comment;
    int result;
} Test;

// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
    int expected = isdigit(test.input);

	if ((expected == 0) && (test.result == 0))
	{
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	}
	else if ((expected != 0) && (test.result != 0))
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

#define NUM_TESTS 31

int main(void)
{
    int fail_counter = 0;

    Test tests[NUM_TESTS] = {
	{0, "NULL", ft_isdigit(0)},	
    {-1, "negative integer (invalid ASCII)", ft_isdigit(-1)},
    {47, "/ (ASCII)", ft_isdigit(47)},
	{48, "digit 0 (ASCII)", ft_isdigit(48)},
	{49, "digit 1 (ASCII)", ft_isdigit(49)},
	{50, "digit 2 (ASCII)", ft_isdigit(50)},
	{51, "digit 3 (ASCII)", ft_isdigit(51)},
	{52, "digit 4 (ASCII)", ft_isdigit(52)},
	{53, "digit 5 (ASCII)", ft_isdigit(53)},
	{54, "digit 6 (ASCII)", ft_isdigit(54)},
	{55, "digit 7 (ASCII)", ft_isdigit(55)},
	{56, "digit 8 (ASCII)", ft_isdigit(56)},
	{57, "digit 9 (ASCII)", ft_isdigit(57)},
	{58, ": (ASCII)", ft_isdigit(58)},
    {65, "uppercase letter A (ASCII)", ft_isdigit('A')},
    {90, "uppercase letter Z (ASCII)", ft_isdigit('Z')},
    {97, "lowercase letter a (ASCII)", ft_isdigit('a')},
    {122, "lowercase letter z (ASCII)", ft_isdigit('z')},
    {127, "delete character (ASCII)", ft_isdigit(127)},
    {178, "superscript two (ISO-8859-1)", ft_isdigit(178)},
    {192, "À uppercase A with grave (ISO-8859-1)", ft_isdigit(192)},
    {214, "Ö uppercase O with diaeresis (ISO-8859-1)", ft_isdigit(214)},
    {222, "Þ uppercase Thorn (ISO-8859-1)", ft_isdigit(222)},
    {223, "ß lowercase sharp S (ISO-8859-1)", ft_isdigit(223)},
    {224, "à lowercase a with grave (ISO-8859-1)", ft_isdigit(224)},
    {255, "ÿ lowercase y with diaeresis (ISO-8859-1)", ft_isdigit(255)},
    {304, "İ uppercase I with dot above (Latin Extended-A)", ft_isdigit(304)},
    {321, "Ł uppercase L with stroke (Latin Extended-A)", ft_isdigit(321)},
    {0x3B1, "Greek small letter alpha (Unicode, not ISO-8859-1)", ft_isdigit(0x3B1)},
    {0x660, "Arabic-Indic digit zero (Unicode, not ISO-8859-1)", ft_isdigit(0x660)},
    {0x1F600, "Emoji (grinning face) (Unicode)", ft_isdigit(0x1F600)}
	};

    printf(">>>>> TESTING ft_isdigit\n");
    printf("Only looking for digits and letters within ASCII range\n");
	printf("As long the expected and the result values are non-zero, it's a PASS.\n");

	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);


	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_isdigit: FAIL");
    else
        ft_save_results("ft_isdigit: OK");


    printf("\n");
    return (0);
}
