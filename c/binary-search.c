#include <stdio.h>

int binary_search( int [], int, int );

int main() {
	int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }, size = sizeof(data) / sizeof(data[0]);
	int to_find = 1;
	
	printf("Location of %d in data[] is %d\n\n", to_find, binary_search(data, size, to_find) );
	
	
	return 0;
}

int binary_search( int array[], int size, int to_find ) {
	int i = 0, j = size - 1, m;
	
	while( i < j ) {
		m = ( i + j ) / 2;
		if( to_find > array[m] ) {
			i = m + 1;
		} else {
			j = m;
		}
	}
	
	if( to_find == array[i] ) {
		return i;
	} else {
		return -1;
	}
}
