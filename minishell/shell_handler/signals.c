/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:11:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 15:29:52 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_handler.h"

void	sig(int flag)
{
	if (flag == 0)
		signal(SIGINT, handle_sig);
	else if (flag == 1)
		signal(SIGINT, handle_fork_sig);
	signal(SIGQUIT, SIG_IGN);
}

void	handle_sig(int sig)
{
	if (sig == SIGINT)
	{
		fd_printf(1, "\n");
		set_exit(130, 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_fork_sig(int sig)
{
	if (sig == SIGINT)
	{
		set_exit(130, 1);
		fd_printf(1, "\n");
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	signal_intercepter(void)
{
	signal(SIGINT, sig);
	signal(SIGQUIT, SIG_IGN);
	return ;
}

int	ctrld_heredoc(char *buffer, char *delimiter)
{
	if (!buffer)
	{
		fd_printf(2, "warning: here-document at line %i ", count_hist());
		fd_printf(2, "delimited by end-of-file (wanted '%s')\n", delimiter);
		return (1);
	}
	return (0);
}
