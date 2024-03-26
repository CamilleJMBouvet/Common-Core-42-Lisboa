/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_n_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:06:52 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/14 00:59:17 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_handler.h"

// Trims commands of residues, adds it to history + hist list
void	add_hist(char *cmd)
{
	char	*clean_cmd;

	if (!cmd)
		return ;
	if (cmd[ft_strlen(cmd) - 1] == '\n')
		cmd[ft_strlen(cmd) - 1] = 0;
	clean_cmd = ft_strdup(cmd);
	add_history(clean_cmd);
	addback_dlist(&var()->hist, new_dlist_node(clean_cmd, -1));
}

// Counts number of commands placed
int	count_hist(void)
{
	int		i;
	t_dlist	*ptr;

	i = 0;
	if (!var()->hist)
		return (0);
	ptr = var()->hist;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

// Adds env variables to export linked list
void	set_export(char *config_file)
{
	int		i;

	if ((find_index("OLDPWD=") == -1) && !var()->exp)
		addascii_dlist(&var()->exp, new_dlist_node(export_str("OLDPWD"), -1));
	if (config_file)
		return ;
	i = 0;
	while (var()->env[i])
		addascii_dlist(&var()->exp, \
		new_dlist_node(export_str(var()->env[i++]), -1));
}

// Creates export string with adequate format
char	*export_str(char *str)
{
	int		eq;
	char	*tmp1;
	char	*tmp2;
	char	*decl_x;

	if (ft_strncmp(str, "_=", 2) == 0)
		return (NULL);
	decl_x = "declare -x ";
	eq = first_occur(str, '=');
	if (eq == -1)
		return (ft_strjoin(decl_x, str));
	tmp1 = ft_substr(str, 0, eq +1);
	tmp2 = ft_strjoin(decl_x, tmp1);
	free(tmp1);
	tmp1 = ft_strjoin(tmp2, "\"");
	free(tmp2);
	tmp2 = ft_strjoin(tmp1, &str[eq +1]);
	free (tmp1);
	tmp1 = ft_strjoin(tmp2, "\"");
	free(tmp2);
	return (tmp1);
}

// Finds 1st occurence of a specified char, returns index
int	first_occur(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (i == (int)ft_strlen(str) && str[i -1] != c)
		return (-1);
	return (i);
}
