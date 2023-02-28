/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 08:25:50 by hman          #+#    #+#                 */
/*   Updated: 2021/06/17 12:40:31 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack_node.h"

t_stack_node	*create_stack(char *argv[]);
void			exit_on_error(void);

#endif