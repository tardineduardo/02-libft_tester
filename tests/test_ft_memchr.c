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

	void *expected = memchr(test.s, test.c, test.size);
	void *result = ft_memchr(test.s, test.c, test.size);



	if (result == expected)
	{
		printf(COLOR_GREEN "\n[[[PASS]]] " COLOR_RESET);
	}
	else
	{
		printf(COLOR_RED "\n[[[FAIL]]] " COLOR_RESET);
		(*fail_count)++;
	}

	printf("%s", test.comment);
    printf(" - Pointer address: expected = %p, result = %p", (void *)expected, (void *)result);


}


#define NUM_TESTS 6

int main(void)
{
    int fail_counter = 0;

	char s1[30] = {"123456789012345678901234567890"};
	char s2[30] = {"123456789012345a78901a34567890"};
	char s3[30] = {"000000000000000000000000000@00"};
	char s4[30] = {"0000000000000000000x0000000000"};
	char s5[30] = {"00000000000000000000000000000s"};
	char s6[30] = {"0a0000000000002000000000000000"};

Test tests[NUM_TESTS] = {
{s1, 'a', 2, "s = {\"123456789012345678901234567890\"}, c = 'a', n = 2"},
{s2, 'a', 30, "s = {\"123456789012345a78901a34567890\"}, c = 'a', n = 30"},
{s3, '@', 30, "s = {\"000000000000000000000000000@00\"}, c = '@', n = 30"},
{s4, 'x', 30, "s = {\"0000000000000000000x0000000000\"}, c = 'x', n = 30"},
{s5, 's', 31, "s = {\"00000000000000000000000000000s\"}, c = 's', n = 31"},
{s6, 'a', 2, "s = {\"0a0000000000002000000000000000\"}, c = 'a', n = 2"}
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

    printf("\n\n\n");
    return (0);
}
