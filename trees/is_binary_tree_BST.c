
/*
Check if binary tree is a binary search tree
(duplicates are not handled)

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * leftchild;
	struct node * rightchild;
} Node;

void createNode(Node ** root, char ch) {
	Node * newnode = (Node*)malloc(sizeof(Node));
	newnode->data = ch;
	newnode->leftchild = NULL;
	newnode->rightchild = NULL;
	*root = newnode;
}

void insert(Node ** root, char ch) {
	if (*root == NULL) {
		createNode(root, ch);
	} else if (ch <= (*root)->data) {
		insert(&(*root)->leftchild, ch);
	} else {
		insert(&(*root)->rightchild, ch);
	}
}

void freeBinaryTree(Node * root) {
	if (root == NULL) {
		return;
	}

	freeBinaryTree(root->leftchild);
	freeBinaryTree(root->rightchild);

	free(root);
}

int isBSTUtil(Node * node, int min, int max);

int isBST(Node * node) {
	return (isBSTUtil(node, INT_MIN, INT_MAX));
}

int isBSTUtil(Node * node, int min, int max) {
	if (node == NULL) {
		return 1;
	}

	if (node->data < min || node->data > max) {
		return 0;
	}

	if (isBSTUtil(node->leftchild, min, node->data - 1)
		&& isBSTUtil(node->rightchild, node->data + 1, max)) {
		return 1;
	}
	return 0;
}

int main() {
	Node * root = NULL;
	int temp = 0;
	while (temp != -1) {
		printf("Type number: ");
		scanf("%d", &temp);
		if (temp != -1) {
			insert(&root, temp);
		}
	}

	printf("%d ", isBST(root));
	freeBinaryTree(root);
	return 0;
}