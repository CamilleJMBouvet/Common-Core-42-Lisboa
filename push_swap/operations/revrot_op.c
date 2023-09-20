/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:34:02 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 18:57:58 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Reverse-Rotate operation
void	rev_rotate(t_node **stack)
{
	t_node	*tmp;

	tmp = last_node(*stack);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	add_front(stack, tmp);
	*stack = tmp;
}

// rra command
void	rra(t_node **stack_a)
{
	if (*stack_a)
	{
		rev_rotate(stack_a);
		ft_printf("rra\n");
	}
}

// rrb command
void	rrb(t_node **stack_b)
{
	if (*stack_b)
	{
		rev_rotate(stack_b);
		ft_printf("rrb\n");
	}
}

// rrr command
void	rrr(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a && *stack_b)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
		ft_printf("rrr\n");
	}
}
