/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:41:06 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 18:58:16 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Check if stack is sorted
int	is_sorted(t_node *stack)
{
	t_node	*cursor;

	cursor = stack;
	while (cursor->next)
	{
		if (cursor->value > cursor->next->value)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

//Calculates size of stack
int	stack_size(t_node *stack)
{
	t_node	*cursor;
	int		size;

	if (!stack)
		return (0);
	cursor = stack;
	size = 0;
	while (cursor)
	{
		size++;
		cursor = cursor->next;
	}
	return (size);
}

// Find smallest int in stack
t_node	*find_small(t_node *stack)
{
	t_node	*cursor;
	t_node	*small;

	small = stack;
	cursor = stack;
	while (cursor)
	{
		if (small->value > cursor->value)
			small = cursor;
		cursor = cursor->next;
	}
	return (small);
}
