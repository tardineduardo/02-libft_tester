#include "tester.h"

typedef struct
{
	const char	*test_src;
	char		*test_dest;
	const char	*control_src;
	char		*control_dest;
	size_t		size;
	size_t		sbuffer;
	size_t		dbuffer;
	char		*comment;
	size_t		test_return;
	size_t		control_return;
} Test;

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

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



static void	print_array_hex(void *array, size_t n) 
{
	size_t a;
	char *casted = (char*)array;
	for(a = 0; a < n; a++)
		printf("%c ", casted[a]);
}


// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
	printf(COLOR_YELLOW "%s\n" COLOR_RESET, test.comment);

	printf("src expected:\t(string =) %s", test.control_src);
	printf("\t(full src buffer array =)  ");
	
	print_array_hex((void *)test.control_src, test.sbuffer);
	printf("\n");
	printf("src result:\t(string =) %s", test.test_src);
	printf("\t(full src buffer array =)  ");
	print_array_hex((void *)test.test_src, test.sbuffer);
	printf("\n");

	printf("dest expected:\t(string =) %s", test.control_dest);
	printf("\t(full dest buffer array =) ");
	print_array_hex((void *)test.control_dest, test.dbuffer);
	printf("\n");
	printf("dest result:\t(string =) %s", test.test_dest);
	printf("\t(full dest buffer array =) ");
	print_array_hex((void *)test.test_dest, test.dbuffer);
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

#define NUM_TESTS 10

int main(void)
{
    int fail_counter = 0;

	char a_test_src[20] = {"abcdefghij\0........."};
	char a_test_dest[20] = {"1234567890\0!!!!!!!!!"};
	char a_control_src[20] = {"abcdefghij\0........."};
	char a_control_dest[20] = {"1234567890\0!!!!!!!!!"};
	size_t a_expected = strlcpy(a_control_dest, a_control_src, 20);
	size_t a_result = ft_strlcpy(a_test_dest, a_test_src, 20);
	size_t a_sbuffer = 20;
	size_t a_dbuffer = 20;	

	char b_test_src[20] = {"1234\0..............."};
	char b_test_dest[20] = {"abcdefghij\0@@@@@@@@@"};
	char b_control_src[20] = {"1234\0..............."};
	char b_control_dest[20] = {"abcdefghij\0@@@@@@@@@"};
	size_t b_expected = strlcpy(b_control_dest, b_control_src, 20);
	size_t b_result = ft_strlcpy(b_test_dest, b_test_src, 20);
	size_t b_sbuffer = 20;
	size_t b_dbuffer = 20;	

	char c_test_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char c_test_dest[6] = {"12345\0"};
	char c_control_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char c_control_dest[6] = {"12345\0"};
	size_t c_expected = strlcpy(c_control_dest, c_control_src, 6);
	size_t c_result = ft_strlcpy(c_test_dest, c_test_src, 6);
	size_t c_sbuffer = 20;
	size_t c_dbuffer = 6;	

	// Test with the size parameter set to 0 (no characters should be copied)
	char d_test_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char d_test_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	char d_control_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char d_control_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	size_t d_expected = strlcpy(d_control_dest, d_control_src, 0);
	size_t d_result = ft_strlcpy(d_test_dest, d_test_src, 0);
	size_t d_sbuffer = 20;
	size_t d_dbuffer = 20;	

	// Test with a size parameter larger than the source string length
	char e_test_src[20] = {"short\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char e_test_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	char e_control_src[20] = {"short\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char e_control_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	size_t e_expected = strlcpy(e_control_dest, e_control_src, 11);
	size_t e_result = ft_strlcpy(e_test_dest, e_test_src, 11);
	size_t e_sbuffer = 20;
	size_t e_dbuffer = 20;

	// Test with exact buffer size match to the null-terminated source string
	char f_test_src[20] = {"exactfit\0\0\0\0\0\0\0\0\0\0\0\0"};
	char f_test_dest[20] = {"overwrite\0\0\0\0\0\0\0\0\0\0\0"};
	char f_control_src[20] = {"exactfit\0\0\0\0\0\0\0\0\0\0\0\0"};
	char f_control_dest[20] = {"overwrite\0\0\0\0\0\0\0\0\0\0\0"};
	size_t f_expected = strlcpy(f_control_dest, f_control_src, 9);
	size_t f_result = ft_strlcpy(f_test_dest, f_test_src, 9);
	size_t f_sbuffer = 20;
	size_t f_dbuffer = 20;

	// Testing if content leaks will happen after copying less than the buffer size
	char g_test_src[4] = {"abc"};
	char g_test_dest[21] = {"memory-memory-memory"};
	char g_control_src[4] = {"abc"};
	char g_control_dest[21] = {"overwrite\0\0\0\0\0\0\0\0\0\0\0"};
	size_t g_expected = strlcpy(g_control_dest, g_control_src, 5);
	size_t g_result = ft_strlcpy(g_test_dest, g_test_src, 5);
	size_t g_sbuffer = 4;
	size_t g_dbuffer = 21;

    // Test 2
    char h_test_src[20] = {"abcdefghij\0........."};
    char h_test_dest[20] = {"1234567890\0!!!!!!!!!"};
    char h_control_src[20] = {"abcdefghij\0........."};
    char h_control_dest[20] = {"1234567890\0!!!!!!!!!"};
    size_t h_expected = strlcpy(h_control_dest, h_control_src, 10);
    size_t h_result = ft_strlcpy(h_test_dest, h_test_src, 10);
    size_t h_sbuffer = 20;
    size_t h_dbuffer = 20;

    // Test 3
    char i_test_src[20] = {"abcdefghij\0........."};
    char i_test_dest[20] = {"1234567890\0!!!!!!!!!"};
    char i_control_src[20] = {"abcdefghij\0........."};
    char i_control_dest[20] = {"1234567890\0!!!!!!!!!"};
    size_t i_expected = strlcpy(i_control_dest, i_control_src, 0);
    size_t i_result = ft_strlcpy(i_test_dest, i_test_src, 0);
    size_t i_sbuffer = 20;
    size_t i_dbuffer = 20;

    // Test 4
    char j_test_src[20] = {"abcdefghij\0........."};
    char j_test_dest[20] = {"1234567890\0!!!!!!!!!"};
    char j_control_src[20] = {"abcdefghij\0........."};
    char j_control_dest[20] = {"1234567890\0!!!!!!!!!"};
    size_t j_expected = strlcpy(j_control_dest, j_control_src, 30);
    size_t j_result = ft_strlcpy(j_test_dest, j_test_src, 30);
    size_t j_sbuffer = 20;
    size_t j_dbuffer = 20;




	Test tests[NUM_TESTS] = {
	{
		a_test_src,
		a_test_dest,
		a_control_src,
		a_control_dest,
		20,
		a_sbuffer,
		a_dbuffer,
		"src[20] = {\"abcdefghij\\0.........\"} | dest[20] = {\"1234567890\\0!!!!!!!!!\"}\nft_strlcpy(dest, src, 20) | strings and buffers of same size, n = size of dest buffer.",
		a_expected,
		a_result,
	},
	{
		b_test_src,
		b_test_dest,
		b_control_src,
		b_control_dest,
		20,
		b_sbuffer,
		b_dbuffer,
		"src[20] = {\"1234\\0...............\"} | dest[20] = {\"abcdefghij\\0@@@@@@@@@\"}\nft_strlcpy(dest, src, 20) | src shorter, buffers of same size, n = size of dest buffer.",
		b_expected,
		b_result,
	},
	{
		c_test_src,
		c_test_dest,
		c_control_src,
		c_control_dest,
		7,
		c_sbuffer,
		c_dbuffer,		
		"src[20] = {\"abcdefghij\\0\"} | dest[20] = {\"12345\\0\"}\nft_strlcpy(dest, src, 7) | Trying to copy 7 chars into smaller dest.",
		c_expected,
		c_result,
	},
	{
		d_test_src,
		d_test_dest,
		d_control_src,
		d_control_dest,
		0,
		d_sbuffer,
		d_dbuffer,	
		"src[20] = {\"abcdefghij\\0\"} | dest[20] = {\"1234567890\\0\"}\nft_strlcpy(dest, src, 0) | Should copy 0 chars.",
		d_expected,
		d_result,
	},
	{
		e_test_src,
		e_test_dest,
		e_control_src,
		e_control_dest,
		20,
		e_sbuffer,
		e_dbuffer,	
		"src[20] = {\"short\\0\"} | dest[20] = {\"1234567890\\0\"}\nft_strlcpy(dest, src, 20) | Looking for data leaks in the remaining dest buffer after \'\\0\'.",
		e_expected,
		e_result,
	},
	{
		f_test_src,
		f_test_dest,
		f_control_src,
		f_control_dest,
		9,
		f_sbuffer,
		f_dbuffer,	
		"src[20] = {\"exactfit\\0\"} | dest[20] = {\"overwrite\\0\"}\nft_strlcpy(dest, src, 9) | Exact buffer size match to null-terminated source.",
		f_expected,
		f_result,
	},
	{
		g_test_src,
		g_test_dest,
		g_control_src,
		g_control_dest,
		5,
		g_sbuffer,
		g_dbuffer,
		"src[4] = {\"abc\\0\"} | dest[21] = {\"memory-memory-memory\\0\"}\nft_strlcpy(dest, src, 5) | Looking for data leaks in the remaining dest buffer after \'\\0\'.",
		g_expected,
		g_result,
	},
		{h_test_src, h_test_dest, h_control_src, h_control_dest, 10, h_sbuffer, h_dbuffer, "Test 2: src[20] = {\"abcdefghij\\0.........\"} | dest[20] = {\"1234567890\\0!!!!!!!!!\"}\nft_strlcpy(dest, src, 10) | n < size of dest buffer.", h_expected, h_result},
        {i_test_src, i_test_dest, i_control_src, i_control_dest, 0, i_sbuffer, i_dbuffer, "Test 3: src[20] = {\"abcdefghij\\0.........\"} | dest[20] = {\"1234567890\\0!!!!!!!!!\"}\nft_strlcpy(dest, src, 0) | n = 0.", i_expected, i_result},
        {j_test_src, j_test_dest, j_control_src, j_control_dest, 30, j_sbuffer, j_dbuffer, "Test 4: src[20] = {\"abcdefghij\\0.........\"} | dest[20] = {\"1234567890\\0!!!!!!!!!\"}\nft_strlcpy(dest, src, 30) | n > size of dest buffer.", j_expected, j_result}

	};

	printf(COLOR_BLUE ">TESTING ft_strlcpy------------------------------------------------------------------------\n" COLOR_RESET);
	printf("This test compares the behavior of ft_strlcpy (result) with bsd/string.h/strlcpy (expected).\n\n- All the arrays used for testing, both src and dest, have a buffer large enough for the operations [20].\n\n- The \"n\" number of bytes to copy refers to the buffer size (the allocated memory) of dest.\n\n- \"n\" is not supposed to be used like \"this is how many chars I want to copy\", but \"copy string A\nto the place where string B lives, just make sure it doesn't exceed the B's current buffer size,\nwhich is \'n\', and I know that because I allocated myself memory for B, right?\".\n\n- Don't confuse the SIZE of the BUFFER with the LENGHT of the STRING inside it.\n\n");
	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_strlcpy: FAIL");
    else
        ft_save_results("ft_strlcpy: OK");

    printf("\n");
    return (0);
}
