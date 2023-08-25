#include "monty.h"
#include "err.h"

/**
 * push_op - push an element to the stack
 * @stack_head: address of the stack_head
 * @line_number: the opcode line number in the file
 */
void push_op(stack_t **stack_head,
	     __attribute__((unused))unsigned int line_number)
{
	/* just be here with your mate and let exec_instructio do your work */
	if (stack_head == NULL)
		*stack_head = (*stack_head)->prev;
}


/**
 * pall_op - prints all stack value
 * @stack_head: address of the stack_head
 * @line_number: the opcode line number in the file
 */
void pall_op(stack_t **stack_head,
	     __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack_head;

	if (*stack_head != NULL)
	{
		if (!temp)/*change with the lifo flag*/
		{
			while ((*stack_head)->next != NULL)
				*stack_head = (*stack_head)->next;
			while (*stack_head != NULL)
			{
				fprintf(stdout,
					"%d\n", (*stack_head)->n
					);
				*stack_head = (*stack_head)->prev;
			}
		}
		else
		{
			while (*stack_head != NULL)
			{
				fprintf(stdout,
					"%d\n", (*stack_head)->n
					);
				*stack_head = (*stack_head)->next;
			}
		}
	}
	*stack_head = temp;
}

/**
 * pint_op - prints the value at the top of the stack
 * @stack_head: address of the stack_head
 * @line_number: the opcode line number in the file
 */
void pint_op(stack_t **stack_head, unsigned int line_number)
{
	int err = 0;
	int num = stack_top(stack_head, &err);

	if (num == -1 && err == -1)
	{
		fprintf(stderr,
			"L%u: can't pint, stack empty\n", line_number
			);
		freeStack(*stack_head);
		errNum = 1;
	}
	else
		fprintf(stdout, "%d\n", num);
}

/**
 * pop_op - remove the top element on the stack
 * @stack_head: address of the stack_head
 * @line_number: the opcode line number in the file
 */
void pop_op(stack_t **stack_head, unsigned int line_number)
{
	int err = 0;
	int num = stack_pop(stack_head, &err);

	if (num == -1 && err == -1)
	{
		fprintf(stderr,
			"L%u: can't pop an empty stack\n", line_number
			);
		freeStack(*stack_head);
		errNum = 1;
	}
}
/**
 * swap_op - swap the top two elements of the stack
 * @stack_head: address of the stack_head
 * @line_number: the opcode line number in the file
 */
void swap_op(stack_t **stack_head, unsigned int line_number)
{
	int err = 0;
	int num1 = stack_pop(stack_head, &err);
	int num2 = stack_pop(stack_head, &err);


	if ((num1 == -1 || num2 == -1) && err == -1)
	{
		fprintf(stderr,
			"L%u: can't swap, stack too short\n", line_number
			);
		freeStack(*stack_head);
		errNum = 1;
	}
	else
	{
		*stack_head = stack_push(stack_head, num1);
		*stack_head = stack_push(stack_head, num2);
	}
}
