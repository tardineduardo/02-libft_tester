#include "tester.h"

typedef struct
{
	const char	*string;
	int			c;
	char		*comment;
	char 		*test_return;
	char		*control_return;
} Test;

char *ft_strchr(const char *str, int c);

// static void	print_string_hex(char *s) 
// {
// 	while(*s != '\0')
// 	{
// 		printf("%02x ", *s);
// 		s++;
// 	}
// 	printf("%02x ", *s);
// }
// static void	print_string_hex_c(const char *s) 
// {
// 	while(*s != '\0')
// 	{
// 		printf("%02x ", *s);
// 		s++;
// 	}
// 	printf("%02x ", *s);
// }




// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
	printf(COLOR_YELLOW "%s\n" COLOR_RESET, test.comment);

	// printf("src expected:\t%s", test.control_src);
	// printf("\t");
	// print_string_hex_c(test.control_src);
	// printf("\n");
	// printf("src result:\t%s", test.test_src);
	// printf("\t");
	// print_string_hex_c(test.test_src);
	// printf("\n");

	// printf("dest expected:\t%s", test.control_dest);
	// printf("\t");
	// print_string_hex(test.control_dest);
	// printf("\n");
	// printf("dest result:\t%s", test.test_dest);
	// printf("\t");
	// print_string_hex(test.test_dest);
	// printf("\n");
	
	// printf("return value expected:\t%ld", test.control_return);
	// printf("\n");
	// printf("return value result:\t%ld", test.test_return);
	// printf("\n");

	// printf("Is the source string intact?\t(Expected: 0) ---> %d\n", strcmp((char*)test.control_src, (char*)test.test_src));
	// printf("Is the target string correct?\t(Expected: 0) ---> %d\n", strcmp(test.control_dest, test.test_dest));

	if (test.test_return == test.control_return)
		printf(COLOR_GREEN "[[[PASS]]]\n" COLOR_RESET);	
	else
	{
		printf(COLOR_RED "[[[FAIL]]]\n" COLOR_RESET);
		(*fail_count)++;
	}
    printf("\n");

}

#define NUM_TESTS 1

int main(void)
{
    int fail_counter = 0;

	char *a_string = "abcdefghijk1lmnabcdef1ghijklmn";
	int		a_c = '1';
	char *a_expected = strchr(a_string, '1');
	char *a_result = ft_strchr(a_string, '1');


	Test tests[NUM_TESTS] = {
	{
		a_string,
		a_c,
		"coment.",
		a_expected,
		a_result,
	}
	};

	printf(COLOR_BLUE ">TESTING ft_strchr------------------------------------------------------------------------\n" COLOR_RESET);

	
	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_strchr: FAIL");
    else
        ft_save_results("ft_strchr: OK");

    printf("\n");
    return (0);
}
