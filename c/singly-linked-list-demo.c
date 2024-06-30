#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} Node;

_Bool delete( Node **, int );
void insert( Node **, int );
void printList( Node * );


int main() {
	Node * list = NULL;
	
	insert( &list, 3 );
	printList( list );
	puts("");
	
	delete( &list, 3 );
	printList( list );
	puts("");
	
	insert( &list, 4 );
	printList( list );
	puts("");
	
	insert( &list, 6 );
	printList( list );
	puts("");
	
	insert( &list, 1 );
	printList( list );
	puts("");
	
	insert( &list, 9 );
	printList( list );
	puts("");
	
	delete( &list, 4 );
	printList( list );
	puts("");
	
	insert( &list, 7 );
	printList( list );
	puts("");
	
	delete( &list, 7 );
	printList( list );
	puts("");
	
	insert( &list, 0 );
	printList( list );
	puts("");
	
	
}


_Bool delete( Node ** tracer, int item ) {
	Node * temp = NULL;
	
	if( *tracer == NULL )
		return 0; // empty list / not found / not deleted
	
	if( ( *tracer)->data == item ) {
		temp = *tracer;
		*tracer = (*tracer)->next;
		free( temp );
		
		return 1; // found and deleted
	}
	
	while( (*tracer)->next != NULL && (*tracer)->next->data != item )
		tracer = &( (*tracer)->next );
	
	if( (*tracer)->next == NULL )
		return 0; // not found
	
	temp = (*tracer)->next;
	(*tracer)->next = (*tracer)->next->next;
	free( temp );
	
	return 1; // found and deleted
}

void insert( Node ** tracer, int item ) {
	Node * newNodePtr = malloc( sizeof(Node) );
	if( newNodePtr == NULL )
		printf("Error making new node in insert()");
	
	newNodePtr->data = item;
	newNodePtr->next = NULL;
	
	if( (*tracer) == NULL ) {
		*tracer = newNodePtr;
	} else if( item >= (*tracer)->data ) {
		newNodePtr->next = *tracer;
		*tracer = newNodePtr;
	} else {
		while( (*tracer)->next != NULL && item < (*tracer)->next->data )
			tracer = &( (*tracer)->next );
		
		if( (*tracer)->next == NULL ) {
			(*tracer)->next = newNodePtr;
		} else {
			newNodePtr->next = (*tracer)->next;
			(*tracer)->next = newNodePtr;
		}
	}
}

void printList( Node * start ) {
	printf("List: ");
	
	if( start == NULL ) {
		printf("empty");
	}
	else {
		while( start != NULL ) {
			printf("%i ", start->data );
			start = start->next;
		}
	}
	puts("");
}
