#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 *  * struct stack_s - doubly linked list representation of a stack (or queue)
 *   * @n: integer
 *    * @prev: points to the previous element of the stack (or queue)
 *     * @next: points to the next element of the stack (or queue)
 *      *
 *       * Description: doubly linked list node structure
 *        * for stack, queues, LIFO, FIFO
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void _pall(stack_t **stack, unsigned int line);
void translate(char *str, unsigned int line, stack_t **start, char *buffer);
int _atoi(char *s);
void _push(stack_t **stack, unsigned int line);
void orror(char *err);
void _pop(stack_t **stack, unsigned int line);
void freest(stack_t *stack);
void _pint(stack_t **stack, unsigned int line);
int _strlen(char *s);
int lenst(stack_t **start);
void _swap(stack_t **stack, unsigned int line_num);
void _sub(stack_t **stack, unsigned int line);
void _add(stack_t **stack, unsigned int line);
void _mul(stack_t **stack, unsigned int line);
void _nop(stack_t **stack, unsigned int line);
int comp(char *s1, char *s2);
char *tostr(int number);
int notint(char *str);
#endif
