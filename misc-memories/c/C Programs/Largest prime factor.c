#include <stdio.h>
#include <math.h>

//typedef unsigned int uint;

int main()
{
    unsigned long long int input = 100000000000000000, i = input, k = 2;
    
    for( int m = 1; m <= 30000; )
    {
        _Bool isPrime2 = 1;
        
        for( int l = 2; l <= (int)sqrt(k); l++ )
        {
            if( !(k % l) )
            {
                isPrime2 = 0;
                break;
            }
        }
        
        if( isPrime2 )
        {
            if( !(input % k) )
            {
                i = input / k;
            }
            
            printf("%dth prime is %llu\ni = %llu\n", m, k, i);
            
            m++;
        }
        
        k++;
        
    }
    
    while( 1 )
    {
        
        _Bool isPrime = 1;
        for( int j = 2; j <= (int)sqrt(i); j++ )
        {
            if( !(i % j) )
            {
                isPrime = 0;
                break;
            }
        }
        
        if( isPrime )
        {
            if( !(input % i) )
            {
                printf("Largest prime factor of %llu is %llu\n", input, i);
                break;
            }
        }
        
        i--;
    }
    
    return 0;
}







