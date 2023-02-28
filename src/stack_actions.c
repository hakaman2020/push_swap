/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 09:22:44 by hman          #+#    #+#                 */
/*   Updated: 2021/06/22 12:47:45 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack_actions.h"
#include "stack.h"

/*
**	this function will swap the values in the first two nodes in a stack
*/

void	swap_nodes(t_stack_node **stack, char *s)
{
	t_stack_node	*second_node;

	if ((*stack)->next_node->next_node == *stack)
		rotate_stack(stack, s);
	else if (*stack != NULL && (*stack)->next_node != *stack)
	{
		second_node = (*stack)->next_node;
		(*stack)->prev_node->next_node = second_node;
		second_node->next_node->prev_node = (*stack);
		(*stack)->next_node = second_node->next_node;
		second_node->prev_node = (*stack)->prev_node;
		(*stack)->prev_node = second_node;
		second_node->next_node = *stack;
		*stack = second_node;
		print_operation(s);
	}	
}

/*
**	this function will push first element of source stack to the top of the 
**	destination stack.
*/

void	push_node(t_stack_node **src_stack, t_stack_node **dest_stack, char *s)
{
	t_stack_node	*src_node;

	if (*src_stack != NULL)
	{
		if ((*src_stack)->next_node == *src_stack)
		{
			insert_node_front(dest_stack, *src_stack);
			*src_stack = NULL;
		}
		else
		{
			src_node = *src_stack;
			*src_stack = src_node->next_node;
			src_node->next_node->prev_node = src_node->prev_node;
			src_node->prev_node->next_node = src_node->next_node;
			insert_node_front(dest_stack, src_node);
		}
		print_operation(s);
	}
}

/*
**	this function will rotate the stack as in the first element
**	will be become the last element. 	
**	if the stack is empty or only contain one element it will do nothing
*/

void	rotate_stack(t_stack_node **stack, char *s)
{
	if (*stack != NULL)
	{
		*stack = (*stack)->next_node;
		print_operation(s);
	}
}

/*
**	this function will reverse rotate the stack as in the last element
**	will become the first element
** 	if the stack is empty or only contain one element it will do nothing
*/

void	rotate_rev_stack(t_stack_node **stack, char *s)
{
	if (*stack != NULL)
	{
		*stack = (*stack)->prev_node;
		print_operation(s);
	}
}

/*
**	This function will print out the string and end with a new line
**	If the string is NULL then it will do nothing.
*/

void	print_operation(char *s)
{
	int	slength;

	if (s != NULL)
	{
		slength = 0;
		while (s[slength] != '\0')
			slength++;
		write(1, s, slength);
		write(1, "\n", 1);
	}
}
