#pragma once
#include <stdbool.h>

#define INITIAL_CAPACITY 5
#define MULTIPLY_CAPACITY_FACTOR 2
#define ADD_CAPACITY_ADDEND 100

typedef struct {
	int* stack;
	int top;
	int capacity;
} Stack;

void init(Stack* s);

void destroy(Stack* s);

void push(Stack* s, int element);

int pop(Stack* s);

bool isEmpty(const Stack* s);
