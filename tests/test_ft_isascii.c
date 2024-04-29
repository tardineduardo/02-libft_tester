
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/29 18:51:10 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int ft_isascii(int c);

typedef struct
{
    int input;
    char *comment;
    int result;
} Test;

// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
    int expected = isascii(test.input);

	if ((test.result == 0) && (expected == 0))
	{
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	}
	else if ((test.result != 0) && (expected != 0))
	{
		printf(COLOR_GREEN "[[[PASS]]] " COLOR_RESET);
	}
	else
	{
		printf(COLOR_RED "[[[FAIL]]] " COLOR_RESET);
		(*fail_count)++;
	}

    printf("Input: %d \t Expected: %d \t Output: %d \t(%s)\n", test.input, expected, test.result, test.comment);
}

#define NUM_TESTS 156

int main(void)
{
    int fail_counter = 0;

    Test tests[NUM_TESTS] = {
	{0, "NULL character (ASCII)", ft_isascii(0)},
	{1, "Start of Heading (ASCII)", ft_isascii(1)},
	{2, "Start of Text (ASCII)", ft_isascii(2)},
	{3, "End of Text (ASCII)", ft_isascii(3)},
	{4, "End of Transmission (ASCII)", ft_isascii(4)},
	{5, "Enquiry (ASCII)", ft_isascii(5)},
	{6, "Acknowledgment (ASCII)", ft_isascii(6)},
	{7, "Bell (ASCII)", ft_isascii(7)},
	{8, "Backspace (ASCII)", ft_isascii(8)},
	{9, "Horizontal Tab (ASCII)", ft_isascii(9)},
	{10, "Line Feed (ASCII)", ft_isascii(10)},
	{11, "Vertical Tab (ASCII)", ft_isascii(11)},
	{12, "Form Feed (ASCII)", ft_isascii(12)},
	{13, "Carriage Return (ASCII)", ft_isascii(13)},
	{14, "Shift Out (ASCII)", ft_isascii(14)},
	{15, "Shift In (ASCII)", ft_isascii(15)},
	{16, "Data Link Escape (ASCII)", ft_isascii(16)},
	{17, "Device Control 1 (ASCII)", ft_isascii(17)},
	{18, "Device Control 2 (ASCII)", ft_isascii(18)},
	{19, "Device Control 3 (ASCII)", ft_isascii(19)},
	{20, "Device Control 4 (ASCII)", ft_isascii(20)},
	{21, "Negative Acknowledgement (ASCII)", ft_isascii(21)},
	{22, "Synchronous Idle (ASCII)", ft_isascii(22)},
	{23, "End of Transmission Block (ASCII)", ft_isascii(23)},
	{24, "Cancel (ASCII)", ft_isascii(24)},
	{25, "End of Medium (ASCII)", ft_isascii(25)},
	{26, "Substitute (ASCII)", ft_isascii(26)},
	{27, "Escape (ASCII)", ft_isascii(27)},
	{28, "File Separator (ASCII)", ft_isascii(28)},
	{29, "Group Separator (ASCII)", ft_isascii(29)},
	{30, "Record Separator (ASCII)", ft_isascii(30)},
	{31, "Unit Separator (ASCII)", ft_isascii(31)},
	{32, "Space (ASCII)", ft_isascii(32)},
	{33, "Exclamation Mark (ASCII)", ft_isascii(33)},
	{34, "Double Quote (ASCII)", ft_isascii(34)},
	{35, "Number Sign (ASCII)", ft_isascii(35)},
	{36, "Dollar Sign (ASCII)", ft_isascii(36)},
	{37, "Percent Sign (ASCII)", ft_isascii(37)},
	{38, "Ampersand (ASCII)", ft_isascii(38)},
	{39, "Single Quote (ASCII)", ft_isascii(39)},
	{40, "Left Parenthesis (ASCII)", ft_isascii(40)},
	{41, "Right Parenthesis (ASCII)", ft_isascii(41)},
	{42, "Asterisk (ASCII)", ft_isascii(42)},
	{43, "Plus Sign (ASCII)", ft_isascii(43)},
	{44, "Comma (ASCII)", ft_isascii(44)},
	{45, "Hyphen-Minus (ASCII)", ft_isascii(45)},
	{46, "Full Stop (ASCII)", ft_isascii(46)},
	{47, "Slash (ASCII)", ft_isascii(47)},
	{48, "Digit 0 (ASCII)", ft_isascii(48)},
	{49, "Digit 1 (ASCII)", ft_isascii(49)},
	{50, "Digit 2 (ASCII)", ft_isascii(50)},
	{51, "Digit 3 (ASCII)", ft_isascii(51)},
	{52, "Digit 4 (ASCII)", ft_isascii(52)},
	{53, "Digit 5 (ASCII)", ft_isascii(53)},
	{54, "Digit 6 (ASCII)", ft_isascii(54)},
	{55, "Digit 7 (ASCII)", ft_isascii(55)},
	{56, "Digit 8 (ASCII)", ft_isascii(56)},
	{57, "Digit 9 (ASCII)", ft_isascii(57)},
	{58, "Colon (ASCII)", ft_isascii(58)},
	{59, "Semicolon (ASCII)", ft_isascii(59)},
	{60, "Less Than Sign (ASCII)", ft_isascii(60)},
	{61, "Equals Sign (ASCII)", ft_isascii(61)},
	{62, "Greater Than Sign (ASCII)", ft_isascii(62)},
	{63, "Question Mark (ASCII)", ft_isascii(63)},
	{64, "At Sign (ASCII)", ft_isascii(64)},
	{65, "uppercase letter A (ASCII)", ft_isascii(65)},
	{66, "uppercase letter B (ASCII)", ft_isascii(66)},
	{67, "uppercase letter C (ASCII)", ft_isascii(67)},
	{68, "uppercase letter D (ASCII)", ft_isascii(68)},
	{69, "uppercase letter E (ASCII)", ft_isascii(69)},
	{70, "uppercase letter F (ASCII)", ft_isascii(70)},
	{71, "uppercase letter G (ASCII)", ft_isascii(71)},
	{72, "uppercase letter H (ASCII)", ft_isascii(72)},
	{73, "uppercase letter I (ASCII)", ft_isascii(73)},
	{74, "uppercase letter J (ASCII)", ft_isascii(74)},
	{75, "uppercase letter K (ASCII)", ft_isascii(75)},
	{76, "uppercase letter L (ASCII)", ft_isascii(76)},
	{77, "uppercase letter M (ASCII)", ft_isascii(77)},
	{78, "uppercase letter N (ASCII)", ft_isascii(78)},
	{79, "uppercase letter O (ASCII)", ft_isascii(79)},
	{80, "uppercase letter P (ASCII)", ft_isascii(80)},
	{81, "uppercase letter Q (ASCII)", ft_isascii(81)},
	{82, "uppercase letter R (ASCII)", ft_isascii(82)},
	{83, "uppercase letter S (ASCII)", ft_isascii(83)},
	{84, "uppercase letter T (ASCII)", ft_isascii(84)},
	{85, "uppercase letter U (ASCII)", ft_isascii(85)},
	{86, "uppercase letter V (ASCII)", ft_isascii(86)},
	{87, "uppercase letter W (ASCII)", ft_isascii(87)},
	{88, "uppercase letter X (ASCII)", ft_isascii(88)},
	{89, "uppercase letter Y (ASCII)", ft_isascii(89)},
	{90, "uppercase letter Z (ASCII)", ft_isascii(90)},
	{91, "Left Square Bracket (ASCII)", ft_isascii(91)},
	{92, "Backslash (ASCII)", ft_isascii(92)},
	{93, "Right Square Bracket (ASCII)", ft_isascii(93)},
	{94, "Circumflex Accent (ASCII)", ft_isascii(94)},
	{95, "Underscore (ASCII)", ft_isascii(95)},
	{96, "Grave Accent (ASCII)", ft_isascii(96)},
	{97, "lowercase letter a (ASCII)", ft_isascii(97)},
	{98, "lowercase letter b (ASCII)", ft_isascii(98)},
	{99, "lowercase letter c (ASCII)", ft_isascii(99)},
	{100, "lowercase letter d (ASCII)", ft_isascii(100)},
	{101, "lowercase letter e (ASCII)", ft_isascii(101)},
	{102, "lowercase letter f (ASCII)", ft_isascii(102)},
	{103, "lowercase letter g (ASCII)", ft_isascii(103)},
	{104, "lowercase letter h (ASCII)", ft_isascii(104)},
	{105, "lowercase letter i (ASCII)", ft_isascii(105)},
	{106, "lowercase letter j (ASCII)", ft_isascii(106)},
	{107, "lowercase letter k (ASCII)", ft_isascii(107)},
	{108, "lowercase letter l (ASCII)", ft_isascii(108)},
	{109, "lowercase letter m (ASCII)", ft_isascii(109)},
	{110, "lowercase letter n (ASCII)", ft_isascii(110)},
	{111, "lowercase letter o (ASCII)", ft_isascii(111)},
	{112, "lowercase letter p (ASCII)", ft_isascii(112)},
	{113, "lowercase letter q (ASCII)", ft_isascii(113)},
	{114, "lowercase letter r (ASCII)", ft_isascii(114)},
	{115, "lowercase letter s (ASCII)", ft_isascii(115)},
	{116, "lowercase letter t (ASCII)", ft_isascii(116)},
	{117, "lowercase letter u (ASCII)", ft_isascii(117)},
	{118, "lowercase letter v (ASCII)", ft_isascii(118)},
	{119, "lowercase letter w (ASCII)", ft_isascii(119)},
	{120, "lowercase letter x (ASCII)", ft_isascii(120)},
	{121, "lowercase letter y (ASCII)", ft_isascii(121)},
	{122, "lowercase letter z (ASCII)", ft_isascii(122)},
	{123, "Left Curly Bracket (ASCII)", ft_isascii(123)},
	{124, "Vertical Bar (ASCII)", ft_isascii(124)},
	{125, "Right Curly Bracket (ASCII)", ft_isascii(125)},
	{126, "Tilde (ASCII)", ft_isascii(126)},
	{127, "Delete (ASCII)", ft_isascii(127)},
	{128, "Ç (Latin Capital Letter C With Cedilla)", ft_isascii(128)},
	{129, "ü (Latin Small Letter U With Diaeresis)", ft_isascii(129)},
	{139, "ï (Latin Small Letter I With Diaeresis)", ft_isascii(139)},
	{149, "ò (Latin Small Letter O With Grave)", ft_isascii(149)},
	{159, "ƒ (Latin Small Letter F With Hook)", ft_isascii(159)},
	{169, "⌐ (Reversed Not Sign)", ft_isascii(169)},
	{170, "¬ (Not Sign)", ft_isascii(170)},
	{255, "  (Non-Breaking Space)", ft_isascii(255)},
	{256, "Ā (Latin Capital Letter A With Macron)", ft_isascii(256)},
	{257, "ā (Latin Small Letter A With Macron)", ft_isascii(257)},
	{500, "Ǵ (Latin Capital Letter G With Acute)", ft_isascii(500)},
	{501, "ǵ (Latin Small Letter G With Acute)", ft_isascii(501)},
	{700, "ˬ (Modifier Letter Raised Up Arrow)", ft_isascii(700)},
	{701, "˭ (Modifier Letter Raised Down Arrow)", ft_isascii(701)},
	{888, "͸ (Greek Small Letter Pamphylian Digamma)", ft_isascii(888)},
	{889, "͹ (Greek Kolon)", ft_isascii(889)},
	{1000, "Ϩ (Coptic Capital Letter Hori)", ft_isascii(1000)},
	{1001, "ϩ (Coptic Small Letter Hori)", ft_isascii(1001)},
	{1500, "᎐ (Cherokee Letter Ye)", ft_isascii(1500)},
	{1501, "᎑ (Cherokee Letter Yi)", ft_isascii(1501)},
	{2000, "῰ (Greek Ypogegrammeni)", ft_isascii(2000)},
	{2001, "῱ (Greek Prosgegrammeni)", ft_isascii(2001)},
	{3000, "〰 (Wavy Dash)", ft_isascii(3000)},
	{3001, "〱 (Vertical Kana Repeat Mark)", ft_isascii(3001)},
	{4000, "ী (Bengali Vowel Sign Ii)", ft_isascii(4000)},
	{4001, "ু (Bengali Vowel Sign U)", ft_isascii(4001)},
	{5000, "ᚠ (Runic Letter Fehu Feoh Fe F)", ft_isascii(5000)},
	{5001, "ᚡ (Runic Letter V)", ft_isascii(5001)}
	};

    printf(">>>>> TESTING ft_isascii\n");
    printf("Here I'm testing for extended ASCII (0-255) ISO-8859-1 and beyond.\n");
	printf("As long the expected and the result values are non-zero, it's a PASS.\n");

	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);


	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_isascii: FAIL");
    else
        ft_save_results("ft_isascii: OK");


    printf("\n");
    return (0);
}
