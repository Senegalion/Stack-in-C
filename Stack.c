#include "Stack.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void init(Stack* s)
{
	s->stack = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
	if (s->stack == NULL) {
		printf("Bad allocation\n");
		destroy(s);
		abort();
	}
	s->top = -1;
	s->capacity = INITIAL_CAPACITY;
	printf("Stack has been initialized\n");
}

void destroy(Stack* s)
{
	free(s->stack);
	s->capacity = 0;
	s->top = -1;
	printf("Stack has been destroyed\n");
}

void push(Stack* s, int element)
{
	if (s->top == s->capacity - 1) {
		if (s->capacity <= INT_MAX / 2) {
			s->capacity *= 2;
		}
		else if (s->capacity <= INT_MAX - ADD_CAPACITY_ADDEND) {
			s->capacity += ADD_CAPACITY_ADDEND;
		}
		else {
			printf("Capacity is greater than INT_MAX\n");
			destroy(s);
			abort();
		}

		int* temp = (int*)realloc(s->stack, s->capacity * sizeof(int));
		if (temp == NULL) {
			printf("Bad reallocation\n");
			destroy(s);
			abort();
		}
		s->stack = temp;
	}
	s->top++;
	s->stack[s->top] = element;
	printf("\n--------------------------\n");
	printf("%d has been pushed to the stack", element);
	printf("\n--------------------------\n");
}

int pop(Stack* s)
{
	if (!isEmpty(s)) {
		printf("\n--------------------------\n");
		printf("%d has been popped from the stack", s->stack[s->top--]);
		printf("\n--------------------------\n");
		return s->stack[s->top + 1];
	}
	else {
		printf("You cannot pop because stack is empty\n");
		destroy(s);
		// abort();
		exit(EXIT_FAILURE);
	}
}

bool isEmpty(const Stack* s)
{
	bool isStackEmpty = s->top == -1;
	return isStackEmpty;
}
