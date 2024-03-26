/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:01:34 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 14:28:13 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

// Sends chunks of quoted/unquoted str to get expanded
char	*send_exp(char *str, char quote, int i)
{
	int		j;
	int		start;
	char	tmp[1][VAR_LEN];
	char	*new;

	ft_bzero(*tmp, VAR_LEN);
	j = 0;
	start = 0;
	quote = str[0];
	ft_bzero(tmp, VAR_LEN -1);
	while (i <= (int)ft_strlen(str))
	{
		i = find_quote_end(str, start, quote);
		j = expan(&str[start], tmp, j, i - start);
		start = i;
		quote = str[i];
		i++;
	}
	if (!tmp[0][0] && (str[0] == '"'))
		return (ft_strdup(""));
	else if (!tmp[0][0] && str[0] != '"')
		return (NULL);
	new = ft_strdup(tmp[0]);
	return (new);
}

// Copies result of expansion into str
int	expan(char *str, char tmp[1][VAR_LEN], int j, int end)
{
	int		i;
	char	*value;

	i = 0;
	if (is_quote(str[0]))
	{
		i++;
		end--;
	}
	while (str[i] && i < end)
	{
		if (dollar_sign(str, i, end, str[0]) != -1)
		{
			value = get_var(str, i +1, \
				dollar_sign(str, i, end, str[0]), str[0]);
			if (value && value[0])
				j = ft_strlcat(tmp[0], value, VAR_LEN);
			free(value);
			i = dollar_sign(str, i, end, str[0]);
			continue ;
		}
		tmp[0][j++] = str[i++];
	}
	return (j);
}

// Reviews if conditions for expansion are met
int	dollar_sign(char *str, int i, int end, char quote)
{
	if (str[i] != '$' || quote == '\'' || \
		(last_tok() && last_tok()->type == 6))
		return (-1);
	i++;
	if (!str[i] || (!is_quote(str[i]) && !ft_isalnum(str[i]) \
		&& str[i] != '_' && str[i] != '?'))
		return (-1);
	if (is_quote(str[i]) && !is_quote(quote))
		return (i);
	else if (is_quote(str[i]) && is_quote(quote))
		return (-1);
	if (ft_isdigit(str[i]) || str[i] == '?')
		return (i +1);
	while (str[i] && i < end)
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (i);
		i++;
	}
	return (i);
}

// Expands to exit status or env variables
char	*get_var(char *str, int i, int end, char quote)
{
	char	*key;
	char	*value;
	char	*new;

	if (str[i] == '?')
		return (ft_itoa(set_exit(0, 0)));
	key = ft_substr(str, i, end - i);
	value = getenv(key);
	free(key);
	if (!value)
		return (NULL);
	new = ft_strdup(value);
	if (!is_quote(quote))
		new = space_rm(new);
	return (new);
}

// Removes space from expanded variable
char	*space_rm(char *value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (value[i])
	{
		if (is_ifs(value[i]))
		{
			while (is_ifs(value[i]))
				i++;
			i--;
		}
		value[j++] = value[i++];
	}
	value[j] = 0;
	return (value);
}
