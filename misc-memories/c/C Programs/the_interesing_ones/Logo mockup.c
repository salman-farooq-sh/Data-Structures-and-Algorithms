#include <stdio.h>
#include <stdbool.h>

#define ROOM_SIZE 50
#define MAX_CMD 1000

enum direction { UP, RIGHT, DOWN, LEFT };

void swap( short *a, short *b );
void move_turtle( short room[ROOM_SIZE][ROOM_SIZE], short * x, short * y, short face, short distance, bool pen_state );
void draw( short room[ROOM_SIZE][ROOM_SIZE], short x1, short y1, short x2, short y2 );
void print( short [ROOM_SIZE][ROOM_SIZE] );
void get_commands( float * commands );
short interpreter( float * commands );

int main() {
	float commands[MAX_CMD];
	
	get_commands( commands );
	
	interpreter( commands );
	
}

void print( short room[ROOM_SIZE][ROOM_SIZE] ) {
	short i, j;
	
	printf("     ");
	for( i = 0; i < ROOM_SIZE; i++ ) {
		printf("%2i ", i + 1);
	}
	puts("\n");
	
	for( i = 0; i < ROOM_SIZE; i++ ) {
		printf("%2i    ", i + 1);
		for( j = 0; j < ROOM_SIZE; j++ ) {
			printf("%c  ", room[j][i] == 0 ? '.' : '#' );
		}
		puts("");
	}
}

void draw( short room[ROOM_SIZE][ROOM_SIZE], short x1, short y1, short x2, short y2 ) {
	short i;
	
	if( x2 < x1 )
		swap( &x2, &x1 );
	else if( y2 < y1 )
		swap( &y2, &y1 );
	
	if( x1 == x2 )
		for( i = y1; i <= y2; i++ )
			room[x1][i] = 1;
	else if( y1 == y2 )
		for( i = x1; i <= x2; i++ )
			room[i][y1] = 1;
}

void swap( short *a, short *b ) {
	short temp = *a;
	*a = *b;
	*b = temp;
}

void move_turtle( short room[ROOM_SIZE][ROOM_SIZE], short * x, short * y, short face, short distance, bool pen_state ) {
	if( face == LEFT ) {
		pen_state ? draw( room, *x, *y, *x - distance, *y ) : 0;
		*x -= distance;
	} else if( face == RIGHT ) {
		pen_state ? draw( room, *x, *y, *x + distance, *y ) : 0;
		*x += distance;
	} else if( face == UP ) {
		pen_state ? draw( room, *x, *y, *x, *y - distance ) : 0;
		*y -= distance;
	} else if( face == DOWN ) {
		pen_state ? draw( room, *x, *y, *x, *y + distance ) : 0;
		*y += distance;
	}
}

short interpreter( float * commands )  {
	short i;
	short x = 0;
	short y = 0;
	short flag = 1;
	short distance;
	bool pen_state = 0;
	enum direction face = RIGHT;
	short room[ROOM_SIZE][ROOM_SIZE] = {};
	
	for( i = 0; i < MAX_CMD && flag; i++ ) {
		switch ( (short)commands[i] ) {
			case 1:
				pen_state = 0;
				break;
			case 2:
				pen_state = 1;
				break;
			case 3:
				face = ( face + 1 ) % 4;
				break;
			case 4:
				face = ( 4 + face - 1 ) % 4;
				break;
			case 5:
				distance = -1 + (short) ( 100 * commands[i] - 500  );
				move_turtle( room , &x, &y, face, distance, pen_state );
				break;
			case 6:
				print( room );
				break;
			case 9:
				flag = 0;
				break;
			default:
				printf("Invalid Command\n");
				i--;
				break;
		}
	}
	return 0;
}

void get_commands( float * commands ) {
	int i = 0;
	int flag = 1;
	printf( "Enter commands for the turtle: \n" );
	for( i = 0; i < MAX_CMD && flag; i++ ) {
		scanf("%f", &commands[i] );
		if( commands[i] == 9 )
			flag = 0;
	}
}

