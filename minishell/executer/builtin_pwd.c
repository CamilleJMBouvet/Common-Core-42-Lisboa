/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:24:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 14:38:04 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// Retrieves pwd + prints it
void	builtin_pwd(t_ast *node)
{
	char	buff[VAR_LEN];

	ft_bzero(buff, VAR_LEN);
	getcwd(buff, VAR_LEN);
	if (!buff[0])
	{
		fd_printf(2, "Error: pwd: %s\n", strerror(errno));
		set_exit(errno, 1);
	}
	else
	{
		fd_printf(node->in_out[1], "%s\n", buff);
		set_exit(0, 1);
	}
}
