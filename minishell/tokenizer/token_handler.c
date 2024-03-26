/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:52:05 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/15 19:26:54 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

// Returns last token
t_dlist	*last_tok(void)
{
	t_dlist	*last;

	if (!var()->tokens)
		return (NULL);
	last = var()->tokens;
	while (last->next)
		last = last->next;
	return (last);
}

// Returns first token of segment
t_dlist	*start_segment(t_dlist *token, int flag)
{
	t_dlist	*start;

	if (!token || !var()->tokens)
		return (NULL);
	start = token;
	while (start->prev && start->prev->type != 2)
		start = start->prev;
	if (flag == 1)
		start = start->prev;
	if (!start)
		return (NULL);
	return (start);
}

// Returns last token of segment
t_dlist	*end_segment(t_dlist *token)
{
	t_dlist	*end;

	if (!token || !var()->tokens)
		return (NULL);
	end = token;
	while (end && end->type != 2)
		end = end->next;
	if (!end)
		return (NULL);
	return (end);
}

// Retrieves token type according to op flag & token placement
t_etype	get_type(char *content, int op)
{
	if (op == 1)
	{
		if (ft_strncmp(content, "|", ft_strlen(content) + 1) == 0)
			return (AST_PIPE);
		else if (ft_strncmp(content, "<", ft_strlen(content) + 1) == 0)
			return (AST_REDIR_IN);
		else if (ft_strncmp(content, ">", ft_strlen(content) + 1) == 0)
			return (AST_REDIR_OUT);
		else if (ft_strncmp(content, ">>", ft_strlen(content) + 1) == 0)
			return (AST_REDIR_APPEND);
		else if (ft_strncmp(content, "<<", ft_strlen(content) + 1) == 0)
			return (AST_REDIR_HEREDOC);
	}
	if (!var()->tokens || content[0] == '-')
		return (AST_COMMAND);
	if (last_tok()->type < 3)
	{
		if (last_tok()->type == 2 || last_tok()->type == 0 || \
			start_segment(last_tok(), 0)->type != 0)
			return (AST_COMMAND);
	}
	return (AST_FILE);
}

// Detects syntax errors for operators
int	tok_err(void)
{
	int		i;
	char	*err;
	t_dlist	*ptr;

	i = 0;
	ptr = var()->tokens;
	err = "Syntax error near unexpected token";
	while (ptr)
	{
		if (ptr->type > 1)
		{
			if (ptr->type == 2 && (!ptr->prev || !ptr->next))
				i = fd_printf(2, "%s '%s'\n", err, ptr->content);
			else if (!ptr->next || (ptr->next && ((ptr->type == 3 && \
				ptr->next->type == 4))))
				i = fd_printf(2, "%s 'newline'\n", err);
			else if (ptr->type != 2 && ptr->next && ptr->next->type > 1)
				i = fd_printf(2, "%s '%s'\n", err, ptr->next->content);
			if (i)
				return (0);
		}
		ptr = ptr->next;
	}
	return (1);
}
