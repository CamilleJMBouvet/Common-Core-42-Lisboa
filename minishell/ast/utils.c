/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:50:14 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/15 21:58:33 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

// Opens pipes or sends to redirections
int	init_fds(t_dlist *token, t_ast *new, int flag)
{
	new->in = NULL;
	new->out = NULL;
	new->pipe[0] = -1;
	new->pipe[1] = -1;
	if (new->type == 2)
	{
		if (pipe(new->pipe) == -1)
			fd_printf(2, "Error: pipe: %s\n", strerror(errno));
		return (0);
	}
	if (new->type == ERR && !flag)
		token = var()->tokens;
	if (new->type != ERR)
	{
		search_back(token, new, 0);
		search_back(token, new, 1);
	}
	search_front(token, new, 0);
	search_front(token, new, 1);
	return (flag);
}

// Prepares the **arr to receive the arguments
void	make_args(t_dlist *token, t_ast *new, int flag)
{
	int		i;
	t_dlist	*ptr;

	if (!flag)
	{
		new->args = NULL;
		return ;
	}
	i = 0;
	ptr = token;
	while (ptr && ptr != end_segment(token))
	{
		if (ptr->type == 0)
			i++;
		ptr = ptr->next;
	}
	if (!is_builtin(new->value) && i == 1)
		i++;
	new->args = malloc(sizeof(char *) * (i +1));
	if (!new->args)
		return ;
	populate_args(token, new);
}

// Counts number of filenames provided for a redirection
int	filename_size(t_dlist *token)
{
	int		i;
	t_dlist	*ptr;

	i = 0;
	ptr = token;
	while (ptr && ptr->type)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

// Deals with multiple filenames provided for a redirection
void	multiple_files(t_ast *node, t_redir *new)
{
	int	i;
	int	fd;

	i = 1;
	if (new->type == 3 || (node->value && is_builtin(node->value) != -1))
		return ;
	while (new->filename[i])
	{
		fd = open(new->filename[i], O_RDONLY);
		if (fd < 0)
		{
			fd_printf(2, "Error: %s: %s\n", new->filename[i], strerror(errno));
			node->type = ERR;
			return ;
		}
		close(fd);
		i++;
	}
}

// Populates args array with arguments
void	populate_args(t_dlist *token, t_ast *new)
{
	int		i;
	t_dlist	*ptr;

	i = 0;
	ptr = token;
	while (ptr && ptr != end_segment(token))
	{
		if (ptr->type == 0)
		{
			if (ptr->content[0])
				new->args[i] = ptr->content;
			if (ptr->content && !ptr->content[0])
				new->args[i] = "";
			i++;
		}
		ptr = ptr->next;
	}
	if (!is_builtin(new->value) && i == 1)
		new->args[i++] = "";
	new->args[i] = NULL;
}
