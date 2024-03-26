/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 00:41:16 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 14:36:45 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// Deals with path issues + executes command
void	cmd_exec(t_ast *node)
{
	char	*path;

	if (access(node->value, F_OK | X_OK) == 0)
		path = ft_strdup(node->value);
	else
	{
		path = get_path(node->value);
		if (!path)
		{
			if (!getenv("PATH"))
				fd_printf(2, "'%s': No such file or directory\n", node->value);
			else
				fd_printf(2, "'%s': command not found\n", node->value);
			free (path);
			clean_all(1);
			exit(set_exit(127, 1));
		}
	}
	if (execve(path, node->args, var()->env) == -1)
		fd_printf(2, "Error: %s\n", strerror(errno));
	free(path);
}

// Searches for command path
char	*get_path(char *cmd)
{
	int		i;
	char	*tmp;
	char	*path;
	char	**all_paths;

	i = 0;
	if (!getenv("PATH") || !cmd || !cmd[0])
		return (NULL);
	tmp = ft_strjoin("/", cmd);
	all_paths = ft_split(getenv("PATH"), ':');
	while (all_paths[i])
	{
		path = ft_strjoin(all_paths[i++], tmp);
		if (access(path, F_OK | X_OK) == 0)
		{
			free(tmp);
			free_matrix(all_paths);
			return (path);
		}
		free(path);
	}
	free(tmp);
	free_matrix(all_paths);
	return (NULL);
}
