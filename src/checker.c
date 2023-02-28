/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 13:47:44 by hman          #+#    #+#                 */
/*   Updated: 2021/06/17 15:41:05 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"
#include "stack.h"
#include "stack_actions.h"
#include "stack_operations.h"
#include "checker.h"

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				ops_execute;

	if (argc == 1)
		return (0);
	if (!check_args(argc, argv))
		exit_on_error();
	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_stack(argv, stack_a);
	if (stack_a == NULL)
		exit_on_error();
	ops_execute = read_operations(&stack_a, &stack_b);
	if (ops_execute == -1)
		exit_on_error();
	if (check_stack_sort(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear_stack(&stack_a);
	clear_stack(&stack_b);
	return (0);
}

/*
**	this function will create the stack 	
**	RETURN	the stack with the values in a double linked list.
**			NULL if the creation of the stack failed somehow.
*/

t_stack_node	*create_stack(char *argv[], t_stack_node *stack)
{
	int				i;
	int				number;
	t_stack_node	*new_node;

	i = 1;
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
**	this function will check if the stack is sorted in incrementing
**	order. 
**	RETURN	1 if the stack is sorted
**			0 if the stack is not sorted
*/

int	check_stack_sort(t_stack_node *stack)
{
	t_stack_node	*current_node;

	if (stack == NULL)
		return (1);
	current_node = stack;
	while (current_node->next_node != stack)
	{
		if (current_node->number >= current_node->next_node->number)
			return (0);
		current_node = current_node->next_node;
	}
	return (1);
}

void	exit_on_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
