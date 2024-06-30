#include <stdio.h>
#include <math.h>


unsigned long long factorial( int input1 )
{
    int i = 1;
    unsigned long long factorials = 1;
    
    while ( i <= input1 )
    {
        factorials *= i;
        i++;
    }
    
    return factorials;
}

int main()
{
    unsigned char i = 1, power;
    float e = 1;
    
    puts("Enter the power e will be raised to: ");
    scanf("%hhu", &power);
    
    while ( i <= 20 )
    {
        e += pow(power, i) / factorial(i);
        i++;
    }
    
    printf("e to the %hhu is %f\n\n", power, e );
    
    return 0;
}

