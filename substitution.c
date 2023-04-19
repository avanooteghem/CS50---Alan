#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool checkinput(string key);
void substitution(string plaintext,string argv);


int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (checkinput(argv[1])==false)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    else
    {
        string plaintext = get_string("Please input plaintext: ");
        printf("ciphertext: ");
        substitution(plaintext, argv[1]);
        return 0;
    }

}

bool checkinput(string key)
{
    int counter = 0;
    int sameletter = 0;
    for (int i = 0 ; i < strlen(key) ; i++)
    {
        for (int j = i+1 ; j < strlen(key) ; j++)
        {
            if (key[i] == key [j])
                {
                    sameletter+=1;
                }
        }
        if (sameletter >= 1)
        {
            return false;
            break;
        }
        else if (isalpha(key[i]))
        {
            counter += 1;
        }
    }
    if (counter == 26)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void substitution(string plaintext,string argv)
{
    for (int i = 0 ; i < strlen(plaintext) ; i++)
    {
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 65;
            if(isupper(argv[letter]))
            {
                printf("%c",argv[letter]);
            }
            else
            {
                printf("%c",toupper(argv[letter]));
            }
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97;
            if(islower(argv[letter]))
            {
                printf("%c",argv[letter]);
            }
            else
            {
                printf("%c",tolower(argv[letter]));
            }
        }
        else
        {
            printf("%c",plaintext[i]);
        }
    }
    printf("\n");
}