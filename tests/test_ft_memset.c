/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/29 23:50:30 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void *ft_memset(void *s, int c, size_t n);

typedef struct
{
    void	*array_before;
    void	*array_after_result;
    void	*array_after_expected;
	int		value;
	size_t	size;
    char	*comment;
    void	*result;
} Test;

static int	compare_arrays(char *expected, char *result, size_t n) 
{
	size_t a = 0;
	while(a < n) 
	{
		if (expected[a] != result[a])
			return (1);
		a++;
	}
	return (0);
}

static void	print_array_hex(void *array, size_t n) 
{
	size_t a;
	char *casted = (char*)array;
	for(a = 0; a < n; a++)
		printf("%02x ", casted[a]);
}

// static void	print_array(void *array, size_t n) 
// {
// 	size_t a;
// 	char *casted = (char*)array;
// 	printf("\"");
// 	for(a = 0; a < n; a++)
// 		printf("%c", casted[a]);
// 	printf("\"");
// }

// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
    void *expected = memset(test.array_after_expected, test.value, test.size);

	printf("%s\n", test.comment);

	printf("source in HEX:\t\t\t");
	print_array_hex(test.array_before, 35);
	printf("\n");
	printf("expected output in HEX:\t\t");
	print_array_hex(expected, 35);
	printf("\n");
	printf("result output in HEX:\t\t");
	print_array_hex(test.result, 35);
	printf("\n");
	if ((compare_arrays(expected, test.result, test.size) == 0))
	{
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	}
	else
	{
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
		(*fail_count)++;
	}

    printf("compare_arrays = %d | Expected = 0\n\n\n", compare_arrays(expected, test.result, test.size));
}



#define NUM_TESTS 5

int main(void)
{

    int fail_counter = 0;

	char a_before[35] = {"Kelly, can you handle this?"};
	char b_before[35] = {"Michelle, can you handle this?"};
	char c_before[35] = {"Beyonce, can you handle this?"};
	char d_before[35] = {"I dont think they can handle this!"};

	char a_after_result[35] = {"Kelly, can you handle this?"};
	char b_after_result[35] = {"Michelle, can you handle this?"};
	char c_after_result[35] = {"Beyonce, can you handle this?"};
	char d_after_result[35] = {"I dont think they can handle this!"};

	char a_after_expected[35] = {"Kelly, can you handle this?"};
	char b_after_expected[35] = {"Michelle, can you handle this?"};
	char c_after_expected[35] = {"Beyonce, can you handle this?"};
	char d_after_expected[35] = {"I dont think they can handle this!"};
	
	char e_before[35] = {"This should remain unchanged."};
	char e_after_result[35] = {"This should remain unchanged."};
	char e_after_expected[35] = {"This should remain unchanged."};

	Test tests[NUM_TESTS] = {
	{a_before, a_after_result, a_after_expected, '*', 27, "char s[35] = {\"Kelly, can you handle this?\"} ft|memset(s, '*', 27)", ft_memset(a_after_result, '*', 27)},
	{b_before, b_after_result, b_after_expected, '1', 4, "char s[35] = {\"Michelle, can you handle this?\"} ft|memset(s, '1', 4)", ft_memset(b_after_result, '1', 4)},
	{c_before, c_after_result, c_after_expected, 's', 10, "char s[35] = {\"Beyonce, can you handle this?\"} ft|memset(s, 's', 10)", ft_memset(c_after_result, 's', 10)},
	{d_before, d_after_result, d_after_expected, 0, 35, "char s[35] = {\"I dont think they can handle this!\"} ft|memset(s, 0, 35)", ft_memset(d_after_result, 0, 35)},
	{e_before, e_after_result, e_after_expected, '*', 0, "char s[35] = {\"This should remain unchanged.\"} ft|memset(s, '*', 0)", ft_memset(e_after_result, '*', 0)},
	};

	printf(COLOR_BLUE ">TESTING ft_memset------------------------------------------------------------------------\n" COLOR_RESET);


	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_memset: FAIL");
    else
        ft_save_results("ft_memset: OK");


    printf("\n");
    return (0);
}

