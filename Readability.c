#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);

int main(void) {
    //prompt user for name
    string text = get_string("Text: ");

    //count the letters
    int letters = 0;
    for (int i = 0; i < strlen(text); i++) {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
            letters++;
    }

    //count the words
    int words = 1;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ')
            words++;
    }

    //count the sentences
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;
    }

    //coleman-liau index
    float calculation = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;
    int index = round(calculation);
    if (index < 1)
        printf("Before Grade 1\n");
    else if (index >= 1 && index < 16)
        printf("Grade %i\n", index);
    else
        printf("Grade 16+\n");
}
