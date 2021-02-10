
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * nextnode;
} Node;

Node * head;
Node * tail;

void enqueue(int value) {
	Node * temp = (Node *)malloc(sizeof(Node));
	temp->data = value;
	temp->nextnode = NULL;

	if (head == NULL && tail == NULL) {
		head = temp;
		tail = temp;
		return;
	}

	tail->nextnode = temp;
	tail = temp;
} 

int dequeue() {
	Node * temp = head;
	int value = -1;
	if (head == NULL) {
		printf("The queue is empty\n");
		return value;
	}

	if (head == tail) {
		value = head->data;
		head = NULL;
		tail = NULL;
	} else {
		value = head->data;
		head = head->nextnode;
	}

	free(temp);
	return value;
}

void printQueue() {
	Node * temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->nextnode;
	}
	printf("\n");
}

int main() {
	enqueue(1);
	enqueue(2);
	enqueue(3);

	printQueue();

	dequeue();
	printQueue();

	dequeue();
	printQueue();

	dequeue();
	printQueue();

	dequeue();

	enqueue(100);
	enqueue(200);
	enqueue(300);
	enqueue(400);

	while (head != NULL) {
		printQueue();
		dequeue();
	}

	dequeue();

	return 0;
}