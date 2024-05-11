/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:41:14 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/29 20:39:36 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int ft_tolower(int c);

typedef struct
{
    int input;
    char *comment;
    int result;
} Test;

typedef struct failed_test_node
{
    Test test;
    struct failed_test_node *next;
} FailedTestNode;

// Function to execute and print test results
void run_test(Test test, FailedTestNode **failed_tests, int *fail_count)
{
    int expected = tolower(test.input);

    if (expected == test.result)
    {
        printf(COLOR_GREEN "%d, " COLOR_RESET, test.input);
    }
    else
    {
        printf(COLOR_RED "(%d) " COLOR_RESET, test.input);
        FailedTestNode *new_node = malloc(sizeof(FailedTestNode));
        new_node->test = test; // the test that failed
        new_node->next = *failed_tests;
        *failed_tests = new_node;
        (*fail_count)++;
    }

    
}

#define NUM_TESTS 256

int main(void)
{
    int fail_counter = 0;

	FailedTestNode *failed_tests = NULL;


    Test tests[NUM_TESTS] = {
        {0, "NULL character (ASCII)", ft_tolower(0)},
        {1, "Start of Heading (ASCII)", ft_tolower(1)},
        {2, "Start of Text (ASCII)", ft_tolower(2)},
        {3, "End of Text (ASCII)", ft_tolower(3)},
        {4, "End of Transmission (ASCII)", ft_tolower(4)},
        {5, "Enquiry (ASCII)", ft_tolower(5)},
        {6, "Acknowledge (ASCII)", ft_tolower(6)},
        {7, "Bell (ASCII)", ft_tolower(7)},
        {8, "Backspace (ASCII)", ft_tolower(8)},
        {9, "Horizontal Tab (ASCII)", ft_tolower(9)},
        {10, "Line Feed (ASCII)", ft_tolower(10)},
        {11, "Vertical Tab (ASCII)", ft_tolower(11)},
        {12, "Form Feed (ASCII)", ft_tolower(12)},
        {13, "Carriage Return (ASCII)", ft_tolower(13)},
        {14, "Shift Out (ASCII)", ft_tolower(14)},
        {15, "Shift In (ASCII)", ft_tolower(15)},
        {16, "Data Link Escape (ASCII)", ft_tolower(16)},
        {17, "Device Control 1 (ASCII)", ft_tolower(17)},
        {18, "Device Control 2 (ASCII)", ft_tolower(18)},
        {19, "Device Control 3 (ASCII)", ft_tolower(19)},
        {20, "Device Control 4 (ASCII)", ft_tolower(20)},
        {21, "Negative Acknowledge (ASCII)", ft_tolower(21)},
        {22, "Synchronous Idle (ASCII)", ft_tolower(22)},
        {23, "End of Transmission Block (ASCII)", ft_tolower(23)},
        {24, "Cancel (ASCII)", ft_tolower(24)},
        {25, "End of Medium (ASCII)", ft_tolower(25)},
        {26, "Substitute (ASCII)", ft_tolower(26)},
        {27, "Escape (ASCII)", ft_tolower(27)},
        {28, "File Separator (ASCII)", ft_tolower(28)},
        {29, "Group Separator (ASCII)", ft_tolower(29)},
        {30, "Record Separator (ASCII)", ft_tolower(30)},
        {31, "Unit Separator (ASCII)", ft_tolower(31)},
        {32, "Space (ASCII)", ft_tolower(32)},
        {33, "Exclamation Mark (ASCII)", ft_tolower(33)},
        {34, "Double Quote (ASCII)", ft_tolower(34)},
        {35, "Number Sign (ASCII)", ft_tolower(35)},
        {36, "Dollar Sign (ASCII)", ft_tolower(36)},
        {37, "Percent Sign (ASCII)", ft_tolower(37)},
        {38, "Ampersand (ASCII)", ft_tolower(38)},
        {39, "Single Quote (ASCII)", ft_tolower(39)},
        {40, "Left Parenthesis (ASCII)", ft_tolower(40)},
        {41, "Right Parenthesis (ASCII)", ft_tolower(41)},
        {42, "Asterisk (ASCII)", ft_tolower(42)},
        {43, "Plus Sign (ASCII)", ft_tolower(43)},
        {44, "Comma (ASCII)", ft_tolower(44)},
        {45, "Hyphen-Minus (ASCII)", ft_tolower(45)},
        {46, "Full Stop (ASCII)", ft_tolower(46)},
        {47, "Slash (ASCII)", ft_tolower(47)},
        {48, "Digit 0 (ASCII)", ft_tolower(48)},
        {49, "Digit 1 (ASCII)", ft_tolower(49)},
        {50, "Digit 2 (ASCII)", ft_tolower(50)},
        {51, "Digit 3 (ASCII)", ft_tolower(51)},
        {52, "Digit 4 (ASCII)", ft_tolower(52)},
        {53, "Digit 5 (ASCII)", ft_tolower(53)},
        {54, "Digit 6 (ASCII)", ft_tolower(54)},
        {55, "Digit 7 (ASCII)", ft_tolower(55)},
        {56, "Digit 8 (ASCII)", ft_tolower(56)},
        {57, "Digit 9 (ASCII)", ft_tolower(57)},
        {58, "Colon (ASCII)", ft_tolower(58)},
        {59, "Semicolon (ASCII)", ft_tolower(59)},
        {60, "Less Than Sign (ASCII)", ft_tolower(60)},
        {61, "Equals Sign (ASCII)", ft_tolower(61)},
        {62, "Greater Than Sign (ASCII)", ft_tolower(62)},
        {63, "Question Mark (ASCII)", ft_tolower(63)},
        {64, "At Sign (ASCII)", ft_tolower(64)},
        {65, "Uppercase Letter A (ASCII)", ft_tolower(65)},
        {66, "Uppercase Letter B (ASCII)", ft_tolower(66)},
        {67, "Uppercase Letter C (ASCII)", ft_tolower(67)},
        {68, "Uppercase Letter D (ASCII)", ft_tolower(68)},
        {69, "Uppercase Letter E (ASCII)", ft_tolower(69)},
        {70, "Uppercase Letter F (ASCII)", ft_tolower(70)},
        {71, "Uppercase Letter G (ASCII)", ft_tolower(71)},
        {72, "Uppercase Letter H (ASCII)", ft_tolower(72)},
        {73, "Uppercase Letter I (ASCII)", ft_tolower(73)},
        {74, "Uppercase Letter J (ASCII)", ft_tolower(74)},
        {75, "Uppercase Letter K (ASCII)", ft_tolower(75)},
        {76, "Uppercase Letter L (ASCII)", ft_tolower(76)},
        {77, "Uppercase Letter M (ASCII)", ft_tolower(77)},
        {78, "Uppercase Letter N (ASCII)", ft_tolower(78)},
        {79, "Uppercase Letter O (ASCII)", ft_tolower(79)},
        {80, "Uppercase Letter P (ASCII)", ft_tolower(80)},
        {81, "Uppercase Letter Q (ASCII)", ft_tolower(81)},
        {82, "Uppercase Letter R (ASCII)", ft_tolower(82)},
        {83, "Uppercase Letter S (ASCII)", ft_tolower(83)},
        {84, "Uppercase Letter T (ASCII)", ft_tolower(84)},
        {85, "Uppercase Letter U (ASCII)", ft_tolower(85)},
        {86, "Uppercase Letter V (ASCII)", ft_tolower(86)},
        {87, "Uppercase Letter W (ASCII)", ft_tolower(87)},
        {88, "Uppercase Letter X (ASCII)", ft_tolower(88)},
        {89, "Uppercase Letter Y (ASCII)", ft_tolower(89)},
        {90, "Uppercase Letter Z (ASCII)", ft_tolower(90)},
        {91, "Left Square Bracket (ASCII)", ft_tolower(91)},
        {92, "Backslash (ASCII)", ft_tolower(92)},
        {93, "Right Square Bracket (ASCII)", ft_tolower(93)},
        {94, "Circumflex Accent (ASCII)", ft_tolower(94)},
        {95, "Underscore (ASCII)", ft_tolower(95)},
        {96, "Grave Accent (ASCII)", ft_tolower(96)},
        {97, "Lowercase Letter a (ASCII)", ft_tolower(97)},
        {98, "Lowercase Letter b (ASCII)", ft_tolower(98)},
        {99, "Lowercase Letter c (ASCII)", ft_tolower(99)},
        {100, "Lowercase Letter d (ASCII)", ft_tolower(100)},
        {101, "Lowercase Letter e (ASCII)", ft_tolower(101)},
        {102, "Lowercase Letter f (ASCII)", ft_tolower(102)},
        {103, "Lowercase Letter g (ASCII)", ft_tolower(103)},
        {104, "Lowercase Letter h (ASCII)", ft_tolower(104)},
        {105, "Lowercase Letter i (ASCII)", ft_tolower(105)},
        {106, "Lowercase Letter j (ASCII)", ft_tolower(106)},
        {107, "Lowercase Letter k (ASCII)", ft_tolower(107)},
        {108, "Lowercase Letter l (ASCII)", ft_tolower(108)},
        {109, "Lowercase Letter m (ASCII)", ft_tolower(109)},
        {110, "Lowercase Letter n (ASCII)", ft_tolower(110)},
        {111, "Lowercase Letter o (ASCII)", ft_tolower(111)},
        {112, "Lowercase Letter p (ASCII)", ft_tolower(112)},
        {113, "Lowercase Letter q (ASCII)", ft_tolower(113)},
        {114, "Lowercase Letter r (ASCII)", ft_tolower(114)},
        {115, "Lowercase Letter s (ASCII)", ft_tolower(115)},
        {116, "Lowercase Letter t (ASCII)", ft_tolower(116)},
        {117, "Lowercase Letter u (ASCII)", ft_tolower(117)},
        {118, "Lowercase Letter v (ASCII)", ft_tolower(118)},
        {119, "Lowercase Letter w (ASCII)", ft_tolower(119)},
        {120, "Lowercase Letter x (ASCII)", ft_tolower(120)},
        {121, "Lowercase Letter y (ASCII)", ft_tolower(121)},
        {122, "Lowercase Letter z (ASCII)", ft_tolower(122)},
        {123, "Left Curly Bracket (ASCII)", ft_tolower(123)},
        {124, "Vertical Bar (ASCII)", ft_tolower(124)},
        {125, "Right Curly Bracket (ASCII)", ft_tolower(125)},
        {126, "Tilde (ASCII)", ft_tolower(126)},
        {127, "Delete (ASCII)", ft_tolower(127)},
        // Extended ASCII
        {128, "Ç (Latin Capital Letter C With Cedilla)", ft_tolower(128)},
        {129, "ü (Latin Small Letter U With Diaeresis)", ft_tolower(129)},
        {130, "é (Latin Small Letter E With Acute)", ft_tolower(130)},
        {131, "â (Latin Small Letter A With Circumflex)", ft_tolower(131)},
        {132, "ä (Latin Small Letter A With Diaeresis)", ft_tolower(132)},
        {133, "à (Latin Small Letter A With Grave)", ft_tolower(133)},
        {134, "å (Latin Small Letter A With Ring Above)", ft_tolower(134)},
        {135, "ç (Latin Small Letter C With Cedilla)", ft_tolower(135)},
        {136, "ê (Latin Small Letter E With Circumflex)", ft_tolower(136)},
        {137, "ë (Latin Small Letter E With Diaeresis)", ft_tolower(137)},
        {138, "è (Latin Small Letter E With Grave)", ft_tolower(138)},
        {139, "ï (Latin Small Letter I With Diaeresis)", ft_tolower(139)},
        {140, "î (Latin Small Letter I With Circumflex)", ft_tolower(140)},
        {141, "ì (Latin Small Letter I With Grave)", ft_tolower(141)},
        {142, "Ä (Latin Capital Letter A With Diaeresis)", ft_tolower(142)},
        {143, "Å (Latin Capital Letter A With Ring Above)", ft_tolower(143)},
        {144, "É (Latin Capital Letter E With Acute)", ft_tolower(144)},
        {145, "æ (Latin Small Letter Ae)", ft_tolower(145)},
        {146, "Æ (Latin Capital Letter Ae)", ft_tolower(146)},
        {147, "ô (Latin Small Letter O With Circumflex)", ft_tolower(147)},
        {148, "ö (Latin Small Letter O With Diaeresis)", ft_tolower(148)},
        {149, "ò (Latin Small Letter O With Grave)", ft_tolower(149)},
        {150, "û (Latin Small Letter U With Circumflex)", ft_tolower(150)},
        {151, "ù (Latin Small Letter U With Grave)", ft_tolower(151)},
        {152, "ÿ (Latin Small Letter Y With Diaeresis)", ft_tolower(152)},
        {153, "Ö (Latin Capital Letter O With Diaeresis)", ft_tolower(153)},
        {154, "Ü (Latin Capital Letter U With Diaeresis)", ft_tolower(154)},
        {155, "ø (Latin Small Letter O With Stroke)", ft_tolower(155)},
        {156, "£ (Pound Sign)", ft_tolower(156)},
        {157, "Ø (Latin Capital Letter O With Stroke)", ft_tolower(157)},
        {158, "× (Multiplication Sign)", ft_tolower(158)},
        {159, "ƒ (Latin Small Letter F With Hook)", ft_tolower(159)},
        {160, "á (Latin Small Letter A With Acute)", ft_tolower(160)},
        {161, "í (Latin Small Letter I With Acute)", ft_tolower(161)},
        {162, "ó (Latin Small Letter O With Acute)", ft_tolower(162)},
        {163, "ú (Latin Small Letter U With Acute)", ft_tolower(163)},
        {164, "ñ (Latin Small Letter N With Tilde)", ft_tolower(164)},
        {165, "Ñ (Latin Capital Letter N With Tilde)", ft_tolower(165)},
        {166, "ª (Feminine Ordinal Indicator)", ft_tolower(166)},
        {167, "º (Masculine Ordinal Indicator)", ft_tolower(167)},
        {168, "¿ (Inverted Question Mark)", ft_tolower(168)},
        {169, "⌐ (Reversed Not Sign)", ft_tolower(169)},
        {170, "¬ (Not Sign)", ft_tolower(170)},
        {171, "½ (Vulgar Fraction One Half)", ft_tolower(171)},
        {172, "¼ (Vulgar Fraction One Quarter)", ft_tolower(172)},
        {173, "¡ (Inverted Exclamation Mark)", ft_tolower(173)},
        {174, "« (Left-Pointing Double Angle Quotation Mark)", ft_tolower(174)},
        {175, "» (Right-Pointing Double Angle Quotation Mark)", ft_tolower(175)},
        {176, "░ (Light Shade)", ft_tolower(176)},
        {177, "▒ (Medium Shade)", ft_tolower(177)},
        {178, "▓ (Dark Shade)", ft_tolower(178)},
        {179, "│ (Box Drawings Light Vertical)", ft_tolower(179)},
        {180, "┤ (Box Drawings Light Vertical And Left)", ft_tolower(180)},
        {181, "Á (Latin Capital Letter A With Acute)", ft_tolower(181)},
        {182, "Â (Latin Capital Letter A With Circumflex)", ft_tolower(182)},
        {183, "À (Latin Capital Letter A With Grave)", ft_tolower(183)},
        {184, "© (Copyright Sign)", ft_tolower(184)},
        {185, "╣ (Box Drawings Double Vertical And Left)", ft_tolower(185)},
        {186, "║ (Box Drawings Double Vertical)", ft_tolower(186)},
        {187, "╗ (Box Drawings Double Down And Left)", ft_tolower(187)},
        {188, "╝ (Box Drawings Double Up And Left)", ft_tolower(188)},
        {189, "¢ (Cent Sign)", ft_tolower(189)},
        {190, "¥ (Yen Sign)", ft_tolower(190)},
        {191, "┐ (Box Drawings Light Down And Left)", ft_tolower(191)},
        {192, "└ (Box Drawings Light Up And Right)", ft_tolower(192)},
        {193, "┴ (Box Drawings Light Up And Horizontal)", ft_tolower(193)},
        {194, "┬ (Box Drawings Light Down And Horizontal)", ft_tolower(194)},
        {195, "├ (Box Drawings Light Vertical And Right)", ft_tolower(195)},
        {196, "─ (Box Drawings Light Horizontal)", ft_tolower(196)},
        {197, "┼ (Box Drawings Light Vertical And Horizontal)", ft_tolower(197)},
        {198, "ã (Latin Small Letter A With Tilde)", ft_tolower(198)},
        {199, "Ã (Latin Capital Letter A With Tilde)", ft_tolower(199)},
        {200, "╚ (Box Drawings Double Up And Right)", ft_tolower(200)},
        {201, "╔ (Box Drawings Double Down And Right)", ft_tolower(201)},
        {202, "╩ (Box Drawings Double Up And Horizontal)", ft_tolower(202)},
        {203, "╦ (Box Drawings Double Down And Horizontal)", ft_tolower(203)},
        {204, "╠ (Box Drawings Double Vertical And Right)", ft_tolower(204)},
        {205, "═ (Box Drawings Double Horizontal)", ft_tolower(205)},
        {206, "╬ (Box Drawings Double Vertical And Horizontal)", ft_tolower(206)},
        {207, "¤ (Currency Sign)", ft_tolower(207)},
        {208, "ð (Latin Small Letter Eth)", ft_tolower(208)},
        {209, "Ð (Latin Capital Letter Eth)", ft_tolower(209)},
        {210, "Ê (Latin Capital Letter E With Circumflex)", ft_tolower(210)},
        {211, "Ë (Latin Capital Letter E With Diaeresis)", ft_tolower(211)},
        {212, "È (Latin Capital Letter E With Grave)", ft_tolower(212)},
        {213, "ı (Latin Small Letter Dotless I)", ft_tolower(213)},
        {214, "Í (Latin Capital Letter I With Acute)", ft_tolower(214)},
        {215, "Î (Latin Capital Letter I With Circumflex)", ft_tolower(215)},
        {216, "Ï (Latin Capital Letter I With Diaeresis)", ft_tolower(216)},
        {217, "┘ (Box Drawings Light Up And Left)", ft_tolower(217)},
        {218, "┌ (Box Drawings Light Down And Right)", ft_tolower(218)},
        {219, "█ (Full Block)", ft_tolower(219)},
        {220, "▄ (Lower Half Block)", ft_tolower(220)},
        {221, "¦ (Broken Bar)", ft_tolower(221)},
        {222, "Ì (Latin Capital Letter I With Grave)", ft_tolower(222)},
        {223, "▀ (Upper Half Block)", ft_tolower(223)},
        {224, "Ó (Latin Capital Letter O With Acute)", ft_tolower(224)},
        {225, "ß (Latin Small Letter Sharp S)", ft_tolower(225)},
        {226, "Ô (Latin Capital Letter O With Circumflex)", ft_tolower(226)},
        {227, "Ò (Latin Capital Letter O With Grave)", ft_tolower(227)},
        {228, "õ (Latin Small Letter O With Tilde)", ft_tolower(228)},
        {229, "Õ (Latin Capital Letter O With Tilde)", ft_tolower(229)},
        {230, "µ (Micro Sign)", ft_tolower(230)},
        {231, "þ (Latin Small Letter Thorn)", ft_tolower(231)},
        {232, "Þ (Latin Capital Letter Thorn)", ft_tolower(232)},
        {233, "Ú (Latin Capital Letter U With Acute)", ft_tolower(233)},
        {234, "Û (Latin Capital Letter U With Circumflex)", ft_tolower(234)},
        {235, "Ù (Latin Capital Letter U With Grave)", ft_tolower(235)},
        {236, "ý (Latin Small Letter Y With Acute)", ft_tolower(236)},
        {237, "Ý (Latin Capital Letter Y With Acute)", ft_tolower(237)},
        {238, "¯ (Macron)", ft_tolower(238)},
        {239, "´ (Acute Accent)", ft_tolower(239)},
        {240, "≡ (Congruence Sign)", ft_tolower(240)},
        {241, "± (Plus-Minus Sign)", ft_tolower(241)},
        {242, "‗ (Double Low Line)", ft_tolower(242)},
        {243, "¾ (Vulgar Fraction Three Quarters)", ft_tolower(243)},
        {244, "¶ (Pilcrow Sign)", ft_tolower(244)},
        {245, "§ (Section Sign)", ft_tolower(245)},
        {246, "÷ (Division Sign)", ft_tolower(246)},
        {247, "¸ (Cedilla)", ft_tolower(247)},
        {248, "° (Degree Sign)", ft_tolower(248)},
        {249, "¨ (Diaeresis)", ft_tolower(249)},
        {250, "· (Middle Dot)", ft_tolower(250)},
        {251, "¹ (Superscript One)", ft_tolower(251)},
        {252, "³ (Superscript Three)", ft_tolower(252)},
        {253, "² (Superscript Two)", ft_tolower(253)},
        {254, "■ (Black Square)", ft_tolower(254)},
        {255, "nbsp (Non-Breaking Space)", ft_tolower(255)}
        // Additional Unicode characters
        // {256, "Ā (Latin Capital Letter A With Macron)", ft_tolower(256)},
        // {257, "ā (Latin Small Letter A With Macron)", ft_tolower(257)},
        // {258, "Ă (Latin Capital Letter A with Breve)", ft_tolower(258)},
        // {259, "ă (Latin Small Letter A with Breve)", ft_tolower(259)},
        // {260, "Ą (Latin Capital Letter A with Ogonek)", ft_tolower(260)},
        // {261, "ą (Latin Small Letter A with Ogonek)", ft_tolower(261)},
        // {262, "Ć (Latin Capital Letter C with Acute)", ft_tolower(262)},
        // {263, "ć (Latin Small Letter C with Acute)", ft_tolower(263)},
        // {264, "Ĉ (Latin Capital Letter C with Circumflex)", ft_tolower(264)},
        // {265, "ĉ (Latin Small Letter C with Circumflex)", ft_tolower(265)},
        // {266, "Ċ (Latin Capital Letter C with Dot Above)", ft_tolower(266)},
        // {267, "ċ (Latin Small Letter C with Dot Above)", ft_tolower(267)},
        // {268, "Č (Latin Capital Letter C with Caron)", ft_tolower(268)},
        // {269, "č (Latin Small Letter C with Caron)", ft_tolower(269)},
        // {270, "Ď (Latin Capital Letter D with Caron)", ft_tolower(270)},
        // {271, "ď (Latin Small Letter D with Caron)", ft_tolower(271)},
        // {272, "Đ (Latin Capital Letter D with Stroke)", ft_tolower(272)},
        // {273, "đ (Latin Small Letter D with Stroke)", ft_tolower(273)},
        // {274, "Ē (Latin Capital Letter E with Macron)", ft_tolower(274)},
        // {275, "ē (Latin Small Letter E with Macron)", ft_tolower(275)},
        // {276, "Ĕ (Latin Capital Letter E with Breve)", ft_tolower(276)},
        // {277, "ĕ (Latin Small Letter E with Breve)", ft_tolower(277)},
        // {278, "Ė (Latin Capital Letter E with Dot Above)", ft_tolower(278)},
        // {279, "ė (Latin Small Letter E with Dot Above)", ft_tolower(279)},
        // {280, "Ę (Latin Capital Letter E with Ogonek)", ft_tolower(280)},
        // {281, "ę (Latin Small Letter E with Ogonek)", ft_tolower(281)},
        // {282, "Ě (Latin Capital Letter E with Caron)", ft_tolower(282)},
        // {283, "ě (Latin Small Letter E with Caron)", ft_tolower(283)},
        // {284, "Ĝ (Latin Capital Letter G with Circumflex)", ft_tolower(284)},
        // {285, "ĝ (Latin Small Letter G with Circumflex)", ft_tolower(285)},
        // {286, "Ğ (Latin Capital Letter G with Breve)", ft_tolower(286)},
        // {287, "ğ (Latin Small Letter G with Breve)", ft_tolower(287)},
        // {288, "Ġ (Latin Capital Letter G with Dot Above)", ft_tolower(288)},
        // {289, "ġ (Latin Small Letter G with Dot Above)", ft_tolower(289)},
        // {290, "Ģ (Latin Capital Letter G with Cedilla)", ft_tolower(290)},
        // {291, "ģ (Latin Small Letter G with Cedilla)", ft_tolower(291)},
        // {292, "Ĥ (Latin Capital Letter H with Circumflex)", ft_tolower(292)},
        // {293, "ĥ (Latin Small Letter H with Circumflex)", ft_tolower(293)},
        // {294, "Ħ (Latin Capital Letter H with Stroke)", ft_tolower(294)},
        // {295, "ħ (Latin Small Letter H with Stroke)", ft_tolower(295)},
        // {296, "Ĩ (Latin Capital Letter I with Tilde)", ft_tolower(296)},
        // {297, "ĩ (Latin Small Letter I with Tilde)", ft_tolower(297)},
        // {298, "Ī (Latin Capital Letter I with Macron)", ft_tolower(298)},
        // {299, "ī (Latin Small Letter I with Macron)", ft_tolower(299)},
        // {0x1F600, "😀 (Grinning Face Emoji)", ft_tolower(0x1F600)},  // Hex input for emoji
        // {0x1F601, "😁 (Grinning Face With Smiling Eyes Emoji)", ft_tolower(0x1F601)},
        // {0x1F602, "😂 (Face With Tears of Joy Emoji)", ft_tolower(0x1F602)},
        // {0x1F605, "😅 (Smiling Face With Open Mouth & Cold Sweat)", ft_tolower(0x1F605)},
        // {0x1F609, "😉 (Winking Face)", ft_tolower(0x1F609)},
        // {-1, "Negative One", ft_tolower(-1)},  // Negative integer
        // {-128, "Negative One Twenty-Eight", ft_tolower(-128)},
        // {-255, "Negative Two Fifty-Five", ft_tolower(-255)},
        // {0xFFFFFF, "Hex 0xFFFFFF", ft_tolower(0xFFFFFF)},  // Large hex input
        // {0xFFFFFFF, "Hex 0xFFFFFFF", ft_tolower(0xFFFFFFF)}
		};

	printf(COLOR_BLUE ">TESTING ft_tolower------------------------------------------------------------------------\n" COLOR_RESET);
    printf("Here I'm testing for extended ASCII (0-255) ISO-8859-1 and beyond.\n");

	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
    run_test(tests[i], &failed_tests, &fail_counter);

	printf("\n\n");

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_tolower: FAIL");
    else
        ft_save_results("ft_tolower: OK");

    FailedTestNode *current = failed_tests;
    while (current != NULL)
    {
        printf(COLOR_RED "Failed: input = %d (%s) expected = %d | result = %d \n" COLOR_RESET, current->test.input, current->test.comment, tolower(current->test.input), ft_tolower(current->test.input));
        FailedTestNode *next = current->next;
        free(current);
        current = next;
    }

    printf("\n\n");
    return (0);
}
