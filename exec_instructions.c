#include "monty.h"
#include "err.h"

int _atoi(char *s, int *err);
int errNum = 0;
/**
 * exec_instruction - call the crosponnding function to the opcode
 * @opcode: the current opration code
 * @line_num: the number of current opcode line in the file
 * @args: args in the line if avaliable
 * @stack_head: pointer to the first element in the stack
 * Return: 0 in success -1 in failure
 */
int exec_instruction(char **opcode, char **args,
		     stack_t **stack_head, unsigned int line_num)
{
	int num = 0, err = 0;
	instruction_t *crnt_instruction;

	crnt_instruction = NULL;
	if (strcmp(*opcode, "push") == 0)
	{
		num = _atoi(*args, &err);
		if (!num && err)
		{
			fprintf(stderr, "L%u: ", line_num);
			fprintf(stderr, "usage: push integer\n");
			_free(NULL, opcode, args, stack_head);
			return (-1);
		}
		*stack_head = stack_push(stack_head, num);
		if (*stack_head == NULL)
		{
			_free(NULL, opcode, args, stack_head);
			return (-1);
		}
		return (0);
	}
	crnt_instruction = isValide(*opcode);
	if (crnt_instruction == NULL)
	{
		fprintf(stderr, "L%u: ", line_num);
		fprintf(stderr, "unknown instruction %s\n", *opcode);
		_free(NULL, opcode, args, stack_head);
		return (-1);
	}
	(crnt_instruction->f)(stack_head, line_num);
	if (errNum)
	{
		free(crnt_instruction);
		_free(NULL, opcode, args, stack_head);
		return (-1);
	}
	free(crnt_instruction);
	return (0);
}



/**
 * _atoi - convert the number in string to integer values
 * @s: string variable pointer
 * @err: error detection flag
 * Return: the ineger value of the number, if there are non number
 *         in s return 0 and set error flag to one
 */

int _atoi(char *s, int *err)
{
	int i = 0, sign = 1;
	int num = 0;

	if (s == NULL)
	{
		*err = 1;
		return (0);
	}
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign = sign * -1;
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + (s[i] - '0');
		}
		if (num > 0 && (s[i] < '0' || s[i] > '9'))
		{
			*err = 1;
			return (0);
		}
		i++;
	}
	return (num * sign);
}
