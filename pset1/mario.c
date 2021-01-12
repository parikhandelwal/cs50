#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int h, i, j, s;
    
    //prompt user for height of the pyramid
    do
    {
        h = get_int("height: ");
    }   
    while (h < 1 || h > 8);

    // loops for making patterns 
    
    for (i = 1 ; i <= h; i++) // loop for height
    {  
        
        for (s = 1; s <= h - i ; s++) // loop for spaces
        {
            printf(" ");
        }
        
        for (j = 1; j <= i ; j++) // loop for hashs
        {
            printf("#");
        }
        
        printf("\n");
    }

~