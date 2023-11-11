/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:12:49 by cbouvet           #+#    #+#             */
/*   Updated: 2023/10/30 19:43:03 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// Fork, execute, close and wait
void	cmd_exec(char **env, t_data *var)
{
	int	i;

	i = 0;
	while (var->cmds[i])
	{
		var->cpid[i] = fork();
		if (var->cpid[i] < 0)
			clean_exit(1, "Fork", var);
		if (var->cpid[i] == 0)
		{
			close_unused_fds(var->pipe_fd[i][0], var->pipe_fd[i +1][1], var);
			child_process(i, env, var);
			exit (EXIT_SUCCESS);
		}
		i++;
	}
	close_all(var);
	i = 0;
	while (var->cmds[i])
		waitpid(var->cpid[i++], NULL, 0);
}

// Child process actions
void	child_process(int i, char **env, t_data *var)
{
	if (dup2(var->pipe_fd[i][0], STDIN_FILENO) < 0)
		clean_exit(4, NULL, var);
	close(var->pipe_fd[i][0]);
	if (dup2(var->pipe_fd[i +1][1], STDOUT_FILENO) < 0)
		clean_exit(4, NULL, var);
	close(var->pipe_fd[i +1][1]);
	execve(var->cmd_path[i], var->cmds[i], env);
	clean_exit(1, "Execution", var);
}

// Massive file closing
void	close_unused_fds(int i_fd, int o_fd, t_data *var)
{
	int	i;

	i = 0;
	while (i < var->ac - 2)
	{
		if (var->pipe_fd[i][0] == i_fd && var->pipe_fd[i][1] != -1)
			close(var->pipe_fd[i][1]);
		else if (var->pipe_fd[i][1] == o_fd && var->pipe_fd[i][0] != -1)
			close(var->pipe_fd[i][0]);
		else
		{
			if (var->pipe_fd[i][0] != -1)
				close(var->pipe_fd[i][0]);
			if (var->pipe_fd[i][1] != -1)
				close(var->pipe_fd[i][1]);
		}
		i++;
	}
}
