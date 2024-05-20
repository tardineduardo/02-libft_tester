/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/05/20 20:03:48 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

char    **ft_split(char const *s, char c);

typedef struct
{
    char const  *s;
    char        c;
    const char  *control[5];
    char        *comment;
} Test;

int ft_are_string_arrays_equal(char **array1, const char **array2)
{
    while (*array1 != NULL && *array2 != NULL)
    {
        if (strcmp(*array1, *array2) != 0) 
        {
            return (0);
        }
        array1++;
        array2++;
    }
    return (*array1 == NULL && *array2 == NULL);
}

void ft_print_string_arrays(char **array)
{
    printf("\"");
    while (*array != NULL)
    {
        printf("%02x ", **array);
        array++;
    }
    printf("\"");
}

void run_test(Test test, int *fail_counter)
{
    char **result;

    // IF POINTERS ARE NULL
    if (test.s == NULL)
    {
        pid_t pid = fork();
        if (pid == 0) // child process
        {
            result = ft_split(test.s, test.c);
            printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
            printf("ft_split() did not exit/crash when s was NULL.\n");
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
                printf("ft_split() exited/crashed as expected when s was NULL.\n");
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
        result = ft_split(test.s, test.c);

        if (result == NULL && test.control[0] == NULL)
        {
            printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
            printf("(%s)\ts: \"%s\", char: \"%c\"", test.comment, test.s, test.c);
            printf("\texpected: \"NULL1\"\tresult: \"NULL2\"\n");
        }
        else if (result != NULL && test.control[0] == NULL)
        {
            printf(COLOR_PINK "[[[FAIL]]] " COLOR_RESET);
            printf("(%s)\ts: \"%s\", char: \"%c\"", test.comment, test.s, test.c);
            printf("\texpected: \"NULL3\"\tresult: ");
            ft_print_string_arrays(result);
            printf("\n");
            (*fail_counter)++;
        }
        else if (result == NULL && test.control[0] != NULL)
        {
            printf(COLOR_PINK "[[[FAIL]]] " COLOR_RESET);
            printf("(%s)\ts: \"%s\", char: \"%c\"", test.comment, test.s, test.c);
            printf("\texpected: ");
            ft_print_string_arrays((char **)test.control);
            printf("\tresult: \"NULL4\"\n");
            (*fail_counter)++;
        }
        else if (ft_are_string_arrays_equal(result, test.control))
        {
            printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
            printf("(%s)\ts: \"%s\", char: \"%c\"", test.comment, test.s, test.c);
            printf("\texpected: ");
            ft_print_string_arrays((char **)test.control);
            printf("\tresult: ");
            ft_print_string_arrays(result);
            printf("\n");
        }
        else
        {
            printf(COLOR_PINK "[[[FAIL]]] " COLOR_RESET);
            printf("(%s)\ts: \"%s\", char: \"%c\"", test.comment, test.s, test.c);
            printf("\texpected: ");
            ft_print_string_arrays((char **)test.control);
            printf("\tresult: ");
            ft_print_string_arrays(result);
            printf("\n");
            (*fail_counter)++;
        }
    }
}

#define NUM_TESTS 6

int main(void)
{
    int *fail_counter = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *fail_counter = 0;

    const char *a_s = "this-is-a-test";
    char a_c = '-';
    char *a_comment = "Normal string";

    const char *b_s = "thisisatest";
    char b_c = '-';
    char *b_comment = "No delimiter";

    const char *c_s = "";
    char c_c = '-';
    char *c_comment = "Empty string";

    const char *d_s = "-----";
    char d_c = '-';
    char *d_comment = "Only delimiters";

    const char *e_s = "-this-is-a-test-";
    char e_c = '-';
    char *e_comment = "Delimiters at start and end";

    const char *f_s = "this--is-a--test";
    char f_c = '-';
    char *f_comment = "Consecutive delimiters";


    Test tests[NUM_TESTS] = {
        {a_s, a_c, {"this", "is", "a", "test", NULL}, a_comment},
        {b_s, b_c, {"thisisatest", NULL, NULL, NULL, NULL}, b_comment},
        {c_s, c_c, {"", NULL, NULL, NULL, NULL}, c_comment},
        {d_s, d_c, {"", NULL, NULL, NULL, NULL}, d_comment},
        {e_s, e_c, {"this", "is", "a", "test", NULL}, e_comment},
        {f_s, f_c, {"this", "is", "a", "test", NULL}, f_comment},
    };

    printf(COLOR_BLUE ">TESTING ft_split------------------------------------------------------------------------\n" COLOR_RESET);
        
    // RUNNING TESTS
    for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], fail_counter);

    // SAVING RESULTS
    if (*fail_counter > 0)
        ft_save_results("ft_split: FAIL");
    else
        ft_save_results("ft_split: OK");

    printf("\n\n");
    return (0);
}