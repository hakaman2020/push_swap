/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_big_sort_utils.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 19:02:43 by hman          #+#    #+#                 */
/*   Updated: 2021/06/16 19:12:46 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_BIG_SORT_UTILS_H
# define STACK_BIG_SORT_UTILS_H

# include "stack_node.h"

int		count_digits(int n);
int		count_significant_numbers(t_stack_node *stack, int lsd_position,
			unsigned int digit);
int		check_number(unsigned int tag_number, int lsd_position,
			unsigned int digit);
#endif