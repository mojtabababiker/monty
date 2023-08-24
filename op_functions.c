#include "monty.h"
#include "grammer.h"

/**
 * push_op - push an element to the stack
 * @stack_head: address of the stack_head
 * @line_number: the opcode line number in the file
 */
void push_op(__attribute__((unused))stack_t **stack_head,
	     __attribute__((unused))unsigned int line_number)
{
	/* just be here with your mate and let exec_instructio do your work */
}


/**
 * pall_op - prints all stack value
 * @stack_head: address of the stack_head
 * @lifo: flag to set the LIFO algrothim to stack or not
 * @line_number: the opcode line number in the file
 */
void pall_op(stack_t **stack_head, int lifo,
	     __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack != NULL)
	{
		if (!lifo)
		{
			while ((*stack)->next != NULL)
				*stack = (*stack)->next;
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
		freeAll();
		exit(EXIT_FAILURE);
	}
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
	int num = stack_pop(&err);

	if (num == -1 && err == -1)
	{
		fprintf(stderr,
			"L%u: can't pop an empty stack\n", line_number
			);
		freeAll();
		exit(EXIT_FAILURE);
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
	int num1 = stack_pop(head, &err);
	int num2 = stack_pop(head, &err);


	if ((num1 == -1 || num2 == -1) && err == -1)
	{
		fprintf(stderr,
			"L%u: can't swap, stack too short\n", line_number
			);
		freeAll();
		exit(EXIT_FAILURE);
	}
	*stack_head = stack_push(stack_head, num2);
	*stack_head = stack_push(stack_head, num1);
}

/**
 * add_op - add the top two elements of the stack
 * @stack_head: address of the stack_head
 * @line_number: the opcode line number in the file
 */
void add_op(stack_t **stack_head, unsigned int line_number)
{
	int err = 0;
	int num1 = stack_pop(stack_head, &err);
	int num2 = stack_pop(stack_head, &err);

	if ((num1 == -1 || num2 == -1) && err == -1)
	{
		fprintf(stderr,
			"L%u: can't add, stack too short\n", line_number
			);
		freeAll();
		exit(EXIT_FAILURE);
	}
	*stack_head = stack_push(stack_head, (num2 + num1));
}

/**
 * sub_op - subtracts the top element of the stack from the
 *          second top element of the stack.
 * @stack_head: address of the stack_head
 * @line_number: the opcode line number in the file
 */
void sub_op(stack_t **stack_head, unsigned int line_number)
{
	int err = 0;
	int num1 = stack_pop(stack_head, &err);
	int num2 = stack_pop(stack_head, &err);

	if ((num1 == -1 || num2 == -1) && err == -1)
	{
		fprintf(stderr,
			"L%u: can't sub, stack too short\n", line_number
			);
		freeAll();
		exit(EXIT_FAILURE);
	}
	*stack_head = stack_push(stack_head, (num2 - num1));
}

/**
 * mul_op - multiplies the second top element of the stack with
 *          the top element of the stack
 * @stack_head: address of the stack_head
 * @line_number: the opcode line number in the file
 */
void mul_op(stack_t **stack_head, unsigned int line_number)
{
	int err = 0;
	int num1 = stack_pop(stack_head, &err);
	int num2 = stack_pop(stack_head, &err);

	if ((num1 == -1 || num2 == -1) && err == -1)
	{
		fprintf(stderr,
			"L%u: can't mul, stack too short\n", line_number
			);
		freeAll();
		exit(EXIT_FAILURE);
	}
	*stack_head = stack_push(stack_head, (num2 * num1));
}

/**
 * div_op - push an element to the stack
 * @stack_head: address of the stack_head
 * @line_number: the opcode line number in the file
 */
void div_op(stack_t **stack_head, unsigned int line_number)
{
	int err = 0;
	int num1 = stack_pop(stack_head, &err);
	int num2 = stack_pop(stack_head, &err);

	if ((num1 == -1 || num2 == -1) && err == -1)
	{
		fprintf(stderr,
			"L%u: can't div, stack too short\n", line_number
			);
		freeAll();
		exit(EXIT_FAILURE);
	}
	if (num1 == 0)
	{
		fprintf(stderr,
			"L%u: division by zero\n", line_number
			);
		freeAll();
		exit(EXIT_FAILURE);
	}
	*stack_head = stack_push(stack_head, (num2 / num1));
}

/**
 * mod_op - push an element to the stack
 * @stack_head: address of the stack_head
 * @line_number: the opcode line number in the file
 */
void mod_op(stack_t **stack_head, unsigned int line_number)
{
	int err = 0;
	int num1 = stack_pop(stack_head, &err);
	int num2 = stack_pop(stack_head, &err);

	if ((num1 == -1 || num2 == -1) && err == -1)
	{
		fprintf(stderr,
			"L%u: can't mod, stack too short\n", line_number
			);
		freeAll();
		exit(EXIT_FAILURE);
	}
	if (num1 == 0)
	{
		fprintf(stderr,
			"L%u: division by zero\n", line_number
			);
		freeAll();
		exit(EXIT_FAILURE);
	}
	*stack_head = stack_push(stack_head, (num2 % num1));
}

/**
 * nop_op - push an element to the stack
 * @stack_head: address of the stack_head
 * @line_number: the opcode line number in the file
 */
void nop_op(__attribute__((unused))stack_t **stack_head,
	    __attribute__((unused))unsigned int line_number)
{
	/* do nothing just be here with your fams -_- */
}
