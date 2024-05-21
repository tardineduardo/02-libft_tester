#include "tester.h"

typedef struct
{
	const char	*test_src;
	char		*test_dest;
	const char	*control_src;
	char		*control_dest;
	size_t		size;
	char		*comment;
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
	size_t result = ft_strlcat(test.test_dest, test.test_src, test.size);
	size_t control = strlcat(test.control_dest, test.control_src, test.size);


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
	
	printf("return value expected:\t%ld", control);
	printf("\n");
	printf("return value result:\t%ld", result);
	printf("\n");

	printf("Is the source string intact?\t(Expected: 0) ---> %d\n", strcmp((char*)test.control_src, (char*)test.test_src));
	printf("Is the target string correct?\t(Expected: 0) ---> %d\n", strcmp(test.control_dest, test.test_dest));

	if ((strcmp((char*)test.control_src, (char*)test.test_src) ==  0) && (strcmp(test.test_dest, test.control_dest) == 0) && (result == control))
		printf(COLOR_GREEN "[[[PASS]]]\n" COLOR_RESET);	
	else
	{
		printf(COLOR_RED "[[[FAIL]]]\n" COLOR_RESET);
		(*fail_count)++;
	}
    printf("\n");

}

#define NUM_TESTS 14

int main(void)
{
    int fail_counter = 0;

	char a_test_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char a_test_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	char a_control_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char a_control_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	size_t a_size = 20;
	char *a_comment = "src[20] = {\"abcdefghij\\0\"} | dest[20] = {\"1234567890\\0\"}\nft_strlcat(dest, src, 20) | Copying 2 chars."; 

	char b_test_src[20] = {"1234\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char b_test_dest[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char b_control_src[20] = {"1234\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char b_control_dest[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	size_t b_size = 20;
	char *b_comment = "src[20] = {\"1234\\0\"} | dest[20] = {\"abcdefghij\\0\"}\nft_strlcat(dest, src, 20)"; 


	char c_test_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char c_test_dest[20] = {"12345\0"};
	char c_control_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char c_control_dest[20] = {"12345\0"};
	size_t c_size = 20;
	char *c_comment = "src[20] = {\"abcdefghij\\0\"} | dest[20] = {\"12345\\0\"}\nft_strlcat(dest, src, 20)"; 


	char d_test_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char d_test_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	char d_control_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char d_control_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	size_t d_size = 20;
	char *d_comment = "src[20] = {\"abcdefghij\\0\"} | dest[20] = {\"1234567890\\0\"}\nft_strlcat(dest, src, 20)";

	// Test with a size parameter larger than the source string length
	char e_test_src[20] = {"short\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char e_test_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	char e_control_src[20] = {"short\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char e_control_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	size_t e_size = 20;
	char *e_comment = "src[20] = {\"short\\0\"} | dest[20] = {\"1234567890\\0\"}\nft_strlcat(dest, src, 20)";

	// Test with exact buffer size match to the null-terminated source string
	char f_test_src[20] = {"exactfit\0\0\0\0\0\0\0\0\0\0\0\0"};
	char f_test_dest[20] = {"overwrite\0\0\0\0\0\0\0\0\0\0\0"};
	char f_control_src[20] = {"exactfit\0\0\0\0\0\0\0\0\0\0\0\0"};
	char f_control_dest[20] = {"overwrite\0\0\0\0\0\0\0\0\0\0\0"};
	size_t f_size = 20;
	char *f_comment = "src[20] = {\"exactfit\\0\"} | dest[20] = {\"overwrite\\0\"}\nft_strlcat(dest, src, 20)";

	// Test with an empty source string
	char g_test_src[20] = {"\0"};
	char g_test_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	char g_control_src[20] = {"\0"};
	char g_control_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	size_t g_size = 20;
	char *g_comment = "src[20] = {\"\\0\"} | dest[20] = {\"1234567890\\0\"}\nft_strlcat(dest, src, 20)";

	// Test with an empty destination string
	char h_test_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char h_test_dest[20] = {"\0"};
	char h_control_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char h_control_dest[20] = {"\0"};
	size_t h_size = 20;
	char *h_comment = "src[20] = {\"abcdefghij\\0\"} | dest[20] = {\"\\0\"}\nft_strlcat(dest, src, 20)";


	// Test with both source and destination strings empty
	char i_test_src[20] = {"\0"};
	char i_test_dest[20] = {"\0"};
	char i_control_src[20] = {"\0"};
	char i_control_dest[20] = {"\0"};
	size_t i_size = 20;
	char *i_comment = "src[20] = {\"\\0\"} | dest[20] = {\"\\0\"}\nft_strlcat(dest, src, 20)";

	// Test with a size parameter equal to the length of the source string plus one
	char j_test_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char j_test_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	char j_control_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char j_control_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	size_t j_size = strlen(j_control_src) + 1;
	char *j_comment = "src[20] = {\"abcdefghij\\0\"} | dest[20] = {\"1234567890\\0\"}\nft_strlcat(dest, src, strlen(src) + 1)";

	// Test with a size parameter equal to the length of the destination string plus one
	char k_test_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char k_test_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	char k_control_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char k_control_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	size_t k_size = strlen(k_control_dest) + 1;
	char *k_comment = "src[20] = {\"abcdefghij\\0\"} | dest[20] = {\"1234567890\\0\"}\nft_strlcat(dest, src, strlen(dest) + 1)";

	// Test with a size parameter equal to the length of the source string plus the length of the destination string plus one
	char l_test_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char l_test_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	char l_control_src[20] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0"};
	char l_control_dest[20] = {"1234567890\0\0\0\0\0\0\0\0\0\0"};
	size_t l_size = strlen(l_control_src) + strlen(l_control_dest) + 1;
	char *l_comment = "src[20] = {\"abcdefghij\\0\"} | dest[20] = {\"1234567890\\0\"}\nft_strlcat(dest, src, strlen(src) + strlen(dest) + 1)";

	char m_test_src[40] = {"the cake is a lie !\0I'm hidden lol\r\n"};
	char m_test_dest[40] = {"there is no stars in the sky"};
	char m_control_src[40] = {"the cake is a lie !\0I'm hidden lol\r\n"};
	char m_control_dest[40] = {"there is no stars in the sky"};
	size_t m_size = strlen(l_control_src) + 4;
	char *m_comment = "Stupid case from stupid Francinette.";

	char n_test_src[32] = {"thx to eduribei for this test !"};
	char n_test_dest[4] = {""};
	char n_control_src[32] = {"thx to eduribei for this test !"};
	char n_control_dest[4] = {""};
	size_t n_size = 4;
	char *n_comment = "Stupid case from stupid Francinette.";


Test tests[NUM_TESTS] = {
    {a_test_src, a_test_dest, a_control_src, a_control_dest, a_size, a_comment},
    {b_test_src, b_test_dest, b_control_src, b_control_dest, b_size, b_comment},
    {c_test_src, c_test_dest, c_control_src, c_control_dest, c_size, c_comment},
    {d_test_src, d_test_dest, d_control_src, d_control_dest, d_size, d_comment},
    {e_test_src, e_test_dest, e_control_src, e_control_dest, e_size, e_comment},
    {f_test_src, f_test_dest, f_control_src, f_control_dest, f_size, f_comment},
    {g_test_src, g_test_dest, g_control_src, g_control_dest, g_size, g_comment},
    {h_test_src, h_test_dest, h_control_src, h_control_dest, h_size, h_comment},
    {i_test_src, i_test_dest, i_control_src, i_control_dest, i_size, i_comment},
    {j_test_src, j_test_dest, j_control_src, j_control_dest, j_size, j_comment},
    {k_test_src, k_test_dest, k_control_src, k_control_dest, k_size, k_comment},
    {l_test_src, l_test_dest, l_control_src, l_control_dest, l_size, l_comment},
    {m_test_src, m_test_dest, m_control_src, m_control_dest, m_size, m_comment},
    {n_test_src, n_test_dest, n_control_src, n_control_dest, n_size, n_comment}
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
