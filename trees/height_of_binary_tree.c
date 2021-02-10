
#include <stdio.h>
#include <stdlib.h>


/*
The height of a tree is the longest path (edges)
from the root to a leaf.
*/
typedef struct bstnode {
	int data;
	struct bstnode * leftchild;
	struct bstnode * rightchild;
} Bstnode;

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

int findHeight(Bstnode * root) {
	if (root == NULL) {
		return -1;
	}

	int leftsubtreeheight = findHeight(root->leftchild);
	int rightsubtreeheight = findHeight(root->rightchild);

	int max = 0;
	if (leftsubtreeheight > rightsubtreeheight) {
		max = leftsubtreeheight;
	} else {
		max = rightsubtreeheight;
	}

	return max + 1;
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

	printf("Height of binary tree: %d\n", findHeight(Root));
	freeBstMemory(Root);

	return 0;
}