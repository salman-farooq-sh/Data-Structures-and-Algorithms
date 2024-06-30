#include <stdio.h>

int main ()
{
    int marks = 0, sum = 0, i = -1;
    
    while ( marks != -1 )
    {
        sum = sum + marks;
        i++;
        
        puts("Enter marks (0-10) or \"-1\" if you are the last person");
        scanf("%d", &marks);
        
        if ( marks < -1 || marks > 10 )
        {
            puts("Please enter between 0 and 10");
            marks = 0;
            i--;
        }
    }
    
    if ( sum == 0 )
    {
        puts("Thanks!\n");
    }
    else
    {
        printf("Average is %d\n", sum/i);
    }
    
    return 0;
}
