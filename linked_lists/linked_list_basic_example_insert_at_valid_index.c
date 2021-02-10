
/*
Linked lists insertion into any valid index
I used zero indexing because it's better.
*/

#include <stdio.h>
#include <stdlib.h>

// Node struct
typedef struct _node {
	int data;
	struct _node * nextnode;
} Node;

// Head is just a pointer to Node
typedef Node * Head;

// insert node at zero indexed position
void insertAtIndex(Node ** head, int index, int value) {
	int c;
	Node * temp = (Node*)malloc(sizeof(Node));
	temp->data = value;
	temp->nextnode = NULL;

	if (index == 0) {
		temp->nextnode = *head;
		*head = temp;
		return;
	}

	Node * temp2 = *head;
	for (c = 0; c < index - 1; c++) {
		temp2 = temp2->nextnode;
	}
	temp->nextnode = temp2->nextnode;
	temp2->nextnode = temp;

}

// prints all the nodes in the linked list.
void printAllNodes(Node * head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->nextnode;
	}
}

// Frees memory
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
	insertAtIndex(&head, 0, 4);
	insertAtIndex(&head, 1, 5);
	insertAtIndex(&head, 2, 2);
	insertAtIndex(&head, 3, 3);
	insertAtIndex(&head, 4, 1000);
	printAllNodes(head);

	insertAtIndex(&head, 1, 2300);
	printf("\n");
	printAllNodes(head);

	freeAllNodes(head);

	return 0;
}