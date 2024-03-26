/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:24:48 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 14:38:47 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// Merges extra out filenames as args, sends to -n detection & printer
void	builtin_echo(t_ast *node)
{
	int		i;
	int		n_flag;
	char	**args;

	args = merge_args(node);
	n_flag = find_n_flag(args);
	i = n_flag;
	while (args[i])
	{
		if (args[i][0] == -1)
			fd_printf(node->in_out[1], " ");
		else
		{
			fd_printf(node->in_out[1], "%s", args[i]);
			if (args[i +1])
				fd_printf(node->in_out[1], " ");
		}
		i++;
	}
	free(args);
	if (n_flag == 0)
		fd_printf(node->in_out[1], "\n");
	set_exit(0, 1);
}

// Detects -n flag(s) and returns the last one's position
int	find_n_flag(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		if (args[i][0] != '-')
			return (i);
		j = 1;
		while (args[i][j])
		{
			if (args[i][j] != 'n')
				return (i);
			j++;
		}
		i++;
	}
	return (1);
}

// Merges args + output redirection filenames to all be treated as args
char	**merge_args(t_ast *node)
{
	int		i;
	int		size;
	char	**args;

	size = 0;
	if (node->args && node->args[1])
		size += index_nb(node->args) - 1;
	if (node->out && node->out->filename && node->out->filename[1])
		size += index_nb(node->out->filename) - 1;
	args = malloc(sizeof(char *) * (size +1));
	if (!args)
		return (NULL);
	i = 1;
	size = 0;
	while (node->args[i])
		args[size++] = node->args[i++];
	i = 1;
	if (node->out && node->out->filename && node->out->filename[1])
		while (node->out->filename[i])
			args[size++] = node->out->filename[i++];
	args[size] = NULL;
	return (args);
}
