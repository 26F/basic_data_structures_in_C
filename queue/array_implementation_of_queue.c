
#include <stdio.h>

/*
Queue implementation using array
*/

#define MAXSIZE 1024

int Array[MAXSIZE];
int frontindex = -1;
int backindex = -1;

int isEmpty() {
	if (frontindex == -1 && backindex == -1) {
		return 1;
	}
	return 0;
}

int isFull() {
	return backindex == MAXSIZE;
}

void enqueue(int value) {
	if (!isFull()) {
		if (isEmpty()) {
			frontindex = 0;
			backindex = 0;
			Array[backindex] = value;
		} else {
			backindex++;
			Array[backindex] = value;
		}
	}	
}

int front() {
	if (!isEmpty()) {
		return Array[frontindex];	
	} else {
		printf("The Queue is empty");
		return -1;
	}
	
}

int back() {
	if (!isEmpty()) {
		return Array[backindex];	
	} else {
		printf("The Queue is empty");
		return -1;
	}
	
}

int dequeue() {
	if (!isEmpty()) {
		int value = Array[frontindex];
		if (frontindex == backindex) {
			frontindex = -1;
			backindex = -1;
		} else {
			frontindex++;
		}
		return value;
	}
	printf("The Queue is empty");
	return -1;
}

void printQueue() {
	int c;
	if (!isEmpty()) {
		for (c = frontindex; c <= backindex; c++) {
			printf("%d ", Array[c]);
		}
	}
	printf("\n");
	
}

int main() {
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	printQueue(); //1 2 3 4
	dequeue();
	printQueue(); //2 3 4
	dequeue();
	printQueue(); //3 4
	dequeue();
	printQueue(); //4
	dequeue();
	printQueue(); //
	dequeue();    //The Queue is empty
	enqueue(100);
	printf("\n%d %d\n", front(), back());
	enqueue(200);
	printf("\n%d %d\n", front(), back());
	enqueue(300);
	printQueue();

	return 0;
}