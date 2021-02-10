
#include <stdio.h>
#include <stdlib.h>

/*
BST (Binary search tree)

The values of the child nodes to the left are smaller than that of the parent.
The values of the child nodes to the right are larger than that of the parent.

	   50
      /  \
     10   20
    / \   / \
   2  11  18 29


*/

typedef struct node {
	int data;
	struct node * leftchild;
	struct node * rightchild;
} Node;

Node * createNode(int value) {
	Node * node = (Node*)malloc(sizeof(Node));
	node->data = value;
	node->leftchild = NULL;
	node->rightchild = NULL;
	return node;
}

Node * insert(Node * node, int data) {
	if (node == NULL) {
		node = createNode(data);
	} else if (data <= node->data) {
		node->leftchild = insert(node->leftchild, data);
	} else {
		node->rightchild = insert(node->rightchild, data);
	}

	return node;
}

int search(Node * root, int data) {
	if (root == NULL) {
		return 0;
	} else if (root->data == data) {
		return 1;
	} else if (data < root->data) {
		return search(root->leftchild, data);
	} else {
		return search(root->rightchild, data);
	}
}

void freeBstMemory(Node * root) {
	if (root == NULL) {
		return;
	}

	freeBstMemory(root->leftchild);
	freeBstMemory(root->rightchild);

	free(root);
}

int main() {
	Node * root = NULL;
	root = insert(root, 100);
	root = insert(root, 15);
	root = insert(root, 20);
	root = insert(root, 15);
	root = insert(root, 200);
	root = insert(root, 12);
	root = insert(root, 1);
	root = insert(root, 1000);

	int search4 = 0;
	printf("Which number to search for: ");
	scanf("%d", &search4);

	printf("%d ", search(root, search4));

	freeBstMemory(root);

	return 0;
}