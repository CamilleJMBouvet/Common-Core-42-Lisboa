/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:10:55 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/18 17:24:36 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Push numbers to B by chunks of size until stack_a has 3 elements or is sorted
void	push_to_b(int base_size, int *arr, t_node **stack_a, t_node **stack_b)
{
	int	chunk;
	int	i;

	chunk = chunk_size(base_size);
	i = chunk;
	while (stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		while (find_small(*stack_a)->value < arr[i -1] && !is_sorted(*stack_a))
		{
			if ((*stack_a)->value < arr[i -1])
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		i += chunk;
		if (i > base_size -3)
			i = base_size -2;
	}
	rankit(*stack_b);
	rankit(*stack_a);
}

// Attribute chunk size based on size of stack
int	chunk_size(int base_size)
{
	if (base_size <= 10)
		return (4);
	if (base_size < 100)
		return (25);
	if (base_size == 100)
		return (24);
	if (base_size < 500)
		return (60);
	if (base_size == 500)
		return (73);
	return (120);
}

// Find node that requires least amount of moves to be above its twin
t_node	*find_cheap(t_node *stack)
{
	t_node	*cursor;
	t_node	*cheap;

	cursor = stack;
	cheap = stack;
	while (cursor)
	{
		if (cursor->cost < cheap->cost)
			cheap = cursor;
		cursor = cursor->next;
	}
	return (cheap);
}

// Rotate or RevRotate until smallest is at top
void	final_sort(t_node **stack)
{
	t_node	*small;

	if (is_sorted(*stack))
		return ;
	small = find_small(*stack);
	if (small->rank > 0)
	{
		while (*stack != small)
		{
			ra(stack);
			rankit(*stack);
		}
	}
	else if (small->rank < 0)
	{
		while (*stack != small)
		{
			rra(stack);
			rankit(*stack);
		}
	}
}
