#include "tester.h"

typedef struct
{
	const char	*test_src;
	char		*test_dest;
	const char	*control_src;
	char		*control_dest;
	size_t		size;
	char		*comment;
	size_t		test_return;
	size_t		control_return;
} Test;

size_t	ft_strlcat(char *dst, const char *src, size_t size);

static void	print_string_hex(char *s) 
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
}




// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
	printf(COLOR_YELLOW "%s\n" COLOR_RESET, test.comment);

	printf("src expected:\t%s", test.control_src);
	printf("\t");
	print_string_hex_c(test.control_src);
	printf("\n");
	printf("src result:\t%s", test.test_src);
	printf("\t");
	print_string_hex_c(test.test_src);
	printf("\n");

	printf("dest expected:\t%s", test.control_dest);
	printf("\t");
	print_string_hex(test.control_dest);
	printf("\n");
	printf("dest result:\t%s", test.test_dest);
	printf("\t");
	print_string_hex(test.test_dest);
	printf("\n");
	
	printf("return value expected:\t%ld", test.control_return);
	printf("\n");
	printf("return value result:\t%ld", test.test_return);
	printf("\n");

	printf("Is the source string intact?\t(Expected: 0) ---> %d\n", strcmp((char*)test.control_src, (char*)test.test_src));
	printf("Is the target string correct?\t(Expected: 0) ---> %d\n", strcmp(test.control_dest, test.test_dest));

	if ((strcmp((char*)test.control_src, (char*)test.test_src) ==  0) && (strcmp(test.test_dest, test.control_dest) == 0) && (test.test_return == test.control_return))
		printf(COLOR_GREEN "[[[PASS]]]\n" COLOR_RESET);	
	else
	{
		printf(COLOR_RED "[[[FAIL]]]\n" COLOR_RESET);
		(*fail_count)++;
	}
    printf("\n");

}

#define NUM_TESTS 6

int main(void)
{
    int fail_counter = 0;

	char a_test_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char a_test_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	char a_control_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char a_control_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	size_t a_expected = strlcat(a_control_dest, a_control_src, 20);
	size_t a_result = ft_strlcat(a_test_dest, a_test_src, 20);

	char b_test_src[20] = {"1234\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char b_test_dest[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char b_control_src[20] = {"1234\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char b_control_dest[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	size_t b_expected = strlcat(b_control_dest, b_control_src, 20);
	size_t b_result = ft_strlcat(b_test_dest, b_test_src, 20);

	char c_test_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char c_test_dest[20] = {"12345\0"};
	char c_control_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char c_control_dest[20] = {"12345\0"};
	size_t c_expected = strlcat(c_control_dest, c_control_src, 20);
	size_t c_result = ft_strlcat(c_test_dest, c_test_src, 20);

	// Test with the size parameter set to 0 (no characters should be copied)
	char d_test_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char d_test_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	char d_control_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char d_control_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	size_t d_expected = strlcat(d_control_dest, d_control_src, 20);
	size_t d_result = ft_strlcat(d_test_dest, d_test_src, 20);

	// Test with a size parameter larger than the source string length
	char e_test_src[20] = {"short\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char e_test_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	char e_control_src[20] = {"short\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char e_control_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	size_t e_expected = strlcat(e_control_dest, e_control_src, 20);
	size_t e_result = ft_strlcat(e_test_dest, e_test_src, 20);

	// Test with exact buffer size match to the null-terminated source string
	char f_test_src[20] = {"exactfit\0\0\0\0\0\0\0\0\0\0\0\0"};
	char f_test_dest[20] = {"overwrite\0\0\0\0\0\0\0\0\0\0\0"};
	char f_control_src[20] = {"exactfit\0\0\0\0\0\0\0\0\0\0\0\0"};
	char f_control_dest[20] = {"overwrite\0\0\0\0\0\0\0\0\0\0\0"};
	size_t f_expected = strlcat(f_control_dest, f_control_src, 20);
	size_t f_result = ft_strlcat(f_test_dest, f_test_src, 20);


	Test tests[NUM_TESTS] = {
	{
		a_test_src,
		a_test_dest,
		a_control_src,
		a_control_dest,
		20,
		"src[20] = {\"abcdefghij\\0\"} | dest[20] = {\"1234567890\\0\"}\nft_strlcat(dest, src, 20) | Copying 2 chars.",
		a_expected,
		a_result,
	},
	{
		b_test_src,
		b_test_dest,
		b_control_src,
		b_control_dest,
		20,
		"src[20] = {\"1234\\0\"} | dest[20] = {\"abcdefghij\\0\"}\nft_strlcat(dest, src, 20)",
		b_expected,
		b_result,
	},
	{
		c_test_src,
		c_test_dest,
		c_control_src,
		c_control_dest,
		20,
		"src[20] = {\"abcdefghij\\0\"} | dest[20] = {\"12345\\0\"}\nft_strlcat(dest, src, 20)",
		c_expected,
		c_result,
	},
	{
		d_test_src,
		d_test_dest,
		d_control_src,
		d_control_dest,
		20,
		"src[20] = {\"abcdefghij\\0\"} | dest[20] = {\"1234567890\\0\"}\nft_strlcat(dest, src, 20)",
		d_expected,
		d_result,
	},
	{
		e_test_src,
		e_test_dest,
		e_control_src,
		e_control_dest,
		2011,
		"src[20] = {\"short\\0\"} | dest[20] = {\"1234567890\\0\"}\nft_strlcat(dest, src, 20)",
		e_expected,
		e_result,
	},
	{
		f_test_src,
		f_test_dest,
		f_control_src,
		f_control_dest,
		20,
		"src[20] = {\"exactfit\\0\"} | dest[20] = {\"overwrite\\0\"}\nft_strlcat(dest, src, 20)",
		f_expected,
		f_result,
	}
	};

	printf(COLOR_BLUE ">TESTING ft_strlcat------------------------------------------------------------------------\n" COLOR_RESET);
	printf("This test compares the behavior of ft_strlcat (result) with bsd/string.h/strlcat (expected).\n\n- All the arrays used for testing, both src and dest, have a buffer large enough for the operations [20].\n\n- The \"n\" number of bytes to copy refers to the buffer size (the allocated memory) of dest.\n\n- \"n\" is not supposed to be used like \"this is how many chars I want to copy\", but \"copy string A\nto the place where string B lives, just make sure it doesn't exceed the B's current buffer size,\nwhich is \'n\', and I know that because I allocated myself memory for B, right?\".\n\n- Don't confuse the SIZE of the BUFFER with the LENGHT of the STRING inside it.\n\n");
	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_strlcat: FAIL");
    else
        ft_save_results("ft_strlcat: OK");

    printf("\n");
    return (0);
}
