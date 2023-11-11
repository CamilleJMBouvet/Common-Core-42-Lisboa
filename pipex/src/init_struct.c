/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:23:55 by cbouvet           #+#    #+#             */
/*   Updated: 2023/11/11 19:29:08 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// Malloc all pipes to be used
//set pipe[0][0] as RDONLY infile & pipe[last][1] as WRONLY outfile
void	pipe_arr(int ac, char **av, t_data *var)
{
	static int	i;

	var->pipe_fd = malloc(sizeof(int *) * var->ac -2);
	if (!var->pipe_fd)
		clean_exit(1, "Malloc", var);
	while (i < ac -2)
	{
		var->pipe_fd[i] = malloc(sizeof(int) * 2);
		if (!var->pipe_fd[i])
			clean_exit(1, "Malloc", var);
		var->pipe_fd[i][0] = -1;
		var->pipe_fd[i][1] = -1;
		if (pipe(var->pipe_fd[i]) == -1)
			clean_exit(1, "Pipe", var);
		i++;
	}
	close(var->pipe_fd[0][0]);
	close(var->pipe_fd[i -1][1]);
	var->pipe_fd[0][0] = open(av[1], O_RDONLY);
	if (var->pipe_fd[0][0] == -1)
		err_message(2, av[1]);
	var->pipe_fd[i -1][1] = open(av[ac -1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (var->pipe_fd[i -1][1] < 0)
		clean_exit(2, av[var->ac -1], var);
}

// Store all the commands & their flags
void	store_cmds(char **av, t_data *var)
{
	int			i;
	static int	j;

	i = 2;
	var->cmds = malloc(sizeof(char **) * var->ac -2);
	if (!var->cmds)
		clean_exit(1, "Malloc", var);
	while (i < var->ac -1)
	{
		if (!av[i][0])
			var->cmds[j] = ft_split("Null_cmd", ' ');
		else
			var->cmds[j] = ft_split(av[i], ' ');
		j++;
		i++;
	}
	var->cmds[j] = NULL;
	j = 0;
	while (var->cmds[j])
		if (ft_strncmp(var->cmds[j++][0], "Null_cmd", 8) == 0)
			clean_exit(3, "", var);
}

// Store the env command paths
void	store_paths(char **env, t_data *var)
{
	static int	i;

	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			var->env_path = ft_split(&env[i][5], ':');
			return ;
		}
		i++;
	}
	clean_exit(1, "Env path", var);
}

// Store the path to each command
void	store_cmdpath(t_data *var)
{
	static int	i;

	var->cmd_path = malloc(sizeof(char *) * var->ac -2);
	if (!var->cmd_path)
		clean_exit(1, "Malloc", var);
	while (var->cmds[i])
	{
		var->cmd_path[i] = find_cmd(var->cmds[i][0], *var);
		if (!var->cmd_path[i])
			clean_exit(3, var->cmds[i][0], var);
		i++;
	}
	var->cmd_path[i] = NULL;
}

// Find the path to each command
char	*find_cmd(char *cmd, t_data var)
{
	int			i;
	static char	*tmp;
	static char	*fullpath;

	i = 0;
	tmp = ft_strjoin("/", cmd);
	while (var.env_path[i])
	{
		fullpath = ft_strjoin(var.env_path[i], tmp);
		if (access(fullpath, F_OK | X_OK) == 0)
		{
			free(tmp);
			return (fullpath);
		}
		free(fullpath);
		i++;
	}
	free (tmp);
	return (NULL);
}
