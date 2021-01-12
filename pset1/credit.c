#include<cs50.h>
#include<stdio.h>

int checksum(long n);  // declreation of the functions made 
int first(long n);
int second(long n);
int count(long n);

int main(void)
{
    int i, c, d, v, f, s;
    long cn;

    // prompt the user for input
    do
    {
        cn = get_long("number: ");

    }
    while (cn == 0);

    c = count(cn);   

    v = checksum(cn);

    // checking the check sum and printing according

    if ((v % 10 == 0) && (count(cn) == 13 || count(cn) == 16) && (first(cn) == 4))  // checking for visa
    {
        printf("VISA\n");
    }
    else if ((v % 10 == 0) && (count(cn) == 16) && (first(cn) == 5) && (second(cn) == 1 || second(cn) == 2 || second(cn) == 3 
             || second(cn) == 4
             || second(cn) == 5))  // checking for master card
    {
        printf("MASTERCARD\n");
    }
    else if ((v % 10 == 0) && (count(cn) == 15) && (first(cn) == 3) && (second(cn) == 4 || second(cn) == 7)) 
    {
        printf("AMEX\n");   // checking for american express card
    }
    else if 
    {
        printf("INVALID\n");
    }
}
// for counting digits of the card number
int count(long n)
{
    int i = 0;
    if (n != 0)
    {
        i++;
        return i + count(n / 10);
    }
    else
    {
        return 0;
    }
}

// for checking Luhn's algorithm
int checksum(long n)
{
    int sum1 = 0, sum2 = 0, c, i, a, d, d2, x, total = 0;
    c = count(n);

    for (i = 0 ; i < c ; i++)
    {
        d = (n % 10);
        n = (n / 10);
        sum1 = sum1 + d;

        d2 = (n % 10);
        n = (n / 10);
        x = (d2 * 2);

        if (count(x) > 1)
        {
            a = x % 10;
            x = x / 10;
            sum2 = sum2 + a + x;
        }
        else
        {
            sum2 = sum2 + x;
        }
    }
    total = sum1 + sum2;
    return total;
}

// to check the first digit of the card number
int first(long n)
{
    while (n >= 10)
    {
        n /= 10;
    }
    return n;
}

// to check the second digit of the card number
int second(long n)
{
    while (n >= 100)
    {
        n /= 10;
    }
    n = n % 10;
    return n;
}
