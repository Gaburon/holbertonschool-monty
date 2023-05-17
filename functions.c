#include "monty.h"

/**
 * _strcmp - compares strings
 * @opcode: string to be compared
 * @list: string to be compared
 * Return: 0
 */
int _strcmp(char *opcode, char *list)
{
	while (*list != '\0')
	{
		if (*list == ' ')
			list++;
		else if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0' && (*list == ' ' || *list == '\n' || *list == '\0'))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

/**
 * nlfind - finds newline
 * @list: the string to find \n
 * Return: 1 || 0
 */
int nlfind(char *list)
{
	char *opcode = "\n";

	while (*list != '\0')
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0')
				return (1);
		}
		else
			list++;
	}
	return (0);
}

/**
 * pushint -int for push opcode
 * @list: the content of the file
 * @ln: line number
 * Return: the number
 */
int pushint(char *list, int ln)
{
    char *opcode = "push";
    char *endptr;
    long int num;

    while (*list != '\0')
    {
        if (*opcode == *list)
        {
            opcode++;
            list++;
            if (*opcode == '\0')
            {
                num = strtol(list, &endptr, 10);
                if (endptr != list && *endptr == '\0')
                {
                    combfind(list, ln);
                    return (num);
                }
                else
                {
                    fprintf(stderr, "L%d: usage: push integer\n", ln);
                    exit(EXIT_FAILURE);
                }
            }
        }
        else
        {
            list++;
        }
    }
    return (0);
}

/**
 * combfind - finds nonnumbers and number combinations
 * @list: the string
 * @ln: line number
 * Return: 1
 */
int combfind(char *list, int ln)
{
	int i = 1;

	while (list[i])
	{
		if (list[i] == '\0' || list[i] == '\n')
			break;
		if ((list[i] >= '0' && list[i] <= '9') || list[i] == ' ')
			i++;
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
