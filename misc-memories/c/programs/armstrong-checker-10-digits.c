#include <stdio.h>
#include <math.h>

int main()
{
    char stopper2 = 1;
    
    puts("An armstrong number is any number of \"n\" digits which \nis equal to the sum of nth powers of its digits. \n---> Example: 153 = 1^3 + 5^3 + 3^3 \n\nCheck if you can guess one! ");
    
    while ( stopper2 == 1 ) {
        unsigned long long num = 0, j = 1000000000, sum = 0;
        char digit, tryagain, i = 11, stopper = 1, power = 0, n = 0;
        
        while(stopper == 1) {
            if ( i == 11 ) {
                printf("\nEnter your guess:  ");
                scanf("%llu", &num);
            }
            
            if (  num >= 0 && num <= 9999999999 ) {
                i = 1;
                stopper = 0;
                
                while ( n <= 9 ) // 1st iteration checks if num is 1-digit, 2nd one checks if 2-digit.............10th one checks if num is 10-digit {
                    if ( ( num >= pow(10, n) && num < pow(10, n+1) ) || num == 0) {
                        power = n + 1;
                    }
                    n++;
                }
            } else {
                printf("\nYou entered either a negative number or a number bigger than 10-digits. \nPlease try again:- \n\n");
            }
            
            while( i <= 10 ) {
                digit = (num / j) % 10;
                
                sum += pow(digit, power);
                
                j /= 10;
                i++;
            }
        }
        
        if ( num == sum) {
            printf("\n---> Your guesses are awesome! %llu is an armstrong number", num);
        } else {
            printf("\n---> Aaaah! %llu is NOT an armstrong number", num);
        }
        
        printf("\n\nWill you like to have another try? \n\n---> 1 = yes\n---> 2 = no\n\n1 or 2? ");
        scanf("%hhi", &tryagain);
        
        if ( tryagain == 1 ) {
            stopper = 1;
        } else if ( tryagain == 2 ) {
            stopper2 = 0;
        }
    }
    
    return 0;
}








