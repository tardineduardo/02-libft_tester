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
	void 	*pointer_log;
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

static char compare_pointers(void *p1, void *p2)
{
	if (p1 == p2)
		return ('Y');
	else
		return ('N');
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
	void *result = ft_memset(test.array_after_result, test.value, test.size);
    void *expected = memset(test.array_after_expected, test.value, test.size);

	printf("%s\n", test.comment);

	printf("source in HEX:\t\t\t");
	print_array_hex(test.array_before, 35);
	printf("\n");
	printf("expected output in HEX:\t\t");
	print_array_hex(expected, 35);
	printf("\n");
	printf("result output in HEX:\t\t");
	print_array_hex(result, 35);
	printf("\n");
	if ((compare_arrays(expected, result, test.size) == 0) && (result == test.pointer_log))
	{
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	}
	else
	{
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
		(*fail_count)++;
	}

    printf("compare_arrays == %d, expected == 0 | is the pointer correct? %c \n\n", compare_arrays(expected, result, test.size), compare_pointers(result, test.pointer_log));
}



#define NUM_TESTS 5

int main(void)
{

    int fail_counter = 0;

	char	a_before[35] = {"Kelly, can you handle null?"};
	char	a_after_result[35] = {"Kelly, can you handle null?"};
	char	a_after_expected[35] = {"Kelly, can you handle null?"};
	int		a_value = '*';
	size_t	a_size = 27;
    char	*a_comment = "char s[35] = {\"Kelly, can you handle null?\"} ft_memset(s, '*', 27)";
	void	*a_pointer_log = (void *)a_after_result;

	char b_before[35] = {"Michelle, can you handle null?"};
	char b_after_result[35] = {"Michelle, can you handle null?"};
	char b_after_expected[35] = {"Michelle, can you handle null?"};
	int		b_value = '1';
	size_t	b_size = 4;
    char	*b_comment = "char s[35] = {\"Michelle, can you handle null?\"} ft_memset(s, '1', 4)";
	void	*b_pointer_log = (void *)b_after_result;

	char c_before[35] = {"Beyonce, can you handle null?"};
	char c_after_result[35] = {"Beyonce, can you handle null?"};
	char c_after_expected[35] = {"Beyonce, can you handle null?"};
	int		c_value = 's';
	size_t	c_size = 10;
    char	*c_comment = "char s[35] = {\"Beyonce, can you handle null?\"} ft_memset(s, 's', 10)";
	void	*c_pointer_log = (void *)c_after_result;

	char d_before[35] = {"I dont think they can handle null!"};
	char d_after_result[35] = {"I dont think they can handle null!"};
	char d_after_expected[35] = {"I dont think they can handle null!"};
	int		d_value = 0;
	size_t	d_size = 35;
    char	*d_comment = "char s[35] = {\"I dont think they can handle null!\"} ft_memset(s, 0, 35)";
	void	*d_pointer_log = (void *)d_after_result;	

	char e_before[35] = {"This should remain unchanged."};
	char e_after_result[35] = {"This should remain unchanged."};
	char e_after_expected[35] = {"This should remain unchanged."};
	int		e_value = '*';
	size_t	e_size = 0;
    char	*e_comment = "char s[35] = {\"This should remain unchanged.\"} ft_memset(s, '*', 0)";	
	void	*e_pointer_log = (void *)e_after_result;

	Test tests[NUM_TESTS] = {
	{a_before, a_after_result, a_after_expected, a_value, a_size, a_comment, a_pointer_log},
	{b_before, b_after_result, b_after_expected, b_value, b_size, b_comment, b_pointer_log},
	{c_before, c_after_result, c_after_expected, c_value, c_size, c_comment, c_pointer_log},
	{d_before, d_after_result, d_after_expected, d_value, d_size, d_comment, d_pointer_log},
	{e_before, e_after_result, e_after_expected, e_value, e_size, e_comment, e_pointer_log}
	};

	printf(COLOR_BLUE ">TESTING ft_memset------------------------------------------------------------------------\n" COLOR_RESET);
	printf(COLOR_BLUE ">void *memset(void *s, int c, size_t n);--------------------------------------------------\n" COLOR_RESET);
	printf("From MAN MEMSET: \"The memset() function fills the first n bytes of the memory area pointed\nto by s with the constant byte c. The memset() function returns a pointer to the memory area s.\"\nI test ft_memset() by comparing its behavior to the standard memset(). I use function compare_arrays\nto compare every byte (unsigned char) from index 0 to index n of the arrays transformed by memset()\nand ft_memset(). I also check if the pointer returned is pointing to the right place (index 0 of \nthe array just edited).\n\n");

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

