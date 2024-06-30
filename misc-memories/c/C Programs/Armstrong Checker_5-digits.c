#include <stdio.h>
#include <math.h>

int main ()
{
    unsigned long num, d1, d2, d3, d4, d5, D1, D2, D3, D4, D5, digitcheck;
    
    puts("Enter a number: ");
    scanf("%lu", &num);
    
    digitcheck = num / 10;
    
    if ( digitcheck == 0 ) //for one digit number
    {
        printf("%lu is an armstrong number", num);
    }
    
    else if ( digitcheck >= 1 && digitcheck <= 9 ) // for two digit number
    {
        printf("%lu is not an armstrong number", num);
    }
    
    else if ( digitcheck >= 10 && digitcheck <= 99 ) // for 3 digit number
    {
        d1 = num / 100;
        d2 = ( num / 10 ) % 10;
        d3 = num % 10;
        
        D1 = pow(d1,3);
        D2 = pow(d2,3);
        D3 = pow(d3,3);
        
        if ( num == D1 + D2 + D3 )
            printf("%lu is an armstrong number", num);
        else
            printf("%lu is not an armstrong number", num);
    }
    
    else if ( digitcheck >= 100 && digitcheck <= 999 ) // for 4 digit number
    {
        d1 = num / 1000;
        d2 = (num / 100) % 10;
        d3 = (num / 10) % 10;
        d4 = num % 10;
        
        D1 = pow(d1,4);
        D2 = pow(d2,4);
        D3 = pow(d3,4);
        D4 = pow(d4,4);
        
        if ( num == D1 + D2 + D3 + D4 )
            printf("%lu is an armstrong number", num);
        else
            printf("%lu is not an armstrong number", num);
    }
    
    else if ( digitcheck >= 1000 && digitcheck <= 9999 ) // for 5 digit number
    {
        d1 = num / 10000;
        d2 = (num / 1000) % 10;
        d3 = (num / 100) % 10;
        d4 = (num / 10) % 10;
        d5 = num % 10;
        
        D1 = pow(d1,5);
        D2 = pow(d2,5);
        D3 = pow(d3,5);
        D4 = pow(d4,5);
        D5 = pow(d5,5);
        
        if ( num == D1 + D2 + D3 + D4 + D5 )
            printf("%lu is an armstrong number", num);
        else
            printf("%lu is not an armstrong number", num);
    }
    
    return 0;
}

