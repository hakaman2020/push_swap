/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pre_sort_stack.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 12:37:43 by hman          #+#    #+#                 */
/*   Updated: 2021/06/17 12:48:18 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRE_SORT_STACK_H
# define PRE_SORT_STACK_H

# include "stack_node.h"

t_stack_node	*pre_sort_stack(char *argv[]);
t_stack_node	*insert_node_sorted_stack(t_stack_node *stack,
					t_stack_node *new_node);
t_stack_node	*tag_nodes(t_stack_node *stack);
t_stack_node	*insert_tags(t_stack_node *stack, t_stack_node *sorted_stack);
int				get_tag_number(int number, t_stack_node *sorted_stack);

#endif