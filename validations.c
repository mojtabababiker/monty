#include "monty.h"

/**
 * isValide - check the validaty of the opcode
 * @opcode: the opcode to check its validaty
 * Return:  structure_t struct if valid
 *         NULL other wise
 */
instruction_t *isValide(char *opcode)
{
	instruction_t *crnt_instruction = NULL;

	void (*opFunctions[])(stack_t **stack, unsigned int line_number) = {
		push_op, pall_op, pint_op, pop_op, swap_op, add_op,
		sub_op, mul_op, div_op, mod_op, push_op};

	char opCodes[19][11] = {"push", "pall", "pint", "pop",
			       "swap", "add", "sub", "mul",
			       "div", "mod", "nop"};
	int i = 0;

	crnt_instruction = malloc(sizeof(instruction_t));

	if (crnt_instruction == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	while (i < 11)
	{
		if (strcmp(opcode, opCodes[i]) == 0)
		{
			/*set the instruction_t*/
			crnt_instruction->opcode = opcode;
			crnt_instruction->f = opFunctions[i];
			return (crnt_instruction);
		}
		i++;
	}
	free(crnt_instruction);
	return (NULL);
}
