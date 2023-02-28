/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_operations.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 10:44:35 by hman          #+#    #+#                 */
/*   Updated: 2021/05/24 10:51:39 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPERATIONS_H
# define STACK_OPERATIONS_H

# include "stack_node.h"

int	read_operations(t_stack_node **stack_a, t_stack_node **stack_b);
int	process_operations(t_stack_node **stack_a, t_stack_node **stack_b,
		char *line);
int	process_swap_push(t_stack_node **stack_a, t_stack_node **stack_b,
		char *line);
int	process_rotation(t_stack_node **stack_a, t_stack_node **stack_b,
		char *line);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif