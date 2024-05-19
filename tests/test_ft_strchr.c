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
	const char	*s;
	int			c;
	char		*comment;
} Test;

char	*ft_strchr(const char *str, int c);


// Function to execute and print test results
void run_test(Test test, int *fail_count)
{

	char *expected = strchr((char *)test.s, test.c);
	char *result = ft_strchr((char *)test.s, test.c);



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
    printf(" - Pointer address: expected = %p, result = %p", (char *)expected, (char *)result);


}


#define NUM_TESTS 7

int main(void)
{
    int fail_counter = 0;


	const char *s1 = "1234567";
	const char *s2 = "1234567";
	const char *s3 = "1234567";
	const char *s4 = "s";
	const char *s5 = "s";
	const char *s6 = "";
	const char *s7 = "123a567";


Test tests[NUM_TESTS] = {
{s1, '1', "s = {\"1234567\"}, c = '1'"},
{s2, '7', "s = {\"1234567\"}, c = '7'"},
{s3, '8', "s = {\"1234567\"}, c = '8'"},
{s4, 's', "s = {\"s\"}, c = 's'"},
{s5, '@', "s = {\"s\"}, c = '@'"},
{s6, 'a', "s = {\"\"}, c = 'a'"},
{s7, 'a' + 256, "s = {\"123a56\"}, c = 'a' + 256"},


};

	printf(COLOR_BLUE ">TESTING ft_strchr------------------------------------------------------------------------\n" COLOR_RESET);
	printf("The standard functions strchr() and strchr() cast the int parameter as unsigned char.\nTo reproduce their behaviour, values biger than 255 should wrap around to the start of the range.");
	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_strchr: FAIL");
    else
        ft_save_results("ft_strchr: OK");

    printf("\n\n\n");
    return (0);
}
