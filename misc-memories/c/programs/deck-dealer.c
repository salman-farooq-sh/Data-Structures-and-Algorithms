#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	char *suit;
	char *face;
} card;

void shuffle( card * const deck );
void fillDeck( card * const deck, char * const faces[], char * const suits[] );
void dealDeck( card * const deck);

int main() {
	srand( (int)time(0) );
	card deck[52];
	
	char *faces[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	char *suits[] = { "HEARTS", "DIAMONDS", "CLUBS", "SPADES" };
	
	fillDeck(deck, faces, suits);
	shuffle(deck);
	dealDeck(deck);
	
	getchar();getchar();getchar();getchar();getchar();getchar();getchar();getchar();getchar();getchar();
}

void shuffle( card * const deck ) {
	int i, j;
	card temp;
	
	for( i = 0; i < 52; i++ ) {
		j = rand() % 52;
		
		temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

void fillDeck( card * const deck, char * const faces[], char * const suits[] ) {
	for( int i = 0; i < 52; i++ ) {
		deck[i].face = faces[i % 13];
		deck[i].suit = suits[i / 13];
	}
}

void dealDeck( card * const deck ) {
	for( int i = 0; i < 52; i++ ) {
		printf("%15s of %-15s%c", deck[i].face, deck[i].suit, (i+1) % 4 ? '\t' : '\n' );
	}
}

