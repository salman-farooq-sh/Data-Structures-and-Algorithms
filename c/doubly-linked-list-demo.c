//doubly-linked list demo

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * before;
	struct node * next;
} Node;

void insertNode( Node ** start, int item );
void deleteNode( Node ** start, int item );
void printList( Node * start );

int main() {
	Node * startOfList = NULL;
	
	insertNode( &startOfList, 1 );
	printList( startOfList );
	
	deleteNode( &startOfList, 1 );
	printList( startOfList );
	
	insertNode( &startOfList, 2 );
	printList( startOfList );
	
	insertNode( &startOfList, 3 );
	printList( startOfList );
	
	insertNode( &startOfList, 5 );
	printList( startOfList );
	
	insertNode( &startOfList, 4 );
	printList( startOfList );
	
	deleteNode( &startOfList, 2 );
	printList( startOfList );
	
	insertNode( &startOfList, 2 );
	printList( startOfList );
	
	insertNode( &startOfList, 1 );
	printList( startOfList );
	
	deleteNode( &startOfList, 5 );
	printList( startOfList );
	
	deleteNode( &startOfList, 3 );
	printList( startOfList );
	
	insertNode( &startOfList, 3 );
	printList( startOfList );
	
	
	
	
	
	
	
	
}

void printList( Node * start ) {
	printf("List: ");
	while( start != NULL ) {
		printf( "%i ", start->data );
		start = start->next;
	}
	puts("");
}

void insertNode( Node ** start, int item ) {
	Node * newNode = malloc( sizeof(Node) );
	Node * probe = *start;
	Node * temp = NULL;
	
	newNode->before = NULL;
	newNode->data = item;
	newNode->next = NULL;
	
	if( *start == NULL ) {
		*start = newNode;
	} else {
		while( item > probe->data && probe->next != NULL ) {
			probe = probe->next;
		}
		
		if( item <= (*start)->data ) {
			*start = newNode;
			newNode->next = probe;
		} else {
			if( probe->next == NULL && item > probe->data ) {
				probe->next = newNode;
				newNode->before = probe;
			} else {
				temp = probe->before;
				
				temp->next = newNode;
				newNode->before = temp;
				
				newNode->next = probe;
				probe->before = newNode;
			}
		}
	}
}

void deleteNode( Node ** start, int item ) {
	Node * probe = *start;
	Node * previousNode = NULL;
	Node * nextNode = NULL;
	
	if( probe != NULL ) {
		while( probe != NULL && probe->data != item ) 
			probe = probe->next;
		
		if( probe->next == NULL && probe->before == NULL ) {
			*start = NULL;
			free( probe );
		} else if( probe->next != NULL && probe->before != NULL ) {
			previousNode = probe->before;
			nextNode = probe->next;
			
			previousNode->next = nextNode;
			nextNode->before = previousNode;
			
			free( probe );
		} else if( probe->next != NULL && probe->before == NULL ) {
			*start = probe->next;
			free( probe );
		} else {
			previousNode = probe->before;
			previousNode->next = NULL;
			free(probe);
		}
	}
}

