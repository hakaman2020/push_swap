/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_big_sort.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 14:15:10 by hman          #+#    #+#                 */
/*   Updated: 2021/06/16 19:13:30 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_BIG_SORT_H
# define STACK_BIG_SORT_H

# include "stack_node.h"

void	sort_big(t_stack_node **stack_a, int n);
void	radix_lsd_sorting(t_stack_node **stack_a, int n);
void	first_sort_to_stack_b(t_stack_node **stack_a, t_stack_node **stack_b,
			int current_lsd, int n);
void	sort_to_stack_b(t_stack_node **stack_a, t_stack_node **stack_b,
			int current_lsd, int n);
void	sort_to_stack_a(t_stack_node **stack_a, t_stack_node **stack_b,
			int current_lsd, int n);

#endif