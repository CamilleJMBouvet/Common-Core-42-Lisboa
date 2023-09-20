/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:53:16 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 18:57:38 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Base function sending to algorithms according to size
void	push_swap(t_node **stack_a, t_node **stack_b)
{
	int	base_size;

	base_size = stack_size(*stack_a);
	if (is_sorted(*stack_a) || base_size < 2)
		return ;
	else if (base_size == 2)
		sa(stack_a);
	else if (base_size == 3)
		sort_three(stack_a);
	else if (base_size == 5)
		sort_five(stack_a, stack_b);
	else
		sort_big(base_size, stack_a, stack_b);
	return ;
}

// Sorts 3-elements stack
void	sort_three(t_node **stack_a)
{
	t_node	*last;

	while (!is_sorted(*stack_a))
	{
		last = last_node(*stack_a);
		if ((*stack_a)->value > (*stack_a)->next->value)
		{
			if ((*stack_a)->value > last->value)
				ra(stack_a);
			else
				sa(stack_a);
		}
		else
			rra(stack_a);
	}
	rankit(*stack_a);
}

// Sorts 5-elements stack
void	sort_five(t_node **stack_a, t_node **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_size(*stack_a) != 5)
	{
		find_twin(stack_a, stack_b);
		push_to_a(*stack_b, stack_a, stack_b);
		rankit(*stack_a);
	}
	rankit(*stack_a);
	final_sort(stack_a);
}

// Sorts 6+ elements stack
void	sort_big(int base_size, t_node **stack_a, t_node **stack_b)
{
	t_node	*cheap;
	int		*arr;

	arr = make_arr(*stack_a);
	push_to_b(base_size, arr, stack_a, stack_b);
	if (stack_size(*stack_a) == 3)
		sort_three(stack_a);
	while (stack_size(*stack_a) != base_size)
	{
		find_twin(stack_a, stack_b);
		set_cost(*stack_b);
		cheap = find_cheap(*stack_b);
		push_to_a(cheap, stack_a, stack_b);
	}
	final_sort(stack_a);
	free(arr);
}
