/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:24:34 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/14 00:53:35 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// Checks if command is a builtin
int	is_builtin(char *cmd)
{
	int		i;
	char	*builtins[8];

	i = 0;
	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	builtins[7] = NULL;
	while (builtins[i])
	{
		if (!ft_strncmp(cmd, builtins[i], ft_strlen(cmd) + 1))
			return (i);
		i++;
	}
	return (-1);
}

// Executes builtins based on whether they're piped
void	builtin_exec(t_ast *node, int builtin)
{
	if (!is_pipe())
	{
		if (builtin == 1)
			builtin_cd(node);
		if (builtin == 6)
			builtin_exit(node);
	}
	if (builtin == 0)
		builtin_echo(node);
	if (builtin == 2)
		builtin_pwd(node);
	if (builtin == 3)
		builtin_export(node);
	if (builtin == 4)
		builtin_unset(node);
	if (builtin == 5)
		builtin_env(node);
}

// Checks if there is at least 1 pipe in prompt
int	is_pipe(void)
{
	t_ast	*ptr;

	ptr = var()->ast;
	while (ptr)
	{
		if (ptr->type == 2)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
