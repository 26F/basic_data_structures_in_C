
/*
Linked list example reversing a linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * nextnode;
} Node;

typedef Node * Head;

void reverseLinkedList(Node ** head) {
	Node * current = *head;
	Node * prev = NULL;
	Node * next = NULL;

	while (current != NULL) {
		next = current->nextnode;
		current->nextnode = prev;
		prev = current;
		current = next;

	}
	*head = prev;
}

void insertAtEnd(Node ** head, int data) {
	Node * newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->nextnode = NULL;

	if (*head == NULL) {
		*head = newnode;
	} else {
		Node * lastnode = *head;
		while (lastnode->nextnode != NULL) {
			lastnode = lastnode->nextnode;
		}

		lastnode->nextnode = newnode;
	}
}

void printAllNodes(Node * head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->nextnode;
	}
}

void freeAllNodes(Node * head) {
	Node * tempnext = NULL;
	while (head != NULL) {
		tempnext = head->nextnode;
		free(head);
		head = tempnext;
	}
}

int main() {
	Head head = NULL;
	int c, n, j;
	printf("How many numbers? \n");
	scanf("%d", &c);

	for (n = 0; n < c; n++) {
		scanf("%d", &j);
		insertAtEnd(&head, j);
	}

	printAllNodes(head);
	reverseLinkedList(&head);
	printf("\n");
	printAllNodes(head);

	freeAllNodes(head);

	return 0;
}