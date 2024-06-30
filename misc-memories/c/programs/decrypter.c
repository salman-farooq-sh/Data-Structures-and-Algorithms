#include <stdio.h>

int main ()
{
	int num, d1, d2, d3, d4, D1, D2, D3, D4, temp, ifdigit4 = 1;
	
	
	while ( ifdigit4 )
	{
		
		puts("Enter the 4-digit number to be decrypted: ");
		scanf("%d", &num);
		
		temp = num/1000;
		
		if ( temp >= 1 && temp <= 9 )
		{
			d1 = num/1000;
			d2 = (num/100)%10;
			d3 = (num/10)%10;
			d4 = num%10;
			
			D1 = (d1+4)%5;
			D2 = (d2+4)%5;
			D3 = (d3+4)%5;
			D4 = (d4+4)%5;
			
			printf("\nThe decrypted number is %d\n", 1000*D3+100*D4+10*D1+D2);
			
			ifdigit4 = 0;
		}
		else
		{
			puts("\nPlease enter a \"4\"-digit number\nHave another try:\n");
			
			ifdigit4 = 1;
		}
	}
	
	return 0;
}