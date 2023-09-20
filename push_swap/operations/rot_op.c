/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:31:34 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 18:58:01 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Rotate operation
void	rotate(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	add_back(stack, tmp);
}

// ra command
void	ra(t_node **stack_a)
{
	if (*stack_a)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
}

// rb command
void	rb(t_node **stack_b)
{
	if (*stack_b)
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
}

// rr command
void	rr(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a && *stack_b)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
}
