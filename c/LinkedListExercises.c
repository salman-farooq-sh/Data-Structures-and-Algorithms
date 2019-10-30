#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} Node; 

typedef Node* NodePtr;

void printList( NodePtr );

void insertNode( NodePtr *, int );
void insertNodeAtEnd( NodePtr *, int );
void insertNodeAtBegin( NodePtr *, int );

void deleteNode( NodePtr *, int );
void concatenateLists( NodePtr *, NodePtr * );

NodePtr mergeLists( NodePtr, NodePtr );
NodePtr reverseList( NodePtr );

int main() {
	NodePtr list1 = NULL;
	NodePtr list2 = NULL;
	
	srand( 3 );
	
	for( int i = 0; i < 10; i++ ) 
		insertNode( &list1, rand() % 100 );
	
	printList( list1 );
	
	for( int i = 0; i < 7; i++ ) 
		insertNode( &list2, rand() % 100 );
	
	printList( list2 );
	
	NodePtr mergedList = mergeLists( list1, list2 );
	
	printList( mergedList );
	
	NodePtr reversedMergedList = reverseList( mergedList );
	
	printList( reversedMergedList );
	
}

void printList( NodePtr listStart ) {
	printf("LIST: ");
	
	if( listStart != NULL ) {
		while( listStart != NULL ) {
			printf("%d ", listStart->data );
			listStart = listStart->next;
		}
	} else {
		printf("<empty>");
	}
	puts("");
}

void insertNode( NodePtr * tracer, int item ) {
	NodePtr newNodePtr = (NodePtr) malloc( sizeof( Node ) );
	newNodePtr->data = item;
	newNodePtr->next = NULL;
	
	if( *tracer == NULL ) {
		*tracer = newNodePtr;
	} else if( item < (*tracer)->data ) {
		newNodePtr->next = *tracer;
		*tracer = newNodePtr;
	} else {
		while( (*tracer)->next != NULL && item > (*tracer)->next->data ) 
			tracer = &( (*tracer)->next );
		
		if( (*tracer)->next != NULL ) {
			newNodePtr->next = (*tracer)->next;
			(*tracer)->next = newNodePtr;
		} else {
			(*tracer)->next = newNodePtr;	
		}
	}
}

void deleteNode( NodePtr * tracer, int itemToDelete ) {
	NodePtr NodeToBeDeleted = NULL;
	
	if( *tracer != NULL ) {
		if( (*tracer)->data == itemToDelete ) {
			NodeToBeDeleted = *tracer;
			*tracer = (*tracer)->next;
			free( NodeToBeDeleted );
		} else {
			while( (*tracer)->next != NULL && (*tracer)->next->data != itemToDelete )
				tracer = &( (*tracer)->next );
			
			if( (*tracer)->next != NULL ) {
				NodeToBeDeleted = (*tracer)->next;
				(*tracer)->next = (*tracer)->next->next;
				free( NodeToBeDeleted );
			}
		}	
	}
}

void concatenateLists( NodePtr * list1, NodePtr * list2 ) {
	if( *list1 != NULL ) {
		while( (*list1)->next != NULL ) 
			list1 = &( (*list1)->next );
		
		(*list1)->next = *list2;
	} else {
		*list1 = *list2;
	}
}

NodePtr mergeLists( NodePtr list1Remaining, NodePtr list2Remaining ) {
	NodePtr mergedList = NULL;
	
	while( list1Remaining != NULL || list2Remaining != NULL ) {
		if( list1Remaining != NULL && list2Remaining != NULL ) {
			int next;
			
			if( list1Remaining->data < list2Remaining->data ) {
				next = list1Remaining->data;
				list1Remaining = list1Remaining->next;	
			} else {
				next = list2Remaining->data;
				list2Remaining = list2Remaining->next;
			}
			
			insertNodeAtEnd( &mergedList, next );
		} else if( list1Remaining == NULL && list2Remaining != NULL ) {
			insertNodeAtEnd( &mergedList, list2Remaining->data );
			list2Remaining = list2Remaining->next;
		} else if( list1Remaining != NULL && list2Remaining == NULL ) {
			insertNodeAtEnd( &mergedList, list1Remaining->data );
			list1Remaining = list1Remaining->next;
		}
	}
	
	return mergedList;
}

NodePtr reverseList( NodePtr listPtr ) {
	NodePtr reversedList = NULL;
	
	while( listPtr != NULL ) {
		insertNodeAtBegin( &reversedList, listPtr->data );
		listPtr = listPtr->next;
	}
	
	return reversedList;
}

void insertNodeAtEnd( NodePtr * list, int item ) {
	NodePtr newNodePtr = (NodePtr) malloc( sizeof(Node) );
	newNodePtr->next = NULL;
	newNodePtr->data = item;
	
	if( *list == NULL ) {
		*list = newNodePtr;
	} else {
		while( (*list)->next != NULL ) 
			list = &( (*list)->next );
		
		(*list)->next = newNodePtr;
	}
}

void insertNodeAtBegin( NodePtr * list, int item ) {
	NodePtr newNodePtr = (NodePtr) malloc( sizeof(Node) );
	newNodePtr->next = NULL;
	newNodePtr->data = item;
	
	if( *list == NULL ) {
		*list = newNodePtr;
	} else {
		newNodePtr->next = *list;
		*list = newNodePtr;
	}
}
