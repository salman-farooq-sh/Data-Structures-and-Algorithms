#include <stdio.h>

int palindrome_checker( int );

int main() {
    int num, i = 0, flag = 1;
    
    for( num = 999 * 999; num > 9999 && flag; num-- ) {
        if( palindrome_checker(num) ) {
            for( i = 999; i > 99; i-- ) {
                if( num % i == 0 && num / i < 1000 && num / i > 99 ) {
                    flag = 0;
                    break;
                }
            }
        }
    }
    
    printf("%d\n", ++num );
}

int palindrome_checker( int num ) {
    int num_copy = num, num_count = 0, d1, d2, d3, d4, d5, d6;
    
    do {
        num_copy /= 10;
        num_count++;
    } while( num_copy );
    num_copy = num;
    
    if( num_count == 5 ) {
        d1 = num / 10000;
        d2 = num / 1000 % 10;
        d4 = num / 10 % 10;
        d5 = num % 10;
        
        if( d1 == d5 && d2 == d4 ) {
            return 1;
        } else {
            return 0;
        }
    }
    
    else {
        d1 = num / 100000;
        d2 = num / 10000 % 10;
        d3 = num / 1000 % 10;
        d4 = num / 100 % 10;
        d5 = num / 10 % 10;
        d6 = num     % 10;
        
        if( d1 == d6 && d2 == d5 && d3 == d4 ) {
            return 1;
        } else {
            return 0;
        }
    }
}
