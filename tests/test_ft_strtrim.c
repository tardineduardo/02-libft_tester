/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/27 14:52:03 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"


char *ft_strtrim(char const *s1, char const *set);


typedef struct
{
	const char	*set;
	const char	*test_src;
	char		*test_dest;
	char		*control_dest;
	char		*comment;
} Test;

 
/*static void	print_string_hex(char *s) 
{
	while(*s != '\0')
	{
		printf("%02x ", *s);
		s++;
	}
	printf("%02x ", *s);
}

static void	print_string_hex_c(const char *s) 
{
	while(*s != '\0')
	{
		printf("%02x ", *s);
		s++;
	}
	printf("%02x ", *s);
}*/

// static void	print_array_hex(void *array, size_t n)
// {
// 	size_t a;
// 	char *casted = (char*)array;
// 	for(a = 0; a < n; a++)
// 		printf("%c ", casted[a]);
// }

// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
	if ((strcmp(test.test_dest, test.control_dest) == 0)) 
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);	
	else
	{
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
		(*fail_count)++;
	}
	printf("(%s)\ts1: \"%s\", set: [", test.comment, test.test_src);
	printf(COLOR_YELLOW "%s" COLOR_RESET, test.set);
	printf("]\texpected:\"%s\"\tresult:\"%s\"", test.control_dest, test.test_dest);
    printf("\n");

}

#define NUM_TESTS 12

int main(void)
{
    int fail_counter = 0;

	char *a_set = "._ ";
	char *a_test_src = "._   don't+go+for  _";
	char *a_test_dest = ft_strtrim(a_test_src, a_set);
	char *a_control_dest = "don't+go+for";
	char *a_comment = "Trimming on both ends";

	char *b_set = ">,./";
	char *b_test_src = "secondbest,baby,..>";
	char *b_test_dest = ft_strtrim(b_test_src, b_set);
	char *b_control_dest = "secondbest,baby";
	char *b_comment = "Set chars at the end";

    char *c_set = "putyorlve";
    char *c_test_src = "putyourlove";
    char *c_test_dest = ft_strtrim(c_test_src, c_set);
    char *c_control_dest = "";
    char *c_comment = "All chars are in the set";

    char *d_set = "@.,:? _";
    char *d_test_src = "to the test";
    char *d_test_dest = ft_strtrim(d_test_src, d_set);
    char *d_control_dest = "to the test";
    char *d_comment = "No s1 chars are in the set";

    char *f_set = "";
    char *f_test_src = "likealittleprayer";
    char *f_test_dest = ft_strtrim(f_test_src, f_set);
    char *f_control_dest = "likealittleprayer";
    char *f_comment = "The trim set is empty";

    char *h_set = ".!";
    char *h_test_src = "!..aaa.!.aaa..!";
    char *h_test_dest = ft_strtrim(h_test_src, h_set);
    char *h_control_dest = "aaa.!.aaa";
    char *h_comment = "Set chars in the middle";

	char *j_set = "life";
	char *j_test_src = "lifeisamistery";
	char *j_test_dest = ft_strtrim(j_test_src, j_set);
	char *j_control_dest = "samistery";
	char *j_comment = "Set at the beginning";

	char *n_set = ".";
	char *n_test_src = " iwannatakeyouthere ";
	char *n_test_dest = ft_strtrim(n_test_src, n_set);
	char *n_control_dest = " iwannatakeyouthere ";
	char *n_comment = "s1 has whitespace chars";

	char *q_set = "\\n\\t";
	char *q_test_src = "\\n\\thello!\\n\\t";
	char *q_test_dest = ft_strtrim(q_test_src, q_set);
	char *q_control_dest = "hello!";
	char *q_comment = "Set contains escape chars";

	char *r_set = "";
	char *r_test_src = "";
	char *r_test_dest = ft_strtrim(r_test_src, r_set);
	char *r_control_dest = "";
	char *r_comment = "s1 and set are both empty";

    char *e_set = "expressyourselfheyhey";
    char *e_test_src = "";
    char *e_test_dest = ft_strtrim(e_test_src, e_set);
    char *e_control_dest = "";
    char *e_comment = "The string is empty";	

    char *g_set = ". ";
    char *g_test_src = "....     a    ..";
    char *g_test_dest = ft_strtrim(g_test_src, g_set);
    char *g_control_dest = "a";
    char *g_comment = "Single char in the middle";	

	Test tests[NUM_TESTS] = {
	{
		f_set,
		f_test_src,
		f_test_dest,
		f_control_dest,
		f_comment
	},
	{
        n_set,
        n_test_src,
        n_test_dest,
        n_control_dest,
        n_comment
    },
	{
		a_set,
		a_test_src,
		a_test_dest,
		a_control_dest,
		a_comment
	},
	{
		b_set,
		b_test_src,
		b_test_dest,
		b_control_dest,
		b_comment
	},

	{
		d_set,
		d_test_src,
		d_test_dest,
		d_control_dest,
		d_comment
	},

	{
		h_set,
		h_test_src,
		h_test_dest,
		h_control_dest,
		h_comment
	},
    {
        j_set,
        j_test_src,
        j_test_dest,
        j_control_dest,
        j_comment
    },

    {
        q_set,
        q_test_src,
        q_test_dest,
        q_control_dest,
        q_comment
    },
	{
		c_set,
		c_test_src,
		c_test_dest,
		c_control_dest,
		c_comment
	},
	{
		e_set,
		e_test_src,
		e_test_dest,
		e_control_dest,
		e_comment
	},
	{
		g_set,
		g_test_src,
		g_test_dest,
		g_control_dest,
		g_comment
	},
    {
        r_set,
        r_test_src,
        r_test_dest,
        r_control_dest,
        r_comment
    }	
	};

	printf(COLOR_BLUE ">TESTING ft_strtrim------------------------------------------------------------------------\n" COLOR_RESET);
	printf("If your function needs to return a pointer to an empty string, it should not point to an empty string literal,\nbut to an allocated memory space. This is because string literals are stored in read-only memory, and any attempt\nto modify this memory can lead to undefined behavior or a segmentation fault. Instead, you should allocate memory\nfor a single character and set it to the null terminator ('\\0'). This represents an empty string and ensures\nthat the memory is writable, preventing potential errors.\n\n");
	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_strtrim: FAIL");
    else
        ft_save_results("ft_strtrim: OK");

    printf("\n");
    return (0);
}
