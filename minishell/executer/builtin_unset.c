/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:25:09 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/14 01:48:52 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// Removes existing variables from env & export
void	builtin_unset(t_ast *node)
{
	int		i;
	char	*key;

	i = 1;
	if (!node->args[i][0] || is_pipe())
		return ;
	while (node->args[i])
	{
		key = ft_strjoin(node->args[i], "=");
		if (getenv(node->args[i]) || find_index(key) != -1)
			var()->env[find_index(key)][0] = -10;
		edit_export(node->args[i], 1);
		free(key);
		i++;
	}
	if (remove_vars())
		shell_reboot();
}

// Removes unset variables from env array
int	remove_vars(void)
{
	int		i;
	int		size;
	char	**tmp;

	i = 0;
	size = 0;
	while (var()->env[i])
		if (var()->env[i++][0] == -10)
			size++;
	if (!size)
		return (0);
	tmp = malloc(sizeof(char *) * (index_nb(var()->env) - size +1));
	if (!tmp)
		return (0);
	i = 0;
	size = 0;
	while (var()->env[i])
	{
		if (var()->env[i][0] != -10)
			tmp[size++] = ft_strdup(var()->env[i]);
		i++;
	}
	tmp[size] = NULL;
	var()->env = tmp;
	return (1);
}
