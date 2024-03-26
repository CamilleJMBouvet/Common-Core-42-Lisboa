/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reboot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:13:12 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 15:31:34 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_handler.h"

// Prepares env variable for reboot
void	shell_reboot(void)
{
	int		i;
	int		index;
	char	*new_env[VAR_LEN];
	char	stack_env[100][VAR_LEN];

	i = 0;
	index = index_nb(var()->env);
	while (i < index +1)
	{
		ft_bzero(stack_env[i], VAR_LEN);
		if (i < index)
			ft_strlcpy(stack_env[i], var()->env[i], VAR_LEN);
		i++;
	}
	free_matrix(var()->env);
	i = 0;
	while (i < index && stack_env[i][0] != 0)
	{
		new_env[i] = stack_env[i];
		i++;
	}
	new_env[i] = NULL;
	launch_reboot(new_env);
}

// Prepares args for reboot + launches reboot
void	launch_reboot(char **new_env)
{
	int		i;
	char	*new_args[VAR_LEN];

	i = 0;
	while (i < 7 && var()->pgr[i][0])
	{
		new_args[i] = var()->pgr[i];
		i++;
	}
	new_args[i] = NULL;
	write_config();
	clean_all(1);
	if (execve(var()->pgr[0], new_args, new_env) == -1)
		reboot_err(errno);
}

// Writes configuration file to be retrieved by reboot
void	write_config(void)
{
	int		config_fd;
	char	*config_file;
	t_dlist	*ptr;

	config_file = ft_strjoin(var()->shell_path, CONFIG);
	config_fd = open(config_file, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	free(config_file);
	if (config_fd < 0)
		return ;
	fd_printf(config_fd, "%i\n", set_exit(0, 0));
	ptr = var()->hist;
	while (ptr)
	{
		fd_printf(config_fd, "%s\n", ptr->content);
		ptr = ptr->next;
	}
	fd_printf(config_fd, "%c\n", (char)-1);
	ptr = var()->exp;
	while (ptr)
	{
		fd_printf(config_fd, "%s\n", ptr->content);
		ptr = ptr->next;
	}
	close (config_fd);
}

// Handles reboot error
void	reboot_err(int error)
{
	char	*config_file;

	if (error >= 0)
		return ;
	fd_printf(2, "couldn't update shell env\n");
	config_file = ft_strjoin(var()->shell_path, CONFIG);
	unlink(config_file);
	free(config_file);
	set_exit(errno, 1);
	exit (set_exit(0, 0));
}
