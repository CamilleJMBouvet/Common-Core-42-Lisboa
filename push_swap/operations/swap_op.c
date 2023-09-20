/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:26:31 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 18:58:04 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Swap operation
void	swap(t_node **stack)
{
	t_node	*top;
	t_node	*mid;
	t_node	*bottom;

	top = *stack;
	mid = (*stack)->next;
	if ((*stack)->next->next)
	{
		bottom = (*stack)->next->next;
		bottom->prev = top;
		top->prev = mid;
		top->next = bottom;
		mid->next = top;
		mid->prev = NULL;
	}
	else
	{
		top->prev = mid;
		mid->next = top;
		top->next = NULL;
		mid->prev = NULL;
	}
	*stack = mid;
}

// sa command
void	sa(t_node **stack_a)
{
	if (stack_a && (*stack_a)->next)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
}

// sb command
void	sb(t_node **stack_b)
{
	if (stack_b && (*stack_b)->next)
	{
		swap(stack_b);
		ft_printf("sb\n");
	}
}

// ss command
void	ss(t_node **stack_a, t_node **stack_b)
{
	if ((stack_a && (*stack_a)->next) && (stack_b && (*stack_b)->next))
	{
		swap(stack_a);
		swap(stack_b);
		ft_printf("ss\n");
	}
}
