// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string argv);

// El programa no cumple con el siguiente requerimiento:
// Your program must contain a function called replace which takes a string input and returns a string output.
// The main function will then print the converted word, followed by \n.
int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("invalid\n");
        return 1;
    }
    string new_word = replace(argv[1]);
    printf("%s\n", new_word);
    return 0;
}


string replace(string word)
{
    for (int i=0;i<strlen(word);i++)
    {
        switch(word[i])
        {
            case 'a':
                word[i]='6';
                break;
            case 'e':
               word[i]='3';
                break;
            case 'i':
                word[i]='1';
                break;
            case 'o':
                word[i]='0';
                break;
            default:
                word[i]= word[i];
                break;
        }

    }

    return word;
}