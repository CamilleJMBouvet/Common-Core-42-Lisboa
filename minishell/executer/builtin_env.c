/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:25:14 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 14:38:35 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// Prints env + any argument that contains a '='
void	builtin_env(t_ast *node)
{
	int	i;

	i = 1;
	while (node->args[i])
	{
		if (first_occur(node->args[i], '=') == -1)
		{
			fd_printf(2, "'%s': No such file or directory\n", node->args[i]);
			set_exit(1, 1);
			return ;
		}
		i++;
	}
	i = 0;
	while (var()->env[i])
		fd_printf(node->in_out[1], "%s\n", var()->env[i++]);
	i = 1;
	while (node->args[i])
		fd_printf(node->in_out[1], "%s\n", node->args[i++]);
}
