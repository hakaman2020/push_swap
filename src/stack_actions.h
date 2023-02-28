/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_actions.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 13:16:33 by hman          #+#    #+#                 */
/*   Updated: 2021/05/29 10:21:33 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_ACTIONS_H
# define STACK_ACTIONS_H

# include "stack_node.h"

void	swap_nodes(t_stack_node **stack, char *s);
void	push_node(t_stack_node **src_stack, t_stack_node **dest_stack, char *s);
void	rotate_stack(t_stack_node **stack, char *s);
void	rotate_rev_stack(t_stack_node **stack, char *s);
void	print_operation(char *s);

#endif