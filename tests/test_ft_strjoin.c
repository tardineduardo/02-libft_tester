/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:52:03 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"


char *ft_strjoin(char const *s1, char const *set);


typedef struct
{
	const char	*s1;
	const char	*s2;
	char		*result;
	char		*control;		
	char		*comment;
} Test;


// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
	if (test.s1 == NULL && test.s2 != NULL)
	{
	if (strcmp(test.result, test.s2) == 0)
        {
            printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
            printf("(s1 NULL)\t\tft_strjoin returns s2\n");
            return;
        }
        else
        {
            printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
            printf("(s1 NULL)\t\tft_strjoin DOES NOT return s2\n");      
            (*fail_count)++;
            return;
        }
	}
	else if (test.s2 == NULL && test.s1 != NULL)
	{
        if (strcmp(test.result, test.s1) == 0)
        {
            printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
            printf("(s2 NULL)\t\tft_strjoin returns s1\n");
            return;
        }
        else
        {
            printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
            printf("(s2 NULL)\t\tft_strjoin DOES NOT return s1\n");      
            (*fail_count)++;
            return;
        }
    }
	else if (test.s2 == NULL && test.s1 == NULL)
	{
		if (test.result == NULL)
		{
			printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
			printf("(s1 and s2 NULL)\tft_strjoin returns NULL\n");
			return;
		}
		else
		{
			printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
			printf("s1 and s2 are NULL and ft_strjoin does NOT return NULL\n");		
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
	printf("(%s)\ts1: \"%s\", s2: \"%s\"", test.comment, test.s1, test.s2);
	printf("\texpected:\"%s\"\tresult:\"%s\"", test.control, test.result);
    printf("\n");

}

#define NUM_TESTS 8

int main(void)
{
    int fail_counter = 0;

	const char	*a_s1 = "abc";
	const char	*a_s2 = "def";
	char 		*a_result = ft_strjoin(a_s1, a_s2);
	char		*a_control = "abcdef";
	char		*a_comment = "Normal string";

	const char	*b_s1 = "";
	const char	*b_s2 = "123456";
	char 		*b_result = ft_strjoin(b_s1, b_s2);
	char		*b_control = "123456";
	char		*b_comment = "Empty string s1";

	const char	*c_s1 = "rstuvx";
	const char	*c_s2 = "";
	char 		*c_result = ft_strjoin(c_s1, c_s2);
	char		*c_control = "rstuvx";
	char		*c_comment = "Empty string s2";

    const char	*e_s1 = NULL;
    const char	*e_s2 = "123456";
	char		*e_result = ft_strjoin(e_s1, e_s2);
    char		*e_control = "123456";
    char		*e_comment = "Null string s1";

    const char	*f_s1 = "berlin42";
    const char	*f_s2 = NULL;
    char		*f_result = ft_strjoin(f_s1, f_s2);
    char		*f_control = "berlin42";
    char		*f_comment = "Null string s2";

    const char *g_s1 = "c\"de";
    const char *g_s2 = "23\"45";
    char *g_result = ft_strjoin(g_s1, g_s2);
    char *g_control = "c\"de23\"45";
    char *g_comment = "With escape chars";

    const char *h_s1 = NULL;
    const char *h_s2 = NULL;
    char *h_result = ft_strjoin(h_s1, h_s2);
    char *h_control = NULL;
    char *h_comment = "s1 and s2 are NULL";

	const char	*d_s1 = "";
	const char	*d_s2 = "";
	char 		*d_result = ft_strjoin(d_s1, d_s2);
	char		*d_control = "";
	char		*d_comment = "Empty s1 and s2";



	Test tests[NUM_TESTS] = {
	    {a_s1, a_s2, a_result, a_control, a_comment},
        {b_s1, b_s2, b_result, b_control, b_comment},
        {c_s1, c_s2, c_result, c_control, c_comment},
        {g_s1, g_s2, g_result, g_control, g_comment},
        {d_s1, d_s2, d_result, d_control, d_comment},
        {e_s1, e_s2, e_result, e_control, e_comment},
        {f_s1, f_s2, f_result, f_control, f_comment},
        {h_s1, h_s2, h_result, h_control, h_comment}
	};

	printf(COLOR_BLUE ">TESTING ft_strjoin------------------------------------------------------------------------\n" COLOR_RESET);
	printf("1) If your function needs to return a pointer to an empty string, it should not point to an empty string literal,\nbut to an allocated memory space for a single character and set it to the null terminator ('\\0').\n\n2) If any of s1 or s2 is NULL, your function should return NULL. Returning a pointer to copy to the non-null value\nis a not recommended. Ideally, a non-initialized pointer should not be passed as an argument, and if your function\nhandles it silently you might not spot this bug. You should always check if a pointer is NULL beforing passing it\nas an argument.\n\n");
		
	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_strjoin: FAIL");
    else
        ft_save_results("ft_strjoin: OK");

    printf("\n\n");
    return (0);
}
