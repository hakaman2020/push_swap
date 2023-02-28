/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pre_sort_stack.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 12:41:41 by hman          #+#    #+#                 */
/*   Updated: 2021/06/17 14:18:56 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pre_sort_stack.h"
#include "parser.h"
#include "stack.h"

/*
**	This function will sort the stack for tagging later
**	RETURN	stack pointer to a sorted stack.
**			NULL if something went wrong like a malloc error.
*/

t_stack_node	*pre_sort_stack(char *argv[])
{
	int				i;
	int				number;
	t_stack_node	*stack;
	t_stack_node	*new_node;

	i = 1;
	stack = NULL;
	while (argv[i] != NULL)
	{
		number = ft_atoi_strict(argv[i]);
		new_node = create_new_stack_node(number);
		if (new_node == NULL)
		{
			clear_stack(&stack);
			return (NULL);
		}
		stack = insert_node_sorted_stack(stack, new_node);
		i++;
	}
	return (stack);
}

t_stack_node	*insert_node_sorted_stack(t_stack_node *stack
	, t_stack_node *new_node)
{
	t_stack_node	*current_node;

	if (stack == NULL)
		insert_node_front(&stack, new_node);
	else
	{
		current_node = stack;
		if (current_node->number > new_node->number)
		{
			insert_node_front(&current_node, new_node);
			stack = current_node;
		}
		else
		{
			current_node = current_node->next_node;
			while (current_node->number < new_node->number
				&& current_node != stack)
				current_node = current_node->next_node;
			insert_node_front(&current_node, new_node);
		}
	}
	return (stack);
}

/*
**	this function will tag the nodes in the stack in ascending order
**	RETURN	pointer to the tagged stack.
*/

t_stack_node	*tag_nodes(t_stack_node *stack)
{
	int				i;
	t_stack_node	*current_node;

	i = 0;
	current_node = stack;
	while (current_node->tag_active == 0)
	{
		current_node->tag_active = 1;
		current_node->tag_number = i;
		current_node = current_node->next_node;
		i++;
	}
	return (stack);
}

/*
**	This function will update the tag number in stack a according to the sorted
**	stack.
*/

t_stack_node	*insert_tags(t_stack_node *stack, t_stack_node *sorted_stack)
{
	t_stack_node	*stack_node;

	stack_node = stack;
	stack_node->tag_number = get_tag_number(stack_node->number, sorted_stack);
	stack_node = stack_node->next_node;
	while (stack_node != stack)
	{
		stack_node->tag_number = get_tag_number(stack_node->number,
				sorted_stack);
		stack_node = stack_node->next_node;
	}
	return (stack);
}

/*
**	this function will return the tag number (place in the sorted stack) of a 
**	number
**	RETURN	integer tag number of input number
*/
int	get_tag_number(int number, t_stack_node *sorted_stack)
{
	while (sorted_stack->number != number)
		sorted_stack = sorted_stack->next_node;
	return (sorted_stack->tag_number);
}
