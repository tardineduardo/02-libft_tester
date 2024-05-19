/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:52:03 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

char *ft_substr(char const *s, unsigned int start, size_t len);

typedef struct
{
	const char		*s;
	unsigned int	start;
	size_t			len;
	char			*control;
	char			*comment;
} Test;


// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
    char *result;

    if (test.s == NULL)
    {
        pid_t pid = fork();
        if (pid == 0) // child process
        {
            result = ft_substr(test.s, test.start, test.len);
            // If the function returns instead of exiting, it's a failure
            printf(COLOR_YELLOW "[[[FAIL]]] " COLOR_RESET);
            printf("ft_substr() did not exit in error when a pointer to NULL was passed as a parameter.\n");
			(*fail_count)++;
            exit(0);
        }
        else if (pid > 0) // parent process
        {
            int status;
            waitpid(pid, &status, 0); // wait for child process to finish
            if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
            {
                printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
                printf("ft_substr() exited in error when a pointer to NULL was passed as a parameter.\n");
            }
        }
        else // fork failed
        {
            perror("fork");
            exit(1);
        }
    }
    else if (test.start > strlen(test.s))
    {
        pid_t pid = fork();
        if (pid == 0) // child process
        {
            result = ft_substr(test.s, test.start, test.len);
            // If the function returns instead of exiting, it's a failure
            printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
            printf("ft_substr() did not exit in error when start > strlen(s).\n");
            (*fail_count)++;
            exit(0);
        }
        else if (pid > 0) // parent process
        {
            int status;
            waitpid(pid, &status, 0); // wait for child process to finish
            if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
            {
                printf(COLOR_YELLOW "[[[PASS]]] " COLOR_RESET);
                printf("ft_substr() exited in error when start > strlen(s).\n");
            }
        }
        else
        {
            perror("fork");
            exit(1);
        }
    }
    else
    {
        result = ft_substr(test.s, test.start, test.len);
        if ((strcmp(result, test.control) == 0))
            printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);    
        else
        {
            printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
            (*fail_count)++;
        }
        printf("(%s)\ts == \"%s\"", test.comment, test.s);
        printf("\texpected:\"%s\"\tresult:\"%s\"", test.control, result);
        printf("\n");
    }
}

#define NUM_TESTS 6

int main(void)
{
    int fail_counter = 0;

	const char		*a_s = "abcdefghij";
	unsigned int 	a_start = 3;
	size_t			a_len = 3;
	char			*a_control = "def";
	char			*a_comment = "start and lenght fit normal limits.";
	
	const char		*b_s = "abcdefghij";
	unsigned int 	b_start = 0;
	size_t			b_len = 10;
	char			*b_control = "abcdefghij";
	char			*b_comment = "Minimum start index, max len possible.";

	const char		*c_s = "abcdefghij";
	unsigned int 	c_start = 9;
	size_t			c_len = 5;
	char			*c_control = "j";
	char			*c_comment = "len to copy exceeds end of src string.";

	const char		*d_s = "abcdefghij";
	unsigned int 	d_start = 9;
	size_t			d_len = 0;
	char			*d_control = "";
	char			*d_comment = "Len 0 returns empty string with \'\\0\'.";

	const char		*e_s = "abcdefghij";
	unsigned int 	e_start = 20;
	size_t			e_len = 3;
	char			*e_control = "";
	char			*e_comment = "start exceeds max index, should return NULL.";

	const char		*f_s = NULL;
	unsigned int 	f_start = 9;
	size_t			f_len = 0;
	char			*f_control = "";
	char			*f_comment = "";


	Test tests[NUM_TESTS] = {
		{a_s, a_start, a_len, a_control, a_comment},
		{b_s, b_start, b_len, b_control, b_comment},
		{c_s, c_start, c_len, c_control, c_comment},
		{d_s, d_start, d_len, d_control, d_comment},
		{e_s, e_start, e_len, e_control, e_comment},
		{f_s, f_start, f_len, f_control, f_comment},
	
	};

	printf(COLOR_BLUE "\n>TESTING ft_substr------------------------------------------------------------------------\n" COLOR_RESET);
	printf("Comment.\n\n");
		
	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_substr: FAIL");
    else
        ft_save_results("ft_substr: OK");

    printf("\n\n");
    return (0);
}
