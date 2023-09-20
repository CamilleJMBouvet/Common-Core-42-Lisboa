/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:33:29 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/15 20:32:04 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Malloc and initialise new node
t_node	*new_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->rank = 0;
	new->cost = INT_MAX;
	new->prev = NULL;
	new->next = NULL;
	new->twin = NULL;
	return (new);
}

// Get last node
t_node	*last_node(t_node *stack)
{
	t_node	*cursor;

	if (!stack)
		return (NULL);
	cursor = stack;
	while (cursor->next != NULL)
		cursor = cursor->next;
	return (cursor);
}

// Add node to back of stack
void	add_back(t_node **stack, t_node *node)
{
	t_node	*cursor;

	if (!*stack)
	{
		*stack = node;
		return ;
	}
	cursor = last_node(*stack);
	cursor->next = node;
	node->prev = cursor;
}

// Add node to front of stack
void	add_front(t_node **stack, t_node *node)
{
	node->next = *stack;
	(*stack)->prev = node;
	*stack = node;
}

// Free stack
void	free_stack(t_node **stack)
{
	t_node	*cursor;

	if (!*stack)
		return ;
	while (*stack)
	{
		cursor = (*stack)->next;
		free(*stack);
		*stack = cursor;
	}
	return ;
}
