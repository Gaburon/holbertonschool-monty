#include "monty.h"

/**
 * getopcode_fun - gets the function for a given opcode
 * @opcode: operation code to search
 * Return: Pointer to opcode function
 */

void (*getopcode_fun(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t made_opcodes[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"#", op_nop},
		{"pchar", op_pchar},
		{"pstr", op_pstr}
	};

	while (i <= 13)
	{
		if (_strcmp(made_opcodes[i].opcode, opcode) == 0)
			return (made_opcodes[i].f);
		i++;
	}
	return (NULL);
}
