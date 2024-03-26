/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 00:53:57 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/14 01:11:58 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// Checks if keyname has a valid format
int	valid_keyname(char *key)
{
	int	i;

	if (key[0] != '_' && !ft_isalpha(key[0]))
		return (0);
	i = 1;
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

// Finds at what index of env is key located
int	find_index(char *key)
{
	int	i;

	i = 0;
	while (var()->env[i])
	{
		if (!ft_strncmp(key, var()->env[i], ft_strlen(key)))
			return (i);
		i++;
	}
	return (-1);
}

// Adds a new value to an array
char	**add_env(char **new_env, char *arg)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = malloc(sizeof(char *) * (index_nb(new_env) +2));
	if (!tmp)
		return (NULL);
	if (new_env)
	{
		while (new_env[i])
		{
			tmp[i] = new_env[i];
			i++;
		}
		free(new_env);
	}
	tmp[i++] = ft_strdup(arg);
	tmp[i] = NULL;
	return (tmp);
}

// Copies env vars + new vars to **array, then assign it to var()->env
void	cpy_env(char **new_env)
{
	int		i;
	int		size;
	char	**tmp;

	i = 0;
	size = index_nb(new_env);
	if (!new_env)
		size = 0;
	tmp = malloc(sizeof(char *) * (index_nb(var()->env) + size +1));
	while (var()->env[i])
	{
		tmp[i] = ft_strdup(var()->env[i]);
		i++;
	}
	size = 0;
	if (new_env)
		while (new_env[size])
			tmp[i++] = new_env[size++];
	tmp[i] = NULL;
	var()->env = tmp;
}
