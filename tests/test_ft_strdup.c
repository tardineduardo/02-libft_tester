/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:52:03 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"


char *ft_strdup(const char *s);


typedef struct
{
	const char	*s;
	char		*result;
	char		*control;		
	char		*comment;
} Test;


// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
	if (test.s == NULL)
	{
		if (test.result == NULL)
        {
            printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
            printf("(s == NULL)\t\tft_strdup returns NULL\n");
            return;
        }
        else
        {
            printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
            printf("(s NULL)\t\tft_strdup DOES NOT return NULL\n");      
            (*fail_count)++;
            return;
        }
	}
	
	if ((strcmp(test.result, test.control) == 0))
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);	
	else
	{
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
		(*fail_count)++;
	}
	printf("(%s)\ts: \"%s\"", test.comment, test.s);
	printf("\texpected:\"%s\"\tresult:\"%s\"", test.control, test.result);
    printf("\n");

}

#define NUM_TESTS 3

int main(void)
{
    int fail_counter = 0;

	const char	*a_s = "abc";
	char 		*a_result = ft_strdup(a_s);
	char		*a_control = "abc";
	char		*a_comment = "Normal string";

	const char	*b_s = "\0";
	char 		*b_result = ft_strdup(b_s);
	char		*b_control = "\0";
	char		*b_comment = "Empty string";

	const char	*c_s = NULL;
	char 		*c_result = ft_strdup(c_s);
	char		*c_control = NULL;
	char		*c_comment = "s is NULL\t";



	Test tests[NUM_TESTS] = {
		{a_s, a_result, a_control, a_comment},
		{b_s, b_result, b_control, b_comment},
		{c_s, c_result, c_control, c_comment}
	};

	printf(COLOR_BLUE ">TESTING ft_strdup------------------------------------------------------------------------\n" COLOR_RESET);
		
	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_strdup: FAIL");
    else
        ft_save_results("ft_strdup: OK");

    printf("\n\n");
    return (0);
}
