/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:20:16 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/18 17:42:02 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Base function for the creation + population of stack_a
t_node	*make_stack(char **av, t_node **stack)
{
	char	**new_av;
	int		i;

	new_av = make_new_av(av);
	i = 0;
	if (param_error(new_av) || too_long(new_av))
		error_procedure(new_av);
	*stack = fill_stack(new_av, stack);
	while (new_av[i])
		free(new_av[i++]);
	free(new_av);
	check_dup(*stack);
	return (*stack);
}

// Creates a new_av to isolate each arg, including those in between ""
char	**make_new_av(char **av)
{
	int		i;
	char	*tmp;
	char	*tmp_bis;
	char	**new_av;

	tmp = ft_calloc(2, 1);
	i = 1;
	while (av[i])
	{
		tmp_bis = ft_strjoin(tmp, av[i]);
		free(tmp);
		tmp = ft_strjoin(tmp_bis, " ");
		free(tmp_bis);
		i++;
	}
	new_av = ft_split(tmp, ' ');
	free(tmp);
	return (new_av);
}

// Fills up stack_a
t_node	*fill_stack(char **new_av, t_node **stack)
{
	int		i;
	long	tmp;
	t_node	*node;

	i = 0;
	while (new_av[i])
	{
		tmp = long_atoi(new_av[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
		{
			free_stack(stack);
			error_procedure(new_av);
		}
		node = new_node((int)tmp);
		add_back(stack, node);
		i++;
	}
	return (*stack);
}

//atoi but long
long	long_atoi(char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] < 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * neg);
}
