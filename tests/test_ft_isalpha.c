/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:22:00 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/29 18:51:10 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int ft_isalpha(int c);

typedef struct
{
    int input;
    char *comment;
} Test;


typedef struct failed_test_node
{
    Test test;
    struct failed_test_node *next;
} FailedTestNode;

// Function to execute and print test results
void run_test(Test test, FailedTestNode **failed_tests, int *fail_count)
{
    int expected = isalpha(test.input);
    int result = ft_isalpha(test.input);

    if ((result == 0) && (expected == 0))
    {
        printf(COLOR_GREEN "%d " COLOR_RESET, test.input);
    }
    else if ((result != 0) && (expected != 0))
    {
        printf(COLOR_GREEN "%d " COLOR_RESET, test.input);
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
        {0, "NULL character (ASCII)"},
        {1, "Start of Heading (ASCII)"},
        {2, "Start of Text (ASCII)"},
        {3, "End of Text (ASCII)"},
        {4, "End of Transmission (ASCII)"},
        {5, "Enquiry (ASCII)"},
        {6, "Acknowledge (ASCII)"},
        {7, "Bell (ASCII)"},
        {8, "Backspace (ASCII)"},
        {9, "Horizontal Tab (ASCII)"},
        {10, "Line Feed (ASCII)"},
        {11, "Vertical Tab (ASCII)"},
        {12, "Form Feed (ASCII)"},
        {13, "Carriage Return (ASCII)"},
        {14, "Shift Out (ASCII)"},
        {15, "Shift In (ASCII)"},
        {16, "Data Link Escape (ASCII)"},
        {17, "Device Control 1 (ASCII)"},
        {18, "Device Control 2 (ASCII)"},
        {19, "Device Control 3 (ASCII)"},
        {20, "Device Control 4 (ASCII)"},
        {21, "Negative Acknowledge (ASCII)"},
        {22, "Synchronous Idle (ASCII)"},
        {23, "End of Transmission Block (ASCII)"},
        {24, "Cancel (ASCII)"},
        {25, "End of Medium (ASCII)"},
        {26, "Substitute (ASCII)"},
        {27, "Escape (ASCII)"},
        {28, "File Separator (ASCII)"},
        {29, "Group Separator (ASCII)"},
        {30, "Record Separator (ASCII)"},
        {31, "Unit Separator (ASCII)"},
        {32, "Space (ASCII)"},
        {33, "Exclamation Mark (ASCII)"},
        {34, "Double Quote (ASCII)"},
        {35, "Number Sign (ASCII)"},
        {36, "Dollar Sign (ASCII)"},
        {37, "Percent Sign (ASCII)"},
        {38, "Ampersand (ASCII)"},
        {39, "Single Quote (ASCII)"},
        {40, "Left Parenthesis (ASCII)"},
        {41, "Right Parenthesis (ASCII)"},
        {42, "Asterisk (ASCII)"},
        {43, "Plus Sign (ASCII)"},
        {44, "Comma (ASCII)"},
        {45, "Hyphen-Minus (ASCII)"},
        {46, "Full Stop (ASCII)"},
        {47, "Slash (ASCII)"},
        {48, "Digit 0 (ASCII)"},
        {49, "Digit 1 (ASCII)"},
        {50, "Digit 2 (ASCII)"},
        {51, "Digit 3 (ASCII)"},
        {52, "Digit 4 (ASCII)"},
        {53, "Digit 5 (ASCII)"},
        {54, "Digit 6 (ASCII)"},
        {55, "Digit 7 (ASCII)"},
        {56, "Digit 8 (ASCII)"},
        {57, "Digit 9 (ASCII)"},
        {58, "Colon (ASCII)"},
        {59, "Semicolon (ASCII)"},
        {60, "Less Than Sign (ASCII)"},
        {61, "Equals Sign (ASCII)"},
        {62, "Greater Than Sign (ASCII)"},
        {63, "Question Mark (ASCII)"},
        {64, "At Sign (ASCII)"},
        {65, "Uppercase Letter A (ASCII)"},
        {66, "Uppercase Letter B (ASCII)"},
        {67, "Uppercase Letter C (ASCII)"},
        {68, "Uppercase Letter D (ASCII)"},
        {69, "Uppercase Letter E (ASCII)"},
        {70, "Uppercase Letter F (ASCII)"},
        {71, "Uppercase Letter G (ASCII)"},
        {72, "Uppercase Letter H (ASCII)"},
        {73, "Uppercase Letter I (ASCII)"},
        {74, "Uppercase Letter J (ASCII)"},
        {75, "Uppercase Letter K (ASCII)"},
        {76, "Uppercase Letter L (ASCII)"},
        {77, "Uppercase Letter M (ASCII)"},
        {78, "Uppercase Letter N (ASCII)"},
        {79, "Uppercase Letter O (ASCII)"},
        {80, "Uppercase Letter P (ASCII)"},
        {81, "Uppercase Letter Q (ASCII)"},
        {82, "Uppercase Letter R (ASCII)"},
        {83, "Uppercase Letter S (ASCII)"},
        {84, "Uppercase Letter T (ASCII)"},
        {85, "Uppercase Letter U (ASCII)"},
        {86, "Uppercase Letter V (ASCII)"},
        {87, "Uppercase Letter W (ASCII)"},
        {88, "Uppercase Letter X (ASCII)"},
        {89, "Uppercase Letter Y (ASCII)"},
        {90, "Uppercase Letter Z (ASCII)"},
        {91, "Left Square Bracket (ASCII)"},
        {92, "Backslash (ASCII)"},
        {93, "Right Square Bracket (ASCII)"},
        {94, "Circumflex Accent (ASCII)"},
        {95, "Underscore (ASCII)"},
        {96, "Grave Accent (ASCII)"},
        {97, "Lowercase Letter a (ASCII)"},
        {98, "Lowercase Letter b (ASCII)"},
        {99, "Lowercase Letter c (ASCII)"},
        {100, "Lowercase Letter d (ASCII)"},
        {101, "Lowercase Letter e (ASCII)"},
        {102, "Lowercase Letter f (ASCII)"},
        {103, "Lowercase Letter g (ASCII)"},
        {104, "Lowercase Letter h (ASCII)"},
        {105, "Lowercase Letter i (ASCII)"},
        {106, "Lowercase Letter j (ASCII)"},
        {107, "Lowercase Letter k (ASCII)"},
        {108, "Lowercase Letter l (ASCII)"},
        {109, "Lowercase Letter m (ASCII)"},
        {110, "Lowercase Letter n (ASCII)"},
        {111, "Lowercase Letter o (ASCII)"},
        {112, "Lowercase Letter p (ASCII)"},
        {113, "Lowercase Letter q (ASCII)"},
        {114, "Lowercase Letter r (ASCII)"},
        {115, "Lowercase Letter s (ASCII)"},
        {116, "Lowercase Letter t (ASCII)"},
        {117, "Lowercase Letter u (ASCII)"},
        {118, "Lowercase Letter v (ASCII)"},
        {119, "Lowercase Letter w (ASCII)"},
        {120, "Lowercase Letter x (ASCII)"},
        {121, "Lowercase Letter y (ASCII)"},
        {122, "Lowercase Letter z (ASCII)"},
        {123, "Left Curly Bracket (ASCII)"},
        {124, "Vertical Bar (ASCII)"},
        {125, "Right Curly Bracket (ASCII)"},
        {126, "Tilde (ASCII)"},
        {127, "Delete (ASCII)"},
        // Extended ASCII
        {128, "Ç (Latin Capital Letter C With Cedilla)"},
        {129, "ü (Latin Small Letter U With Diaeresis)"},
        {130, "é (Latin Small Letter E With Acute)"},
        {131, "â (Latin Small Letter A With Circumflex)"},
        {132, "ä (Latin Small Letter A With Diaeresis)"},
        {133, "à (Latin Small Letter A With Grave)"},
        {134, "å (Latin Small Letter A With Ring Above)"},
        {135, "ç (Latin Small Letter C With Cedilla)"},
        {136, "ê (Latin Small Letter E With Circumflex)"},
        {137, "ë (Latin Small Letter E With Diaeresis)"},
        {138, "è (Latin Small Letter E With Grave)"},
        {139, "ï (Latin Small Letter I With Diaeresis)"},
        {140, "î (Latin Small Letter I With Circumflex)"},
        {141, "ì (Latin Small Letter I With Grave)"},
        {142, "Ä (Latin Capital Letter A With Diaeresis)"},
        {143, "Å (Latin Capital Letter A With Ring Above)"},
        {144, "É (Latin Capital Letter E With Acute)"},
        {145, "æ (Latin Small Letter Ae)"},
        {146, "Æ (Latin Capital Letter Ae)"},
        {147, "ô (Latin Small Letter O With Circumflex)"},
        {148, "ö (Latin Small Letter O With Diaeresis)"},
        {149, "ò (Latin Small Letter O With Grave)"},
        {150, "û (Latin Small Letter U With Circumflex)"},
        {151, "ù (Latin Small Letter U With Grave)"},
        {152, "ÿ (Latin Small Letter Y With Diaeresis)"},
        {153, "Ö (Latin Capital Letter O With Diaeresis)"},
        {154, "Ü (Latin Capital Letter U With Diaeresis)"},
        {155, "ø (Latin Small Letter O With Stroke)"},
        {156, "£ (Pound Sign)"},
        {157, "Ø (Latin Capital Letter O With Stroke)"},
        {158, "× (Multiplication Sign)"},
        {159, "ƒ (Latin Small Letter F With Hook)"},
        {160, "á (Latin Small Letter A With Acute)"},
        {161, "í (Latin Small Letter I With Acute)"},
        {162, "ó (Latin Small Letter O With Acute)"},
        {163, "ú (Latin Small Letter U With Acute)"},
        {164, "ñ (Latin Small Letter N With Tilde)"},
        {165, "Ñ (Latin Capital Letter N With Tilde)"},
        {166, "ª (Feminine Ordinal Indicator)"},
        {167, "º (Masculine Ordinal Indicator)"},
        {168, "¿ (Inverted Question Mark)"},
        {169, "⌐ (Reversed Not Sign)"},
        {170, "¬ (Not Sign)"},
        {171, "½ (Vulgar Fraction One Half)"},
        {172, "¼ (Vulgar Fraction One Quarter)"},
        {173, "¡ (Inverted Exclamation Mark)"},
        {174, "« (Left-Pointing Double Angle Quotation Mark)"},
        {175, "» (Right-Pointing Double Angle Quotation Mark)"},
        {176, "░ (Light Shade)"},
        {177, "▒ (Medium Shade)"},
        {178, "▓ (Dark Shade)"},
        {179, "│ (Box Drawings Light Vertical)"},
        {180, "┤ (Box Drawings Light Vertical And Left)"},
        {181, "Á (Latin Capital Letter A With Acute)"},
        {182, "Â (Latin Capital Letter A With Circumflex)"},
        {183, "À (Latin Capital Letter A With Grave)"},
        {184, "© (Copyright Sign)"},
        {185, "╣ (Box Drawings Double Vertical And Left)"},
        {186, "║ (Box Drawings Double Vertical)"},
        {187, "╗ (Box Drawings Double Down And Left)"},
        {188, "╝ (Box Drawings Double Up And Left)"},
        {189, "¢ (Cent Sign)"},
        {190, "¥ (Yen Sign)"},
        {191, "┐ (Box Drawings Light Down And Left)"},
        {192, "└ (Box Drawings Light Up And Right)"},
        {193, "┴ (Box Drawings Light Up And Horizontal)"},
        {194, "┬ (Box Drawings Light Down And Horizontal)"},
        {195, "├ (Box Drawings Light Vertical And Right)"},
        {196, "─ (Box Drawings Light Horizontal)"},
        {197, "┼ (Box Drawings Light Vertical And Horizontal)"},
        {198, "ã (Latin Small Letter A With Tilde)"},
        {199, "Ã (Latin Capital Letter A With Tilde)"},
        {200, "╚ (Box Drawings Double Up And Right)"},
        {201, "╔ (Box Drawings Double Down And Right)"},
        {202, "╩ (Box Drawings Double Up And Horizontal)"},
        {203, "╦ (Box Drawings Double Down And Horizontal)"},
        {204, "╠ (Box Drawings Double Vertical And Right)"},
        {205, "═ (Box Drawings Double Horizontal)"},
        {206, "╬ (Box Drawings Double Vertical And Horizontal)"},
        {207, "¤ (Currency Sign)"},
        {208, "ð (Latin Small Letter Eth)"},
        {209, "Ð (Latin Capital Letter Eth)"},
        {210, "Ê (Latin Capital Letter E With Circumflex)"},
        {211, "Ë (Latin Capital Letter E With Diaeresis)"},
        {212, "È (Latin Capital Letter E With Grave)"},
        {213, "ı (Latin Small Letter Dotless I)"},
        {214, "Í (Latin Capital Letter I With Acute)"},
        {215, "Î (Latin Capital Letter I With Circumflex)"},
        {216, "Ï (Latin Capital Letter I With Diaeresis)"},
        {217, "┘ (Box Drawings Light Up And Left)"},
        {218, "┌ (Box Drawings Light Down And Right)"},
        {219, "█ (Full Block)"},
        {220, "▄ (Lower Half Block)"},
        {221, "¦ (Broken Bar)"},
        {222, "Ì (Latin Capital Letter I With Grave)"},
        {223, "▀ (Upper Half Block)"},
        {224, "Ó (Latin Capital Letter O With Acute)"},
        {225, "ß (Latin Small Letter Sharp S)"},
        {226, "Ô (Latin Capital Letter O With Circumflex)"},
        {227, "Ò (Latin Capital Letter O With Grave)"},
        {228, "õ (Latin Small Letter O With Tilde)"},
        {229, "Õ (Latin Capital Letter O With Tilde)"},
        {230, "µ (Micro Sign)"},
        {231, "þ (Latin Small Letter Thorn)"},
        {232, "Þ (Latin Capital Letter Thorn)"},
        {233, "Ú (Latin Capital Letter U With Acute)"},
        {234, "Û (Latin Capital Letter U With Circumflex)"},
        {235, "Ù (Latin Capital Letter U With Grave)"},
        {236, "ý (Latin Small Letter Y With Acute)"},
        {237, "Ý (Latin Capital Letter Y With Acute)"},
        {238, "¯ (Macron)"},
        {239, "´ (Acute Accent)"},
        {240, "≡ (Congruence Sign)"},
        {241, "± (Plus-Minus Sign)"},
        {242, "‗ (Double Low Line)"},
        {243, "¾ (Vulgar Fraction Three Quarters)"},
        {244, "¶ (Pilcrow Sign)"},
        {245, "§ (Section Sign)"},
        {246, "÷ (Division Sign)"},
        {247, "¸ (Cedilla)"},
        {248, "° (Degree Sign)"},
        {249, "¨ (Diaeresis)"},
        {250, "· (Middle Dot)"},
        {251, "¹ (Superscript One)"},
        {252, "³ (Superscript Three)"},
        {253, "² (Superscript Two)"},
        {254, "■ (Black Square)"},
        {255, "nbsp (Non-Breaking Space)"}
        // // Additional Unicode characters
        // {256, "Ā (Latin Capital Letter A With Macron)"},
        // {257, "ā (Latin Small Letter A With Macron)"},
        // {258, "Ă (Latin Capital Letter A with Breve)"},
        // {259, "ă (Latin Small Letter A with Breve)"},
        // {260, "Ą (Latin Capital Letter A with Ogonek)"},
        // {261, "ą (Latin Small Letter A with Ogonek)"},
        // {262, "Ć (Latin Capital Letter C with Acute)"},
        // {263, "ć (Latin Small Letter C with Acute)"},
        // {264, "Ĉ (Latin Capital Letter C with Circumflex)"},
        // {265, "ĉ (Latin Small Letter C with Circumflex)"},
        // {266, "Ċ (Latin Capital Letter C with Dot Above)"},
        // {267, "ċ (Latin Small Letter C with Dot Above)"},
        // {268, "Č (Latin Capital Letter C with Caron)"},
        // {269, "č (Latin Small Letter C with Caron)"},
        // {270, "Ď (Latin Capital Letter D with Caron)"},
        // {271, "ď (Latin Small Letter D with Caron)"},
        // {272, "Đ (Latin Capital Letter D with Stroke)"},
        // {273, "đ (Latin Small Letter D with Stroke)"},
        // {274, "Ē (Latin Capital Letter E with Macron)"},
        // {275, "ē (Latin Small Letter E with Macron)"},
        // {276, "Ĕ (Latin Capital Letter E with Breve)"},
        // {277, "ĕ (Latin Small Letter E with Breve)"},
        // {278, "Ė (Latin Capital Letter E with Dot Above)"},
        // {279, "ė (Latin Small Letter E with Dot Above)"},
        // {280, "Ę (Latin Capital Letter E with Ogonek)"},
        // {281, "ę (Latin Small Letter E with Ogonek)"},
        // {282, "Ě (Latin Capital Letter E with Caron)"},
        // {283, "ě (Latin Small Letter E with Caron)"},
        // {284, "Ĝ (Latin Capital Letter G with Circumflex)"},
        // {285, "ĝ (Latin Small Letter G with Circumflex)"},
        // {286, "Ğ (Latin Capital Letter G with Breve)"},
        // {287, "ğ (Latin Small Letter G with Breve)"},
        // {288, "Ġ (Latin Capital Letter G with Dot Above)"},
        // {289, "ġ (Latin Small Letter G with Dot Above)"},
        // {290, "Ģ (Latin Capital Letter G with Cedilla)"},
        // {291, "ģ (Latin Small Letter G with Cedilla)"},
        // {292, "Ĥ (Latin Capital Letter H with Circumflex)"},
        // {293, "ĥ (Latin Small Letter H with Circumflex)"},
        // {294, "Ħ (Latin Capital Letter H with Stroke)"},
        // {295, "ħ (Latin Small Letter H with Stroke)"},
        // {296, "Ĩ (Latin Capital Letter I with Tilde)"},
        // {297, "ĩ (Latin Small Letter I with Tilde)"},
        // {298, "Ī (Latin Capital Letter I with Macron)"},
        // {299, "ī (Latin Small Letter I with Macron)"},
        // {0x1F600, "😀 (Grinning Face Emoji)"},  // Hex input for emoji
        // {0x1F601, "😁 (Grinning Face With Smiling Eyes Emoji)"},
        // {0x1F602, "😂 (Face With Tears of Joy Emoji)"},
        // {0x1F605, "😅 (Smiling Face With Open Mouth & Cold Sweat)"},
		// {0x1F609, "😉 (Winking Face)"},
		// {-1, "Negative One"},  // Negative integer
        // {-128, "Negative One Twenty-Eight"},
        // {-255, "Negative Two Fifty-Five"},
        // {0xFFFFFF, "Hex 0xFFFFFF"},  // Large hex input
        // {0xFFFFFFF, "Hex 0xFFFFFFF"}
		};


	printf(COLOR_BLUE ">TESTING ft_isalpha------------------------------------------------------------------------\n" COLOR_RESET);
    printf("Comparing ft_isalpha (result) with isalpha/ctype.h (expected).\n");

	printf("As long the expected and the result values are non-zero, it's a PASS.\n");

	// RUNNING TESTS
	for (int i = 0; i < NUM_TESTS; i++)
    run_test(tests[i], &failed_tests, &fail_counter);

	printf("\n\n");


	// SAVING RESULTS
    if (fail_counter > 0)
        ft_save_results("ft_isalpha: FAIL");
    else
        ft_save_results("ft_isalpha: OK");

    FailedTestNode *current = failed_tests;
    while (current != NULL)
    {
        printf(COLOR_RED "Failed: input = %d (%s) expected = %d | result = %d \n" COLOR_RESET, current->test.input, current->test.comment, isalpha(current->test.input), ft_isalpha(current->test.input));
        FailedTestNode *next = current->next;
        free(current);
        current = next;
    }


    printf("\n\n");
    return (0);
}
