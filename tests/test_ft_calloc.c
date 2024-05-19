/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:52:03 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void *ft_calloc(size_t nmemb, size_t size);

typedef struct
{
    size_t nmemb;
    size_t size;
    size_t control_size;
    char *comment;
} Test;

// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
    unsigned char *result = ft_calloc(test.nmemb, test.size);
    if (result)
    {
        for (size_t i = 0; i < test.control_size; i++)
        {
            if (result[i] != 0)
            {
                printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
                printf("(%s)\tnmemb: %zu, size: %zu\tresult should be all zeroes\n", test.comment, test.nmemb, test.size);
                (*fail_count)++;
                return;
            }
        }
        printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
    }
    else
    {
        if (test.nmemb == 0 || test.size == 0 || test.nmemb > SIZE_MAX / test.size)
        {
            printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
        }
        else
        {
            printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
            (*fail_count)++;
        }
    }
    printf("(%s)\tnmemb: %zu, size: %zu\n", test.comment, test.nmemb, test.size);
}

#define NUM_TESTS 1

int main(void)
{
    int fail_counter = 0;

    Test tests[NUM_TESTS] = {
        {5, sizeof(int), 5 * sizeof(int), "Normal case"}
//        {0, sizeof(int), 0, "Zero nmemb, should return NULL."},
//        {5, 0, 0, "Zero size, should return NULL."},
//        {SIZE_MAX, 2, 0, "Overflow case, should return NULL."},
//        {5, sizeof(long), 5 * sizeof(long), "Valid long allocation"}
    };

    printf(COLOR_BLUE "\n>TESTING ft_calloc------------------------------------------------------------------------\n" COLOR_RESET);
    printf("Comment.\n\n");
    
    // RUNNING TESTS
    for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

    // SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_calloc: FAIL");
    else
        ft_save_results("ft_calloc: OK");

    printf("\n\n");
    return (0);
}