/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:36:08 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 18:57:56 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Push operation
void	push(t_node **stack_src, t_node **stack_dst)
{
	t_node	*tmp;

	tmp = *stack_src;
	if (stack_size(*stack_src) > 1)
	{
		*stack_src = (*stack_src)->next;
		(*stack_src)->prev = NULL;
	}
	if (*stack_dst)
	{
		tmp->next = *stack_dst;
		(*stack_dst)->prev = tmp;
	}
	else
		tmp->next = NULL;
	*stack_dst = tmp;
}

// pa command
void	pa(t_node **stack_b, t_node **stack_a)
{
	if (*stack_b)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}

// pb command
void	pb(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a)
	{
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
}
