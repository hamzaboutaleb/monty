#include "monty.h"


instruction_t *push(void (*f)(stack_t**, unsigned int))
{
	instruction_t* new_instr;

	new_instr = (instruction_t *)malloc_memo(sizeof(instruction_t));

	new_instr->opcode = "push";
	new_instr->f = &f;

	return (new_instr);
}

void push_fun(stack_t **stack, unsigned int line_number)
{
	if (g_value =)
}


/**
  * add_dnodeint_end - add node at the end of dbly linked list
  * @head: head
  * @n: value
  * Return: node
  */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *node;
	stack_t *curr;

	node = (stack_t *) malloc_memo(sizeof(dlistint_t));
	node->n = n;
	curr = *head;
	if (!curr)
	{
		(*head) = node;
		return (node);
	}
	while (curr->next)
		curr = curr->next;
	node->prev = curr;
	curr->next = node;

	return (node);
}
