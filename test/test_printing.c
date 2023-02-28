#include "stack.h"
#include "stack_operations.h"
#include <stdio.h>

void print_stack(t_stack_node *stack, char stackname)
{
	t_stack_node *current_node;
	printf("Stack %c :", stackname);
	if (stack == NULL)
		printf(" Empty");
	else
	{
		current_node = stack;
		printf(" %d (%d) ",current_node->number, current_node->tag_number);
		current_node = current_node->next_node;
		while (current_node != stack)
		{
			printf("%d (%d) ", current_node->number, current_node->tag_number);
			current_node = current_node->next_node;
		}
	}
	printf("\n");
}

void print_stack_tag(t_stack_node *stack, char stackname)
{
	t_stack_node *current_node;
	printf("Stack %c :", stackname);
	if (stack == NULL)
		printf(" Empty");
	else
	{
		current_node = stack;
		printf(" %d ", current_node->tag_number);
		current_node = current_node->next_node;
		while (current_node != stack)
		{
			printf("%d ", current_node->tag_number);
			current_node = current_node->next_node;
		}
	}
	printf("\n");
}