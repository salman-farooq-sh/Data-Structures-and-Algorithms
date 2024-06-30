
#include <stdio.h>
#include <math.h>

int main ()
{
    int rows = 0, spaces, stars, height, input_height, i, tower;
    
    puts("Enter height of pyramid: ");
    scanf("%d", &input_height);
    
    puts("Enter height of the tower on the pyramid: ");
    scanf("%d", &tower);
    
    height = input_height - 1;
    
    puts("");
    
    i = 1;
    while( i <= tower )
    {
        spaces = 1;
        while ( spaces <= input_height )
        {
            printf(" ");
            spaces++;
        }
        
        if ( i == 1 )
        {
            puts("*");
        }
        else
        {
            puts("|");
        }
        
        i++;
    }
    
    while( rows <= height )
    {
        spaces = 1; stars = 1;
        while( spaces <= height - rows )
        {
            printf(" ");
            spaces++;
        }
        
        printf("/");
        
        stars = 1;
        
        while( stars <= 2*rows + 1 )
        {
            printf("*");
            stars++;
        }
        
        puts("\\");
        rows++;
    }
    
    return 0;
}


