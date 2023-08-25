#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* helper functions */
/*in the scanning_proccess.c file*/
int parseFile(char *fileName, stack_t **stack_head);
 /*in the _strtok.c*/
char *_strtok(char *str, char delim, size_t *len);
 /*in the validation.c*/
instruction_t *isValide(char *opcode);
/* in the exec_instructions.c */
int exec_instruction(char **opcode, char **args, stack_t **stack_head,
		     unsigned int line_num);
/* in _free.c */

void _free(char **line, char **opcode, char **args, stack_t **stack_head);
int freeStack(stack_t *stack_head);

/* stack operations functions */
stack_t *stack_push(stack_t **stack_head, int num);
int stack_pop(stack_t **stack_head, int *err);
int stack_top(stack_t **stack_head, int *err);

/* opcode functions */
void pall_op(stack_t **stack_head,
	__attribute__((unused))unsigned int line_number);
void push_op(stack_t **stack,
	__attribute__((unused))unsigned int line_number);
void pint_op(stack_t **stack_head, unsigned int line_number);
void pop_op(stack_t **stack_head, unsigned int line_number);
void swap_op(stack_t **stack_head, unsigned int line_number);
void add_op(stack_t **stack_head, unsigned int line_number);
void sub_op(stack_t **stack_head, unsigned int line_number);
void mul_op(stack_t **stack_head, unsigned int line_number);
void div_op(stack_t **stack_head, unsigned int line_number);
void mod_op(stack_t **stack_head, unsigned int line_number);
void pchar_op(stack_t **stack_head, unsigned int line_number);
void pstr_op(stack_t **stack_head,
	     __attribute__((unused))unsigned int line_number);
#endif /** MONTY_H */
