/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_algo_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:04:14 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/18 16:33:47 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Rotate according to rank + push to a
void	push_to_a(t_node *cheap, t_node **stack_a, t_node **stack_b)
{
	t_node	*twin;

	twin = cheap->twin;
	if (cheap->rank < 0 && twin->rank < 0)
		bot_op(twin, cheap, stack_a, stack_b);
	else if (cheap->rank > 0 && twin->rank > 0)
		top_op(twin, cheap, stack_a, stack_b);
	else
		sep_op(twin, cheap, stack_a, stack_b);
	pa(stack_b, stack_a);
	rankit(*stack_a);
	if (stack_b)
		rankit(*stack_b);
}

// Rotate 2 bottom values
void	bot_op(t_node *twin, t_node *cheap, t_node **stack_a, t_node **stack_b)
{
	while (twin->rank != cheap->rank)
	{
		while (twin->rank < cheap->rank)
		{
			rra(stack_a);
			rankit(*stack_a);
		}
		while (twin->rank > cheap->rank)
		{
			rrb(stack_b);
			rankit(*stack_b);
		}
	}
	while (*stack_a != twin && *stack_b != cheap)
		rrr(stack_a, stack_b);
}

// Rotate 2 top values
void	top_op(t_node *twin, t_node *cheap, t_node **stack_a, t_node **stack_b)
{
	while (twin->rank != cheap->rank)
	{
		while (twin->rank > cheap->rank)
		{
			ra(stack_a);
			rankit(*stack_a);
		}
		while (twin->rank < cheap->rank)
		{
			rb(stack_b);
			rankit(*stack_b);
		}
	}
	while (*stack_a != twin && *stack_b != cheap)
		rr(stack_a, stack_b);
}

// Rotate values separately
void	sep_op(t_node *twin, t_node *cheap, t_node **stack_a, t_node **stack_b)
{
	while (*stack_a != twin)
	{
		if (twin->rank < 0)
			rra(stack_a);
		else if (twin->rank > 0)
			ra(stack_a);
	}
	while (*stack_b != cheap)
	{
		if (cheap->rank < 0)
			rrb(stack_b);
		else if (cheap->rank > 0)
			rb(stack_b);
	}
}
