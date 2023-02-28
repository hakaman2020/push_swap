#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack_actions.h"

void print_stack(t_stack_node *stack)
{
	if (stack != NULL)
	{
		t_stack_node *start = stack;
		
		printf("%d",stack->number);
		stack = stack->next_node;

		while (stack != start)
		{
			printf("%d",stack->number);
			stack = stack->next_node;
		}
		printf("\n");
	}
	else
		printf("empty\n");
}


int main()
{
//testing stack.c
	t_stack_node *stacka = NULL;

	insert_node_front(&stacka, create_new_stack_node(4));
	insert_node_front(&stacka, create_new_stack_node(3));
	insert_node_front(&stacka, create_new_stack_node(2));
	insert_node_front(&stacka, create_new_stack_node(1));
	print_stack(stacka);
	

	rotate_rev_stack(&stacka);
	print_stack(stacka);
	rotate_rev_stack(&stacka);
	print_stack(stacka);
	rotate_rev_stack(&stacka);
	print_stack(stacka);
	rotate_rev_stack(&stacka);
	print_stack(stacka);
	rotate_rev_stack(&stacka);
	print_stack(stacka);
	rotate_rev_stack(&stacka);
	print_stack(stacka);
	rotate_rev_stack(&stacka);
	print_stack(stacka);
	rotate_rev_stack(&stacka);
	print_stack(stacka);
//	swap_nodes(&stacka);
//	print_stack(stacka);
printf("push node\n");
	t_stack_node *stackb = NULL;
	push_node(&stacka,&stackb);
	push_node(&stacka,&stackb);
	push_node(&stacka,&stackb);

	print_stack(stacka);
	print_stack(stackb);


	clear_stack(&stacka);
	clear_stack(&stackb);
	//while(1);
	return (0);
}
