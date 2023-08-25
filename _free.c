#include "monty.h"

/**
 * _free - is a helper function that free the line and opcode
 *         if an error happend during parsing the file
 * @line: to be freed
 * @opcode: to be freed
 * @args: to be freed
 * @stack_head: pointer to the first element in the stack
 */
void _free(char **line, char **opcode, char **args, stack_t **stack_head)
{
	if (opcode)
	{
		free(*opcode);
		*opcode = NULL;
	}
	if (args)
	{
		free(*args);
		*args = NULL;
	}
	if (line)
	{
		free(*line);
		*line = NULL;
	}
	if (stack_head)
		freeStack(*stack_head);

}

/**
 * freeStack - free the stack if avaliable
 * @stack_head: the top element of the stack
 * Return: always 0
 */
int freeStack(stack_t *stack_head)
{
	if (stack_head == NULL)
		return (0);
	if (stack_head->next == NULL)
	{
		free(stack_head);
		return (0);
	}
	freeStack(stack_head->next);
	free(stack_head);
	return (0);
}
