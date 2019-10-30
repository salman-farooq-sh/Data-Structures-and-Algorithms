#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define MAX_VRTXS 9
#define INFINITY 999999

int is_not_full( bool [], int );
void array_copier( int [], int [], int );
void array_printer( int [], int );
void dijkstra( int[][MAX_VRTXS], int, int );

int main() {
	/* int A[9][9] = {
	 {0,  4,  0,  0,  0,  0,   0,  8,  0},
	 {4,  0,  8,  0,  0,  0,   0,  11, 0},
	 {0,  8,  0,  7,  0,  4,   0,  0,  2},
	 {0,  0,  7,  0,  9,  14,  0,  0,  0},
	 {0,  0,  0,  9,  0,  10,  0,  0,  0},
	 {0,  0,  4,  14, 10, 0,   2,  0,  0},
	 {0,  0,  0,  0,  0,  2,   0,  1,  6},
	 {8,  11, 0,  0,  0,  0,   1,  0,  7},
	 {0,  0,  2,  0,  0,  0,   6,  7,  0}
	 }; */
	
	int i, j, num_of_vertices, src;
	
	printf("Enter the number of verices in the graph: ");
	scanf("%d", &num_of_vertices);
	
	printf("Enter source: ");
	scanf("%d", &src);
	
	int matrix[num_of_vertices][num_of_vertices];
	
	puts("");
	for( i = 0; i < num_of_vertices; i++ )
		for( j = i + 1; j < num_of_vertices; j++ ) {
			printf("Enter weight between %d and %d: ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	
	puts("");
	
	int distance_from[num_of_vertices];
	int distance_from_copy[num_of_vertices];
	int sum;
	int temp_vertex = src;
	bool set_of_visited[num_of_vertices];
	
	memset(set_of_visited, 0, num_of_vertices);
	
	for( i = 0; i < num_of_vertices; i++ )
		for( j = 0; j < num_of_vertices; j++ )
			if( matrix[i][j] == 0 )
				matrix[i][j] = INFINITY;
	
	for( i = 0; i < num_of_vertices; i++ )
		distance_from[i] = INFINITY;
	
	distance_from[src] = 0;
	
	array_copier(distance_from_copy, distance_from, num_of_vertices);
	
	while( is_not_full(set_of_visited, num_of_vertices) ) {
		
		for( i = 0; i < num_of_vertices; i++ )
			if( !set_of_visited[i] )
				temp_vertex = distance_from_copy[i] < distance_from_copy[temp_vertex] ? i : temp_vertex;
		
		set_of_visited[temp_vertex] = 1;
		
		for( i = 0; i < num_of_vertices; i++ )
			if( !set_of_visited[i] ) {
				
				sum = distance_from[temp_vertex] + matrix[temp_vertex][i];
				
				distance_from[i] = sum < distance_from[i] ? sum : distance_from[i];
			}
		
		array_copier(distance_from_copy, distance_from, num_of_vertices);
		
		for( i = 0; i < num_of_vertices; i++ )
			if( set_of_visited[i] )
				distance_from_copy[i] = INFINITY;
	}
	array_printer( distance_from, num_of_vertices );
	
}


int is_not_full( bool set[], int n ) {
	int i;
	int flag = 0;
	
	for( i = 0; i < n; i++ )
		if( set[i] == 0 ) {
			flag = 1;
			break;
		}
	
	return flag;
}

void array_copier( int a[], int b[], int n ) {
	for( int i = 0; i < n; i++ )
		a[i] = b[i];
}

void array_printer( int array[], int n ) {
	puts(" Vertex         Shortest path length\n");
	for( int i = 0; i < n; i++ )
		printf("%5d                     %d\n", i, array[i] );
	
	puts("");
}

