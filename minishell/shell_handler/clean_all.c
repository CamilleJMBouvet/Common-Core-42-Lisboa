/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:37:31 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/15 21:58:38 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_handler.h"

// Sends to frees according to code
void	clean_all(int code)
{
	close_fds(0, 1);
	if (var()->input)
		free(var()->input);
	if (var()->tokens)
		free_dlist(&var()->tokens);
	if (var()->ast)
		free_ast(&var()->ast);
	if (code == 1)
	{
		if (var()->hist)
			free_dlist(&var()->hist);
		if (var()->exp)
			free_dlist(&var()->exp);
		rl_clear_history();
	}
}

// Frees dlist lists
void	free_dlist(t_dlist **dlist)
{
	t_dlist	*ptr;

	if (!*dlist)
		return ;
	ptr = *dlist;
	while (*dlist)
	{
		ptr = (*dlist)->next;
		free((*dlist)->content);
		free(*dlist);
		*dlist = ptr;
	}
}

// Frees AST
void	free_ast(t_ast **ast)
{
	t_ast	*ptr;

	if (!ast)
		return ;
	ptr = *ast;
	while (*ast)
	{
		ptr = (*ast)->next;
		if ((*ast)->args)
			free((*ast)->args);
		if ((*ast)->in)
		{
			free((*ast)->in->filename);
			free((*ast)->in);
		}
		if ((*ast)->out)
		{
			free((*ast)->out->filename);
			free((*ast)->out);
		}
		free(*ast);
		*ast = ptr;
	}
}

// Frees **arrays
void	free_matrix(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		if (args[i])
			free(args[i]);
		i++;
	}
	free(args);
}

// Closes all fds unequal to in/out & superior to 2
void	close_fds(int in, int out)
{
	t_ast	*node;

	node = var()->ast;
	if (!node)
		return ;
	while (node)
	{
		if (node->in && node->in->fd != in && node->in->fd > 2)
			close(node->in->fd);
		if (node->pipe[0] != in && node->pipe[0] > 2)
			close(node->pipe[0]);
		if (node->in_out[0] != in && node->in_out[0] > 2)
			close(node->in_out[0]);
		if (node->out && node->out->fd != out && node->out->fd > 2)
			close(node->out->fd);
		if (node->pipe[1] != out && node->pipe[1] > 2)
			close(node->pipe[1]);
		if (node->in_out[1] != out && node->in_out[1] > 2)
			close(node->in_out[1]);
		node = node->next;
	}
}
