/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:45:47 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/18 21:39:51 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

// Builds AST based on token type + position
void	ast_builder(void)
{
	int		sgmt;
	t_dlist	*ptr;

	sgmt = 0;
	ptr = var()->tokens;
	insert_lone_node(NULL);
	while (ptr)
	{
		if ((ptr->type == 0 && !sgmt) || ptr->type == 2)
		{
			if (ptr->type == 2)
				sgmt = 0;
			if (ptr->type == 0)
				sgmt = 1;
			insert_node(new_node(ptr, 1));
			if (last_node() && last_node()->type == 2)
				insert_lone_node(ptr);
		}
		ptr = ptr->next;
	}
}

// Initializes new node + its values according to type + flag
t_ast	*new_node(t_dlist *token, int flag)
{
	t_ast	*new;

	new = malloc(sizeof(t_ast));
	if (!new)
		return (NULL);
	if (!flag)
	{
		new->type = ERR;
		new->value = NULL;
	}
	else
	{
		new->type = token->type;
		new->value = token->content;
	}
	flag = init_fds(token, new, flag);
	make_args(token, new, flag);
	new->pid = -1;
	new->in_out[0] = STDIN_FILENO;
	new->in_out[1] = STDOUT_FILENO;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

// Fetches last node of AST
t_ast	*last_node(void)
{
	t_ast	*last;

	if (!var()->ast)
		return (NULL);
	last = var()->ast;
	while (last->next)
		last = last->next;
	return (last);
}

// Inserts new node into AST
void	insert_node(t_ast *new)
{
	t_ast	*ptr;

	if (new->type == ERR)
	{
		if (new->in)
			new->in = del_redir(new->in);
		if (new->out)
			new->out = del_redir(new->out);
	}
	if (var()->ast && !var()->ast->value)
	{
		free(var()->ast);
		var()->ast = NULL;
	}
	if (!var()->ast)
	{
		var()->ast = new;
		return ;
	}
	ptr = last_node();
	ptr->next = new;
	new->prev = ptr;
}

// Inserts NULL node for void commands with redirections
void	insert_lone_node(t_dlist *token)
{
	t_dlist	*ptr;

	if (!token)
	{
		token = var()->tokens;
		if (token->type == 0)
			return ;
	}
	ptr = token;
	if (token->type == 2)
		ptr = token->next;
	while (ptr && ptr != end_segment(token))
	{
		if (ptr->type == 0)
			return ;
		ptr = ptr->next;
	}
	insert_node(new_node(token, 0));
}
