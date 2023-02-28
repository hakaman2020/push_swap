/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 16:44:48 by hman          #+#    #+#                 */
/*   Updated: 2021/05/29 10:19:56 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stack_actions.h"
#include "stack_operations.h"
#include "get_next_line.h"

/*
**	this function will read from STDIN for operations and process the stack
**	operation if the input is valid
**	RETURN	1 if the input operation is valid
**			-1 if the input operation is not valid
*/

int	read_operations(t_stack_node **stack_a, t_stack_node **stack_b)
{
	char	*line;
	int		gnl_return;
	int		process_result;

	gnl_return = 1;
	while (gnl_return == 1)
	{
		gnl_return = get_next_line(0, &line);
		if (gnl_return == -1)
			return (-1);
		process_result = process_operations(stack_a, stack_b, line);
		if (process_result == 0 && gnl_return != 0)
			return (-1);
		free(line);
	}
	return (1);
}

/*
**	This function will try to process the operation that has been given
**	if it doesn't find the corresponding operations it will return -1
**	RETURN	1 if the operation has been recognized
**			0 if operation is not recognized
*/

int	process_operations(t_stack_node **stack_a, t_stack_node **stack_b
	, char *line)
{
	int	found;

	found = 0;
	if (line[0] == 's' || line[0] == 'p')
		found = process_swap_push(stack_a, stack_b, line);
	else if (line[0] == 'r')
		found = process_rotation(stack_a, stack_b, line);
	return (found);
}

/*
**	this function will check whether the given operation is an swap or push 
** 	operationn and execute it if found.
**	Return	1 if the operation has been recognized
**			0 if the operation is not recognized
*/

int	process_swap_push(t_stack_node **stack_a, t_stack_node **stack_b
	, char *line)
{
	if (!ft_strncmp("sa", line, 5))
		swap_nodes(stack_a, NULL);
	else if (!ft_strncmp("sb", line, 5))
		swap_nodes(stack_b, NULL);
	else if (!ft_strncmp("ss", line, 5))
	{
		swap_nodes(stack_a, NULL);
		swap_nodes(stack_b, NULL);
	}
	else if (!ft_strncmp("pa", line, 5))
		push_node(stack_b, stack_a, NULL);
	else if (!ft_strncmp("pb", line, 5))
		push_node(stack_a, stack_b, NULL);
	else
		return (0);
	return (1);
}

/*
**	this function will check whether the given operation is an rotation
**	operation and execute it if found.
**	Return	1 if the operation has been recognized
**			0 if the operation is not recognized
*/

int	process_rotation(t_stack_node **stack_a, t_stack_node **stack_b, char *line)
{
	if (!ft_strncmp("ra", line, 5))
		rotate_stack(stack_a, NULL);
	else if (!ft_strncmp("rb", line, 5))
		rotate_stack(stack_b, NULL);
	else if (!ft_strncmp("rr", line, 5))
	{
		rotate_stack(stack_a, NULL);
		rotate_stack(stack_b, NULL);
	}
	else if (!ft_strncmp("rra", line, 5))
		rotate_rev_stack(stack_a, NULL);
	else if (!ft_strncmp("rrb", line, 5))
		rotate_rev_stack(stack_b, NULL);
	else if (!ft_strncmp("rrr", line, 5))
	{
		rotate_rev_stack(stack_a, NULL);
		rotate_rev_stack(stack_b, NULL);
	}
	else
		return (0);
	return (1);
}	

/*
**	This function compares to strings with each other
**	RETURN 	0 is they are equal
**			not 0 if they are not equal
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1p;
	const unsigned char	*s2p;

	i = 0;
	s1p = (const unsigned char *)s1;
	s2p = (const unsigned char *)s2;
	if (n != 0)
	{
		while (i < n)
		{
			if (!(s1p[i] == s2p[i]) || s1p[i] == '\0')
			{
				if ((s1p[i] - s2p[i]) < 0)
					return (-1);
				else if ((s1p[i] - s2p[i]) > 0)
					return (1);
				else
					return (0);
			}
			i++;
		}
	}
	return (0);
}
