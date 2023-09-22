#include "monty.h"
/**
 * f_push - add node to the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (buss.arg)
	{
		if (buss.arg[0] == '-')
			j++;
		for (; buss.arg[j] != '\0'; j++)
		{
			if (buss.arg[j] > 57 || buss.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(buss.file);
			free(buss.content);
			free_stack(*stack);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(buss.file);
		free(buss.content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	n = atoi(buss.arg);
	if (buss.lifi == 0)
		addnode(stack, n);
	else
		addqueue(stack, n);
}
