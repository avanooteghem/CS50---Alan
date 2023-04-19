#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void evaluation(string word);

int main(void)
{
    string word = get_string("ingrese su palabra: ");
    evaluation(word);

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

void evaluation(string word)
{
    for (int i = 0 ; i < strlen(word);i++)
    {
        char letter = word[i];
        for (int power = 7 ; power >= 0 ; power--)
        {
            int divisor = pow(2,power);
            if(letter / divisor >= 1)
            {
                print_bulb(1);
                letter -= divisor;
            }

            else
            {
                print_bulb(0);
            }
    }
        printf("\n");
    }
}





