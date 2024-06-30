#include <stdio.h>

void pascalTriPrinter( int );
unsigned long long factorial( unsigned long long );

int main() {
    pascalTriPrinter(18);
    return 0;
}

void pascalTriPrinter( int n ) {
    for( int rows = 0; rows < n; rows++ ) {
        printf("%-2d    |      ", rows+1);
        
        for( int spaces = 1; spaces <= 4 * (n - rows - 1); spaces++ ) {
            printf(" ");
        }
        for( int nums = 0; nums <= rows; nums++ ) {
            printf("%-8llu", factorial(rows)/(factorial(nums)*factorial(rows - nums)));
        }
        
        for( int spaces = 1; spaces <= 4 * (n - rows - 1); spaces++ ) {
            printf(" ");
        }
        
        printf("|    %2d", rows+1);
        
        puts("\n\n");
    }
}

unsigned long long factorial( unsigned long long n ) {
    unsigned long long product = 1;
    for( unsigned long long i = n; i > 0; i-- ) {
        product *= i;
    }
    return product;
}

