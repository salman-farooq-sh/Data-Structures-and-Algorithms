#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_EXPRESSION_SIZE 1000
#define DIV_BY_ZERO 39212842920.93289138 //a random number, no mystery behind

#define CAST_TO_INT( x ) ( (int)( x + 0.5 ) )

typedef struct stackNode 
{
	long double data;
	struct stackNode * next;
} 
StackNode;

//-------------------------------------------------------------------------------------------------
void           push                        ( StackNode **, const long double );
long double    pop                         ( StackNode ** );
void           printStack                  ( const StackNode * );
long double    stackTop                    ( const StackNode * );
int            isEmptyStack                ( const StackNode * const );
//-------------------------------------------------------------------------------------------------
char*          convertToPostfix            ( char * const, const char * const );
long double    evaluatePostfix             ( const char * const );

int            precedence1                 ( const char, const char );
int            isOperator                  ( const char );
int            isDigit                     ( const char );
long double    calculate                   ( const long double, const long double, const char );
int            getDigits                   ( const char * const );
int            numberLength                ( const int );
bool           isValidInfix                ( const char * const );
//-------------------------------------------------------------------------------------------------

int main() 
{
	char infix[MAX_EXPRESSION_SIZE] = "((.1+.23))4.5(3(4))-(6.7/8.9+0.1)+2.3(4.5)";
	char postfix[MAX_EXPRESSION_SIZE];
	long double answer;

	printf("%s\n\n", convertToPostfix(postfix, infix) );
	
	if( convertToPostfix( postfix, infix ) == NULL )
	{
		printf("Invalid expression entered\n");
	}
	else if( ( answer = evaluatePostfix(postfix) ) == DIV_BY_ZERO )
	{
		printf("Can't divide by zero\n");
	}
	else 
	{
		printf("%Lf\n\n", answer );
	}
}

void push( StackNode ** tracer, const long double item )
{
	StackNode * newStackPtr = (StackNode *) malloc( sizeof( StackNode ) );
	
	if( newStackPtr == NULL ) 
	{
		printf("couldn't allocate memory for new stack in function push() ");
		return;
	}
	
	newStackPtr->data = item;
	newStackPtr->next = NULL;
	
	if( *tracer == NULL ) 
	{
		*tracer = newStackPtr;
	}
	else 
	{
		while( (*tracer)->next != NULL )
			tracer = &( (*tracer)->next );
		
		(*tracer)->next = newStackPtr;
	}
}

long double pop( StackNode ** tracer )
{
	long double poppedData;
	
	if( *tracer != NULL && (*tracer)->next != NULL ) 
	{
		while( (*tracer)->next->next != NULL )
			tracer = &( (*tracer)->next );
		
		poppedData = (*tracer)->next->data; 
		free( (*tracer)->next );
		(*tracer)->next = NULL;
		
		return poppedData;
	} 
	else if( *tracer != NULL && (*tracer)->next == NULL )
	{
		poppedData = (*tracer)->data;
		free( *tracer );
		*tracer = NULL;
		
		return poppedData;
	}
	
	return EOF;
}

void printStack( const StackNode * probe ) 
{
	printf("Stack: ");
	
	if( probe != NULL ) 
	{
		while( probe != NULL )
		{
			printf("%.2Lf   -->   ", probe->data );
			probe = probe->next;
		}
	}
	
	puts("NULL");
}

int precedence1( const char operator1, const char operator2 ) 
{
	int op1Level = 0;
	int op2Level = 0;
	
//	 Precedence chart:
//	 
//	 3  ^
//	 2  *  /  %
//	 1  +  -
	
	switch( operator1 ) 
	{
		case '^':
			op1Level = 3;
			break;
			
		case '*':
		case '/':
		case '%':
			op1Level = 2;
			break;
			
		case '+':
		case '-':
			op1Level = 1;
			break;
	}
	
	switch( operator2 ) 
	{
		case '^':
			op2Level = 3;
			break;
			
		case '*':
		case '/':
		case '%':
			op2Level = 2;
			break;
			
		case '+':
		case '-':
			op2Level = 1;
			break;
	}
	
	if( op1Level < op2Level )
		return -1;
	
	if( op1Level == op2Level ) 
		return 0;
	
	if( op1Level > op2Level ) 
		return 1;
	
	return -99; 	
}

int isOperator( const char character ) 
{
	return ( character == '^' || 
			 character == '*' || 
			 character == '/' || 
			 character == '%' ||
			 character == '-' || 
			 character == '+'  ) ? 1 : 0;
}

long double stackTop( const StackNode * probe ) 
{
	if( probe == NULL ) 
		return EOF;
	
	while( probe->next != NULL ) 
	{
		probe = probe->next;
	}
	
	return probe->data;
}

int isEmptyStack( const StackNode * const base ) 
{
	return base == NULL;
}

int isDigit ( const char character ) 
{
	return( character == '0' || 
			character == '1' || 
			character == '2' || 
			character == '3' || 
			character == '4' || 
			character == '5' || 
			character == '6' || 
			character == '7' || 
			character == '8' || 
			character == '9'  ) ? 1 : 0;
}

long double calculate( const long double operand1, const long double operand2, const char operator ) 
{
	switch ( operator ) 
	{
		case '+':
			return operand1 + operand2;
			
		case '*':
			return operand1 * operand2;
			
		case '-':
			return operand1 - operand2;
			
		case '/':
			return operand1 / operand2;
			
		case '%':
			return fmodl(operand1, operand2);
			
		case '^':
			return powl(operand1,operand2);
			
		default:
			return -9999999.9999999;
	}
}

int getDigits( const char * const firstDigit ) 
{
	return atoi( firstDigit );
}

int numberLength( const int x ) //I like this
{
	if (x >= 1000000000) return 10;
	if (x >= 100000000)  return 9;
	if (x >= 10000000)   return 8;
	if (x >= 1000000)    return 7;
	if (x >= 100000)     return 6;
	if (x >= 10000)      return 5;
	if (x >= 1000)       return 4;
	if (x >= 100)        return 3;
	if (x >= 10)         return 2;
						 return 1;
}

char * convertToPostfix( char * postfix, const char * const infix )
{
	void addMissingParantheses( char * const ); //prototype
	void insertMissingAsterisks( char * const ); //prototype
	
	char infixCopy[MAX_EXPRESSION_SIZE];
	strcpy( infixCopy, infix );
	
	if( !isValidInfix(infixCopy) )
	{
		return NULL;
	}
	
	addMissingParantheses( infixCopy );
	insertMissingAsterisks( infixCopy );
	
	printf("%s\n\n", infixCopy );
		
	StackNode * stack = NULL;
	const char * currentInfix = infixCopy;
	char * currentpostfix = postfix;
	
	push( &stack, '(' );
	
	strcat( infixCopy, ")" );
	
	while( !isEmptyStack(stack) )
	{
		if( isDigit( *currentInfix ) ) 
		{
			int currentNumber = getDigits( currentInfix );
			
			for( int i = numberLength(currentNumber) - 1; i >= 0; i-- ) 
			{
				*currentpostfix = '0' + ( currentNumber / CAST_TO_INT(pow(10,i)) );
				
				currentNumber %= CAST_TO_INT(pow(10,i));
				
				currentpostfix++;
				currentInfix++;
			}
			
			if( *currentInfix != '.' )
			{
				*currentpostfix = ' ';
				currentpostfix++;
			}
		} 
		else if( *currentInfix == '(' ) 
		{
			push( &stack, '(' );
			currentInfix++;
		}
		else if( isOperator( *currentInfix ) ) 
		{
			while(  isOperator( stackTop(stack) ) && 
				    (precedence1( stackTop(stack), *currentInfix ) == 1 ||
				     precedence1( stackTop(stack), *currentInfix ) == 0  ) ) 
			{
				*currentpostfix = (char)pop( &stack );
				
				currentpostfix++;
				
				*currentpostfix = ' ';
				currentpostfix++;
			}
			
			push( &stack, *currentInfix );
			currentInfix++;
		}
		else if( *currentInfix == ')' ) 
		{
			while( stackTop(stack) != '(' && isOperator( stackTop( stack ) ) ) 
			{
				*currentpostfix = (char)pop( &stack );
				currentpostfix++;
				
				*currentpostfix = ' ';
				currentpostfix++;
			}
			
			pop( &stack );
			currentInfix++;
		}
		else if( *currentInfix == '.' ) 
		{
			*currentpostfix = '.';
			currentpostfix++;
			currentInfix++;
		}
		else if( *currentInfix == ' ' ) 
		{
			currentInfix++;
		}
		else 
		{
			printf("error encoutered in convertToPostfix(): unknown symbol in expression\n");
			return NULL;
		}
	}
	
	return postfix;
}
void addMissingParantheses( char * const infix )
{
	char * currentChar = infix;
	int needle = 0;
	
	while( *currentChar != '\0' )
	{
		if( *currentChar == '(' )
		{
			needle++;
		}	
		else if( *currentChar == ')' )
		{
			needle--;
		}
		
		currentChar++;
	}
	
	for( int i = 0; i < needle; ++i )
	{
		strcat( infix, ")" );
	}
}
void insertMissingAsterisks( char * const infix )
{
	void insertAsterisk( char * const, const char * ); //prototype
	
	char * currentChar = infix;
	
	while( *currentChar != '\0' )
	{
		if( isDigit(*currentChar) && *(currentChar+1) == '(' )
		{
			insertAsterisk( infix, currentChar );
		}
		
		else if( *(currentChar) == ')' && isDigit( *(currentChar+1) ) )
		{
			insertAsterisk( infix, currentChar );
		}
		
		currentChar++;
	}
}
void insertAsterisk( char * const parent, const char * after )
{
	void moveForward( char * ); //prototype
	
	int i = 0;
	while( parent+i != after )
	{
		i++;
	}
	
	moveForward( parent + i + 1 );
	
	parent[i+1] = '*';
	
}
void moveForward( char * c ) //usurps memory not allocated for the string
{
	if( *c != '\0' )
		moveForward(c+1);
	
	*(c+1) = *c;
}

long double evaluatePostfix( const char * const postfixExpression ) //requires string to end with '\0'
{
	const char * currentWord = postfixExpression;
	StackNode * stack = NULL;
	
	long double operand1;
	long double operand2;

	while( *currentWord != '\0' ) 
	{
		if( isDigit( *currentWord ) ) 
		{			
			long double currentNumber = getDigits(currentWord);
			
			if( *( currentWord += numberLength(getDigits(currentWord)) ) == '.' )
			{
				currentWord++;
				currentNumber += getDigits(currentWord) / powl( 10, numberLength(getDigits(currentWord)) );
				currentWord += numberLength( getDigits(currentWord) );
			}
			
			push( &stack, currentNumber );
		}
		else if( *currentWord == '.' ) //infers numbers such as .123 as 0.123
		{
			currentWord++;
			push( &stack, getDigits(currentWord) / powl( 10, numberLength(getDigits(currentWord)) ) );
			currentWord += numberLength( getDigits(currentWord) );
		}
		else if( isOperator(*currentWord) ) 
		{
			operand1 = pop( &stack );
			operand2 = pop( &stack );
			
			if( (*currentWord == '/' || *currentWord == '%') && operand1 == 0 )
			{
				return DIV_BY_ZERO;
			}
			
			push( &stack, calculate( operand2, operand1, *currentWord ) );
			
			currentWord++;
		}
		else if( *currentWord == ' ' ) 
		{	
			currentWord++;
		}
	}
	
	return pop( &stack );
}

bool isValidInfix( const char * const infix )
{
	bool isEmptyStr( const char * const );  //prototype
	bool hasValidParantheses( const char * const ); //prototype
	
	
	return !isEmptyStr(infix) && hasValidParantheses(infix); // && other checks (to be added)
}

bool isEmptyStr ( const char * const str )
{
	return *str == '\0';
}

bool hasValidParantheses( const char * const infix ) //requires string to end with '\0' 
{
	bool ParanthesesCheck1( const char * const ); //prototype
	bool ParanthesesCheck2( const char * const ); //prototype
	
	
	return ParanthesesCheck1(infix) && ParanthesesCheck2(infix);
}

bool ParanthesesCheck1( const char * const exp ) 
{	
	const char * currWord = exp;
	
	int needle = 0;
	
	while( *currWord != '\0' )
	{
		if( *currWord == '(' )
		{
			needle++;;
		}
		else if( *currWord == ')' )
		{
			if( needle <= 0 )
			{
				return false;
			}
			else 
			{
				needle--;
			}
		}
		
		currWord++;
	}
	
	return true;
}

bool ParanthesesCheck2( const char * const exp )
{	
	const char * currWord = exp;
	
	while( *(currWord+1) != '\0' )
		currWord++;
	
	if( *currWord == '(' )
		return false;
	
	return true;
}


//operators with missing operands
//operands with missing operators

//multiple radix point in single number
//multiple operators
//disable specific keys after specific keys are pressed until specific keys are pressed




