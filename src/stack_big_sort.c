/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_big_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 14:13:57 by hman          #+#    #+#                 */
/*   Updated: 2021/06/17 15:28:11 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_sorting.h"
#include "stack_actions.h"
#include "stack_big_sort.h"
#include "stack_big_sort_utils.h"

/*
**	the sorting algorithm for bigger amounts of integers will be based on
**	radix sort using Least Significant Digit (LSD)
*/

void	sort_big(t_stack_node **stack_a, int n)
{
	int				sort_status;

	sort_status = is_stack_sorted(*stack_a);
	if (sort_status == 2)
		rotate_sorted_stack(stack_a, (unsigned int) n);
	else if (sort_status != 1)
		radix_lsd_sorting(stack_a, n);
}

/*
**	this function performs the actual radix sort using LSD
*/

void	radix_lsd_sorting(t_stack_node **stack_a, int n)
{
	int				max_lsd;
	int				current_lsd;
	t_stack_node	*stack_b;

	max_lsd = count_digits(n - 1);
	current_lsd = 1;
	stack_b = NULL;
	while (current_lsd <= max_lsd)
	{
		if (current_lsd == 1)
			first_sort_to_stack_b(stack_a, &stack_b, current_lsd, n);
		else if ((current_lsd % 2) == 1)
			sort_to_stack_b(stack_a, &stack_b, current_lsd, n);
		else
			sort_to_stack_a(stack_a, &stack_b, current_lsd, n);
		current_lsd++;
	}
	if (*stack_a == NULL)
	{
		while (stack_b != NULL)
			push_node(&stack_b, stack_a, "pa");
	}	
}

/*
**	This function will push the integers to stack B just like the function 
**	sort_to_stack_b, but the difference is that it won't go through the whole 
**	stack once all the elements of the current lsd has been pushed to stack b.
**	This is to save on instructions and can only be done as the first step of 
**	the sorting algorithm according to the radix sort.
*/

void	first_sort_to_stack_b(t_stack_node **stack_a, t_stack_node **stack_b,
			int current_lsd, int n)
{
	int				count;
	int				max_sig_nmb;
	unsigned int	digit;

	digit = 0;
	while (digit <= 9 && n != 0)
	{
		max_sig_nmb = count_significant_numbers (*stack_a, current_lsd, digit);
		count = 0;
		while (count < max_sig_nmb)
		{
			if (check_number((*stack_a)->tag_number, current_lsd, digit))
			{
				push_node(stack_a, stack_b, "pb");
				count++;
			}
			else
				rotate_stack(stack_a, "ra");
		}
		n = n - count;
		digit++;
	}
}
/*
**	This function will push the integers to stack B according to the radix 
**	sort with Least Significant Digit (LSD)
*/

void	sort_to_stack_b(t_stack_node **stack_a, t_stack_node **stack_b,
			int current_lsd, int n)
{
	int	count;
	int	digit;
	int	pushed;

	digit = 0;
	while (digit <= 9 && n != 0)
	{
		count = 0;
		pushed = 0;
		while (count < n)
		{
			if (check_number((*stack_a)->tag_number, current_lsd, digit))
			{
				push_node(stack_a, stack_b, "pb");
				pushed++;
			}
			else
				rotate_stack(stack_a, "ra");
			count++;
		}
		n = n - pushed;
		digit++;
	}
}

/*
**	This function will push the integers to stack A according to the radix 
**	sort with Least Significant Digit (LSD)
*/

void	sort_to_stack_a(t_stack_node **stack_a, t_stack_node **stack_b,
			int current_lsd, int n)
{
	int	count;
	int	digit;
	int	pushed;

	digit = 9;
	while (digit >= 0 && n != 0)
	{
		count = 0;
		pushed = 0;
		while (count < n)
		{
			if (check_number((*stack_b)->tag_number, current_lsd, digit))
			{
				push_node(stack_b, stack_a, "pa");
				pushed++;
			}
			else
				rotate_stack(stack_b, "rb");
			count++;
		}
		n = n - pushed;
		digit--;
	}
}
