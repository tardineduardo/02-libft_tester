/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:52:03 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void ft_add_one(unsigned int i, char *s)
{
	(void)i;
	*s = *s + 1;
}


void ft_striteri(char *s, void (*f)(unsigned int, char*));

typedef struct
{
	char	*s;
	char	*s_log;
	void	(*f)(unsigned int, char*);
	char	*control;
	char	*comment;
} Test;


// Function to execute and print test results
void run_test(Test test, int *fail_counter)
{
    if (test.s == NULL)
    {
        pid_t pid = fork();
        if (pid == 0) // child process
        {
            ft_striteri(test.s, test.f);
            printf(COLOR_YELLOW "[[[FAIL]]] " COLOR_RESET);
            printf("ft_striteri() did not exit when string was NULL. It should exit instead.\n");
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
                printf("ft_striteri() exited as expected when s1 and s2 were NULL.\n");
            }
        }
        else // fork failed
        {
            perror("fork");
            exit(1);
        }
    }

    else if (test.f == NULL)
    {
        pid_t pid = fork();
        if (pid == 0) // child process
        {
            ft_striteri(test.s, test.f);
            printf(COLOR_YELLOW "[[[FAIL]]] " COLOR_RESET);
            printf("ft_striteri() didn't exit when pointer to function was NULL. It should exit instead.\n");
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
                printf("ft_striteri() exited as expected when one string was valid but the other was NULL.\n");
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
		ft_striteri(test.s, test.f);

		if (strcmp(test.s, test.control) == 0)
		{
			printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
		}
		else
		{
			printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
			(*fail_counter)++;
		}
		printf("(%s)\ts: \"%s\"", test.comment, test.s);
		printf("\texpected:\"%s\"\tresult:\"%s\"", test.control, test.s);
		printf("\n");
	}
}

#define NUM_TESTS 4

int main(void)
{
    int fail_counter = 0;

	char	a_s[] = "abc";
	char	a_s_log[] = "abc";
	void	(*a_f) = ft_add_one;
	char	*a_control = "bcd";
	char	*a_comment = "Normal string, applying ft_add_one()";

	char	b_s[] = "";
	char	b_s_log[] = "";
	void	(*b_f) = ft_add_one;
	char	*b_control = "";
	char	*b_comment = "Empty string, applying ft_add_one()";

	char	*c_s = NULL;
	char	*c_s_log = "a";
	void	(*c_f) = ft_add_one;
	char	*c_control = "a";
	char	*c_comment = "NULL";

	char	*d_s = "abcde";
	char	*d_s_log = "abcde";
	void	(*d_f) = NULL;
	char	*d_control = "a";
	char	*d_comment = "NULL";


	Test tests[NUM_TESTS] = {
		{a_s, a_s_log, a_f, a_control, a_comment},
		{b_s, b_s_log, b_f, b_control, b_comment},
		{c_s, c_s_log, c_f, c_control, c_comment},						
		{d_s, d_s_log, d_f, d_control, d_comment}	
	};

	printf(COLOR_BLUE ">TESTING ft_striteri------------------------------------------------------------------------\n" COLOR_RESET);
		
	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_striteri: FAIL");
    else
        ft_save_results("ft_striteri: OK");

    printf("\n\n");
    return (0);
}
