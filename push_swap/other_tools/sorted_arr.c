/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:55:00 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 18:58:13 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Malloc array, fill it & sort it
int	*make_arr(t_node *stack_b)
{
	int		i;
	int		*arr;
	t_node	*cursor;

	arr = malloc(sizeof(int) * stack_size(stack_b));
	if (!arr)
		return (NULL);
	i = 0;
	cursor = stack_b;
	while (cursor)
	{
		arr[i] = cursor->value;
		cursor = cursor->next;
		i++;
	}
	arr = bubble_sort(arr, stack_size(stack_b));
	return (arr);
}

// Perform bubble sort on array
int	*bubble_sort(int *arr, int size)
{
	int	i;
	int	tmp;
	int	counter;

	i = 0;
	counter = 0;
	while (i < size -1)
	{
		if (arr[i] > arr[i +1])
		{
			tmp = arr[i];
			arr[i] = arr[i +1];
			arr[i +1] = tmp;
			counter++;
		}
		i++;
	}
	if (counter != 0)
		bubble_sort(arr, size);
	return (arr);
}
