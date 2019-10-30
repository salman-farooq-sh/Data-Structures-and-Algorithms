#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

void insertionSort( int *, int, int (*funcPtr)( int, int ) );

int ascending( int a, int b );
int descending( int a, int b );

//utility functions
void printer( int *, int );
void randFiller( int *, int );

int main() {
	int data[ SIZE ], choice;
	srand( (int)time(NULL) );
	
	printf("ASCENDING(1) OR DESCENDING(2)? ");
	scanf("%d", &choice);
	
	time_t start, end;
	
	randFiller( data, SIZE );
	
	printer( data, SIZE );
	
	time( &start );
	
	if( choice == 1 ) {
		insertionSort(data, SIZE, ascending );
	} else {
		insertionSort(data, SIZE, descending );
	}
	
	time( &end );
	
	printer( data, SIZE );
	
	printf("\ntime taken: %li\n\n", end - start);
	
}

void insertionSort( int *arr, int n, int (*funcPtr)(int, int) ) {
	int i, j, k, flag, tmp;
	
	for( i = 1; i < n ; i++ ) {
		tmp = arr[i];
		k = 0;
		flag = 1;
		
		for( j = i - 1; j >= 0 && flag ; j-- ) {
			flag = 0;
			if( (*funcPtr)( arr[j], arr[i] ) ) {
				k++;
				flag = 1;
			}
		}
		
		for( j = 0; j < k; j++ ) {
			arr[i - j] = arr[i - j - 1];
		}
		
		arr[i - k] = tmp;
	}
}

int ascending( int a, int b ) {
	return a > b;
}

int descending( int a, int b ) {
	return a < b;
}

void printer( int *arr, int n ) {
	for( int i = 0; i < n; i++ ) {
		printf("%d%c ", arr[i], i == n - 1 ? '\n' : ',');
	}
}

void randFiller( int *arr, int n ) {
	for( int i = 0; i < n; i++ ) {
		arr[i] = rand() % 50;
	}
}


