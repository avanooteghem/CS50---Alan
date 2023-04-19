#include <cs50.h>
#include <stdio.h>

long get_nrotarjeta(void);
bool calculate_visa(long cardnumber);
int largo_tarjeta(long cardnumber);
string tipo_tarjeta (int digitostarjeta, long cardnumber);

int main(void)
{
    //American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers
    //All American Express numbers start with 34 or 37; MasterCard start with 51, 52, 53, 54, or 55; Visa numbers start with 4.
    //multiplicar por 2 un digito si un digito no; sumarlos entre ellos y ese numero mas los digitos no multiplicados
    //tiene que dar un multiplo de 10 (terminar en 0)
    long cardnumber = get_nrotarjeta();
    int digitostarjeta = largo_tarjeta(cardnumber);
    string nombretarjeta = tipo_tarjeta(digitostarjeta, cardnumber);
    if (calculate_visa(cardnumber))
    {
        printf("%s\n", nombretarjeta);
    }
    else
    {
        printf("INVALID\n");
    }

}

long get_nrotarjeta(void)
{
    long nrotarjeta = get_long ("Credit Card number: ");
    return nrotarjeta;
}



int largo_tarjeta (long cardnumber)
{
    int contador = 0;
    while (cardnumber!=0) //!= significa diferente
    {
        cardnumber = cardnumber / 10;
        contador++;
    }
    return contador;
}

string tipo_tarjeta (int digitostarjeta, long cardnumber)
{
    string tarjeta = "INVALID";
    if (digitostarjeta == 15)
    {
        int twodigits = cardnumber / 10000000000000;
        if (twodigits==34 || twodigits==37)
        {
            tarjeta = "AMEX";
        }
    }
    if (digitostarjeta == 16)
    {
        while (cardnumber >= 1000000000000000)
        {
            cardnumber = cardnumber / 100000000000000;
            if (cardnumber==51 || cardnumber==52 ||cardnumber==53 || cardnumber==54 || cardnumber==55)
            {
                    tarjeta = "MASTERCARD";
            }
            else if (cardnumber / 10 == 4)
            {
                tarjeta = "VISA";
            }
        }
    }
    if (digitostarjeta == 13)
    {
        while (cardnumber >= 1000000000000)
        {
            cardnumber = cardnumber / 1000000000000;
            if (cardnumber== 4)
            {
                    tarjeta = "VISA";
            }

        }
    }

    return tarjeta;
}

    //multiplicar por 2 un digito si un digito no; sumarlos entre ellos y ese numero mas los digitos no multiplicados
    //tiene que dar un multiplo de 10 (terminar en 0)

bool calculate_visa(long cardnumber)

{
    int counter = 0;
    long porcentaje = 100;
    int validationnumber = 0;

    while (counter < 16)
    {
        int sumas = (cardnumber%porcentaje)/(porcentaje/10)*2;
        int digito1 = sumas/10;
        int digito2 = sumas%10;
        int impares = (cardnumber%(porcentaje/10))/(porcentaje/100);
        validationnumber = validationnumber + digito1 + digito2 + impares;
        counter++;
        porcentaje = porcentaje*100;
    }

    return (validationnumber % 10 == 0);

}