
/*
Linked lists example deleting items from a linked list
*/

#include <stdio.h>
#include <stdlib.h>

// Node
struct Node {
	int data;
	struct Node * nextnode;
};

// Head
typedef struct Node * Head;

void insertAtEnd(struct Node ** head, int data) {
	struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->nextnode = NULL;

	if (*head == NULL) {
		*head = newnode;
	} else {
		struct Node * lastnode = *head;
		while (lastnode->nextnode != NULL) {
			lastnode = lastnode->nextnode;
		}

		lastnode->nextnode = newnode;
	}
}

void printAllNodes(struct Node * head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->nextnode;
	}
}

void freeAllNodes(struct Node * head) {
	struct Node * tempnext = NULL;
	while (head != NULL) {
		tempnext = head->nextnode;
		free(head);
		head = tempnext;
	}
}

void deleteNodeAtIndex(struct Node ** head, int index) {
	int c;
	struct Node * temp = *head;

	if (index == 0) {
		*head = temp->nextnode;
		free(temp);
		return;
	}

	for (c = 0; c < index - 1; c++) {
		temp = temp->nextnode;
	}

	struct Node * temp2 = temp->nextnode;
	temp->nextnode = temp2->nextnode;

	free(temp2);
}

int main() {
	Head head = NULL;
	int num;
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 4);
	insertAtEnd(&head, 6);
	insertAtEnd(&head, 5);

	printAllNodes(head);

	printf("Which node to delete [0--3]\n");
	scanf("%d", &num);

	deleteNodeAtIndex(&head, num);
	printAllNodes(head);

	freeAllNodes(head);

	return 0;
}