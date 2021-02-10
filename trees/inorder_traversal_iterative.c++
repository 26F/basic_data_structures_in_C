
#include <iostream>
#include <stack>
#include <stdlib.h>

/*
An iterative version of inorder traversal
*/

using namespace std;

typedef struct node {
	int data;
	struct node * leftchild;
	struct node * rightchild;
} Node;

void createNode(Node ** root, int value) {
	Node * node = (Node *)malloc(sizeof(Node));
	node->data = value;
	node->leftchild = NULL;
	node->rightchild = NULL;

	*root = node;
}

void insert(Node ** root, int data) {
	if (*root == NULL) {
		createNode(root, data);
	} else if (data <= (*root)->data) {
		insert(&(*root)->leftchild, data);
	} else {
		insert(&(*root)->rightchild, data);
	}
}

void freeBinaryTree(Node * root) {
	if (root == NULL) {
		return;
	}

	freeBinaryTree(root->leftchild);
	freeBinaryTree(root->rightchild);
	free(root);
	root = NULL;
}

void inOrderTraversalIterative(Node * root) {
	stack<Node *> stk;
	Node * current = root;

	while (current != NULL || stk.empty() == false) {
		while (current != NULL) {
			stk.push(current);
			current = current->leftchild;
		}
	
		current = stk.top();
		stk.pop();
		cout << current->data << " ";
		current = current->rightchild;
	}
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

	inOrderTraversalIterative(root);

	freeBinaryTree(root);
	return 0;
}