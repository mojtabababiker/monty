#include "monty.h"
#include "err.h"

/**
 * pchar_op - print the top element of the stack as charcacter
 * @stack_head: pointer to the top element on the stack
 * @line_number: the line number of the opcode (pchar)
 */
void pchar_op(stack_t **stack_head, unsigned int line_number)
{
	int chr, err;

	chr = stack_top(stack_head, &err);
	if (chr == -1 && err == -1)
	{
		/*empty stack*/
		fprintf(stderr,
			"L%u: can't pchar, stack empty\n", line_number);
		errNum = 1;
	}
	else if (chr < 0 || chr > 127)
	{
		/*out of range error*/
		fprintf(stderr,
			"L%u: can't pchar, value out of range\n", line_number);
		errNum = 1;
	}
	else
		printf("%c\n", chr);
}

/**
 * pstr_op - print the string from the stack
 * @stack_head: pointer to the top element on the stack
 * @line_number: the line number of the opcode (pstr)
 */
void pstr_op(stack_t **stack_head,
	     __attribute__((unused))unsigned int line_number)
{
	int chr, err;
	stack_t *temp;

	chr = stack_top(stack_head, &err);
	if (chr == -1 && err == -1)
	{
		printf("\n");
		return;
	}
	temp = *stack_head;
	while (*stack_head != NULL)
	{
		chr = stack_top(stack_head, &err);
		if (chr == -1 && err == -1)
			break;
		if (chr == 0)
			break;
		if (chr < 0 || chr > 127)
			break;
		printf("%c", chr);
		*stack_head = (*stack_head)->next;
	}
	*stack_head = temp;
	printf("\n");
}
