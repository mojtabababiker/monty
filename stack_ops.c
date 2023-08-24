#include "monty.h"
#include "grammer.h"

/**
 * stack_push - push the number num to the stack
 * @num: the number to be pushed
 * @stack_head: pointer to the head of the stack
 * Return: pointer to the new head of the stack
 */
stack_t *stack_push(stack_t **stack_head, int num)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeAll();
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->prev = NULL;
	new->next = *stack_head;
	if (*stack_head != NULL)
	{
		new->prev = (*stack_head)->prev;
		(*stack_head)->prev = new;
	}
	*stack_head = new;
	return (new);
}

/**
 * stack_pop - pull and return the first number on the stack if the lifo
 *           flag is set, if not it will return the last number
 * @stack_head: pointer to the head of the stack
 * @err: address of the error falg
 * Return: the number or -1 and set the err to 1 in failure
 */
int stack_pop(stack_t **stack_head, int *err)
{
	int num = 0;
	stack_t *temp = *stack_head;
	stack_t *stack_tail = NULL;

	err = 0;
	if (!lifo)
	{
		if (stack_head == NULL || *stack_head == NULL)
		{
			*err = -1;
			return (-1);
		}
		while ((*stack_head)->next != NULL)
			*stack_head = (*stack_head)->next;
		stack_tail = *stack_head;
		num = (*stack_head)->n;
		*stack_head = (*stack_head)->prev;
		if (*stack_head != NULL)
			(*stack_head)->next = NULL;
		free(stack_tail);
		*stack_head = temp;
		return (num);
	}
	else
	{
		if (stack_head == NULL || *stack_head == NULL)
		{
			*err = -1;
			return (-1);
		}
		num  = (*stack_head)->n;
		*stack_head = (*stack_head)->next;
		if (*stack_head != NULL)
			(*stack_head)->prev = NULL;
		free(temp);
	}
	return (num);
}

/**
 * stack_top - display the top num in the stack
 * @stack_head: the head of the stack
 * @err: error flag indicator
 * Return: the top element on the stack
 */
int stack_top(stack_t **stack_head, int *err)
{
	int num;

	*err = 0;
	if (stack_head == NULL || *stack_head == NULL)
	{
		*err = -1;
		return (-1);
	}
	num = stack_head->n;
	return (num);
}
