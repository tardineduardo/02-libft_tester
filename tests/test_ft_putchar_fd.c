/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:21:26 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/14 19:37:20 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	printf(COLOR_BLUE "test_ft_putchar_fd - This test is not ready yet ------------------------------------------------------.\n\n" COLOR_RESET);
	ft_save_results("test_ft_putchar_fd: not ready");
}


// int compare_files(const char *file1, const char *file2);

// char *ft_putchar_fd(const char *s);


// typedef struct
// {
// 	const char	*s;
// 	char		*control;		
// 	char		*comment;
// } Test;


// // Function to execute and print test results
// void run_test(Test test, int *fail_count)
// {
//     char *result;

//     if (test.s == NULL)
//     {
//         pid_t pid = fork();
//         if (pid == 0) // child process
//         {
//             result = ft_strdup(test.s);
//             exit(0); // exit with zero status if strdup returned NULL
//         }
//         else if (pid > 0) // parent process
//         {
//             int status;
//             waitpid(pid, &status, 0); // wait for child process to finish
//             if (WIFSIGNALED(status)) // if not zero
//             {
//                 printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
//                 printf("ft_strdup crashed when s1 = NULL.\n");
//             }
//             else // if zero
//             {
//                 printf(COLOR_YELLOW "[[[FAIL]]] " COLOR_RESET);
//                 printf("ft_strdup did not crash when s1 = NULL. It should instead crash.\n");
//                 (*fail_count)++;
//             }
//         }
//         else // fork failed
//         {
//             perror("fork");
//             exit(1);
//         }
//     }
//     else
//     {
//         result = ft_strdup(test.s);
//         if ((strcmp(result, test.control) == 0))
//             printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);    
//         else
//         {
//             printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
//             (*fail_count)++;
//         }
//         printf("(%s)\ts: \"%s\"", test.comment, test.s);
//         printf("\texpected:\"%s\"\tresult:\"%s\"", test.control, result);
//         printf("\n");
//     }
// }

// #define NUM_TESTS 3

// int main(void)
// {
//     int fail_counter = 0;

// 	const char	*a_s = "abc";
// 	char		*a_control = "abc";
// 	char		*a_comment = "Normal string";

// 	const char	*b_s = "\0";
// 	char		*b_control = "\0";
// 	char		*b_comment = "Empty string";

// 	const char	*c_s = NULL;
// 	char		*c_control = "it should crash";
// 	char		*c_comment = "NULL pointer";

// 	Test tests[NUM_TESTS] = {
// 		{a_s, a_control, a_comment},
// 		{b_s, b_control, b_comment},
// 		{c_s, c_control, c_comment}
// 	};

// 	printf(COLOR_BLUE "\n>TESTING ft_strdup------------------------------------------------------------------------\n" COLOR_RESET);
// 	printf("MAN STRDUP says: \"On success, the strdup() function returns a pointer to the duplicated string.\nIt returns NULL if insufficient memory was available, with errno set to indicate the cause of the\n error.\" It is not clear whether strdup() handle a NULL pointer as parameter, but the strdup()\navaliable on string.h won\'t handle NULL, it will crash instead. I will reproduce this behavior\nand consider a FAIL if ft_strdup returns NULL for a NULL pointer.\n\n");

		
// 	// RUNNING TESTS
// 	for (int i = 0; i < NUM_TESTS; i++)
//         run_test(tests[i], &fail_counter);

// 	// SAVING RESULTS
//     if (fail_counter > 0)
//         ft_save_results("ft_strdup: FAIL");
//     else
//         ft_save_results("ft_strdup: OK");

//     printf("\n\n");
//     return (0);
// }


// int compare_files(const char *file1, const char *file2) 
// {
//     FILE *f1 = fopen(file1, "rb");
//     FILE *f2 = fopen(file2, "rb");

//     if (f1 == NULL || f2 == NULL) {
//         printf("Error opening one of the files.\n");
//         return -1;
//     }

//     int ch1, ch2;
//     while (((ch1 = fgetc(f1)) != EOF) && ((ch2 = fgetc(f2)) != EOF)) {
//         if (ch1 != ch2) {
//             fclose(f1);
//             fclose(f2);
//             return 0; // Files are different
//         }
//     }

//     fclose(f1);
//     fclose(f2);
    
//     // Check if both files reached the end
//     return (ch1 == EOF && ch2 == EOF); // 1 if same, 0 if different
// }