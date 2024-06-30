#include <stdio.h>

double power ( int base, int exponent )
{
    double product = 1;
    short i = 1, tempEx = exponent;
    double inverse;
    
    if ( tempEx < 0)
    {
        tempEx = -tempEx;
    }
    
    while( i <= tempEx )
    {
        product *= base;
        i++;
    }
    
    if ( exponent >= 0)
    {
        return product;
    }
    
    else
    {
        inverse = 1 / product;
        return inverse;
    }
}

int main()
{
    printf("%lf \n", power(3, -1) );
    
    return 0;
}




















