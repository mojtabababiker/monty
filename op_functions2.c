#include "monty.h"
#include "err.h"

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
		freeStack(*stack_head);
		errNum = 1;
	}
	else
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
		freeStack(*stack_head);
		errNum = 1;
	}
	else
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
		freeStack(*stack_head);
		errNum = 1;
	}
	else
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
		freeStack(*stack_head);
		errNum = 1;
	}
	else if (num1 == 0)
	{
		fprintf(stderr,
			"L%u: division by zero\n", line_number
			);
		freeStack(*stack_head);
		errNum = 1;
	}
	else
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
		freeStack(*stack_head);
		errNum = 1;
	}
	else if (num1 == 0)
	{
		fprintf(stderr,
			"L%u: division by zero\n", line_number
			);
		freeStack(*stack_head);
		errNum = 1;
	}
	else
		*stack_head = stack_push(stack_head, (num2 % num1));
}
