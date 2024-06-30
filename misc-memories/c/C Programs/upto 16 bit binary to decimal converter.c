#include <stdio.h>
#include <math.h>

int main ()
{
    unsigned long long binary, zeros = pow(10, 15), digitDecimal;
    unsigned short digitBinary, decimal = 0;
    
    
    printf("Enter binary number; ");
    scanf ("%llu", &binary);
    
    for( short i = 15; i >= 0; i--)
    {
        digitBinary = (binary / zeros) % 10;
        zeros /= 10;
        
        digitDecimal = digitBinary * pow(2, i);
        
        decimal += digitDecimal;
        
    }
    
    printf("%lli is %hu", binary, decimal);
    
    return 0;
}




