#include <stdio.h>
#include <stdlib.h>

#define OTHER_THAN(x, y) (6-(x+y))

void hanoi_solver( int height, int start, int destination );

int main() {
	char height_of_tower[1000];  int height_of_tower_int = 1;
	char starting[1000];         int starting_int = 1;
	char ending[1000];           int ending_int = 1;
	
	int flag;
	
	flag = 1;
	while( flag ) {
		printf("\nEnter the number of rings in your tower: ");
		scanf(" %s", height_of_tower);
		
		height_of_tower_int = atoi(height_of_tower);
		
		if( height_of_tower_int > 0 ) {
			flag = 0;
		} else {
			printf("\nPlease enter a NUMBER bigger than zero. Try again");
		}
	}
	
	flag = 1;
	while( flag ) {
		printf("\nEnter the current position of the tower: ");
		scanf(" %s", starting);
		
		starting_int = atoi(starting);
		
		if( starting_int > 0 && starting_int < 4 ) {
			flag = 0;
		} else {
			printf("\nEnter 1, 2 or 3. Try again");
		}
	}
	
	flag = 1;
	while( flag ) {
		printf("\nEnter the final position of the tower: ");
		scanf(" %s", ending);
		
		ending_int = atoi(ending);
		
		if( ending_int == starting_int ) {
			printf("\nEnding and starting positions should be different");
		} else if( ending_int > 0 && ending_int < 4  ) {
			flag = 0;
		} else {
			printf("\nEnter 1, 2 or 3. Try again");
		}
	}
	
	puts("\nFollow these steps: \n");
	
	hanoi_solver( height_of_tower_int, starting_int, ending_int );
}

void hanoi_solver( int height, int start , int destination ) {
	static int step = 0;
	
	if( height != 1 ) {
		hanoi_solver( height - 1, start, OTHER_THAN(start, destination) );
		printf("%2d. Move ring #%d from pole %c to %c\n", ++step, height, start + 64, destination + 64);
		hanoi_solver( height - 1, OTHER_THAN(start, destination), destination );
	} else {
		printf("%2d. Move ring #1 from pole %c to %c\n", ++step, start + 64, destination + 64);
	}
}

