/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/22 08:55:32 by hman          #+#    #+#                 */
/*   Updated: 2021/05/25 19:52:35 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "parser.h"
#include "stack.h"

#define ERROR 9999999999

/*
**	this function will convert a string to a long integer. The return is of the
**	datatype long to use it for error signaling.
**	RETURN	9999999999 if something went wrong
**			else it will return the number converted from the string.
*/

long	ft_atoi_strict(const char *s)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	if (*s == '\0' || ((*s == '-' || *s == '+') && s[1] == '\0') || s == NULL)
		return (ERROR);
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
			result = (result * 10) + (*s - 48);
		else
			return (ERROR);
		if ((result > INT_MAX && sign == 1)
			|| (result > ((long)INT_MAX + 1) && sign == -1))
			return (ERROR);
		s++;
	}
	return (result * sign);
}

/*
**	this function will check whether each input is valid
**	RETURN	0 if it has encountered a non-valid input
**			1 if alll arguments are valid
*/

int	check_args(int argc, char *argv[])
{
	int		i;
	int		*array;
	long	number;

	array = malloc((argc - 1) * sizeof(int));
	if (array == NULL)
		return (0);
	i = 1;
	while (argv[i] != NULL)
	{
		number = ft_atoi_strict(argv[i]);
		if (number == ERROR || !insert_number(array, (int) number, i - 1))
		{
			free(array);
			return (0);
		}
		i++;
	}
	free(array);
	return (1);
}

/*
**	this function will attempt to insert the number in the array
**	it will not if it encounters a duplicate.
**	RETURN	0 if failed	
**			1 if succesfull
*/

int	insert_number(int *array, int number, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (array[i] == number)
			return (0);
		i++;
	}
	array[i] = number;
	return (1);
}
