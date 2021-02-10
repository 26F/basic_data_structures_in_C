
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 200

// Globals
char Stack[STACKSIZE] = {0};
int loc = -1;

void push(char ch) {
	if (loc + 1 >= STACKSIZE) {
		printf("StackOverflowError");
		return;
	}
	loc++;
	Stack[loc] = ch;
}

int pop() {
	return Stack[loc--];
}

int isEmpty() {
	return loc == -1;
}

void reverseStr(char * string) {
	int c;
	for (c = 0; string[c]; c++) {
		push(string[c]);
	}

	for (c = 0; !isEmpty(); c++) {
		string[c] = pop();
	}
}

int main() {
	char string[STACKSIZE] = {0};
	printf("Enter string:");
	scanf("%s", string);

	reverseStr(string);
	printf("\n%s", string);
	return 0;
}