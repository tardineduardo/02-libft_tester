/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/05/20 19:00:59 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"


char	*ft_strnstr(const char *big, const char *little, size_t len);

typedef struct
{
	const char	*big;
	const char	*little;
	size_t		len;
	const char		*control;
	char		*comment;
} Test;

// Function to execute and print test results
void run_test(Test test, int *fail_counter)
{
    char *result;

    // IF POINTERS ARE NULL
    if (test.big == NULL || test.little == NULL)
    {
        pid_t pid = fork();
        if (pid == 0) // child process
        {
            result = ft_strnstr(test.big, test.little, test.len);
            if (result == NULL)
            {
                printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
                printf("ft_strnstr() returned NULL when big and/or little were NULL.\n");
            }
            else
            {
                printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
                printf("ft_strnstr() did not return NULL when big and/or little were NULL.\n");
                (*fail_counter)++;
            }
            exit(0);  // Ensure child process exits after execution
        }
        else if (pid > 0) // parent process
        {
            int status;
            waitpid(pid, &status, 0); // wait for child process to finish
            if (WIFSIGNALED(status))
            {
                printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
                printf("ft_strnstr() exited/crashed as expected when big and little were NULL.\n");
            }
        }
        else // fork failed
        {
            perror("fork");
            exit(1);
        }
    }
    // IF LITTLE IS LONGER THAN BIG
    else if (strlen(test.big) < strlen(test.little))
    {
        pid_t pid = fork();
        if (pid == 0) // child process
        {
            result = ft_strnstr(test.big, test.little, test.len);
            if (result == NULL)
            {
                printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
                printf("ft_strnstr() returned NULL when little is longer than big.\n");
            }
            else
            {
                printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
                printf("ft_strnstr() did not return NULL when little is longer than big.\n");
                (*fail_counter)++;
            }
            exit(0);  // Ensure child process exits after execution
        }
        else if (pid > 0) // parent process
        {
            int status;
            waitpid(pid, &status, 0); // wait for child process to finish
            if (WIFSIGNALED(status))
            {
                printf(COLOR_PINK "[[[FAIL]]] " COLOR_RESET);
                printf("ft_strnstr() exited when little is longer than big. It should return NULL.\n");
            }
        }
        else // fork failed
        {
            perror("fork");
            exit(1);
        }
    }
    // IF LITTLE IS LONGER THAN LEN
    else if (strlen(test.little) > test.len)
    {
        pid_t pid = fork();
        if (pid == 0) // child process
        {
            result = ft_strnstr(test.big, test.little, test.len);
            if (result == NULL)
            {
                printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
                printf("ft_strnstr() returned NULL when little is longer than len.\n");
            }
            else
            {
                printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
                printf("ft_strnstr() did not return NULL when little is longer than len.\n");
                (*fail_counter)++;
            }
            exit(0);  // Ensure child process exits after execution
        }
        else if (pid > 0) // parent process
        {
            int status;
            waitpid(pid, &status, 0); // wait for child process to finish
            if (WIFSIGNALED(status))
            {
                printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
                printf("ft_strnstr() exited when little is longer than len. It should return NULL.\n");
                (*fail_counter)++;
            }
        }
        else // fork failed
        {
            perror("fork");
            exit(1);
        }
    }
    // NORMAL CASE
    else
    {
        result = ft_strnstr(test.big, test.little, test.len);

        if (result == NULL && test.control == NULL)
        {
            printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
   	   		printf("(%s)\tbig: \"%s\", little: \"%s\", len: %zu", test.comment, test.big, test.little, test.len);
        	printf("\texpected:\"NULL\"\tresult:\"NULL\"");
        	printf("\n");
        }
        else if (result != NULL && test.control == NULL)
        {
            printf(COLOR_PINK "[[[FAIL]]] " COLOR_RESET);
   	   		printf("(%s)\tbig: \"%s\", little: \"%s\", len: %zu", test.comment, test.big, test.little, test.len);
        	printf("\texpected:\"NULL\"\tresult:\"%s\"", result);
        	printf("\n");
            (*fail_counter)++;
        }
        else if (result == NULL && test.control != NULL)
        {
            printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
   	   		printf("(%s)\tbig: \"%s\", little: \"%s\", len: %zu", test.comment, test.big, test.little, test.len);
        	printf("\texpected:\"%s\"\tresult:\"NULL\"", test.control);
        	printf("\n");
            (*fail_counter)++;
        }
		else if (strcmp(result, test.control) == 0)
        {
            printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
   	   		printf("(%s)\tbig: \"%s\", little: \"%s\", len: %zu", test.comment, test.big, test.little, test.len);
        	printf("\texpected:\"%s\"\tresult:\"%s\"", test.control, result);
        	printf("\n");
        }
		else if (strcmp(result, test.control) != 0)
        {
            printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
   	   		printf("(%s)\tbig: \"%s\", little: \"%s\", len: %zu", test.comment, test.big, test.little, test.len);
        	printf("\texpected:\"%s\"\tresult:\"%s\"", test.control, result);
        	printf("\n");
        }
    }
}

#define NUM_TESTS 12

int main(void)
{
    int *fail_counter = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *fail_counter = 0;

    const char  *a_big = "ooooxxxooo";
    const char  *a_little = "xx";
    size_t      a_len = 10;
    const char  *a_control = &a_big[4];
    char        *a_comment = "Normal string";

    const char  *b_big = "oaaa";
    const char  *b_little = "aaaaaaa";
    size_t      b_len = 10;
    const char  *b_control = NULL;
    char        *b_comment = "Little is longer than big";

    const char  *c_big = "aaaaaaaa";
    const char  *c_little = "aaaaaaa";
    size_t      c_len = 2;
    const char  *c_control = NULL;
    char        *c_comment = "L is longer than len";

    const char  *d_big = "";
    const char  *d_little = "a";
    size_t      d_len = 1;
    const char  *d_control = NULL;
    char        *d_comment = "Big is empty";

    const char  *e_big = "a";
    const char  *e_little = "";
    size_t      e_len = 1;
    const char  *e_control = &e_big[0];
    char        *e_comment = "Little is empty";

    const char  *f_big = "";
    const char  *f_little = "";
    size_t      f_len = 0;
    const char  *f_control = &f_big[0];
    char        *f_comment = "B and L are empty";

    const char  *g_big = "hello world";
    const char  *g_little = "hello";
    size_t      g_len = 11;
    const char  *g_control = &g_big[0];
    char        *g_comment = "L at beginning of B";

    const char  *h_big = "hello world";
    const char  *h_little = "world";
    size_t      h_len = 11;
    const char  *h_control = &h_big[6];
    char        *h_comment = "L at end of B";

    const char  *i_big = "rio de janeiro";
    const char  *i_little = "de";
    size_t      i_len = 11;
    const char  *i_control = &i_big[4];
    char        *i_comment = "L in middle of B";

    const char  *j_big = "abcdef";
    const char  *j_little = "xyz";
    size_t      j_len = 6;
    const char  *j_control = NULL;
    char        *j_comment = "L not found in B";

    const char  *k_big = "123456";
    const char  *k_little = "234";
    size_t      k_len = 3;
    const char  *k_control = NULL;
    char        *k_comment = "L not within len";

    const char  *l_big = "special $*chars";
    const char  *l_little = "$*";
    size_t      l_len = 15;
    const char  *l_control = &l_big[8];
    char        *l_comment = "Special chars";

    Test tests[NUM_TESTS] = {
        {a_big, a_little, a_len, a_control, a_comment},
        {b_big, b_little, b_len, b_control, b_comment},
        {c_big, c_little, c_len, c_control, c_comment},
        {d_big, d_little, d_len, d_control, d_comment},
        {e_big, e_little, e_len, e_control, e_comment},
        {f_big, f_little, f_len, f_control, f_comment},
        {g_big, g_little, g_len, g_control, g_comment},
        {h_big, h_little, h_len, h_control, h_comment},
        {i_big, i_little, i_len, i_control, i_comment},
        {j_big, j_little, j_len, j_control, j_comment},
        {k_big, k_little, k_len, k_control, k_comment},
        {l_big, l_little, l_len, l_control, l_comment}
    };

	printf(COLOR_BLUE ">TESTING ft_strnstr------------------------------------------------------------------------\n" COLOR_RESET);
		
	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], fail_counter);

	// SAVING RESULTS
    if (*fail_counter > 0)
        ft_save_results("ft_strnstr: FAIL");
    else
        ft_save_results("ft_strnstr: OK");

    printf("\n\n");
    return (0);
}
