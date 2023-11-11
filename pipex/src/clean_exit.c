/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:38:46 by cbouvet           #+#    #+#             */
/*   Updated: 2023/10/30 20:40:04 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// Print error message, free mallocs, close fds
void	clean_exit(int err, char *msg, t_data *var)
{
	err_message(err, msg);
	if (var->pipe_fd)
		close_all(var);
	free_all(var);
	if (err == 0)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

// Print error messages
void	err_message(int err, char *msg)
{
	if (err == 1)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	if (err == 2)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	if (err == 3)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
}

// Free all malloc'ed values
void	free_all(t_data *var)
{
	static int	i;

	if (var->cpid)
		free(var->cpid);
	if (var->pipe_fd)
	{
		while (i < var->ac -2)
			free(var->pipe_fd[i++]);
		free(var->pipe_fd);
	}
	if (var->cmds)
	{
		i = 0;
		while (var->cmds[i])
		{
			free_matrix(var->cmds[i]);
			i++;
		}
		free(var->cmds);
	}
	free_matrix(var->env_path);
	free_matrix(var->cmd_path);
}

// Free matrixes
void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
		{
			if (matrix[i])
				free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

void	close_all(t_data *var)
{
	int	i;

	i = 0;
	while (i < var->ac -2)
	{
		if (var->pipe_fd[i])
		{
			if (var->pipe_fd[i][0] != -1)
				close(var->pipe_fd[i][0]);
			if (var->pipe_fd[i][1] != -1)
				close(var->pipe_fd[i][1]);
		}
		i++;
	}
}
