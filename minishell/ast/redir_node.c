/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:48:17 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/18 22:17:38 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

// Searches for redirections prior to command
void	search_back(t_dlist *token, t_ast *node, int fifo)
{
	t_dlist	*ptr;

	ptr = token;
	while (ptr && ptr != start_segment(token, 1))
	{
		if (ptr->type > 2)
		{
			if (!fifo && (ptr->type == 3 || ptr->type == 6))
			{
				node->in = new_redir(ptr, node);
				break ;
			}
			else if (fifo && (ptr->type == 4 || ptr->type == 5))
			{
				node->out = new_redir(ptr, node);
				break ;
			}
		}
		ptr = ptr->prev;
	}
}

// Searches for redirections after command
void	search_front(t_dlist *token, t_ast *node, int fifo)
{
	t_dlist	*ptr;

	ptr = token;
	while (ptr && ptr != end_segment(token))
	{
		if (ptr->type > 2)
		{
			if (!fifo && (ptr->type == 3 || ptr->type == 6))
			{
				node->in = del_redir(node->in);
				node->in = new_redir(ptr, node);
				break ;
			}
			else if (fifo && (ptr->type == 4 || ptr->type == 5))
			{
				node->out = del_redir(node->out);
				node->out = new_redir(ptr, node);
			}
		}
		ptr = ptr->next;
	}
}

// Initializes new redirection node
t_redir	*new_redir(t_dlist *token, t_ast *node)
{
	int		i;
	t_redir	*new;
	t_dlist	*ptr;

	ptr = token->next;
	new = malloc(sizeof(t_redir));
	if (!new)
		return (NULL);
	new->fd = -1;
	new->type = token->type;
	new->filename = malloc(sizeof(char *) * (filename_size(ptr) +1));
	if (!new->filename)
		return (NULL);
	i = 0;
	while (ptr && ptr->type == 1)
	{
		new->filename[i++] = ptr->content;
		ptr = ptr->next;
	}
	new->filename[i] = NULL;
	open_fds(node, new);
	return (new);
}

// Deletes redirection node
t_redir	*del_redir(t_redir *redir)
{
	if (redir)
	{
		if (redir->fd > 2)
			close(redir->fd);
		if (redir->filename)
			free(redir->filename);
		free(redir);
	}
	return (NULL);
}
