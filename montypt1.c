#include "monty.h"

/**
 * pall -          Print all values on the stack
 * @stack:         pointer to head of stack
 * @line_num:      file's line number
 * Return:         Void
 */

void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack;
	(void)line_num;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * push -          Pushes an element to the stack
 * @stack:         pointer to head of stack
 * @line_num:      file's line number
 * @n:             variable
 * Return:         address of new element
 */

void push(stack_t **stack, unsigned int line_num, int n)
{
	stack_t *new, *h = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->prev = NULL;
	new->n = n;
	new->next = *stack;
	if (*stack)
		h->prev = new;
	*stack = new;
}
