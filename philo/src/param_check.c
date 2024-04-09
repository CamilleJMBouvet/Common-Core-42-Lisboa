/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:40:53 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/31 15:07:35 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Checks if arg nb is correct + args are digits
int	param_check(int ac, char **av)
{
	int	i;
	int	err;

	if (ac < 5 || ac > 6)
		err = PARAM_NB;
	else
	{
		i = 1;
		while (av[i])
		{
			err = format_check(av[i++]);
			if (err < 0)
				break ;
		}
	}
	if (err < 0)
	{
		err_message(err);
		return (0);
	}
	return (1);
}

// Checks format constraints of arguments
int	format_check(char *arg)
{
	int	i;

	i = 0;
	while ((arg[i] >= 9 && arg[i] <= 13) || arg[i] == ' ')
		i++;
	if (arg[i] == '-')
		return (NEG_PARAM);
	if (arg[i] == '+')
		i++;
	if (ph_strlen(&arg[i]) > 10)
		return (OVERFLOW);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (PARAM_TYPE);
		i++;
	}
	return (0);
}
