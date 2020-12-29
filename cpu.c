#include <assert.h>

#include "Print.h"

#define TYPE int
#include "StackFunc.h"
#undef TYPE

//==========================================================================

void Push (struct Stack_int *stack, FILE *file);

void Pop (struct Stack_int *stack, FILE *file, int *reg);

void Add (struct Stack_int *stack);

void Sub (struct Stack_int *stack);

void Mul (struct Stack_int *stack);

void Div (struct Stack_int *stack);

//--------------------------------------------------------------------------

int main (){

	FILE *file = fopen ("Prog2.txt", "r");

	struct Stack_int stack = {};
	int register_arr[4] = {0};

	StackConstruct_int (&stack, 10);

	int flag = 1;
	int command;

	fscanf (file, "%d", &command);
	while (flag){

		switch (command){

			case 1:
				Push (&stack, file);
				break;

			case 2:
				Pop (&stack, file, &register_arr[0]);
				break;

			case 3:
				Add (&stack);
				break;

			case 4:
				Sub (&stack);
				break;

			case 5:
				Mul (&stack);
				break;

			case 6:
				Div (&stack);
				break;
				
			case -1:
				flag = 0;
				break;
		}

		if(fscanf (file, "%d", &command) == 0){

			break;
		}
	}

	return 0;
}

//--------------------------------------------------------------------------

void Push (struct Stack_int *stack, FILE *file){

	assert(stack != NULL);
	assert(file != NULL);

	int num = 0;

	if (fscanf (file, "%d", &num) != 0){

		StackPush_int (stack, num);
	}

	return;
}

//--------------------------------------------------------------------------

void Pop (struct Stack_int *stack, FILE *file, int *reg){

	assert(stack != NULL);
	assert(file != NULL);
	assert(reg != NULL);

	int num;

	if (fscanf (file, "%d", reg) != 0){

		StackPop_int (stack, &num);

		printf ("%d\n", num);
	}

	//*reg = num;

	return;
}

//--------------------------------------------------------------------------

void Add (struct Stack_int *stack){

	assert(stack != NULL);

	int num1 = 0, num2 = 0;

	StackPop_int (stack, &num1);	//Надо будет сделать транзакцию, на случай пустого стека

	StackPop_int (stack, &num2);

	StackPush_int (stack, num1 + num2);

	return;
}

//--------------------------------------------------------------------------

void Sub (struct Stack_int *stack){

	assert(stack != NULL);

	int num1 = 0, num2 = 0;

	StackPop_int (stack, &num1);	//Надо будет сделать транзакцию, на случай пустого стека

	StackPop_int (stack, &num2);

	StackPush_int (stack, num2 - num1);

	return;
}

//--------------------------------------------------------------------------

void Mul (struct Stack_int *stack){

	assert(stack != NULL);

	int num1 = 0, num2 = 0;

	StackPop_int (stack, &num1);	//Надо будет сделать транзакцию, на случай пустого стека

	StackPop_int (stack, &num2);

	StackPush_int (stack, num1 * num2);

	return;
}

//--------------------------------------------------------------------------

void Div (struct Stack_int *stack){

	assert(stack != NULL);

	int num1 = 0, num2 = 0;

	StackPop_int (stack, &num1);	//Надо будет сделать транзакцию, на случай пустого стека

	StackPop_int (stack, &num2);

	StackPush_int (stack, num2 / num1);

	return;
}

//==========================================================================