#include "tester.h"

void	test_ft_atoi(char *nptr, char *comment)
{
	int	result = ft_atoi(nptr);
	int	expected = atoi(nptr);

	if (result == expected) 
		printf(ANSI_COLOR_GREEN "[[[PASS]]] " ANSI_COLOR_RESET);
	else
		printf(ANSI_COLOR_RED "[[[FAIL]]] " ANSI_COLOR_RESET);

	printf("ft_strlen > Input: <\"%s\"> (%s) | Expected: %d | Output: %d \n", nptr, comment, expected, result);

}

int	main(void)
{
	printf(">>>>> TESTING FT_ATOI\n");
	test_ft_atoi("Twinkle twinkle little star...", "Normal string");
	test_ft_atoi("", "Empty string");
	test_ft_atoi("1", "String with one numeric char");
	test_ft_atoi("+35", "String with plus sign");
	test_ft_atoi("  ", "String with only spaces");
	test_ft_atoi("-9384", "String with minus sign");
	test_ft_atoi("   84", "String with trailing spaces at the beginning");
	test_ft_atoi("84   ", "String with trailing spaces at the end");
	test_ft_atoi(" 84  ", "String with trailing spaces at both ends");

	printf("\n");

	return (0);
}