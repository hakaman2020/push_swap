/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_node.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 08:46:30 by hman          #+#    #+#                 */
/*   Updated: 2021/05/25 10:25:32 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_NODE_H
# define STACK_NODE_H

# include <stddef.h>

/*
**	the struct for the node of the double linked list.
**	the number is for the integer.
**	the tag_active signals if the tag is active (1) or not (0).
**	the tag_number is the final place in a sorted list.
*/

typedef struct s_stack_node
{
	int					number;
	struct s_stack_node	*next_node;
	struct s_stack_node	*prev_node;
	int					tag_active;
	unsigned int		tag_number;
}				t_stack_node;

#endif
