
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
Infix to postfix - basic implementation.
*/

char Stack[512] = {0};
int loc = -1;

int isEmpty() {
	return loc == -1;
}

void push(int value) {
	loc++;
	Stack[loc] = value;
}

int pop() {
	int value = Stack[loc];
	loc--;
	return value;
}

int top() {
	return Stack[loc];
}

int topHasHigherPrec(char top, char other) {
	if (top == other) {
		return 1;
	}

	if ((top == '*' && other == '-') || (top == '*' && other == '+')) {
		return 1;
	} else if ((top == '/' && other == '-') || (top == '/' && other == '+')) {
		return 1;
	}

	return 0;
}

char * infixToPostfix(char * infix) {
	int c;
	int loc = 0;
	char temp = 0;
	char * resultstr = (char*)malloc(strlen(infix) * 2);
	for (c = 0; infix[c]; c++) {
		if (isalnum(infix[c])) {
			resultstr[loc] = infix[c];
			loc++;
		} else if (infix[c] == '(') {
			push('(');
		} else if (infix[c] == ')') {
			while (top() != '(') {
				temp = pop();
				if (temp != '(' && temp != ')') {
					resultstr[loc] = temp;
					loc++;
				}
			}
			pop();
		} else {
			while (!isEmpty() && topHasHigherPrec(top(), infix[c])) {
				resultstr[loc] = pop();
				loc++;
			}
			push(infix[c]);
		} 
	}
	while (!isEmpty()) {
		resultstr[loc] = pop();
		loc++;
	}
	resultstr[loc] = '\0';
	return resultstr;
}

int main() {
	char infix[512] = {0};
	printf("Type infix expression: ");
	scanf("%s", infix);

	char * result = infixToPostfix(infix);
	printf("%s", result);

	free(result);

	return 0;
}