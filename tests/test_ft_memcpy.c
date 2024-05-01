/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:52:03 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void *ft_memcpy(void *dest, const void *src, size_t n);

typedef struct
{
	void	*array_original;
	void	*array_destiny;
	void 	*array_result_original_before;
	void	*array_result_original_after;
	void 	*array_result_destiny_after;
	void 	*array_expected_original_before;
	void 	*array_expected_original_after;
	void 	*array_expected_destiny_after;
	void 	*result_pointer_log;
	size_t	size;
    char	*comment;
    void	*result;
} Test;


static char	are_sources_intact(char *expected, char *result, size_t n) 
{
  size_t a = 0;
  while(a < n) 
  	{
    	if (expected[a] != result[a])
			return ('N');
		a++;
  	}
  	return ('Y');
}


static char	are_arrays_equal(char *expected, char *result, size_t n) 
{
  size_t a = 0;
  while(a < n) 
  	{
    	if (expected[a] != result[a])
			return ('N');
		a++;
  	}
  	return ('Y');
}

static char	are_pointers_equal(void *expected, void *result) 
{
	char *a = (char *)expected;
	char *b = (char *)result;
   	if (a != b)
		return ('N');
	else	
	  	return ('Y');
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
    void *expected = memcpy(test.array_expected_destiny_after, test.array_expected_original_after, test.size);

	printf("%s\n", test.comment);

	printf("source in HEX:\t\t\t");
	print_array_hex(test.array_original, 35);
	printf("\n");
	printf("dest in HEX:\t\t\t");
	print_array_hex(test.array_destiny, 35);
	printf("\n");

	printf("source result in HEX:\t\t");
	print_array_hex(test.array_result_original_after, 35);
	printf("\n");
	printf("source expected in HEX:\t\t");
	print_array_hex(test.array_expected_original_after, 35);
	printf("\n");

	printf("dest result in HEX: \t\t");
	print_array_hex(test.array_result_destiny_after, 35);
	printf("\n");
	printf("dest expected in HEX:\t\t");
	print_array_hex(test.array_expected_destiny_after, 35);
	printf("\n");

	printf("Is the source data intact?\t\t\t(Expected: Y) ---> %c\n", are_sources_intact(test.array_expected_original_after, test.array_result_original_after, test.size));
	printf("Is the target data what it's supposed to be?\t(Expected: Y) ---> %c\n", are_arrays_equal(expected, test.result, test.size));
	printf("The returned pointer points to the right place?\t(Expected: Y) ---> %c", are_pointers_equal(test.array_result_destiny_after, test.result_pointer_log));

	if ((are_arrays_equal(expected, test.result, test.size) == 'Y') && (are_pointers_equal(test.array_result_destiny_after, test.result_pointer_log) == 'Y') && (are_sources_intact(test.array_expected_original_after, test.array_result_original_after, test.size)) == 'Y')
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


#define NUM_TESTS 3

int main(void)
{
    int fail_counter = 0;

    char a_original[35] = {"1234567890abcdefghijklmnopqrs"};
    char a_destiny[35] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};

    char a_result_original_before[35] = {"1234567890abcdefghijklmnopqrs"};
    char a_result_original_after[35] = {"1234567890abcdefghijklmnopqrs"};
    char a_result_destiny_after[35] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};

    char a_expected_original_before[35] = {"1234567890abcdefghijklmnopqrs"};
    char a_expected_original_after[35] = {"1234567890abcdefghijklmnopqrs"};
    char a_expected_destiny_after[35] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};

    char *a_result_pointer_log = a_result_destiny_after;

    Test tests[NUM_TESTS] = {
        {a_original, a_destiny, a_result_original_before, a_result_original_after, a_result_destiny_after, a_expected_original_before, a_expected_original_after, a_expected_destiny_after, a_result_pointer_log, 6, "char src[35] = {\"1234567890abcdefghijklmnopqrs\"} char dest[35] = {\"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\"} Copy 6 bytes from non-overlapping buffers.", ft_memcpy(a_result_destiny_after, a_result_original_after, 6)},
        {a_original, a_destiny, a_result_original_before, a_result_original_after, a_result_destiny_after, a_expected_original_before, a_expected_original_after, a_expected_destiny_after, a_result_pointer_log, 0, "char src[35] = {\"1234567890abcdefghijklmnopqrs\"} char dest[35] = {\"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\"} Zero-length copy, should not alter the destination.", ft_memcpy(a_result_destiny_after, a_result_original_after, 0)},
        {a_original, a_destiny, a_result_original_before, a_result_original_after, a_result_destiny_after, a_expected_original_before, a_expected_original_after, a_expected_destiny_after, a_result_pointer_log, 35, "char src[35] = {\"1234567890abcdefghijklmnopqrs\"} char dest[35] = {\"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\"} Full buffer copy, check for any overflow.", ft_memcpy(a_result_destiny_after, a_result_original_after, 35)},
    };

	printf(COLOR_BLUE ">TESTING ft_memcpy------------------------------------------------------------------------\n" COLOR_RESET);
	// printf("XXXXXXXXXXXX \n");

	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_memcpy: FAIL");
    else
        ft_save_results("ft_memcpy: OK");


    printf("\n");
    return (0);
}

