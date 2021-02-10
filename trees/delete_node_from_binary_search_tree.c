
#include <stdio.h>
#include <stdlib.h>


/*
Delete a node from a binary search tree
*/

typedef struct node {
	int data;
	struct node * leftchild;
	struct node * rightchild;
} Node;


Node * min(Node * node) {

	if (node == NULL) {
		printf("Tree is empty\n");
		return NULL;
	}
	while (node->leftchild != NULL) {
		node = node->leftchild;
	}
	return node;
}

void createNode(Node ** root, int value) {
	Node * node = (Node*)malloc(sizeof(Node));
	node->data = value;
	node->leftchild = NULL;
	node->rightchild = NULL;
	*root = node;
}

void insert(Node ** node, int data) {
	if (*node == NULL) {
		createNode(node, data);
	} else if (data <= (*node)->data) {
		insert(&(*node)->leftchild, data);
	} else {
		insert(&(*node)->rightchild, data);
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

void printInorderTraversal(Node * root) {
	if (root == NULL) {
		return;
	}

	printInorderTraversal(root->leftchild);
	printf("%d ", root->data);
	printInorderTraversal(root->rightchild);
}

void delete(Node ** root, int data) {
	if (*root == NULL) {
		return;
	} else if ((*root)->data > data) {
		delete(&(*root)->leftchild, data);
	} else if ((*root)->data < data) {
		delete(&(*root)->rightchild, data);
	} else {
		if ((*root)->leftchild == NULL && (*root)->rightchild == NULL) {
			free(*root);
			*root = NULL;
		} else if ((*root)->leftchild == NULL) {
			Node  * temp = *root;
			*root = (*root)->rightchild;
			free(temp);
			temp = NULL;
		} else if ((*root)->rightchild == NULL) {
			Node * temp = *root;
			*root = (*root)->leftchild;
			free(temp);
			temp = NULL;
		} else {
			Node * temp = min((*root)->rightchild);
			(*root)->data = temp->data;
			delete(&(*root)->rightchild, temp->data);	
		}
	}
}

int main() {
	Node * root = NULL;
	int temp = 0;
	while (temp != -1) {
		printf("Type integer: ");
		scanf("%d", &temp);
		if (temp != -1) {
			insert(&root, temp);	
		}
	}

	for (;;) {
		printInorderTraversal(root);
		printf("Type number to delete; ");
		scanf("%d", &temp);
		if (temp != -1) {
			delete(&root, temp);	
		} else {
			break;
		}
		
	}

	freeBinaryTree(root);

	return 0;
}