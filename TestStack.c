#include "Stack.c"
#include <stdio.h>

int main()
{
	Stack stack;

	init(&stack);

	int action;
	int element;
	int isCorrectAction;
	int askAgain = 1;

	while (askAgain) {
		printf("\nWhat do you want to do with the stack?\n");
		printf("1 - Push element\n");
		printf("2 - Pop element\n");
		printf("3 - Show stack\n");
		printf("4 - Quit\n");
		printf("--------------------------\n");

		isCorrectAction = scanf("%d", &action);

		if (!isCorrectAction || action < 1 || action > 4) {
			while (getchar() != '\n')
				;
			printf("Incorrect action. Try again: \n");
		}
		else {
			if (action == 1) {
				printf("Enter the integer you want to add to the stack: \n");
				int isCorrectElement = scanf("%d", &element);

				if (!isCorrectElement) {
					while (getchar() != '\n')
						;
					printf("Incorrect element. Try again: \n");
				}
				else {
					push(&stack, element);
				}
			}
			else if (action == 2) {
				pop(&stack);
			}
			else if (action == 3) {
				printf("\n--------------------------\n");
				for (int cell = stack.top; cell >= 0; cell--) {
					printf("%d\n", stack.stack[cell]);
				}
				printf("--------------------------\n");
			}
			else {
				askAgain = 0;
				destroy(&stack);
			}
		}
	}

	return 0;
}
