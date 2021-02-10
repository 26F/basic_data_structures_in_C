
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/*
Shit implementation of postfix calculator.
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
	printf("Type Postfix Expression");
	scanf("%s", postfix);

	int index = 0;
	while (postfix[index]) {
		if (isdigit(postfix[index])) {
			push((int)(postfix[index] - '0'));
		} else {
			int op2 = pop();
			int op1 = pop();

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
		index++;
	}

	printf("%d", pop());

	return 0;
}