#include "tester.h"

typedef struct
{
	void	*test_src;
	void	*test_dest;
	void	*control_src;
	void	*control_dest;
	void	*pointer_log;
	size_t	size;
	char	*comment;
	void	*result;
	void	*expected;
} Test;

void *ft_memset(void *s, int c, size_t n);

void *ft_memmove(void *dest, const void *src, size_t n);

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
	printf(COLOR_YELLOW "%s\n" COLOR_RESET, test.comment);

	printf("src expected:\t");
	print_array(test.control_src, 25);
	printf("\n");
	printf("src result:\t");
	print_array(test.test_src, 25);
	printf("\n");
	printf("src expected (hex):\t");
	print_array_hex(test.control_src, 25);
	printf("\n");
	printf("src result (hex):\t");
	print_array_hex(test.test_src, 25);
	printf("\n");

	printf("dest expected:\t");
	print_array(test.control_dest, 25);
	printf("\n");
	printf("dest result:\t");
	print_array(test.test_dest, 25);
	printf("\n");
	printf("dest expected (hex):\t");
	print_array_hex(test.control_dest, 25);
	printf("\n");
	printf("dest result (hex):\t");
	print_array_hex(test.test_dest, 25);
	printf("\n");

	printf("Is the source data intact?\t\t\t(Expected: Y) ---> %c\n", are_sources_intact(test.test_src, test.control_src, test.size));
	printf("Is the target data what it's supposed to be?\t(Expected: Y) ---> %c\n", are_arrays_equal(test.expected, test.result, test.size));
	printf("The returned pointer points to the right place?\t(Expected: Y) ---> %c", are_pointers_equal(test.test_dest, test.pointer_log));


	if ((are_arrays_equal(test.expected, test.result, test.size) == 'Y') &&
		(are_pointers_equal(test.test_dest, test.pointer_log) == 'Y') &&
		(are_sources_intact(test.test_src, test.control_src, test.size)) == 'Y')
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


#define NUM_TESTS 4

int main(void)
{
    int fail_counter = 0;




	char a_test_src[25] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char a_test_dest[25] = {"1234567890\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char a_control_src[25] = {"abcdefghij\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char a_control_dest[25] = {"1234567890\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char *a_expected = memmove(a_control_dest, a_control_src, 5);
	char *a_result = ft_memmove(a_test_dest, a_test_src, 5);

	char b_test_src[25] = {"1234567890\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char *b_test_dest = &b_test_src[2];
	char b_control_src[25] = {"1234567890\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char *b_control_dest = &b_control_src[2];
	char *b_expected = memmove(b_control_dest, b_control_src, 7);
	char *b_result = ft_memmove(b_test_dest, b_test_src, 7);

	char c_test_src[25] = {"1234567890\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char *c_test_dest = &c_test_src[1];
	char c_control_src[25] = {"1234567890\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char *c_control_dest = &c_control_src[1];
	char *c_expected = memmove(c_control_dest, c_control_src, 2);
	char *c_result = ft_memmove(c_test_dest, c_test_src, 2);

	char d_test_dest[25] = {"thelazybrownfox\0\0\0\0\0\0\0\0\0\0"};
	char *d_test_src = &d_test_dest[6];
	char d_control_dest[25] = {"thelazybrownfox\0\0\0\0\0\0\0\0\0\0"};
	char *d_control_src = &d_control_dest[6];
	char *d_expected = memmove(d_control_dest, d_control_src, 6);
	char *d_result = ft_memmove(d_test_dest, d_test_src, 6);



Test tests[NUM_TESTS] = {
{
    a_test_src,
    a_test_dest,
    a_control_src,
    a_control_dest,
    a_test_dest,
    5,
    "src[25] = {\"1234567890\"} | dest[25] = {\"1234567890\"}\nft_memmove(dest, src, 5) | Moving 5 bytes, no ovelap.",
	a_expected,
	a_result,
    },
{
    b_test_src,
    b_test_dest,
    b_control_src,
    b_control_dest,
    b_test_dest,
    7,
    "src[25] = {\"1234567890\"} | dest = src[2]\"}\nft_memmove(dest, src, 7) | Moving 7 bytes, with ovelap, src < dest.",
	b_expected,
	b_result,
    },
{
    c_test_src,
    c_test_dest,
    c_control_src,
    c_control_dest,
    c_test_dest,
    2,
    "src[25] = {\"1234567890\"} | dest = src[1]\"}\nft_memmove(dest, src, 2) | Moving 2 bytes, with ovelap, src < dest.",
	c_expected,
	c_result,
    },
{
    d_test_src,
    d_test_dest,
    d_control_src,
    d_control_dest,
    d_test_dest,
    6,
    "dest[25] = {\"thelazybrownfox\"} | src = dest[6]\"}\nft_memmove(dest, src, 6) | Moving 6 bytes, with ovelap, src > dest.",
	d_expected,
	d_result,
    }
};

	printf(COLOR_BLUE ">TESTING ft_memmove------------------------------------------------------------------------\n" COLOR_RESET);
	printf("For the uninitialized values of the arrays, the test might show garbage values.\n\n");

	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_memmove: FAIL");
    else
        ft_save_results("ft_memmove: OK");

    printf("\n");
    return (0);
}
