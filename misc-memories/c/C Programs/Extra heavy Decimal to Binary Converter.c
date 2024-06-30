#include <stdio.h>
#include <math.h>

int main()
{
    unsigned long long decimal, temp;
    short counter = -1;
    
    printf("Enter number: ");
    scanf("%llu", &decimal);
    
    temp = decimal;
    while( decimal != 0 )
    {
        decimal /= 2;
        counter++;
    }
    decimal = temp;
    
    printf("\nBinary: ");
    
    while( counter != -1 )
    {
        printf("%llu%c", decimal / (unsigned long long)(pow(2, counter)+0.5), counter % 4 == 0 ? ' ' : '\0' );
        
        decimal %= (unsigned long long)(pow(2, counter)+0.5);
        counter--;
    }
    
    return 0;
}

