#include "monty.h"

/**
  * stack_node - create new node stack
  * @n: value
  * @prev: poiter to prev value
  * @next: pointer to next
  * Return: pointer to new node
  */
stack_t *stack_node(int n, stack_t *prev, stack_t *next)
{
	stack_t *node;

	node = (stack_t *) malloc_memo(sizeof(stack_t));

	node->n = n;
	node->prev = prev;
	node->next = next;

	return (node);
}
