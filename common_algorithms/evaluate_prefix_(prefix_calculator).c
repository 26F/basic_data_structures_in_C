
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/*
Shit implementation of prefix calculator.
*/

int Stack[200] = {0};
int loc = -1;

int isempty() {
	return loc == -1;
}

void push(int value) {
	loc++;
	Stack[loc] = value;
}

int pop() {
	int value = Stack[loc--];
	return value;
}

int main() {
	char postfix[200] = {0};
	printf("Type Prefix Expression");
	scanf("%s", postfix);

	int index = strlen(postfix) - 1;
	while (index >= 0) {
		if (isdigit(postfix[index])) {
			push((int)(postfix[index] - '0'));
		} else {
			int op1 = pop();
			int op2 = pop();

			if (postfix[index] == '*') {
				push(op1 * op2);
			} else if (postfix[index] == '/') {
				push(op1 / op2);
			} else if (postfix[index] == '+') {
				push(op1 + op2);
			} else if (postfix[index] == '-') {
				push(op1 - op2);
			}
		}
		index--;
	}

	printf("%d", pop());

	return 0;
}