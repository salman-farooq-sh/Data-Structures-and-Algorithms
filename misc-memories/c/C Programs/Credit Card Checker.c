#include <stdio.h>
#include <math.h>

int main()
{
    unsigned long input, temp;
    int sum = 0, evenDigit, oddDigit;
    
    printf("%s", "Enter credit card number: ");
    scanf("%lu", &input);
    
    temp = input;
    input *= 10;
    while( input != 0 )
    {
        input /= 100;
        evenDigit = input % 10;
        evenDigit *= 2;
        sum += evenDigit/10 + evenDigit%10;
        
    }
    input = temp;
    
    input *= 100;
    while( input != 0 )
    {
        input /= 100;
        oddDigit = input % 10;
        sum += oddDigit;
    }
    input = temp;
    
    while( input > 10 )
    {
        input /= 10;
    }
    
    if( sum % 10 == 0 )
    {
        if( input == 5 )
        {
            printf("MASTERCARD\n");
        }
        else if( input == 3 )
        {
            printf("AMEX\n");
        }
        else if( input == 4 )
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID");
    }
    
    return 0;
}
//test inputs: 378282246310005, 371449635398431, 4012888888881881, 4111111111111111, 5555555555554444, 5105105105105100

