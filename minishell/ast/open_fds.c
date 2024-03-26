/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:44:16 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/13 00:37:20 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

// Opens fds according to type of redirection
void	open_fds(t_ast *node, t_redir *new)
{
	if (!new)
		return ;
	if (new->type == 3 || new->type == 6)
		open_in_fd(new);
	else if (new->type == 4)
		new->fd = open(new->filename[0], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (new->type == 5)
		new->fd = open(new->filename[0], O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (new->fd && new->fd < 0)
	{
		if (new->type == 6 && new->fd && new->fd < 0)
			fd_printf(2, "Heredoc failed\n");
		else
			fd_printf(2, "Error: %s: %s\n", new->filename[0], strerror(errno));
		node->type = ERR;
	}
	multiple_files(node, new);
}

// Handles openings of input redirections
void	open_in_fd(t_redir *new)
{
	int		i;
	char	*heredoc;

	i = 0;
	if (new->type == 3)
	{
		while (new->filename[i])
		{
			new->fd = open(new->filename[i], O_RDONLY);
			if (new->fd < 0)
				return ;
			if (new->filename[i +1])
				close(new->fd);
			i++;
		}
		return ;
	}
	heredoc = ft_strjoin(var()->shell_path, HDOC);
	set_heredoc(new, heredoc);
	free(heredoc);
}

// Handles heredoc
void	set_heredoc(t_redir *new, char *heredoc)
{
	char	*line;

	new->fd = open(heredoc, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (new->fd < 0)
		return ;
	while (1)
	{
		line = readline("> ");
		if (ctrld_heredoc(line, new->filename[0]) \
			|| !ft_strncmp(line, new->filename[0], ft_strlen(line) + 1))
		{
			free(line);
			break ;
		}
		fd_printf(new->fd, "%s\n", line);
		free(line);
	}
	close(new->fd);
	new->fd = open(heredoc, O_RDONLY);
}
