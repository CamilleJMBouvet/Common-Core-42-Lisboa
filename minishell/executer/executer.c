/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 00:40:29 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 15:11:35 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// Launches execution of commands/builtins
void	execute_ast(void)
{
	int		builtin;
	t_ast	*node;

	builtin = -1;
	node = var()->ast;
	while (node)
	{
		if (node->type == 0)
		{
			set_in_out(node);
			builtin = is_builtin(node->value);
			if (builtin >= 0 && !is_pipe())
				builtin_exec(node, builtin);
			else
			{
				sig(1);
				launch_pid(builtin, node);
				sig(0);
			}
		}
		node = node->next;
	}
	parent_pid();
}

// Sets input/output files according to existing redirections/pipes
void	set_in_out(t_ast *node)
{
	if (node->in)
		node->in_out[0] = node->in->fd;
	else if (node->prev && node->prev->type == 2)
		node->in_out[0] = node->prev->pipe[0];
	if (node->out)
		node->in_out[1] = node->out->fd;
	else if (node->next && node->next->type == 2)
		node->in_out[1] = node->next->pipe[1];
}

// Launches child processes for execution of commands or piped builtins
void	launch_pid(int builtin, t_ast *node)
{
	(void)builtin;
	sig(1);
	signal(SIGQUIT, SIG_IGN);
	node->pid = fork();
	if (node->pid < 0)
	{
		fd_printf(2, "Error: %s\n", strerror(errno));
		return ;
	}
	if (node->pid == 0)
	{
		if (builtin == -1)
		{
			close_fds(node->in_out[0], node->in_out[1]);
			dup2(node->in_out[0], STDIN_FILENO);
			close_fds(0, node->in_out[1]);
			dup2(node->in_out[1], STDOUT_FILENO);
			close_fds(0, 1);
			cmd_exec(node);
		}
		else
			builtin_exec(node, builtin);
		clean_all(1);
		exit (set_exit(0, 0));
	}
}

// Closes fds, waits for child processes, converts exit status, removes heredoc
void	parent_pid(void)
{
	t_ast	*node;
	char	*heredoc;
	int		status;

	close_fds(0, 1);
	node = var()->ast;
	signal_intercepter();
	while (node)
	{
		if (node->pid > 0)
		{
			waitpid(node->pid, &status, 0);
			if (WIFEXITED(status))
				set_exit(WEXITSTATUS(status), 1);
		}
		node = node->next;
	}
	heredoc = ft_strjoin(var()->shell_path, HDOC);
	if (access(heredoc, F_OK) == 0)
		unlink(heredoc);
	free(heredoc);
}
