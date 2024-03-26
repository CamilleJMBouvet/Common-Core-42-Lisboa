/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:25:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 14:38:24 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// Sends to variable format check, adds to env + adds to export list
void	builtin_export(t_ast *node)
{
	int		i;
	int		format;
	char	**new_env;

	i = 1;
	new_env = NULL;
	if (!node->args[i])
	{
		print_export(node);
		return ;
	}
	if (is_pipe())
		return ;
	while (node->args[i])
	{
		format = valid_identifier(node->args[i]);
		if (format == 2)
			new_env = update_env(new_env, node->args[i]);
		if (format > 0)
			edit_export(node->args[i], 0);
		i++;
	}
	cpy_env(new_env);
	shell_reboot();
}

// Prints export list
void	print_export(t_ast *node)
{
	t_dlist	*ptr;

	ptr = var()->exp;
	while (ptr)
	{
		fd_printf(node->in_out[1], "%s\n", ptr->content);
		ptr = ptr->next;
	}
}

// Checks if the provided variable name is valid
int	valid_identifier(char *arg)
{
	int		format;
	char	*key;

	format = 2;
	if (first_occur(arg, '=') == -1)
	{
		format = 1;
		key = ft_strdup(arg);
	}
	else
		key = ft_substr(arg, 0, first_occur(arg, '='));
	if (!valid_keyname(key))
	{
		fd_printf(2, "export: '%s': not a valid identifier\n", key);
		set_exit(1, 1);
		format = 0;
	}
	free(key);
	return (format);
}

// Updates environment variables + reboots
char	**update_env(char **new_env, char *arg)
{
	int		index;
	char	*key;

	key = ft_substr(arg, 0, first_occur(arg, '=') + 1);
	index = find_index(key);
	if (index != -1)
		var()->env[index] = arg;
	else
		new_env = add_env(new_env, arg);
	free(key);
	return (new_env);
}

// Edits export list to add, update or remove existing variables
void	edit_export(char *arg, int flag)
{
	int		eq;
	t_dlist	*ptr;

	ptr = var()->exp;
	eq = first_occur(arg, '=');
	if (eq == -1)
		eq = ft_strlen(arg);
	while (ptr)
	{
		if (!ft_strncmp(arg, &ptr->content[11], eq) && \
			(!ptr->content[11 + eq] || ptr->content[11 + eq] == '='))
		{
			if (!flag)
			{
				free(ptr->content);
				ptr->content = export_str(arg);
			}
			else
				rm_dlist(&var()->exp, ptr);
			return ;
		}
		ptr = ptr->next;
	}
	if (!flag)
		addascii_dlist(&var()->exp, new_dlist_node(export_str(arg), -1));
}
