/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_small_sort.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/09 13:18:26 by hman          #+#    #+#                 */
/*   Updated: 2021/06/09 22:38:02 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_SMALL_SORT_H
# define STACK_SMALL_SORT_H

# include "stack_node.h"

void	sort_small(t_stack_node **stack_a, int n);
void	sort_three(t_stack_node **stack);
void	insert_b_into_a(t_stack_node **stack_a, t_stack_node **stack_b);
void	sort_more_than_three(t_stack_node **stack_a, int n);

#endif
