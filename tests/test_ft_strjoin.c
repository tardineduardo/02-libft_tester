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
	char		*control;		
	char		*comment;
} Test;


// Function to execute and print test results
void run_test(Test test, int *fail_counter)
{
    char *result;

    if (test.s1 == NULL && test.s2 == NULL)
    {
        pid_t pid = fork();
        if (pid == 0) // child process
        {
            result = ft_strjoin(test.s1, test.s2);
            printf(COLOR_YELLOW "[[[FAIL]]] " COLOR_RESET);
            if (result == NULL)
                printf("ft_strjoin() returned NULL when s1 and s2 were NULL. It should exit instead.\n");
            else
                printf("ft_strjoin() did not exit when s1 and s2 were NULL. It should exit instead.\n");
            (*fail_counter)++;
            exit(0);  // Ensure child process exits after execution
        }
        else if (pid > 0) // parent process
        {
            int status;
            waitpid(pid, &status, 0); // wait for child process to finish
            if (WIFSIGNALED(status))
            {
                printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
                printf("ft_strjoin() exited as expected when s1 and s2 were NULL.\n");
            }
        }
        else // fork failed
        {
            perror("fork");
            exit(1);
        }
    }

    else if ((test.s1 == NULL && test.s2 != NULL) || (test.s1 != NULL && test.s2 == NULL))
    {
        pid_t pid = fork();
        if (pid == 0) // child process
        {
            result = ft_strjoin(test.s1, test.s2);
            printf(COLOR_YELLOW "[[[FAIL]]] " COLOR_RESET);
            if (result == NULL)
                printf("ft_strjoin() returned NULL when one string was valid but the other was NULL. It should exit instead.\n");
            else if (strcmp(result, test.control) == 0)
                printf("ft_strjoin() returned a duplicate of the valid string when the other was NULL. It should exit instead.\n");
            else
                printf("ft_strjoin() didn't exit when one string valid but the other was NULL. It should exit instead.\n");
            (*fail_counter)++;
            exit(0);
        }
        else if (pid > 0) // parent process
        {
            int status;
            waitpid(pid, &status, 0); // wait for child process to finish
            if (WIFSIGNALED(status))
            {
                printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
                printf("ft_strjoin() exited as expected when one string was valid but the other was NULL.\n");
            }
        }
        else // fork failed
        {
            perror("fork");
            exit(1);
        }
    }
	else
	{
		result = ft_strjoin(test.s1, test.s2);

		if (strcmp(result, test.control) == 0)
		{
			printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
		}
		else
		{
			printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
			(*fail_counter)++;
		}
		printf("(%s)\ts1: \"%s\", s2: \"%s\"", test.comment, test.s1, test.s2);
		printf("\texpected:\"%s\"\tresult:\"%s\"", test.control, result);
		printf("\n");
	}
}

#define NUM_TESTS 8

int main(void)
{
    int fail_counter = 0;

	const char	*a_s1 = "abc";
	const char	*a_s2 = "def";
	char		*a_control = "abcdef";
	char		*a_comment = "Normal string";

	const char	*b_s1 = "";
	const char	*b_s2 = "123456";
	char		*b_control = "123456";
	char		*b_comment = "Empty string s1";

	const char	*c_s1 = "rstuvx";
	const char	*c_s2 = "";
	char		*c_control = "rstuvx";
	char		*c_comment = "Empty string s2";

    const char	*d_s1 = "c\"de";
    const char	*d_s2 = "23\"45";
    char 		*d_control = "c\"de23\"45";
    char 		*d_comment = "With escape chars";

	const char	*e_s1 = "";
	const char	*e_s2 = "";
	char		*e_control = "";
	char		*e_comment = "Empty s1 and s2";

    const char	*f_s1 = NULL;
    const char	*f_s2 = "123456";
    char		*f_control = "123456";
    char		*f_comment = "Null string s1";

    const char	*g_s1 = "berlin42";
    const char	*g_s2 = NULL;
    char		*g_control = "berlin42";
    char		*g_comment = "Null string s2";

    const char	*h_s1 = NULL;
    const char 	*h_s2 = NULL;
    char 		*h_control = NULL;
    char 		*h_comment = "s1 and s2 are NULL";


	Test tests[NUM_TESTS] = {
		{a_s1, a_s2, a_control, a_comment},
        {b_s1, b_s2, b_control, b_comment},
        {c_s1, c_s2, c_control, c_comment},
        {d_s1, d_s2, d_control, d_comment},
        {e_s1, e_s2, e_control, e_comment},
        {f_s1, f_s2, f_control, f_comment},
        {g_s1, g_s2, g_control, g_comment},
        {h_s1, h_s2, h_control, h_comment}
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
