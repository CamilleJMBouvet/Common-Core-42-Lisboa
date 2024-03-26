/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:24:53 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 14:39:09 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// Checks for errors, changes dir, updates env variables
void	builtin_cd(t_ast *node)
{
	if (cd_errors(node))
		return ;
	if (!node->args[1])
		chdir(getenv("HOME"));
	else
		chdir(node->args[1]);
	if (errno)
	{
		perror("cd");
		set_exit(1, 1);
		return ;
	}
	edit_pwd_oldpwd();
}

// Checks for errors + prints error messages + updates exstat
int	cd_errors(t_ast *node)
{
	if (!node->args[1] && !getenv("HOME"))
	{
		fd_printf(2, "cd: HOME not set\n");
		set_exit(1, 1);
		return (1);
	}
	if (index_nb(node->args) > 2)
	{
		fd_printf(2, "cd: too many arguments\n");
		set_exit(1, 1);
		return (1);
	}
	return (0);
}

// Updates values of PWD and OLDPWD to match current location
void	edit_pwd_oldpwd(void)
{
	char	*pwd;
	char	*oldpwd;
	char	buff[VAR_LEN];
	char	**new_env;

	new_env = NULL;
	pwd = getenv("PWD");
	if (!pwd)
		pwd = "";
	oldpwd = ft_strjoin("OLDPWD=", pwd);
	new_env = update_env(new_env, oldpwd);
	edit_export(oldpwd, 0);
	getcwd(buff, VAR_LEN);
	pwd = ft_strjoin("PWD=", buff);
	new_env = update_env(new_env, pwd);
	edit_export(pwd, 0);
	cpy_env(new_env);
	free(oldpwd);
	free(pwd);
	shell_reboot();
}
