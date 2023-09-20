/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:55:33 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 18:57:48 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Populate the rank values of the struct
void	rankit(t_node *stack)
{
	int		rank;
	t_node	*cursor;
	int		count;

	rank = 0;
	count = 0;
	cursor = stack;
	while (count < (stack_size(stack) / 2) + 1)
	{
		cursor->rank = rank;
		cursor = cursor->next;
		rank++;
		count++;
	}
	rank = -1;
	cursor = last_node(stack);
	count--;
	while (count > 0)
	{
		cursor->rank = rank;
		cursor = cursor->prev;
		rank--;
		count--;
	}
}

// Populate the twin values (aka next smallest value) of stack_b
void	find_twin(t_node **stack_a, t_node **stack_b)
{
	t_node	*cursor_a;
	t_node	*cursor_b;
	long	tmp;

	cursor_b = *stack_b;
	while (cursor_b)
	{
		tmp = LONG_MAX;
		cursor_a = *stack_a;
		while (cursor_a)
		{
			if (cursor_a->value > cursor_b->value && cursor_a->value < tmp)
			{
				tmp = cursor_a->value;
				cursor_b->twin = cursor_a;
			}
			cursor_a = cursor_a->next;
		}
		if (tmp == LONG_MAX)
			cursor_b->twin = find_small(*stack_a);
		cursor_b = cursor_b->next;
	}
}

// Iterate stack_b and turn rank values to positive before sending to calc_cost
void	set_cost(t_node *stack_b)
{
	t_node	*cursor;
	int		rank_a;
	int		rank_b;

	cursor = stack_b;
	while (cursor)
	{
		rank_a = cursor->twin->rank;
		if (rank_a < 0)
			rank_a *= -1;
		rank_b = cursor->rank;
		if (rank_b < 0)
			rank_b *= -1;
		calc_cost(rank_a, rank_b, cursor);
		cursor = cursor->next;
	}
}

// Calculates cost of pushing node + twin to the top using their rank
void	calc_cost(int a, int b, t_node *node)
{
	if (node->rank == node->twin->rank)
		node->cost = a;
	else if ((node->rank < 0 && node->twin->rank < 0) \
		|| (node->rank > 1 && node->twin->rank > 1))
	{
		if (a > b)
			node->cost = a;
		else
			node->cost = b;
	}
	else
		node->cost = a + b;
}
