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
	void	*s;
	int		c;
	size_t	size;
	char	*comment;
} Test;

void *ft_memchr(const void *s, int c, size_t n);

// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
	printf("%s", test.comment);

	void *expected = memchr(test.s, test.c, test.size);
	void *result = ft_memchr(test.s, test.c, test.size);

	if (result == expected)
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


#define NUM_TESTS 6

int main(void)
{
    int fail_counter = 0;

	char s1[40] = {"1234567890123456789012345678901a34567890"};
	char s2[40] = {"123456789012345a789012345678901a34567890"};
	char s3[40] = {"0000000000000000000000000000000001000000"};
	char s4[40] = {"0000000000000000000x00000000000001000000"};
	char s5[40] = {"000000000000000000000000000000000100000s"};
	char s6[40] = {"0000000000000020000000000000000001000000"};

Test tests[NUM_TESTS] = {
{s1, 'a', 2, "s = {\"1234567890123456789012345678901a34567890\"} |  c = 'a' | n = 2"},
{s2, 'a', 40, "s = {\"123456789012345a789012345678901a34567890\"} |  c = 'a' | n = 40"},
{s3, '1', 20, "s = {\"0000000000000000000000000000000001000000\"} |  c = '1' | n = 20"},
{s4, 'x', 30, "s = {\"0000000000000000000x00000000000001000000\"} |  c = 'x' | n = 30"},
{s5, 's', 39, "s = {\"000000000000000000000000000000000100000s\"} |  c = 's' | n = 39"},
{s6, 'a', 2, "s = {\"0000000000000020000000000000000001000000\"} |  c = 'a' | n = 2"}
};

	printf(COLOR_BLUE ">TESTING ft_memchr------------------------------------------------------------------------\n" COLOR_RESET);

	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_memchr: FAIL");
    else
        ft_save_results("ft_memchr: OK");

    printf("\n");
    return (0);
}
