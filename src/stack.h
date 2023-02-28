/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:16:43 by hman          #+#    #+#                 */
/*   Updated: 2021/05/25 10:19:57 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "stack_node.h"

t_stack_node	*create_new_stack_node(int number);
void			insert_node_front(t_stack_node **stack, t_stack_node *node);
void			del_node_stack(t_stack_node **stack);
void			clear_stack(t_stack_node **stack);

#endif