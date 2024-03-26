/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:32:30 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 14:34:10 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

// Iterates through input + sends to word or operator tokenizers
int	token_init(void)
{
	int	i;

	i = 0;
	while (var()->input[i])
	{
		if (!is_ifs(var()->input[i]) && !is_op(var()->input[i]))
		{
			i = tokenize_word(i) - 1;
			if (i < 0)
			{
				free_dlist(&var()->tokens);
				return (-1);
			}
		}
		else if (is_op(var()->input[i]))
			i = tokenize_op(i) - 1;
		i++;
	}
	if (!var()->tokens || !tok_err())
		return (-1);
	return (0);
}

// Creates token for word
int	tokenize_word(int start)
{
	int		end;
	char	*tmp;
	char	*new;
	t_dlist	*last;

	end = find_token_end(start);
	if (end < 0)
		return (end);
	tmp = ft_substr(var()->input, start, end - start);
	new = send_exp(tmp, 0, 1);
	last = last_tok();
	while (last && last != start_segment(last_tok(), 1) && last->type != 0)
		last = last->prev;
	if (((last_tok() && last_tok()->type < 3) || (!last_tok())) \
		&& first_occur(tmp, '$') != -1 && new && new[0] && tmp[0] != '"' \
		&& (!last || last->type == 2))
		expanded_cmd(new);
	else
		addback_dlist(&var()->tokens, new_dlist_node(new, 0));
	free(tmp);
	return (end);
}

// Creates token for operator
int	tokenize_op(int start)
{
	int	end;

	end = start +1;
	if ((var()->input[start] == '>' && var()->input[start +1] == '>') \
		|| (var()->input[start] == '<' && var()->input[start +1] == '<'))
		end++;
	addback_dlist(&var()->tokens, new_dlist_node(ft_substr(var()->input, \
		start, end - start), 1));
	return (end);
}

// Finds token limits while checking for quotes
int	find_token_end(int start)
{
	int		i;
	char	quote;

	i = start;
	quote = 0;
	while (var()->input[i])
	{
		quote = quote_status(quote, var()->input[i]);
		if (!quote && (is_ifs(var()->input[i]) || is_op(var()->input[i])))
			return (i);
		i++;
	}
	if (quote)
	{
		fd_printf(2, "Error: unclosed quote\n");
		set_exit(1, 1);
		return (-1);
	}
	return (i);
}

// Tokenizes an expanded variable passed in cmd position
void	expanded_cmd(char *new)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (new[i])
	{
		if (!new[i +1] || is_ifs(new[i +1]))
		{
			i++;
			addback_dlist(&var()->tokens, \
			new_dlist_node(ft_substr(new, start, i - start), 0));
			start = i +1;
			if (!new[i] || !new[start])
				break ;
		}
		i++;
	}
	free(new);
}
