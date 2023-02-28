/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_sorting.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/26 15:35:00 by hman          #+#    #+#                 */
/*   Updated: 2021/06/16 17:52:57 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_SORTING_H
# define STACK_SORTING_H

# include "stack_node.h"

int				is_stack_sorted(t_stack_node *stack);
void			rotate_sorted_stack(t_stack_node **stack, unsigned int n);
unsigned int	get_lowest_tag(t_stack_node *stack);
#endif