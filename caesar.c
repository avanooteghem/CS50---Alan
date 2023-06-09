#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void checkletter (string word,int key);
bool checkdigit(string key);
void printletter (char letter, int start, int limit, int key);

int main(int argc, string argv[])
{
    if (argc != 2 || checkdigit(argv[1]) ==false ) // "if (argc != 2 || !checkdigit(argv[1])" o tambien "if (!(argc == 2 && checkdigit(argv[1])))"
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    else
    {
        string word = get_string("Please input a word: ");
        printf("ciphertext: ");
        checkletter(word,atoi(argv[1]));
        return 0;
    }
}

bool checkdigit (string key)
{
    // Es al pedo que esta funcion lleve la cuenta de la cantidad de numeros. Podes usar un bool que pasa a ser false
    // en la iteracion en la que te encontras con algo distinto de un numero (o directamente un return false)
    for (int i = 0 ; i < strlen(key) ; i++) //que sean solo numeros
    {
        if (isdigit(key[i]))
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

void checkletter (string word, int key)
{
    for (int i = 0 ; i < strlen(word) ; i++)
    {
        if (isalpha(word[i]))
        {
            if isupper(word[i])
            {
                printf("%c",(word[i] - 65 + key) % 26 + 65);
            }
            else if (islower(word[i]))
            {
                printf("%c",(word[i] - 97 + key) % 26 + 97);
            }
        }
        else
        {
            printf("%c",word[i]);
        }

    }
    printf("\n");
}