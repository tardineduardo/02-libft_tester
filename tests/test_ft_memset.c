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

static void	print_array(void *array, size_t n) 
{
	size_t a;
	char *casted = (char*)array;
	printf("\"");
	for(a = 0; a < n; a++)
		printf("%c", casted[a]);
	printf("\"");
}

// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
    void *expected = memset(test.array_after_expected, test.value, test.size);

	print_array(test.array_before, 45);
	printf("\n");
	print_array_hex(test.array_before, 45);
	printf("\n");
	print_array(expected, 45);
	printf("\n");
	print_array_hex(expected, 45);
	printf("\n");
	print_array(test.result, 45);
	printf("\n");
	print_array_hex(test.result, 45);

	if ((compare_arrays(expected, test.result, test.size) == 0))
	{
		printf(COLOR_GREEN "\n[[[PASS]]] " COLOR_RESET);
	}
	else
	{
		printf(COLOR_RED "\n[[[FAIL]]] " COLOR_RESET);
		(*fail_count)++;
	}

    printf("(%s) compare_arrays = %d | Expected = 0\n\n", test.comment, compare_arrays(expected, test.result, test.size));
}


#define NUM_TESTS 5

int main(void)
{

    int fail_counter = 0;

	char a_before[45] = {"Kelly, can you handle this?"};
	char b_before[45] = {"Michelle, can you handle this?"};
	char c_before[45] = {"Beyonce, can you handle this?"};
	char d_before[45] = {"I dont think they can handle this!"};

	char a_after_result[45] = {"Kelly, can you handle this?"};
	char b_after_result[45] = {"Michelle, can you handle this?"};
	char c_after_result[45] = {"Beyonce, can you handle this?"};
	char d_after_result[45] = {"I dont think they can handle this!"};

	char a_after_expected[45] = {"Kelly, can you handle this?"};
	char b_after_expected[45] = {"Michelle, can you handle this?"};
	char c_after_expected[45] = {"Beyonce, can you handle this?"};
	char d_after_expected[45] = {"I dont think they can handle this!"};
	
	char e_before[45] = {"This should remain unchanged."};
	char e_after_result[45] = {"This should remain unchanged."};
	char e_after_expected[45] = {"This should remain unchanged."};

	Test tests[NUM_TESTS] = {
	{a_before, a_after_result, a_after_expected, '*', 27, "ft|memset(a_after_result, '*', 27)", ft_memset(a_after_result, '*', 27)},
	{b_before, b_after_result, b_after_expected, '*', 4, "ft|memset(b_after_result, '1', 4)", ft_memset(b_after_result, '*', 4)},
	{c_before, c_after_result, c_after_expected, '*', 46, "ft|memset(c_after_result, 's', 46)", ft_memset(c_after_result, '*', 46)},
	{d_before, d_after_result, d_after_expected, 0, 45, "ft|memset(d_after_result, 0, 45)", ft_memset(d_after_result, 0, 45)},
	{e_before, e_after_result, e_after_expected, '*', 0, "ft|memset(e_after_result, '*', 0)", ft_memset(e_after_result, '*', 0)},
	};

	printf(">>>>> TESTING ft_memset\n");
	// printf("XXXXXXXXXXXX \n");

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

