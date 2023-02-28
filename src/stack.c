/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 11:35:00 by hman          #+#    #+#                 */
/*   Updated: 2021/05/25 10:19:35 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

/*
**	these functions is to create a circular double linked list
**	because of that it assumes you will keep track of the top of the stack 
**	yourself
*/

/*
** this function creates a new node with the integer in it
** RETURN	the created new stack_node with the integer in it
**			will return NULL if something went wrong.
*/

t_stack_node	*create_new_stack_node(int number)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		return (NULL);
	new_node->number = number;
	new_node->tag_active = 0;
	new_node->tag_number = 0;
	new_node->next_node = NULL;
	new_node->prev_node = NULL;
	return (new_node);
}

/*
** this function will insert the node in front of the node of the stack that 
** has been given and the stackpointer will be set to the inserted node.
** If the given stack is empty (NULL) then the node will be 
** assigned to the stack.
*/

void	insert_node_front(t_stack_node **stack_node, t_stack_node *node)
{
	if (node != NULL)
	{
		if (*stack_node == NULL)
		{
			node->next_node = node;
			node->prev_node = node;
		}
		else
		{
			(*stack_node)->prev_node->next_node = node;
			node->next_node = *stack_node;
			node->prev_node = (*stack_node)->prev_node;
			(*stack_node)->prev_node = node;
		}
		*stack_node = node;
	}
}

/*
**	this function will delete the node on the stack that has been given and 
**	reconnect links between the nodes in the stack and put the stack pointer to 
**	the next node. If it was the only element in the stack it will set the 
**	pointer of the stack to NULL. It will do nothing if the stack is empty.
*/

void	del_node_stack(t_stack_node **stack_node)
{
	t_stack_node	*next_node;

	if (*stack_node != NULL)
	{
		if ((*stack_node)->next_node == *stack_node)
		{
			free(*stack_node);
			*stack_node = NULL;
		}
		else
		{	
			(*stack_node)->prev_node->next_node = (*stack_node)->next_node;
			(*stack_node)->next_node->prev_node = (*stack_node)->prev_node;
			next_node = (*stack_node)->next_node;
			free(*stack_node);
			*stack_node = next_node;
		}
	}
}

/*
** this function will clear the whole stack. Unless it is empty.
** if done correctly the stack pointer will point to NULL.
*/

void	clear_stack(t_stack_node **stack)
{
	if (*stack != NULL)
	{
		while (*stack != NULL)
		{
			del_node_stack(stack);
		}
	}
}
