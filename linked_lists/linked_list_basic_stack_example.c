
#include <stdio.h>
#include <stdlib.h>

/*
Linked list implementation of stack
*/

// Node
typedef struct node {
	int data;
	struct node * nextnode;
} Node;

// Stack
typedef Node * Stack;

// Push
void push(Stack * stack, int value) {
	Node * temp = (Node*)malloc(sizeof(Node));
	temp->data = value;
	temp->nextnode = *stack;
	*stack = temp;
}

// Pop
int pop(Stack * stack) {
	int returnvalue = 0;
	Node * temp;
	if (*stack == NULL) {
		printf("Popped from empty stack\n");
		return -1;
	}
	temp = *stack;
	returnvalue = temp->data;
	*stack = (*stack)->nextnode;
	free(temp);
	return returnvalue;
}

int isEmpty(Stack stack) {
	return stack == NULL;
}

int top(Stack stack) {
	if (stack == NULL) {
		printf("The stack is empty");
		return -1;
	}
	return stack->data;
}

void freeStack(Stack stack) {
	Node * tempnext = NULL;
	while (stack != NULL) {
		tempnext = stack->nextnode;
		free(stack);
		stack = tempnext;
	}
}

int main() {
	int c;
	Stack stack = NULL;
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);

	pop(&stack);
	pop(&stack);

	for (c = 0; !isEmpty(stack); c++) {
		printf("%d ", pop(&stack));
	}
	printf("\n");
	pop(&stack);
	push(&stack, 100);
	push(&stack, 200);
	push(&stack, 300);
	push(&stack, 400);

	printf("%d\n", top(stack));
	for (c = 0; !isEmpty(stack); c++) {
		printf("%d ", pop(&stack));
	}
	printf("\n");
	top(stack);

	return 0;
}


