
/*
Linked lists example
*/

#include <stdio.h>
#include <stdlib.h>


// Node
typedef struct node {
	int data;
	struct node * nextnode;
} Node;


// Head
typedef Node * Head;

void insertNewNodeAtHead(Node ** head, int n) {
	Node * temp = (Node *)malloc(sizeof(Node));
	temp->data = n;
	temp->nextnode = *head;

	*head = temp;
}

// print all nodes in the linked list
void printAllNodes(Node * temp) {
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->nextnode;
	}
	printf("\n");
}

// free memory
void freeAllNodes(Node * temp) {
	Node * tempnext = NULL;
	while (temp != NULL) {
		tempnext = temp->nextnode;
		free(temp);
		temp = tempnext;
	}
}

int main() {
	Head head = NULL;
	int num;
	int c, i;
	printf("How  many numbers to store? \n");
	scanf("%d", &num);
	
	for (c = 0; c < num; c++) {
		printf("Enter number: \n");
		scanf("%d", &i);
		insertNewNodeAtHead(&head, i);
		printAllNodes(head);
	}

	freeAllNodes(head);

	return 0;
}