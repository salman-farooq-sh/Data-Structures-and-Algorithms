#include <stdio.h>
#include <math.h>

int main ()
{
    char rows, spaces, stars, input = 1, height, middle_row;
    
    while( input )
    {
        printf("%s", "Enter an odd number: ");
        scanf("%hhu", &input);
        puts("");
        
        if( input >= 1 && input%2 == 1 )
        {
            height = input - 1;
            middle_row = height / 2;
            input = 0;
            
            rows = 0;
            while( rows <= height)
            {
                if( rows <= middle_row)
                {
                    spaces =  1;
                    while( spaces <= middle_row-rows )
                    {
                        printf(" ");
                        spaces++;
                    }
                    
                    stars = 1;
                    while( stars <= 2*rows+1 )
                    {
                        printf("*");
                        stars++;
                    }
                    
                    puts("");
                }
                
                else
                {
                    spaces =  1;
                    while( spaces <= rows - middle_row )
                    {
                        printf(" ");
                        spaces++;
                    }
                    
                    stars = 1;
                    while( stars <= -2*rows + 4*middle_row+1 )
                    {
                        printf("*");
                        stars++;
                    }
                    
                    puts("");
                }
                
                rows++;
            }
        }
        
        else if( input < 0)
        {
            printf("%s", "Negative numbers are not defined as odd or even\n\n");
            input = 1;
        }
        
        else
        {
            printf("%s", "You, the genius, miraculously entered an even number\n\n");
            input = 1;
        }
        
    }
 
    return 0;
}


