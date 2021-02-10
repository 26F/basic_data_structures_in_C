
#include <stdio.h>
#include <stdlib.h>

typedef struct _stack {
	char data[1000];
	int loc;
} Stack;


Stack createStack() {
	Stack stack = {{0}, -1};
	return stack;
}

void push(Stack * stackptr, char ch) {
	stackptr->loc++;
	stackptr->data[stackptr->loc] = ch;
}

char pop(Stack * stackptr) {
	return stackptr->data[stackptr->loc--];
}

int isEmpty(Stack * stack) {
	return stack->loc == -1;
}

char top(Stack * stack) {
	return stack->data[stack->loc];
}

enum Bracketype {ROUND, CURLY, SQUARE};
enum Bracketype typeOfBracket(char ch) {
	if (ch == '{' || ch == '}') {
		return CURLY;
	} else if (ch == '(' || ch == ')') {
		return ROUND;
	} else {
		return SQUARE;
	}
}

int doBracketsMatch(Stack * stack, char * string) {
	int c;
	char character = 0;
	for (c = 0; string[c]; c++) {
		character = string[c];
		if (character == '(' || character == '{' || character == '[') {
			push(stack, string[c]);	
		} else if (character == ')' || character == '}' || character == ']') {
			if (isEmpty(stack)) {
				return 0;
			} else {
				if (typeOfBracket(string[c]) == typeOfBracket(top(stack))) {
					pop(stack);	
				}
				
			}
		}
	}
	return isEmpty(stack);


}

int main() {
	Stack stack = createStack();
	char string[500] = {0};
	printf("Type string: ");
	scanf("%s", string);

	int result = doBracketsMatch(&stack, string);
	printf("%d ", result);

	return 0;
}


