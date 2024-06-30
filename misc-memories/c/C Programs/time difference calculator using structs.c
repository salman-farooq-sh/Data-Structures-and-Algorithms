#include <stdio.h>

typedef struct {
	int sec;
	int min;
	int hrs;
} time;

time diff_calc( const time *, const time * );

int main() {
	time start, stop, diff;
	
	printf("Enter starting time: ");
	scanf("%d%*c%d%*c%d", &start.hrs, &start.min, &start.sec);
	
	printf("Enter ending time: ");
	scanf("%d%*c%d%*c%d", &stop.hrs, &stop.min, &stop.sec);
	
	diff = diff_calc(&start, &stop);
	
	printf("Difference: %02d:%02d:%02d", diff.hrs, diff.min, diff.sec);
	
	getchar();getchar();getchar();getchar();getchar();getchar();getchar();
	
}

time diff_calc( const time *start, const time *stop ) {
	time difference = { 0, 0, 0 };
	
	difference.hrs = stop->hrs - start->hrs;
	
	if( stop->min < start->min ) {
		difference.min = stop->min - start->min + 60;
		difference.hrs--;
	} else {
		difference.min = stop->min - start->min;
	}
	
	if( stop->sec < start->sec ) {
		difference.sec = stop->sec - start->sec + 60;
		difference.min--;
	} else {
		difference.sec = stop->sec - start->sec;
	}
	
	return difference;
}

