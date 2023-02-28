/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 08:23:54 by hman          #+#    #+#                 */
/*   Updated: 2021/06/17 15:37:39 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "stack.h"
#include "stack_actions.h"
#include "parser.h"
#include "push_swap.h"
#include "stack_sorting.h"
#include "stack_small_sort.h"
#include "stack_big_sort.h"
#include "pre_sort_stack.h"

/*
**	the switch to big sort is set to 51 because at 50 the small sort is still
**	a little better than big sort.
*/

#define SWITCH_BIG_SORT 51

/*
**	This is the main function of push swap. The purpose of the program is to
**	output the instructions for sorting a stack of integer numbers. The goal is
**	to minimize the amount of instructions.
*/

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*sorted_stack;
	int				amount_integers;

	if (argc == 1)
		return (0);
	if (!check_args(argc, argv))
		exit_on_error();
	stack_a = create_stack(argv);
	if (stack_a == NULL)
		exit_on_error();
	sorted_stack = pre_sort_stack(argv);
	if (sorted_stack == NULL)
		exit_on_error();
	sorted_stack = tag_nodes(sorted_stack);
	stack_a = insert_tags(stack_a, sorted_stack);
	amount_integers = argc - 1;
	if (amount_integers < SWITCH_BIG_SORT)
		sort_small(&stack_a, amount_integers);
	else
		sort_big(&stack_a, amount_integers);
	clear_stack(&stack_a);
	clear_stack(&sorted_stack);
	return (0);
}

/*
**	this function will create the stack 	
**	RETURN	the stack with the values in a double linked list.
**			NULL if the creation of the stack failed somehow.
*/

t_stack_node	*create_stack(char *argv[])
{
	int				i;
	int				number;
	t_stack_node	*new_node;
	t_stack_node	*stack;

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
		insert_node_front(&stack, new_node);
		stack = stack->next_node;
		i++;
	}
	return (stack);
}

/*
**	this function will be called when an error has occured and it will exit the
**	program.
*/

void	exit_on_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
