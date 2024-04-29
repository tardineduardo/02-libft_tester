/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:41:14 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/29 20:39:33 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int ft_toupper(int c);

typedef struct
{
    int input;
    char *comment;
    int result;
} Test;

// Function to execute and print test results
void run_test(Test test, int *fail_count)
{
    int expected = toupper(test.input);
	
    if (expected == test.result)
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
	{0, "NULL character (ASCII)", ft_toupper(0)},
	{1, "Start of Heading (ASCII)", ft_toupper(1)},
	{2, "Start of Text (ASCII)", ft_toupper(2)},
	{3, "End of Text (ASCII)", ft_toupper(3)},
	{4, "End of Transmission (ASCII)", ft_toupper(4)},
	{5, "Enquiry (ASCII)", ft_toupper(5)},
	{6, "Acknowledgment (ASCII)", ft_toupper(6)},
	{7, "Bell (ASCII)", ft_toupper(7)},
	{8, "Backspace (ASCII)", ft_toupper(8)},
	{9, "Horizontal Tab (ASCII)", ft_toupper(9)},
	{10, "Line Feed (ASCII)", ft_toupper(10)},
	{11, "Vertical Tab (ASCII)", ft_toupper(11)},
	{12, "Form Feed (ASCII)", ft_toupper(12)},
	{13, "Carriage Return (ASCII)", ft_toupper(13)},
	{14, "Shift Out (ASCII)", ft_toupper(14)},
	{15, "Shift In (ASCII)", ft_toupper(15)},
	{16, "Data Link Escape (ASCII)", ft_toupper(16)},
	{17, "Device Control 1 (ASCII)", ft_toupper(17)},
	{18, "Device Control 2 (ASCII)", ft_toupper(18)},
	{19, "Device Control 3 (ASCII)", ft_toupper(19)},
	{20, "Device Control 4 (ASCII)", ft_toupper(20)},
	{21, "Negative Acknowledgement (ASCII)", ft_toupper(21)},
	{22, "Synchronous Idle (ASCII)", ft_toupper(22)},
	{23, "End of Transmission Block (ASCII)", ft_toupper(23)},
	{24, "Cancel (ASCII)", ft_toupper(24)},
	{25, "End of Medium (ASCII)", ft_toupper(25)},
	{26, "Substitute (ASCII)", ft_toupper(26)},
	{27, "Escape (ASCII)", ft_toupper(27)},
	{28, "File Separator (ASCII)", ft_toupper(28)},
	{29, "Group Separator (ASCII)", ft_toupper(29)},
	{30, "Record Separator (ASCII)", ft_toupper(30)},
	{31, "Unit Separator (ASCII)", ft_toupper(31)},
	{32, "Space (ASCII)", ft_toupper(32)},
	{33, "Exclamation Mark (ASCII)", ft_toupper(33)},
	{34, "Double Quote (ASCII)", ft_toupper(34)},
	{35, "Number Sign (ASCII)", ft_toupper(35)},
	{36, "Dollar Sign (ASCII)", ft_toupper(36)},
	{37, "Percent Sign (ASCII)", ft_toupper(37)},
	{38, "Ampersand (ASCII)", ft_toupper(38)},
	{39, "Single Quote (ASCII)", ft_toupper(39)},
	{40, "Left Parenthesis (ASCII)", ft_toupper(40)},
	{41, "Right Parenthesis (ASCII)", ft_toupper(41)},
	{42, "Asterisk (ASCII)", ft_toupper(42)},
	{43, "Plus Sign (ASCII)", ft_toupper(43)},
	{44, "Comma (ASCII)", ft_toupper(44)},
	{45, "Hyphen-Minus (ASCII)", ft_toupper(45)},
	{46, "Full Stop (ASCII)", ft_toupper(46)},
	{47, "Slash (ASCII)", ft_toupper(47)},
	{48, "Digit 0 (ASCII)", ft_toupper(48)},
	{49, "Digit 1 (ASCII)", ft_toupper(49)},
	{50, "Digit 2 (ASCII)", ft_toupper(50)},
	{51, "Digit 3 (ASCII)", ft_toupper(51)},
	{52, "Digit 4 (ASCII)", ft_toupper(52)},
	{53, "Digit 5 (ASCII)", ft_toupper(53)},
	{54, "Digit 6 (ASCII)", ft_toupper(54)},
	{55, "Digit 7 (ASCII)", ft_toupper(55)},
	{56, "Digit 8 (ASCII)", ft_toupper(56)},
	{57, "Digit 9 (ASCII)", ft_toupper(57)},
	{58, "Colon (ASCII)", ft_toupper(58)},
	{59, "Semicolon (ASCII)", ft_toupper(59)},
	{60, "Less Than Sign (ASCII)", ft_toupper(60)},
	{61, "Equals Sign (ASCII)", ft_toupper(61)},
	{62, "Greater Than Sign (ASCII)", ft_toupper(62)},
	{63, "Question Mark (ASCII)", ft_toupper(63)},
	{64, "At Sign (ASCII)", ft_toupper(64)},
	{65, "uppercase letter A (ASCII)", ft_toupper(65)},
	{66, "uppercase letter B (ASCII)", ft_toupper(66)},
	{67, "uppercase letter C (ASCII)", ft_toupper(67)},
	{68, "uppercase letter D (ASCII)", ft_toupper(68)},
	{69, "uppercase letter E (ASCII)", ft_toupper(69)},
	{70, "uppercase letter F (ASCII)", ft_toupper(70)},
	{71, "uppercase letter G (ASCII)", ft_toupper(71)},
	{72, "uppercase letter H (ASCII)", ft_toupper(72)},
	{73, "uppercase letter I (ASCII)", ft_toupper(73)},
	{74, "uppercase letter J (ASCII)", ft_toupper(74)},
	{75, "uppercase letter K (ASCII)", ft_toupper(75)},
	{76, "uppercase letter L (ASCII)", ft_toupper(76)},
	{77, "uppercase letter M (ASCII)", ft_toupper(77)},
	{78, "uppercase letter N (ASCII)", ft_toupper(78)},
	{79, "uppercase letter O (ASCII)", ft_toupper(79)},
	{80, "uppercase letter P (ASCII)", ft_toupper(80)},
	{81, "uppercase letter Q (ASCII)", ft_toupper(81)},
	{82, "uppercase letter R (ASCII)", ft_toupper(82)},
	{83, "uppercase letter S (ASCII)", ft_toupper(83)},
	{84, "uppercase letter T (ASCII)", ft_toupper(84)},
	{85, "uppercase letter U (ASCII)", ft_toupper(85)},
	{86, "uppercase letter V (ASCII)", ft_toupper(86)},
	{87, "uppercase letter W (ASCII)", ft_toupper(87)},
	{88, "uppercase letter X (ASCII)", ft_toupper(88)},
	{89, "uppercase letter Y (ASCII)", ft_toupper(89)},
	{90, "uppercase letter Z (ASCII)", ft_toupper(90)},
	{91, "Left Square Bracket (ASCII)", ft_toupper(91)},
	{92, "Backslash (ASCII)", ft_toupper(92)},
	{93, "Right Square Bracket (ASCII)", ft_toupper(93)},
	{94, "Circumflex Accent (ASCII)", ft_toupper(94)},
	{95, "Underscore (ASCII)", ft_toupper(95)},
	{96, "Grave Accent (ASCII)", ft_toupper(96)},
	{97, "lowercase letter a (ASCII)", ft_toupper(97)},
	{98, "lowercase letter b (ASCII)", ft_toupper(98)},
	{99, "lowercase letter c (ASCII)", ft_toupper(99)},
	{100, "lowercase letter d (ASCII)", ft_toupper(100)},
	{101, "lowercase letter e (ASCII)", ft_toupper(101)},
	{102, "lowercase letter f (ASCII)", ft_toupper(102)},
	{103, "lowercase letter g (ASCII)", ft_toupper(103)},
	{104, "lowercase letter h (ASCII)", ft_toupper(104)},
	{105, "lowercase letter i (ASCII)", ft_toupper(105)},
	{106, "lowercase letter j (ASCII)", ft_toupper(106)},
	{107, "lowercase letter k (ASCII)", ft_toupper(107)},
	{108, "lowercase letter l (ASCII)", ft_toupper(108)},
	{109, "lowercase letter m (ASCII)", ft_toupper(109)},
	{110, "lowercase letter n (ASCII)", ft_toupper(110)},
	{111, "lowercase letter o (ASCII)", ft_toupper(111)},
	{112, "lowercase letter p (ASCII)", ft_toupper(112)},
	{113, "lowercase letter q (ASCII)", ft_toupper(113)},
	{114, "lowercase letter r (ASCII)", ft_toupper(114)},
	{115, "lowercase letter s (ASCII)", ft_toupper(115)},
	{116, "lowercase letter t (ASCII)", ft_toupper(116)},
	{117, "lowercase letter u (ASCII)", ft_toupper(117)},
	{118, "lowercase letter v (ASCII)", ft_toupper(118)},
	{119, "lowercase letter w (ASCII)", ft_toupper(119)},
	{120, "lowercase letter x (ASCII)", ft_toupper(120)},
	{121, "lowercase letter y (ASCII)", ft_toupper(121)},
	{122, "lowercase letter z (ASCII)", ft_toupper(122)},
	{123, "Left Curly Bracket (ASCII)", ft_toupper(123)},
	{124, "Vertical Bar (ASCII)", ft_toupper(124)},
	{125, "Right Curly Bracket (ASCII)", ft_toupper(125)},
	{126, "Tilde (ASCII)", ft_toupper(126)},
	{127, "Delete (ASCII)", ft_toupper(127)},
	{128, "Ç (Latin Capital Letter C With Cedilla)", ft_toupper(128)},
	{129, "ü (Latin Small Letter U With Diaeresis)", ft_toupper(129)},
	{139, "ï (Latin Small Letter I With Diaeresis)", ft_toupper(139)},
	{149, "ò (Latin Small Letter O With Grave)", ft_toupper(149)},
	{159, "ƒ (Latin Small Letter F With Hook)", ft_toupper(159)},
	{169, "⌐ (Reversed Not Sign)", ft_toupper(169)},
	{170, "¬ (Not Sign)", ft_toupper(170)},
	{255, "  (Non-Breaking Space)", ft_toupper(255)},
	{256, "Ā (Latin Capital Letter A With Macron)", ft_toupper(256)},
	{257, "ā (Latin Small Letter A With Macron)", ft_toupper(257)},
	{500, "Ǵ (Latin Capital Letter G With Acute)", ft_toupper(500)},
	{501, "ǵ (Latin Small Letter G With Acute)", ft_toupper(501)},
	{700, "ˬ (Modifier Letter Raised Up Arrow)", ft_toupper(700)},
	{701, "˭ (Modifier Letter Raised Down Arrow)", ft_toupper(701)},
	{888, "͸ (Greek Small Letter Pamphylian Digamma)", ft_toupper(888)},
	{889, "͹ (Greek Kolon)", ft_toupper(889)},
	{1000, "Ϩ (Coptic Capital Letter Hori)", ft_toupper(1000)},
	{1001, "ϩ (Coptic Small Letter Hori)", ft_toupper(1001)},
	{1500, "᎐ (Cherokee Letter Ye)", ft_toupper(1500)},
	{1501, "᎑ (Cherokee Letter Yi)", ft_toupper(1501)},
	{2000, "῰ (Greek Ypogegrammeni)", ft_toupper(2000)},
	{2001, "῱ (Greek Prosgegrammeni)", ft_toupper(2001)},
	{3000, "〰 (Wavy Dash)", ft_toupper(3000)},
	{3001, "〱 (Vertical Kana Repeat Mark)", ft_toupper(3001)},
	{4000, "ী (Bengali Vowel Sign Ii)", ft_toupper(4000)},
	{4001, "ু (Bengali Vowel Sign U)", ft_toupper(4001)},
	{5000, "ᚠ (Runic Letter Fehu Feoh Fe F)", ft_toupper(5000)},
	{5001, "ᚡ (Runic Letter V)", ft_toupper(5001)}
	};

    printf(">>>>> TESTING ft_toupper\n");
    printf("Here I'm testing for extended ASCII (0-255) ISO-8859-1 and beyond.\n");

	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
        run_test(tests[i], &fail_counter);


	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_toupper: FAIL");
    else
        ft_save_results("ft_toupper: OK");


    printf("\n");
    return (0);
}
