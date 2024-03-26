/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:25:19 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 14:37:48 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// Checks parameters, sets exit status, cleans & exits
void	builtin_exit(t_ast	*node)
{
	fd_printf(1, "exit\n");
	if (node->args[1])
	{
		errno = exit_arg_err(node);
		if (errno == 1)
			return ;
		else if (!errno && node->args[1])
			set_exit(ft_atoi(node->args[1]), 1);
	}
	clean_all(1);
	exit(set_exit(0, 0));
}

// Checks for parameter errors with exit
int	exit_arg_err(t_ast *node)
{
	if (arg_is_digit(node->args[1]) && !node->args[2])
		return (0);
	if (arg_is_digit(node->args[1]) && node->args[2])
	{
		fd_printf(2, "exit: too many arguments\n");
		set_exit(1, 1);
		return (1);
	}
	fd_printf(2, "exit: %s: numeric argument required\n", node->args[1]);
	set_exit(2, 1);
	return (2);
}

// Checks whether args are digits
int	arg_is_digit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i +1] && \
		ft_isdigit(str[i +1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
