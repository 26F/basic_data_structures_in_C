
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * nextnode;
} Node;

typedef Node * Head;

void insertAtEnd(Head * head, int data) {
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

Node * Stack[100];
int Loc = -1;

void push(Node * node) {
	Stack[++Loc] = node;
}

Node * pop() {
	if (Loc != -1) {
		return Stack[Loc--];	
	}
	return NULL;
}

int isEmpty() {
	return Loc == -1;
}

void reverseLinkedList(Head * head) {
	if (*head == NULL) {
		return;
	}

	Node * temp = *head;
	while (temp != NULL) {
		push(temp);
		temp = temp->nextnode;
	}
	temp = pop();
	*head = temp;
	while (!isEmpty()) {
		temp->nextnode = pop();
		temp = temp->nextnode;
	}
	temp->nextnode = NULL;

}

int main() {
	Head head = NULL;
	insertAtEnd(&head, 100);
	insertAtEnd(&head, 200);
	insertAtEnd(&head, 300);
	insertAtEnd(&head, 400);
	insertAtEnd(&head, 500);

	printAllNodes(head);
	printf("\n");
	reverseLinkedList(&head);
	printAllNodes(head);
	freeAllNodes(head);

	return 0;
}