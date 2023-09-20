/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:14:04 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/18 17:37:21 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		i;

	i = 0;
	if (ac < 2)
		return (1);
	while (av[i])
	{
		if (!av[i] || !*av[i])
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	a = NULL;
	b = NULL;
	a = make_stack(av, &a);
	if (!a)
		return (2);
	push_swap(&a, &b);
	free_stack(&a);
}
