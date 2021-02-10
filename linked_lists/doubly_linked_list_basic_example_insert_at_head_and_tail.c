
/*
Doubly Linked list example
*/

#include <stdio.h>
#include <stdlib.h>

// Node
typedef struct node {
	int data;
	struct node * nextnode;
	struct node * previousnode;
} Node;


// Head
typedef Node * Head;

Node * CreateNode(int value) {
	Node * temp = (Node*)malloc(sizeof(Node));
	temp->data = value;
	temp->nextnode = NULL;
	temp->previousnode = NULL;
	return temp;
}

void insertAtHead(Head * head, int value) {
	Node * newnode = CreateNode(value);
	if (*head == NULL) {
		*head = newnode;
		return;
	}	
	(*head)->previousnode = newnode;
	newnode->nextnode = *head;
	*head = newnode;
}

void insertAtTail(Head * head, int value) {
	Node * newnode = CreateNode(value);
	Node * last = *head;

	if (*head == NULL) {
		newnode->previousnode = NULL;
		*head = newnode;
		return;
	}

	while (last->nextnode != NULL) {
		last = last->nextnode;
	}

	last->nextnode = newnode;
	newnode->previousnode = last;
}

void printAllNodes(Head head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->nextnode;
	}
	printf("\n");
}

void printAllNodesInReverse(Head head) {
	if (head == NULL) {
		return;
	}

	while (head->nextnode != NULL) {
		head = head->nextnode;
	}

	while (head != NULL) {
		printf("%d ", head->data);
		head = head->previousnode;
	}
	printf("\n");
}

void freeAllNodes(Head head) {
	Node * tempnext = NULL;
	while (head != NULL) {
		tempnext = head->nextnode;
		free(head);
		head = tempnext;
	}
}

int main() {
	Head head = NULL;

	insertAtHead(&head, 100);
	insertAtHead(&head, 200);
	insertAtHead(&head, 300);
	insertAtTail(&head, 1000);
	printAllNodes(head);
	printAllNodesInReverse(head);
	freeAllNodes(head);
	return 0;
}
