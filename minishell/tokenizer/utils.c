/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:22:44 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/08 16:46:44 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

// Checks if char is an Internal Field Separator
int	is_ifs(char c)
{
	if (c == 9 || c == 10 || c == 32 || c == 0)
		return (1);
	return (0);
}

// Checks if char is an Operator
int	is_op(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

// Checks if char is quote
int	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

// Changes quote value according to quote found and previous quote status
char	quote_status(char quote, char c)
{
	if (c && is_quote(c))
	{
		if (!quote)
			quote = c;
		else if (quote && quote == c)
			quote = 0;
	}
	return (quote);
}

// Finds end of quoted/unquoted segment
int	find_quote_end(char *str, int i, char quote)
{
	if (is_quote(quote))
	{
		i++;
		while (str[i] && str[i] != quote)
			i++;
		i++;
	}
	else
		while (str[i] && !is_quote(str[i]))
			i++;
	return (i);
}
