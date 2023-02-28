/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_sorting.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/26 15:22:48 by hman          #+#    #+#                 */
/*   Updated: 2021/06/16 17:56:58 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_sorting.h"
#include "stack.h"
#include "stack_actions.h"

/*
**	This function check if the given stack is sorted based on tag number.
**	If the tag number of beginning of the stack is not 0, it will return
**	a 2 indicating it is sorted but requires rotations.
**	RETURN	1 if the stack is sorted and top node tag equals to 0	
**			an empty stack will be considered sorted)
**			2 if the stack is sorted but the top node tag doesn't equals to 0
**			and thus require rotations
**			0 if the stack is not sorted
*/

int	is_stack_sorted(t_stack_node *stack)
{
	t_stack_node	*current_node;
	unsigned int	lowest_tag_number;

	if (stack == NULL || stack->next_node == stack)
		return (1);
	lowest_tag_number = get_lowest_tag(stack);
	current_node = stack;
	if ((current_node->tag_number > current_node->next_node->tag_number)
		 && current_node->next_node->tag_number != lowest_tag_number)
		return (0);
	current_node = current_node->next_node;
	while (current_node != stack && ((current_node->tag_number
				< current_node->next_node->tag_number)
			|| current_node->next_node->tag_number == lowest_tag_number))
		current_node = current_node->next_node;
	if (current_node == stack && stack->tag_number == lowest_tag_number)
		return (1);
	else if (current_node == stack && stack->tag_number != lowest_tag_number)
		return (2);
	else
		return (0);
}

/*
**	this function will find the lowest tagnumber in the stack and return it
**	RETURN lowest tag number
*/

unsigned int	get_lowest_tag(t_stack_node *stack)
{
	t_stack_node	*current_node;
	unsigned int	lowest_tag_number;

	lowest_tag_number = stack->tag_number;
	current_node = stack->next_node;
	while (current_node != stack)
	{
		if (current_node->tag_number < lowest_tag_number)
			lowest_tag_number = current_node->tag_number;
		current_node = current_node->next_node;
	}
	return (lowest_tag_number);
}

/*
**	this function will rotate a sorted stack that is out of place 
**	back to where the top of the stack contains the lowest integer
**	it will also print out the rotations.
*/

void	rotate_sorted_stack(t_stack_node **stack, unsigned int n)
{	
	unsigned int	lowest_tag_number;

	lowest_tag_number = get_lowest_tag(*stack);
	if ((*stack)->tag_number <= (n / 2))
	{
		while ((*stack)->tag_number != lowest_tag_number)
			rotate_rev_stack(stack, "rra");
	}
	else
	{
		while ((*stack)->tag_number != lowest_tag_number)
			rotate_stack(stack, "ra");
	}
}
