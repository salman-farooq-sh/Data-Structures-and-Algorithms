#include <stdio.h>

void mergeSort( int *, int, int );
void swap( int *, int * );
void merge( int *, int, int, int );

int main() 
{
	int x = 19;
	int a[] = { 219,12938,21398,912308,289,1908,0, 2, 1, 5, 7, 9, 2, 329, 239,190, 1299,219,291,21};	
	mergeSort( a, 0, x );
	
	for( int i = 0; i <= x; ++i )
		printf( "%d ", a[i] );
	
	puts("\n");
}

void mergeSort( int * array, int start, int end ) 
{
	if( end-start > 1 ) 
	{
		int mid = (start+end) / 2;
		
		mergeSort( array, start, mid );
		mergeSort( array, mid+1, end );
		
		merge( array, start, mid, end );
	}
	else if( end-start == 1 )
		if( array[end] < array[start] )
			swap( &array[start], &array[end] );	
}

void swap( int * a, int * b ) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void merge( int * array, int start, int mid, int end ) 
{
	int leftElements = mid - start + 1;
	int rightElements = end - mid;
	
	int left[ leftElements ];
	int right[ rightElements ];
	
	for( int i = 0; i < leftElements; ++i ) 
		left[i] = array[ start+i ];
	
	for( int i = 0; i < rightElements; ++i ) 
		right[i] = array[ mid+1 +i ];
	
	int l = 0;
	int r = 0;
	int i = start;
	
	while( l < leftElements && r < rightElements )
		if( left[l] < right[r] )
			array[i++] = left[l++];
		else 
			array[i++] = right[r++];
	
	while( r != rightElements )
		array[i++] = right[r++];
	
	
	while( l != leftElements )
		array[i++] = left[l++];
	
	
}
