#define _GNU_SOURCE
#include "monty.h"
#include "err.h"

int _isempty(char *line);

/**
 * parseFile - open and pars the bytecode file
 * @fileName: the name of the file to open
 * @stack_head: pointer to the first element of the the stack
 * Return: 0 in success, in failure the program will be terminated
 *
 * Description: this function is responsiable of open, read and pars
 * the bytecode file line by line, in each line it will check for
 * opcode validity and set the instruction queue after validations
 */

int parseFile(char *fileName, stack_t **stack_head)
{
	FILE *fHandler;

	char *line = NULL, *args = NULL, *opcode = NULL;
	size_t len = 0;
	int line_num = 1;

	fHandler = fopen(fileName, "r");
	if (!fHandler)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, fHandler) != -1)
	{
		if (line == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			_free(&line, NULL, NULL, stack_head);
			fclose(fHandler);
			exit(EXIT_FAILURE);
		}
		if (_isempty(line))
		{
			_free(&line, NULL, NULL, NULL);
			continue;
		}
		opcode = _strtok(line, ' ', &len);/* tockenize line */
		if (opcode[0] == '#')
		{
			_free(&line, &opcode, NULL, NULL);
			continue;
		}
		args = _strtok(NULL, ' ', &len); /*get arg if there are*/
		_free(&line, NULL, NULL, NULL);
		if (exec_instruction(&opcode, &args, stack_head, line_num))
		{
			fclose(fHandler);
			exit(EXIT_FAILURE);
		}
		_free(NULL, &opcode, &args, NULL);
		line_num++;
	}
	free(line);
	fclose(fHandler);
	return (0);
}

/**
 * _isempty - helper function that check if the line is empty line
 * @line: a pointer to the line to check
 * Return: 1 if the line is empty, 0 other wise
 * Description: the line is empty if it's contians only spaces or
 *              a null terminator '\0'.
 */

int _isempty(char *line)
{
	char *temp = line;

	if (*line == '\0' || *line == '#')
		return (1);
	while ((*line) != '\n')
	{
		if ((*line) != ' ' && (*line) != '\t')
		{
			line = temp;
			return (0);
		}
		line++;
	}
	line = temp;

	return (1);
}
