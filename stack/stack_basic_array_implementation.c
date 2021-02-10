
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 200

int Array[MAXLEN];
int loc = -1;

void push(int num) {
	loc++;
	Array[loc] = num;
}

int pop() {
	if (loc == -1) {
		printf("Error: nothing left on stack");
		return - 1;
	}
	int item = Array[loc];
	loc--;
	return item;
}

int isEmpty() {
	return loc == -1;
}

int length() {
	return loc + 1;
}

void print() {
	int c;
	for (c = 0; c < length(); c++) {
		printf("%d ", Array[c]);
	}
	printf("\n");
}

int main() {
	int c;
	push(1);
	push(2);
	push(3);
	push(4);
	pop();
	print();
	
	int len = length();
	for (c = 0; c < len; c++) {
		printf("%d ", pop());
	}
	printf("\n");
	pop();
	printf("\n");
	push(100);
	push(200);
	push(300);
	print();
	


	return 0;
}