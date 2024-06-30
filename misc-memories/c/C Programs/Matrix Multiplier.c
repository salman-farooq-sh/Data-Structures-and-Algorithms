#include <stdio.h>

int main() {
	long long i, j, k, r1, c1, r2, c2, flag = 1;
	
	while( flag ) {
		printf("Enter rows and column for first matrix: ");
		scanf("%lli%lli", &r1, &c1);
		
		printf("Enter rows and column for second matrix: ");
		scanf("%lli%lli",&r2, &c2);
		
		if( c1 == r2 ) {
			flag = 0;
		} else {
			printf("\nGiven matrices cannot be multiplied\n");
		}
	}
	
	long long matrix1[r1][c1], matrix2[r2][c2], result[r1][c2];
	
	printf("Enter entries of the matrix A: \n");
	for( i = 0; i < r1; i++ ) {
		for( j = 0; j < c1; j++ ) {
			printf("a%lli%lli: ", i + 1, j + 1);
			scanf("%lli", &matrix1[i][j]);
		}
	}
	
	printf("Enter entries of the matrix B: \n");
	for( i = 0; i < r2; i++ ) {
		for( j = 0; j < c2; j++ ) {
			printf("a%lli%lli: ", i + 1, j + 1);
			scanf("%lli", &matrix2[i][j]);
		}
	}
	
	for( i = 0; i < r2; i++ ) {
		for( j = 0; j < c2; j++ ) {
			result[i][j] = 0;
		}
	}
	
	for( i = 0; i < r1; i++ ) {
		for( j = 0; j < c2; j++ ) {
			for( k = 0; k < c1; k++ ) {
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	
	printf("\nA x B: \n\n");
	for( i = 0; i < r1; i++ ) {
		for( j = 0; j < c2; j++ ) {
			printf("\t%lli", result[i][j]);
		}
		puts("");
	}
	
	
	
	
	return 0;
}

