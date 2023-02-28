/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_big_sort_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 19:05:35 by hman          #+#    #+#                 */
/*   Updated: 2021/06/16 19:11:31 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_big_sort_utils.h"

/*
**	this function count the amount of digits in n
**	RETURN the amount of digits in n
*/

int	count_digits(int n)
{
	int	amount_digits;

	amount_digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		amount_digits++;
		n = n / 10;
	}
	return (amount_digits);
}

/*
**	this function will check is the given tag_number contain the current active
**	number in the lsd sorting algorithm. e.g. if 1234 and the second from the 
**	right is currently active and the current digit is 3 this function will 
**	return 1. 
**	RETURN	0 if it doesn't and if the lsd_position is smaller than 1 
**			1 if it does.
*/

int	check_number(unsigned int tag_number, int lsd_position, unsigned int digit)
{
	int	i;

	if (lsd_position < 1)
		return (0);
	i = 1;
	while (i < lsd_position)
	{
		tag_number = tag_number / 10;
		i++;
	}
	if (digit == (tag_number % 10))
		return (1);
	else
		return (0);
}

/*
**	this function wil count the amount of integers in the given stack that 
**	that comply to the current active significant digit.
**	RETURN the amount of integers that comply in the stack
*/

int	count_significant_numbers(t_stack_node *stack, int lsd_position,
	unsigned int digit)
{
	int				count;
	t_stack_node	*current_node;

	count = 0;
	current_node = stack;
	if (check_number(current_node->tag_number, lsd_position, digit))
		count++;
	current_node = current_node->next_node;
	while (current_node != stack)
	{
		if (check_number(current_node->tag_number, lsd_position, digit))
			count++;
		current_node = current_node->next_node;
	}
	return (count);
}
