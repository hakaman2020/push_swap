/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 07:45:17 by hman          #+#    #+#                 */
/*   Updated: 2021/05/25 10:43:17 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stack_node.h"

t_stack_node	*create_stack(char *argv[], t_stack_node *stack);
int				check_stack_sort(t_stack_node *stack);
void			exit_on_error(void);

#endif