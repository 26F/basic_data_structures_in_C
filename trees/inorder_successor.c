
#include <stdio.h>
#include <stdlib.h>
/*
Find inorder successor
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
	}
	else if (data <= node->data) {
		node->leftchild = insert(node->leftchild, data);		
	}
	else 
	{
		node->rightchild = insert(node->rightchild, data);
	}
	return node;
}

void freeBinarySearchTree(Node * root) {
	if (root == NULL) {
		return;
	}

	freeBinarySearchTree(root->leftchild);
	freeBinarySearchTree(root->rightchild);
	free(root);
	root = NULL;
}

Node * find(Node * root, int data) {
	if (root == NULL) {
		return NULL;
	}
	else if (root->data == data) {
		return root;
	} 
	else if (data < root->data) {
		return find(root->leftchild, data);
	} 
	else 
	{
		return find(root->rightchild, data);
	}
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

Node * min(Node * root) {
	if (root == NULL) {
		return NULL;
	}

	while (root->leftchild != NULL) {
		root = root->leftchild;
	}
	return root;
}

Node * inorderSuccessor(Node * root, int data) {
	Node * current = find(root, data);
	if (current == NULL) {
		return NULL;
	}

	if (current->rightchild != NULL) {
		return min(current->rightchild);
	}
	else 
	{
		Node * successor = NULL;
		Node * ancestor = root;

		while (ancestor != current) {
			if (current->data < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->leftchild;
			} 
			else 
			{
				ancestor = ancestor->rightchild;
			}
		}
		return successor;
	}
}

int main() {
	Node * root = NULL;
	int temp = 0;
	while (temp != -1) {
		printf("Type number: ");
		scanf("%d", &temp);
		if (temp != -1) {
			root = insert(root, temp);
		}
	}

	printf("\nIs a binary search tree %d\n", isBST(root));

	for (;;) {
		printf("Type node data to view inorder Successor: ");
		scanf("%d", &temp);

		if (temp != -1) {
			Node * node = inorderSuccessor(root, temp);
			if (node != NULL) {
				printf("%d\n", node->data);
			} 
			else 
			{
				printf("NULL\n");
			}
		} 
		else {
			break;
		}
	}

	freeBinarySearchTree(root);
	return 0;
}

