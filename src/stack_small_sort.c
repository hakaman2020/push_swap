/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_small_sort.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 18:05:14 by hman          #+#    #+#                 */
/*   Updated: 2021/06/16 22:15:21 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_sorting.h"
#include "stack_actions.h"
#include "stack_small_sort.h"

/*
**	this function will sort a stack with small amount of integers.
**	n is the amount of integers in the stack.
**	If the n > 3 then it will push everything, save for the last three integers,
**	to stack B and sort the last three integers first and push every element in
**	stack B back into stack A in order.
*/

void	sort_small(t_stack_node **stack_a, int n)
{
	if (n > 1)
	{
		if (n == 2)
		{
			if ((*stack_a)->tag_number > (*stack_a)->next_node->tag_number)
				swap_nodes(stack_a, "sa");
		}
		else if (n == 3)
			sort_three(stack_a);
		else if (n > 3)
			sort_more_than_three(stack_a, n);
	}
}

/*
**	this function will sort a stack with 3 integers
*/

void	sort_three(t_stack_node **stack)
{
	while (is_stack_sorted(*stack) != 1)
	{
		if (is_stack_sorted(*stack) == 2)
		{
			if ((*stack)->tag_number < (*stack)->next_node->tag_number)
				rotate_rev_stack(stack, "rra");
			else
				rotate_stack(stack, "ra");
		}
		else
		{
			if ((*stack)->tag_number > (*stack)->next_node->tag_number)
				swap_nodes(stack, "sa");
			else
				rotate_stack(stack, "ra");
		}
	}
}

/*
**	This function will sort the stack with n < 3
*/

void	sort_more_than_three(t_stack_node **stack_a, int n)
{
	int				i;
	int				sort_status;
	t_stack_node	*stack_b;

	sort_status = is_stack_sorted(*stack_a);
	if (sort_status == 2)
		rotate_sorted_stack(stack_a, n);
	else if (sort_status == 0)
	{
		stack_b = NULL;
		i = n - 3;
		while (i > 0)
		{
			push_node(stack_a, &stack_b, "pb");
			i--;
		}
		sort_three(stack_a);
		insert_b_into_a(stack_a, &stack_b);
		rotate_sorted_stack(stack_a, n);
	}
}

/*
**	This function will insert all the integers in stack b into stack a in 
**	ascending order
*/

void	insert_b_into_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	unsigned int	tag_b;
	unsigned int	tag_a;
	unsigned int	tag_prev_a;

	while (*stack_b != NULL)
	{
		tag_b = (*stack_b)->tag_number;
		tag_a = (*stack_a)->tag_number;
		tag_prev_a = (*stack_a)->prev_node->tag_number;
		if (tag_b > tag_a && tag_b > tag_prev_a && tag_a < tag_prev_a)
			push_node(stack_b, stack_a, "pa");
		else if (tag_b > tag_a)
			rotate_stack(stack_a, "ra");
		else if (tag_b < tag_a && tag_b > tag_prev_a)
			push_node(stack_b, stack_a, "pa");
		else if (tag_b < tag_a && tag_b < tag_prev_a && tag_a < tag_prev_a)
			push_node(stack_b, stack_a, "pa");
		else if (tag_b < tag_a)
			rotate_rev_stack(stack_a, "rra");
	}
}
