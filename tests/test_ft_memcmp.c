/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:52:03 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

typedef struct
{
	void	*s1;
	void	*s2;
	size_t	size;
	char	*comment;
} Test;

int ft_memcmp(const void *s1, const void *s2, size_t n);

// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
	printf(COLOR_YELLOW "%s" COLOR_RESET, test.comment);

	int expected = memcmp(test.s1, test.s2, test.size);
	int result = ft_memcmp(test.s1, test.s2, test.size);

	printf("expected = %d | result = %d", expected, result);

	if (result == 0 && expected == 0)
	{
		printf(COLOR_GREEN "\n[[[PASS]]]\n" COLOR_RESET);
	}
	else if (result > 0 && expected > 0)
	{
		printf(COLOR_GREEN "\n[[[PASS]]]\n" COLOR_RESET);
	}
	else if (result < 0 && expected < 0)
	{
		printf(COLOR_GREEN "\n[[[PASS]]]\n" COLOR_RESET);
	}
	else
	{
		printf(COLOR_RED "\n[[[FAIL]]]\n" COLOR_RESET);
		(*fail_count)++;
	}
    printf("\n");

}


#define NUM_TESTS 4

int main(void)
{
    int fail_counter = 0;

	char a_s1[25] = {"1234567890\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char a_s2[25] = {"1234567890\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};

	char b_s1[25] = {"1234567890\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char b_s2[25] = {"12345abcde\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};

	char c_s1[25] = {"1234567890\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char c_s2[25] = {"12345abcde\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};

	char d_s2[25] = {"thelazybrownfoxthinks\0\0\0\0"};
	char *d_s1 = &d_s2[16];


Test tests[NUM_TESTS] = {
{
    a_s1,
    a_s2,
    2,
    "s1 = {\"1234567890\"} | s2 = {\"1234567890\"} | n = 2\n",
    },
{
    b_s1,
    b_s2,
    7,
    "s1 = {\"1234567890\"} | s2 = {\"12345abcde\"} | n = 7\n",
    },
{
    c_s1,
    c_s2,
    4,
    "s1 = {\"1234567890\"} | s2 = {\"12345abcde\"} | n = 4\n",
    },
{
    d_s1,
    d_s2,
    4,
    "s1 = {\"thelazybrownfoxthinks\"} | s2 = dest[16]\"} n = 4\n",
    }
};

	printf(COLOR_BLUE ">TESTING ft_memcmp------------------------------------------------------------------------\n" COLOR_RESET);
	printf("\"The memcmp() function returns an integer less than, equal to, or greater than zero if the\nfirst n bytes of s1 is found, respectively, to be less than, to match, or be greater than\nthe first n bytes of s2\". The memcmp function, defined in the string.h library, compares two blocks of memory (typically strings) and returns an integer that signifies the relationship between the corresponding bytes in those blocks. However, the specific value returned for non-zero comparisons is implementation-defined, meaning it can vary depending on the C compiler and system architecture.\n\n");

	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_memcmp: FAIL");
    else
        ft_save_results("ft_memcmp: OK");

    printf("\n");
    return (0);
}
