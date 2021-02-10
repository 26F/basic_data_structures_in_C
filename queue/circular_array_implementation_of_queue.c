
#include <stdio.h>

/*
Queue implementation using circular array
*/

#define MAXSIZE 6

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
	if ((backindex + 1) % MAXSIZE == frontindex) {
		return 1;
	}
	return 0;
}

void enqueue(int value) {
	if (!isFull()) {
		if (isEmpty()) {
			frontindex = 0;
			backindex = 0;
			Array[backindex] = value;
		} else {
			backindex = (backindex + 1) % MAXSIZE;
			Array[backindex] = value;
		}
	} else {
		printf("Queue is full\n");
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
			frontindex = (frontindex + 1) % MAXSIZE;
		}
		return value;
	}
	printf("The Queue is empty");
	return -1;
}

void printQueue() {
	int c;
	int index = frontindex;
	if (!isEmpty()) {
		if (frontindex > backindex) {
			for (c = 0; c < MAXSIZE; c++) {
				printf("%d ", Array[index]);
				index = (index + 1) % MAXSIZE;
			}
		} else {
			for (c = frontindex; c <= backindex; c++) {
			printf("%d ", Array[c]);
			}
		}
	}
	printf("\n");	
}

void printArray() {
	int c;
	for (c = 0; c < MAXSIZE; c++) {
		printf("%d ", Array[c]);
	}
	printf("\n");
}

int main() {
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	printQueue();
	dequeue();
	dequeue();
	dequeue();
	printQueue();
	enqueue(7);
	enqueue(8);
	enqueue(9);
	printQueue();
	enqueue(10);

	return 0;
}