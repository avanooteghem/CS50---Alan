#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_sentences(string text, int length);
int count_words (string text, int length);
int count_letters (string text, int length);
string index(int letters, int words, int sentences);


int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);
    int sentences = count_sentences(text, length);
    int words = count_words(text, length);
    int letters = count_letters (text,length);
    string grade = index (letters, words, sentences);
    printf("%s\n",grade);
}


int count_letters(string text, int length)
{
    int letters = 0;
    for (int i = 0, characters = strlen(text);i < characters; i++)
    {
        if (isalpha(text[i]))
        {
           letters += 1;
        }
    }
    return letters;
}


int count_words(string text, int length)
{
    int words = 1;
    for (int i = 0, characters = strlen(text);i < characters; i++)
    {
        if (text[i] == 32)
        {
            words += 1;
        }
    }
    return words;
}

int count_sentences(string text, int length)
{
    int sentences = 0;
    for (int i = 0, characters = strlen(text);i < characters; i++)
    {
        if (text[i] == '?' || text[i] == '!')
        {
            sentences += 1;
        }
        else if (text[i] == '.' && text[i+1] != '.')
        {
            sentences +=1;
        }
    }
    return sentences;
}

string index(int letters, int words, int sentences)
{
    float L = 100 * letters / (float) words;
    float S = 100 * sentences / (float) words;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    long rounded = lroundf (index);
    char str1[10] = "Grade ";
    char str2[10];
    sprintf(str2, "%ld", rounded);
    string grade = "";
    if (rounded > 16)
    {
        grade= "Grade 16+";
    }
    else if (rounded < 1)
    {
        grade= "Before Grade 1";
    }
    else
    {
        grade = strcat(str1,str2);
    }
return grade;
}