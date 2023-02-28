/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/22 16:35:20 by hman          #+#    #+#                 */
/*   Updated: 2021/05/25 10:10:08 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

long			ft_atoi_strict(const char *s);
int				check_args(int argc, char *argv[]);
int				insert_number(int *array, int number, int index);

#endif