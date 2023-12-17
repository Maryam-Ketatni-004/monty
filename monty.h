#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list respresentation of a stack ( or queue)
 * @n: integer
 * @prev: points to the previous element of the stack ( or queu)
 * @next: points to the previous element of the stack ( or queue)
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
 * @f: fuction to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data -all data in program
 * @push_value:value to push
 * @line_num: line number of opcode
 * @opcode: the opcode
 * @mfile: file to open
 * @top: the top of stack
 * @mode: 0 mean stack, 1 mean queue
 * in stack you push in the start
 * in the queue you push at the end
 */
typedef struct data
{
	int push_value;
	unsigned int line_num;
	char *opcode;
	FILE *mfile;
	stack_t *top;
	int mode;
} data;
data datax;

/*main.c*/
void exec(void);
int main(int argc, char **argv);

/*opcodes.c*/
void _push(stack_t **top, unsigned int line_number);
void _pall
