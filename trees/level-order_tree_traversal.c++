
#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

/*
Level-order tree traversal
*/

typedef struct btnode {
  int data;
  btnode * leftchild;
  btnode * rightchild;
} Btnode;

Btnode * createnode(int value) {
	Btnode * btnode = (Btnode*)malloc(sizeof(Btnode));
	btnode->data = value;
	btnode->leftchild = NULL;
	btnode->rightchild = NULL;
	return btnode;
}

Btnode * insert(Btnode * btnode, int data) {
	if (btnode == NULL) {
		btnode = createnode(data);
	} else if (data <= btnode->data) {
		btnode->leftchild = insert(btnode->leftchild, data);
	} else {
		btnode->rightchild = insert(btnode->rightchild, data);
	}

	return btnode;
}

void levelOrderTraversal(Btnode * root) {
  if (root == NULL) {
    return;
  }
  queue<Btnode *> Q;
  Q.push(root);

  while (!Q.empty()) {
  	Btnode * current = Q.front();
  	cout << current->data << " ";
  	if (current->leftchild != NULL) {
  		Q.push(current->leftchild);
  	}
  	if (current->rightchild != NULL) {
  		Q.push(current->rightchild);
  	}
  	Q.pop();
  }
}

void freeBtMemory(Btnode * root) {
	if (root == NULL) {
		return;
	}

	freeBtMemory(root->leftchild);
	freeBtMemory(root->rightchild);

	free(root);
}

int main() {
	Btnode * Root = NULL;
	int temp = 0;
	while (temp != -1) {
		printf("Type number");
		scanf("%d", &temp);
		if (temp != -1) {
			Root = insert(Root, temp);
		}
	}
	levelOrderTraversal(Root);

	freeBtMemory(Root);
	return 0;
}