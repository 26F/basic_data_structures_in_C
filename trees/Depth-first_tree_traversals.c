
/*

Tree traversals
exersize: tree and implement an iterative version!

Space complexity: O(height of binary tree)
                  O(h)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node * leftchild;
	struct node * rightchild;
} Node;

void printPreorderTraversal(Node * root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->data);
	printPreorderTraversal(root->leftchild);
	printPreorderTraversal(root->rightchild);
}

void printInorderTraversal(Node * root) {
	if (root == NULL) {
		return;
	}

	printInorderTraversal(root->leftchild);
	printf("%c ", root->data);
	printInorderTraversal(root->rightchild);
}

void printPostorderTraversal(Node * root) {
	if (root == NULL) {
		return;
	}

	printPostorderTraversal(root->leftchild);
	printPostorderTraversal(root->rightchild);
	printf("%c ", root->data);
}

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

int main() {
	Node * Root = NULL;
	char temp = 0;
	while (temp != '!') {
		printf("Type char:");
		scanf(" %c", &temp);
		if (temp != '!') {
			insert(&Root, temp);
		}
	}

	printPreorderTraversal(Root);
	printf("\n");
	printInorderTraversal(Root);
	printf("\n");
	printPostorderTraversal(Root);

	freeBinaryTree(Root);
	return 0;
}