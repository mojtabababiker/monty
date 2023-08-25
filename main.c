#include "monty.h"
#include "err.h"

/**
 * main - code entery point, initait the stack and the opCodes functions array
 * @argc: the number of arguments given
 * @argv: pointer to the arguments array
 * Return: 0 or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	stack_t *stack_head;

	stack_head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);

	}
	parseFile(argv[1], &stack_head);
	freeStack(stack_head);
	return (0);
}
