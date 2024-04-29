/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/29 20:50:24 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int ft_isprint(int c);

typedef struct
{
    int input;
    char *comment;
    int result;
} Test;

// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
    int expected = isprint(test.input);
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
	{0, "NULL character (ASCII)", ft_isprint(0)},
	{1, "Start of Heading (ASCII)", ft_isprint(1)},
	{2, "Start of Text (ASCII)", ft_isprint(2)},
	{3, "End of Text (ASCII)", ft_isprint(3)},
	{4, "End of Transmission (ASCII)", ft_isprint(4)},
	{5, "Enquiry (ASCII)", ft_isprint(5)},
	{6, "Acknowledgment (ASCII)", ft_isprint(6)},
	{7, "Bell (ASCII)", ft_isprint(7)},
	{8, "Backspace (ASCII)", ft_isprint(8)},
	{9, "Horizontal Tab (ASCII)", ft_isprint(9)},
	{10, "Line Feed (ASCII)", ft_isprint(10)},
	{11, "Vertical Tab (ASCII)", ft_isprint(11)},
	{12, "Form Feed (ASCII)", ft_isprint(12)},
	{13, "Carriage Return (ASCII)", ft_isprint(13)},
	{14, "Shift Out (ASCII)", ft_isprint(14)},
	{15, "Shift In (ASCII)", ft_isprint(15)},
	{16, "Data Link Escape (ASCII)", ft_isprint(16)},
	{17, "Device Control 1 (ASCII)", ft_isprint(17)},
	{18, "Device Control 2 (ASCII)", ft_isprint(18)},
	{19, "Device Control 3 (ASCII)", ft_isprint(19)},
	{20, "Device Control 4 (ASCII)", ft_isprint(20)},
	{21, "Negative Acknowledgement (ASCII)", ft_isprint(21)},
	{22, "Synchronous Idle (ASCII)", ft_isprint(22)},
	{23, "End of Transmission Block (ASCII)", ft_isprint(23)},
	{24, "Cancel (ASCII)", ft_isprint(24)},
	{25, "End of Medium (ASCII)", ft_isprint(25)},
	{26, "Substitute (ASCII)", ft_isprint(26)},
	{27, "Escape (ASCII)", ft_isprint(27)},
	{28, "File Separator (ASCII)", ft_isprint(28)},
	{29, "Group Separator (ASCII)", ft_isprint(29)},
	{30, "Record Separator (ASCII)", ft_isprint(30)},
	{31, "Unit Separator (ASCII)", ft_isprint(31)},
	{32, "Space (ASCII)", ft_isprint(32)},
	{33, "Exclamation Mark (ASCII)", ft_isprint(33)},
	{34, "Double Quote (ASCII)", ft_isprint(34)},
	{35, "Number Sign (ASCII)", ft_isprint(35)},
	{36, "Dollar Sign (ASCII)", ft_isprint(36)},
	{37, "Percent Sign (ASCII)", ft_isprint(37)},
	{38, "Ampersand (ASCII)", ft_isprint(38)},
	{39, "Single Quote (ASCII)", ft_isprint(39)},
	{40, "Left Parenthesis (ASCII)", ft_isprint(40)},
	{41, "Right Parenthesis (ASCII)", ft_isprint(41)},
	{42, "Asterisk (ASCII)", ft_isprint(42)},
	{43, "Plus Sign (ASCII)", ft_isprint(43)},
	{44, "Comma (ASCII)", ft_isprint(44)},
	{45, "Hyphen-Minus (ASCII)", ft_isprint(45)},
	{46, "Full Stop (ASCII)", ft_isprint(46)},
	{47, "Slash (ASCII)", ft_isprint(47)},
	{48, "Digit 0 (ASCII)", ft_isprint(48)},
	{49, "Digit 1 (ASCII)", ft_isprint(49)},
	{50, "Digit 2 (ASCII)", ft_isprint(50)},
	{51, "Digit 3 (ASCII)", ft_isprint(51)},
	{52, "Digit 4 (ASCII)", ft_isprint(52)},
	{53, "Digit 5 (ASCII)", ft_isprint(53)},
	{54, "Digit 6 (ASCII)", ft_isprint(54)},
	{55, "Digit 7 (ASCII)", ft_isprint(55)},
	{56, "Digit 8 (ASCII)", ft_isprint(56)},
	{57, "Digit 9 (ASCII)", ft_isprint(57)},
	{58, "Colon (ASCII)", ft_isprint(58)},
	{59, "Semicolon (ASCII)", ft_isprint(59)},
	{60, "Less Than Sign (ASCII)", ft_isprint(60)},
	{61, "Equals Sign (ASCII)", ft_isprint(61)},
	{62, "Greater Than Sign (ASCII)", ft_isprint(62)},
	{63, "Question Mark (ASCII)", ft_isprint(63)},
	{64, "At Sign (ASCII)", ft_isprint(64)},
	{65, "uppercase letter A (ASCII)", ft_isprint(65)},
	{66, "uppercase letter B (ASCII)", ft_isprint(66)},
	{67, "uppercase letter C (ASCII)", ft_isprint(67)},
	{68, "uppercase letter D (ASCII)", ft_isprint(68)},
	{69, "uppercase letter E (ASCII)", ft_isprint(69)},
	{70, "uppercase letter F (ASCII)", ft_isprint(70)},
	{71, "uppercase letter G (ASCII)", ft_isprint(71)},
	{72, "uppercase letter H (ASCII)", ft_isprint(72)},
	{73, "uppercase letter I (ASCII)", ft_isprint(73)},
	{74, "uppercase letter J (ASCII)", ft_isprint(74)},
	{75, "uppercase letter K (ASCII)", ft_isprint(75)},
	{76, "uppercase letter L (ASCII)", ft_isprint(76)},
	{77, "uppercase letter M (ASCII)", ft_isprint(77)},
	{78, "uppercase letter N (ASCII)", ft_isprint(78)},
	{79, "uppercase letter O (ASCII)", ft_isprint(79)},
	{80, "uppercase letter P (ASCII)", ft_isprint(80)},
	{81, "uppercase letter Q (ASCII)", ft_isprint(81)},
	{82, "uppercase letter R (ASCII)", ft_isprint(82)},
	{83, "uppercase letter S (ASCII)", ft_isprint(83)},
	{84, "uppercase letter T (ASCII)", ft_isprint(84)},
	{85, "uppercase letter U (ASCII)", ft_isprint(85)},
	{86, "uppercase letter V (ASCII)", ft_isprint(86)},
	{87, "uppercase letter W (ASCII)", ft_isprint(87)},
	{88, "uppercase letter X (ASCII)", ft_isprint(88)},
	{89, "uppercase letter Y (ASCII)", ft_isprint(89)},
	{90, "uppercase letter Z (ASCII)", ft_isprint(90)},
	{91, "Left Square Bracket (ASCII)", ft_isprint(91)},
	{92, "Backslash (ASCII)", ft_isprint(92)},
	{93, "Right Square Bracket (ASCII)", ft_isprint(93)},
	{94, "Circumflex Accent (ASCII)", ft_isprint(94)},
	{95, "Underscore (ASCII)", ft_isprint(95)},
	{96, "Grave Accent (ASCII)", ft_isprint(96)},
	{97, "lowercase letter a (ASCII)", ft_isprint(97)},
	{98, "lowercase letter b (ASCII)", ft_isprint(98)},
	{99, "lowercase letter c (ASCII)", ft_isprint(99)},
	{100, "lowercase letter d (ASCII)", ft_isprint(100)},
	{101, "lowercase letter e (ASCII)", ft_isprint(101)},
	{102, "lowercase letter f (ASCII)", ft_isprint(102)},
	{103, "lowercase letter g (ASCII)", ft_isprint(103)},
	{104, "lowercase letter h (ASCII)", ft_isprint(104)},
	{105, "lowercase letter i (ASCII)", ft_isprint(105)},
	{106, "lowercase letter j (ASCII)", ft_isprint(106)},
	{107, "lowercase letter k (ASCII)", ft_isprint(107)},
	{108, "lowercase letter l (ASCII)", ft_isprint(108)},
	{109, "lowercase letter m (ASCII)", ft_isprint(109)},
	{110, "lowercase letter n (ASCII)", ft_isprint(110)},
	{111, "lowercase letter o (ASCII)", ft_isprint(111)},
	{112, "lowercase letter p (ASCII)", ft_isprint(112)},
	{113, "lowercase letter q (ASCII)", ft_isprint(113)},
	{114, "lowercase letter r (ASCII)", ft_isprint(114)},
	{115, "lowercase letter s (ASCII)", ft_isprint(115)},
	{116, "lowercase letter t (ASCII)", ft_isprint(116)},
	{117, "lowercase letter u (ASCII)", ft_isprint(117)},
	{118, "lowercase letter v (ASCII)", ft_isprint(118)},
	{119, "lowercase letter w (ASCII)", ft_isprint(119)},
	{120, "lowercase letter x (ASCII)", ft_isprint(120)},
	{121, "lowercase letter y (ASCII)", ft_isprint(121)},
	{122, "lowercase letter z (ASCII)", ft_isprint(122)},
	{123, "Left Curly Bracket (ASCII)", ft_isprint(123)},
	{124, "Vertical Bar (ASCII)", ft_isprint(124)},
	{125, "Right Curly Bracket (ASCII)", ft_isprint(125)},
	{126, "Tilde (ASCII)", ft_isprint(126)},
	{127, "Delete (ASCII)", ft_isprint(127)},
	{128, "Ç (Latin Capital Letter C With Cedilla)", ft_isprint(128)},
	{129, "ü (Latin Small Letter U With Diaeresis)", ft_isprint(129)},
	{139, "ï (Latin Small Letter I With Diaeresis)", ft_isprint(139)},
	{149, "ò (Latin Small Letter O With Grave)", ft_isprint(149)},
	{159, "ƒ (Latin Small Letter F With Hook)", ft_isprint(159)},
	{169, "⌐ (Reversed Not Sign)", ft_isprint(169)},
	{170, "¬ (Not Sign)", ft_isprint(170)},
	{255, "  (Non-Breaking Space)", ft_isprint(255)},
	{256, "Ā (Latin Capital Letter A With Macron)", ft_isprint(256)},
	{257, "ā (Latin Small Letter A With Macron)", ft_isprint(257)},
	{500, "Ǵ (Latin Capital Letter G With Acute)", ft_isprint(500)},
	{501, "ǵ (Latin Small Letter G With Acute)", ft_isprint(501)},
	{700, "ˬ (Modifier Letter Raised Up Arrow)", ft_isprint(700)},
	{701, "˭ (Modifier Letter Raised Down Arrow)", ft_isprint(701)},
	{888, "͸ (Greek Small Letter Pamphylian Digamma)", ft_isprint(888)},
	{889, "͹ (Greek Kolon)", ft_isprint(889)},
	{1000, "Ϩ (Coptic Capital Letter Hori)", ft_isprint(1000)},
	{1001, "ϩ (Coptic Small Letter Hori)", ft_isprint(1001)},
	{1500, "᎐ (Cherokee Letter Ye)", ft_isprint(1500)},
	{1501, "᎑ (Cherokee Letter Yi)", ft_isprint(1501)},
	{2000, "῰ (Greek Ypogegrammeni)", ft_isprint(2000)},
	{2001, "῱ (Greek Prosgegrammeni)", ft_isprint(2001)},
	{3000, "〰 (Wavy Dash)", ft_isprint(3000)},
	{3001, "〱 (Vertical Kana Repeat Mark)", ft_isprint(3001)},
	{4000, "ী (Bengali Vowel Sign Ii)", ft_isprint(4000)},
	{4001, "ু (Bengali Vowel Sign U)", ft_isprint(4001)},
	{5000, "ᚠ (Runic Letter Fehu Feoh Fe F)", ft_isprint(5000)},
	{5001, "ᚡ (Runic Letter V)", ft_isprint(5001)}
	};

    printf(">>>>> TESTING ft_isprint\n");
    printf("Here I'm testing for extended ASCII (0-255) ISO-8859-1 and beyond.\n");
	printf("As long the expected and the result values are non-zero, it's a PASS.");


	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);


	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_isprint: FAIL");
    else
        ft_save_results("ft_isprint: OK");


    printf("\n");
    return (0);
}
