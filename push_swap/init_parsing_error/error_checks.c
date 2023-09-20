/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:17:12 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/18 17:40:24 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Checks if args are '+', '-' or digit
int	param_error(char **new_av)
{
	int	i;
	int	j;

	i = 0;
	while (new_av[i])
	{
		j = 0;
		if (new_av[i][0] == '-' || new_av[i][0] == '+')
		{
			if (new_av[i][1] && ft_isdigit(new_av[i][1]))
				j++;
			else
				return (1);
		}
		while (new_av[i][j])
		{
			if (!ft_isdigit(new_av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Checks if arg is bigger than the nber of decimal spaces of INT_MAX / INT_MIN
int	too_long(char **new_av)
{
	int	i;
	int	j;

	i = 0;
	while (new_av[i])
	{
		j = 0;
		if (new_av[i][0] == '+' || new_av[i][0] == '-')
			j++;
		while (new_av[i][j] == '0')
			j++;
		if ((ft_strlen(new_av[i]) - j) > 10)
			return (1);
		i++;
	}
	return (0);
}

// Checks if there are duplicate values
void	check_dup(t_node *stack)
{
	t_node	*cursor;
	t_node	*cursor_bis;

	cursor = stack;
	while (cursor->next)
	{
		cursor_bis = cursor->next;
		while (cursor_bis)
		{
			if (cursor->value == cursor_bis->value)
			{
				ft_putstr_fd("Error\n", 2);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
			cursor_bis = cursor_bis->next;
		}
		cursor = cursor->next;
	}
}

// Frees array, displays message, exits
void	error_procedure(char **new_av)
{
	int	i;

	i = 0;
	ft_putstr_fd("Error\n", 2);
	while (new_av[i])
		free(new_av[i++]);
	free(new_av);
	exit(EXIT_FAILURE);
}
