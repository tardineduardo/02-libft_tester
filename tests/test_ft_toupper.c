/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:41:14 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/29 20:39:36 by eduribei         ###   ########.fr       */
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

typedef struct failed_test_node
{
    Test test;
    struct failed_test_node *next;
} FailedTestNode;

// Function to execute and print test results
void run_test(Test test, FailedTestNode **failed_tests, int *fail_count)
{
    int expected = toupper(test.input);

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
        {0, "NULL character (ASCII)", ft_toupper(0)},
        {1, "Start of Heading (ASCII)", ft_toupper(1)},
        {2, "Start of Text (ASCII)", ft_toupper(2)},
        {3, "End of Text (ASCII)", ft_toupper(3)},
        {4, "End of Transmission (ASCII)", ft_toupper(4)},
        {5, "Enquiry (ASCII)", ft_toupper(5)},
        {6, "Acknowledge (ASCII)", ft_toupper(6)},
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
        {21, "Negative Acknowledge (ASCII)", ft_toupper(21)},
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
        {65, "Uppercase Letter A (ASCII)", ft_toupper(65)},
        {66, "Uppercase Letter B (ASCII)", ft_toupper(66)},
        {67, "Uppercase Letter C (ASCII)", ft_toupper(67)},
        {68, "Uppercase Letter D (ASCII)", ft_toupper(68)},
        {69, "Uppercase Letter E (ASCII)", ft_toupper(69)},
        {70, "Uppercase Letter F (ASCII)", ft_toupper(70)},
        {71, "Uppercase Letter G (ASCII)", ft_toupper(71)},
        {72, "Uppercase Letter H (ASCII)", ft_toupper(72)},
        {73, "Uppercase Letter I (ASCII)", ft_toupper(73)},
        {74, "Uppercase Letter J (ASCII)", ft_toupper(74)},
        {75, "Uppercase Letter K (ASCII)", ft_toupper(75)},
        {76, "Uppercase Letter L (ASCII)", ft_toupper(76)},
        {77, "Uppercase Letter M (ASCII)", ft_toupper(77)},
        {78, "Uppercase Letter N (ASCII)", ft_toupper(78)},
        {79, "Uppercase Letter O (ASCII)", ft_toupper(79)},
        {80, "Uppercase Letter P (ASCII)", ft_toupper(80)},
        {81, "Uppercase Letter Q (ASCII)", ft_toupper(81)},
        {82, "Uppercase Letter R (ASCII)", ft_toupper(82)},
        {83, "Uppercase Letter S (ASCII)", ft_toupper(83)},
        {84, "Uppercase Letter T (ASCII)", ft_toupper(84)},
        {85, "Uppercase Letter U (ASCII)", ft_toupper(85)},
        {86, "Uppercase Letter V (ASCII)", ft_toupper(86)},
        {87, "Uppercase Letter W (ASCII)", ft_toupper(87)},
        {88, "Uppercase Letter X (ASCII)", ft_toupper(88)},
        {89, "Uppercase Letter Y (ASCII)", ft_toupper(89)},
        {90, "Uppercase Letter Z (ASCII)", ft_toupper(90)},
        {91, "Left Square Bracket (ASCII)", ft_toupper(91)},
        {92, "Backslash (ASCII)", ft_toupper(92)},
        {93, "Right Square Bracket (ASCII)", ft_toupper(93)},
        {94, "Circumflex Accent (ASCII)", ft_toupper(94)},
        {95, "Underscore (ASCII)", ft_toupper(95)},
        {96, "Grave Accent (ASCII)", ft_toupper(96)},
        {97, "Lowercase Letter a (ASCII)", ft_toupper(97)},
        {98, "Lowercase Letter b (ASCII)", ft_toupper(98)},
        {99, "Lowercase Letter c (ASCII)", ft_toupper(99)},
        {100, "Lowercase Letter d (ASCII)", ft_toupper(100)},
        {101, "Lowercase Letter e (ASCII)", ft_toupper(101)},
        {102, "Lowercase Letter f (ASCII)", ft_toupper(102)},
        {103, "Lowercase Letter g (ASCII)", ft_toupper(103)},
        {104, "Lowercase Letter h (ASCII)", ft_toupper(104)},
        {105, "Lowercase Letter i (ASCII)", ft_toupper(105)},
        {106, "Lowercase Letter j (ASCII)", ft_toupper(106)},
        {107, "Lowercase Letter k (ASCII)", ft_toupper(107)},
        {108, "Lowercase Letter l (ASCII)", ft_toupper(108)},
        {109, "Lowercase Letter m (ASCII)", ft_toupper(109)},
        {110, "Lowercase Letter n (ASCII)", ft_toupper(110)},
        {111, "Lowercase Letter o (ASCII)", ft_toupper(111)},
        {112, "Lowercase Letter p (ASCII)", ft_toupper(112)},
        {113, "Lowercase Letter q (ASCII)", ft_toupper(113)},
        {114, "Lowercase Letter r (ASCII)", ft_toupper(114)},
        {115, "Lowercase Letter s (ASCII)", ft_toupper(115)},
        {116, "Lowercase Letter t (ASCII)", ft_toupper(116)},
        {117, "Lowercase Letter u (ASCII)", ft_toupper(117)},
        {118, "Lowercase Letter v (ASCII)", ft_toupper(118)},
        {119, "Lowercase Letter w (ASCII)", ft_toupper(119)},
        {120, "Lowercase Letter x (ASCII)", ft_toupper(120)},
        {121, "Lowercase Letter y (ASCII)", ft_toupper(121)},
        {122, "Lowercase Letter z (ASCII)", ft_toupper(122)},
        {123, "Left Curly Bracket (ASCII)", ft_toupper(123)},
        {124, "Vertical Bar (ASCII)", ft_toupper(124)},
        {125, "Right Curly Bracket (ASCII)", ft_toupper(125)},
        {126, "Tilde (ASCII)", ft_toupper(126)},
        {127, "Delete (ASCII)", ft_toupper(127)},
        // Extended ASCII
        {128, "Ç (Latin Capital Letter C With Cedilla)", ft_toupper(128)},
        {129, "ü (Latin Small Letter U With Diaeresis)", ft_toupper(129)},
        {130, "é (Latin Small Letter E With Acute)", ft_toupper(130)},
        {131, "â (Latin Small Letter A With Circumflex)", ft_toupper(131)},
        {132, "ä (Latin Small Letter A With Diaeresis)", ft_toupper(132)},
        {133, "à (Latin Small Letter A With Grave)", ft_toupper(133)},
        {134, "å (Latin Small Letter A With Ring Above)", ft_toupper(134)},
        {135, "ç (Latin Small Letter C With Cedilla)", ft_toupper(135)},
        {136, "ê (Latin Small Letter E With Circumflex)", ft_toupper(136)},
        {137, "ë (Latin Small Letter E With Diaeresis)", ft_toupper(137)},
        {138, "è (Latin Small Letter E With Grave)", ft_toupper(138)},
        {139, "ï (Latin Small Letter I With Diaeresis)", ft_toupper(139)},
        {140, "î (Latin Small Letter I With Circumflex)", ft_toupper(140)},
        {141, "ì (Latin Small Letter I With Grave)", ft_toupper(141)},
        {142, "Ä (Latin Capital Letter A With Diaeresis)", ft_toupper(142)},
        {143, "Å (Latin Capital Letter A With Ring Above)", ft_toupper(143)},
        {144, "É (Latin Capital Letter E With Acute)", ft_toupper(144)},
        {145, "æ (Latin Small Letter Ae)", ft_toupper(145)},
        {146, "Æ (Latin Capital Letter Ae)", ft_toupper(146)},
        {147, "ô (Latin Small Letter O With Circumflex)", ft_toupper(147)},
        {148, "ö (Latin Small Letter O With Diaeresis)", ft_toupper(148)},
        {149, "ò (Latin Small Letter O With Grave)", ft_toupper(149)},
        {150, "û (Latin Small Letter U With Circumflex)", ft_toupper(150)},
        {151, "ù (Latin Small Letter U With Grave)", ft_toupper(151)},
        {152, "ÿ (Latin Small Letter Y With Diaeresis)", ft_toupper(152)},
        {153, "Ö (Latin Capital Letter O With Diaeresis)", ft_toupper(153)},
        {154, "Ü (Latin Capital Letter U With Diaeresis)", ft_toupper(154)},
        {155, "ø (Latin Small Letter O With Stroke)", ft_toupper(155)},
        {156, "£ (Pound Sign)", ft_toupper(156)},
        {157, "Ø (Latin Capital Letter O With Stroke)", ft_toupper(157)},
        {158, "× (Multiplication Sign)", ft_toupper(158)},
        {159, "ƒ (Latin Small Letter F With Hook)", ft_toupper(159)},
        {160, "á (Latin Small Letter A With Acute)", ft_toupper(160)},
        {161, "í (Latin Small Letter I With Acute)", ft_toupper(161)},
        {162, "ó (Latin Small Letter O With Acute)", ft_toupper(162)},
        {163, "ú (Latin Small Letter U With Acute)", ft_toupper(163)},
        {164, "ñ (Latin Small Letter N With Tilde)", ft_toupper(164)},
        {165, "Ñ (Latin Capital Letter N With Tilde)", ft_toupper(165)},
        {166, "ª (Feminine Ordinal Indicator)", ft_toupper(166)},
        {167, "º (Masculine Ordinal Indicator)", ft_toupper(167)},
        {168, "¿ (Inverted Question Mark)", ft_toupper(168)},
        {169, "⌐ (Reversed Not Sign)", ft_toupper(169)},
        {170, "¬ (Not Sign)", ft_toupper(170)},
        {171, "½ (Vulgar Fraction One Half)", ft_toupper(171)},
        {172, "¼ (Vulgar Fraction One Quarter)", ft_toupper(172)},
        {173, "¡ (Inverted Exclamation Mark)", ft_toupper(173)},
        {174, "« (Left-Pointing Double Angle Quotation Mark)", ft_toupper(174)},
        {175, "» (Right-Pointing Double Angle Quotation Mark)", ft_toupper(175)},
        {176, "░ (Light Shade)", ft_toupper(176)},
        {177, "▒ (Medium Shade)", ft_toupper(177)},
        {178, "▓ (Dark Shade)", ft_toupper(178)},
        {179, "│ (Box Drawings Light Vertical)", ft_toupper(179)},
        {180, "┤ (Box Drawings Light Vertical And Left)", ft_toupper(180)},
        {181, "Á (Latin Capital Letter A With Acute)", ft_toupper(181)},
        {182, "Â (Latin Capital Letter A With Circumflex)", ft_toupper(182)},
        {183, "À (Latin Capital Letter A With Grave)", ft_toupper(183)},
        {184, "© (Copyright Sign)", ft_toupper(184)},
        {185, "╣ (Box Drawings Double Vertical And Left)", ft_toupper(185)},
        {186, "║ (Box Drawings Double Vertical)", ft_toupper(186)},
        {187, "╗ (Box Drawings Double Down And Left)", ft_toupper(187)},
        {188, "╝ (Box Drawings Double Up And Left)", ft_toupper(188)},
        {189, "¢ (Cent Sign)", ft_toupper(189)},
        {190, "¥ (Yen Sign)", ft_toupper(190)},
        {191, "┐ (Box Drawings Light Down And Left)", ft_toupper(191)},
        {192, "└ (Box Drawings Light Up And Right)", ft_toupper(192)},
        {193, "┴ (Box Drawings Light Up And Horizontal)", ft_toupper(193)},
        {194, "┬ (Box Drawings Light Down And Horizontal)", ft_toupper(194)},
        {195, "├ (Box Drawings Light Vertical And Right)", ft_toupper(195)},
        {196, "─ (Box Drawings Light Horizontal)", ft_toupper(196)},
        {197, "┼ (Box Drawings Light Vertical And Horizontal)", ft_toupper(197)},
        {198, "ã (Latin Small Letter A With Tilde)", ft_toupper(198)},
        {199, "Ã (Latin Capital Letter A With Tilde)", ft_toupper(199)},
        {200, "╚ (Box Drawings Double Up And Right)", ft_toupper(200)},
        {201, "╔ (Box Drawings Double Down And Right)", ft_toupper(201)},
        {202, "╩ (Box Drawings Double Up And Horizontal)", ft_toupper(202)},
        {203, "╦ (Box Drawings Double Down And Horizontal)", ft_toupper(203)},
        {204, "╠ (Box Drawings Double Vertical And Right)", ft_toupper(204)},
        {205, "═ (Box Drawings Double Horizontal)", ft_toupper(205)},
        {206, "╬ (Box Drawings Double Vertical And Horizontal)", ft_toupper(206)},
        {207, "¤ (Currency Sign)", ft_toupper(207)},
        {208, "ð (Latin Small Letter Eth)", ft_toupper(208)},
        {209, "Ð (Latin Capital Letter Eth)", ft_toupper(209)},
        {210, "Ê (Latin Capital Letter E With Circumflex)", ft_toupper(210)},
        {211, "Ë (Latin Capital Letter E With Diaeresis)", ft_toupper(211)},
        {212, "È (Latin Capital Letter E With Grave)", ft_toupper(212)},
        {213, "ı (Latin Small Letter Dotless I)", ft_toupper(213)},
        {214, "Í (Latin Capital Letter I With Acute)", ft_toupper(214)},
        {215, "Î (Latin Capital Letter I With Circumflex)", ft_toupper(215)},
        {216, "Ï (Latin Capital Letter I With Diaeresis)", ft_toupper(216)},
        {217, "┘ (Box Drawings Light Up And Left)", ft_toupper(217)},
        {218, "┌ (Box Drawings Light Down And Right)", ft_toupper(218)},
        {219, "█ (Full Block)", ft_toupper(219)},
        {220, "▄ (Lower Half Block)", ft_toupper(220)},
        {221, "¦ (Broken Bar)", ft_toupper(221)},
        {222, "Ì (Latin Capital Letter I With Grave)", ft_toupper(222)},
        {223, "▀ (Upper Half Block)", ft_toupper(223)},
        {224, "Ó (Latin Capital Letter O With Acute)", ft_toupper(224)},
        {225, "ß (Latin Small Letter Sharp S)", ft_toupper(225)},
        {226, "Ô (Latin Capital Letter O With Circumflex)", ft_toupper(226)},
        {227, "Ò (Latin Capital Letter O With Grave)", ft_toupper(227)},
        {228, "õ (Latin Small Letter O With Tilde)", ft_toupper(228)},
        {229, "Õ (Latin Capital Letter O With Tilde)", ft_toupper(229)},
        {230, "µ (Micro Sign)", ft_toupper(230)},
        {231, "þ (Latin Small Letter Thorn)", ft_toupper(231)},
        {232, "Þ (Latin Capital Letter Thorn)", ft_toupper(232)},
        {233, "Ú (Latin Capital Letter U With Acute)", ft_toupper(233)},
        {234, "Û (Latin Capital Letter U With Circumflex)", ft_toupper(234)},
        {235, "Ù (Latin Capital Letter U With Grave)", ft_toupper(235)},
        {236, "ý (Latin Small Letter Y With Acute)", ft_toupper(236)},
        {237, "Ý (Latin Capital Letter Y With Acute)", ft_toupper(237)},
        {238, "¯ (Macron)", ft_toupper(238)},
        {239, "´ (Acute Accent)", ft_toupper(239)},
        {240, "≡ (Congruence Sign)", ft_toupper(240)},
        {241, "± (Plus-Minus Sign)", ft_toupper(241)},
        {242, "‗ (Double Low Line)", ft_toupper(242)},
        {243, "¾ (Vulgar Fraction Three Quarters)", ft_toupper(243)},
        {244, "¶ (Pilcrow Sign)", ft_toupper(244)},
        {245, "§ (Section Sign)", ft_toupper(245)},
        {246, "÷ (Division Sign)", ft_toupper(246)},
        {247, "¸ (Cedilla)", ft_toupper(247)},
        {248, "° (Degree Sign)", ft_toupper(248)},
        {249, "¨ (Diaeresis)", ft_toupper(249)},
        {250, "· (Middle Dot)", ft_toupper(250)},
        {251, "¹ (Superscript One)", ft_toupper(251)},
        {252, "³ (Superscript Three)", ft_toupper(252)},
        {253, "² (Superscript Two)", ft_toupper(253)},
        {254, "■ (Black Square)", ft_toupper(254)},
        {255, "nbsp (Non-Breaking Space)", ft_toupper(255)}
        // Additional Unicode characters
        // {256, "Ā (Latin Capital Letter A With Macron)", ft_toupper(256)},
        // {257, "ā (Latin Small Letter A With Macron)", ft_toupper(257)},
        // {258, "Ă (Latin Capital Letter A with Breve)", ft_toupper(258)},
        // {259, "ă (Latin Small Letter A with Breve)", ft_toupper(259)},
        // {260, "Ą (Latin Capital Letter A with Ogonek)", ft_toupper(260)},
        // {261, "ą (Latin Small Letter A with Ogonek)", ft_toupper(261)},
        // {262, "Ć (Latin Capital Letter C with Acute)", ft_toupper(262)},
        // {263, "ć (Latin Small Letter C with Acute)", ft_toupper(263)},
        // {264, "Ĉ (Latin Capital Letter C with Circumflex)", ft_toupper(264)},
        // {265, "ĉ (Latin Small Letter C with Circumflex)", ft_toupper(265)},
        // {266, "Ċ (Latin Capital Letter C with Dot Above)", ft_toupper(266)},
        // {267, "ċ (Latin Small Letter C with Dot Above)", ft_toupper(267)},
        // {268, "Č (Latin Capital Letter C with Caron)", ft_toupper(268)},
        // {269, "č (Latin Small Letter C with Caron)", ft_toupper(269)},
        // {270, "Ď (Latin Capital Letter D with Caron)", ft_toupper(270)},
        // {271, "ď (Latin Small Letter D with Caron)", ft_toupper(271)},
        // {272, "Đ (Latin Capital Letter D with Stroke)", ft_toupper(272)},
        // {273, "đ (Latin Small Letter D with Stroke)", ft_toupper(273)},
        // {274, "Ē (Latin Capital Letter E with Macron)", ft_toupper(274)},
        // {275, "ē (Latin Small Letter E with Macron)", ft_toupper(275)},
        // {276, "Ĕ (Latin Capital Letter E with Breve)", ft_toupper(276)},
        // {277, "ĕ (Latin Small Letter E with Breve)", ft_toupper(277)},
        // {278, "Ė (Latin Capital Letter E with Dot Above)", ft_toupper(278)},
        // {279, "ė (Latin Small Letter E with Dot Above)", ft_toupper(279)},
        // {280, "Ę (Latin Capital Letter E with Ogonek)", ft_toupper(280)},
        // {281, "ę (Latin Small Letter E with Ogonek)", ft_toupper(281)},
        // {282, "Ě (Latin Capital Letter E with Caron)", ft_toupper(282)},
        // {283, "ě (Latin Small Letter E with Caron)", ft_toupper(283)},
        // {284, "Ĝ (Latin Capital Letter G with Circumflex)", ft_toupper(284)},
        // {285, "ĝ (Latin Small Letter G with Circumflex)", ft_toupper(285)},
        // {286, "Ğ (Latin Capital Letter G with Breve)", ft_toupper(286)},
        // {287, "ğ (Latin Small Letter G with Breve)", ft_toupper(287)},
        // {288, "Ġ (Latin Capital Letter G with Dot Above)", ft_toupper(288)},
        // {289, "ġ (Latin Small Letter G with Dot Above)", ft_toupper(289)},
        // {290, "Ģ (Latin Capital Letter G with Cedilla)", ft_toupper(290)},
        // {291, "ģ (Latin Small Letter G with Cedilla)", ft_toupper(291)},
        // {292, "Ĥ (Latin Capital Letter H with Circumflex)", ft_toupper(292)},
        // {293, "ĥ (Latin Small Letter H with Circumflex)", ft_toupper(293)},
        // {294, "Ħ (Latin Capital Letter H with Stroke)", ft_toupper(294)},
        // {295, "ħ (Latin Small Letter H with Stroke)", ft_toupper(295)},
        // {296, "Ĩ (Latin Capital Letter I with Tilde)", ft_toupper(296)},
        // {297, "ĩ (Latin Small Letter I with Tilde)", ft_toupper(297)},
        // {298, "Ī (Latin Capital Letter I with Macron)", ft_toupper(298)},
        // {299, "ī (Latin Small Letter I with Macron)", ft_toupper(299)},
        // {0x1F600, "😀 (Grinning Face Emoji)", ft_toupper(0x1F600)},  // Hex input for emoji
        // {0x1F601, "😁 (Grinning Face With Smiling Eyes Emoji)", ft_toupper(0x1F601)},
        // {0x1F602, "😂 (Face With Tears of Joy Emoji)", ft_toupper(0x1F602)},
        // {0x1F605, "😅 (Smiling Face With Open Mouth & Cold Sweat)", ft_toupper(0x1F605)},
        // {0x1F609, "😉 (Winking Face)", ft_toupper(0x1F609)},
        // {-1, "Negative One", ft_toupper(-1)},  // Negative integer
        // {-128, "Negative One Twenty-Eight", ft_toupper(-128)},
        // {-255, "Negative Two Fifty-Five", ft_toupper(-255)},
        // {0xFFFFFF, "Hex 0xFFFFFF", ft_toupper(0xFFFFFF)},  // Large hex input
        // {0xFFFFFFF, "Hex 0xFFFFFFF", ft_toupper(0xFFFFFFF)}
		};

	printf(COLOR_BLUE ">TESTING ft_toupper------------------------------------------------------------------------\n" COLOR_RESET);
    printf("Here I'm testing for extended ASCII (0-255) ISO-8859-1 and beyond.\n");

	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
    run_test(tests[i], &failed_tests, &fail_counter);

	printf("\n\n");

	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_toupper: FAIL");
    else
        ft_save_results("ft_toupper: OK");

    FailedTestNode *current = failed_tests;
    while (current != NULL)
    {
        printf(COLOR_RED "Failed: input = %d (%s) expected = %d | result = %d \n" COLOR_RESET, current->test.input, current->test.comment, toupper(current->test.input), ft_toupper(current->test.input));
        FailedTestNode *next = current->next;
        free(current);
        current = next;
    }

    printf("\n\n");
    return (0);
}
