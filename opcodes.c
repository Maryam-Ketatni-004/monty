#include "monty.h"
/**
 * _mode - aswitch the mode queue/stack
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
{
        (void)top;
        (void)linr_number;
        
        if (strcmp(datax.opcode, "queue") ==0)
		datax.mode = 1;
	else if (strcmp(datax.opcode, "stack") == 0)
		datax.mode = 0;
}

/**
 * _push - adds a new node at the beginning
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: NONE
 */
void _push(stack_t **top, unsigned int line_number)
{
	stack_t *new, *last;
	int i = 0;

	(void)line_number;
	if (!top)
		return;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error:malloc failed");
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	new->n = datax.push_value;
	if (data.mode == 0 || !*top)
	{
		if (*top)
		{
			new->net = *top;
			(*top)->prev = new;
		}
		else
			new->next = NULL;
		new->prev = NULL;
		*top = new;
	}
	else if (datax.mode == 1)
	{
		last = *top;
		for ( i=0; last; i++)
		{
			if (!last->next)
				break;
			last = last->next;
		}
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}

/**
 * _pall - prints all the elements of a dlistint_t list
 * @top: head of double list 
 * @line_number: line number of opcode
 * Return: none
 */
void _pall(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int i;

	(void)line_number;
	for (i = 0; current; i++)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
	fflush(stdout);
}

/**
 * _pint - prints the value at the top of the stack
 * @top: head of double list
 * @line_number: line number of opcode
 * Return:none
 */
void _pint (stack_t **top, unsigned int line_number)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*top)->n);
	fflush(stdout);
}

/**
 * _pop - removes the top element of the stack
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _pop(stack_t **top, unsigned int line_number)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->next == NULL)
	{
		free(*top);
		*top = NULL;
	}
	else
	{
		*top = (*top)->next;
		free((*top)->prev);
		(*top)->prev = NULL;
	}
}
/**
 * _swap - swaps the top two elements of the stack.
 * @top: head of double list
 * @list_number: line number of opcode
 * Return: none
 */
void _swap(stack_t **top, usigned int line_number)
{
	stack_t *tmp1;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	tmp1 = *top;
	tmp1->prev = tmp1->next;
	if ((*top)->next->next == NULL)
		tmp1->next = NULL;
	else
	{
		tmp1->next = tmp1->next->next;
		tmp1->next->prev = *top;
	}
	*top = tmp1->prev;
	(*top)->prev = NULL;
	(*top)->next = tmp1;
}

/**
 * _add - adds the top two elements of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */

