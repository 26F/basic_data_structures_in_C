
#include <stdio.h>
#include <stdlib.h>

/*
Find min and max element of bst
*/

typedef struct bstnode {
	int data;
	struct bstnode * leftchild;
	struct bstnode * rightchild;
} Bstnode;

int findMin(Bstnode * root) {

	if (root == NULL) {
		printf("Tree is empty\n");
		return -1;
	}
	while (root->leftchild != NULL) {
		root = root->leftchild;
	}
	return root->data;
}

int findMinRecursive(Bstnode * root) {
	if (root == NULL) {
		printf("Tree is empty\n");
		return -1;
	} else if (root->leftchild == NULL) {
		return root->data;
	}

	return findMinRecursive(root->leftchild);
}

int findMaxRecursive(Bstnode * root) {
	if (root == NULL) {
		printf("Tree is empty\n");
		return -1;
	} else if (root->rightchild == NULL) {
		return root->data;
	}

	return findMaxRecursive(root->rightchild);
}

void createNode(Bstnode ** root, int value) {
	Bstnode * node = (Bstnode*)malloc(sizeof(Bstnode));
	node->data = value;
	node->leftchild = NULL;
	node->rightchild = NULL;
	*root = node;
}

void insert(Bstnode ** node, int data) {
	if (*node == NULL) {
		createNode(node, data);
	} else if (data <= (*node)->data) {
		insert(&(*node)->leftchild, data);
	} else {
		insert(&(*node)->rightchild, data);
	}
}

int findMax(Bstnode * root) {
	if (root == NULL) {
		printf("Tree is empty\n");
		return -1;
	}
	while (root->rightchild != NULL) {
		root = root->rightchild;
	}
	return root->data;
}

void freeBstMemory(Bstnode * root) {
	if (root == NULL) {
		return;
	}

	freeBstMemory(root->leftchild);
	freeBstMemory(root->rightchild);

	free(root);
}

int main() {
	Bstnode * Root = NULL;
	int temp = 0;
	while (temp != -1) {
		printf("Type Number: ");
		scanf("%d", &temp);
		if (temp != -1) {
			insert(&Root, temp);	
		}
		
	}

	printf("Max iterative: %d\n", findMax(Root));
	printf("Max recursive: %d\n\n", findMaxRecursive(Root));
	printf("Min iterative: %d\n", findMin(Root));
	printf("Min recursive: %d\n", findMinRecursive(Root));

	freeBstMemory(Root);
	return 0;
}