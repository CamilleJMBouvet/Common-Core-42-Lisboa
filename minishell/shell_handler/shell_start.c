/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:47:27 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 14:34:55 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_handler.h"

// Sets shell up depending of reboot, env -i and valgrind status
void	shell_start(char **av, char **env)
{
	int		env_i;
	char	*config_file;

	env_i = 0;
	if (!env || !env[0])
		env_i++;
	set_basic_vars(av);
	config_file = check_config();
	set_config(config_file);
	set_env(env, config_file, env_i);
	set_export(config_file);
	if (!config_file)
		printf("%s\033[1;37mWELCOME\033[0m\033%s\n", LINE, LINE);
	else
		free(config_file);
	if (env_i)
		shell_reboot();
}

// Check if shell is a reboot -> AKA if a config file exists
char	*check_config(void)
{
	char	*config_file;

	config_file = ft_strjoin(var()->shell_path, CONFIG);
	if (access(config_file, F_OK) == 0)
		return (config_file);
	free (config_file);
	return (NULL);
}

// Retrieves data from previous boot through config file
void	set_config(char *config_file)
{
	int		config_fd;
	char	*line;

	if (!config_file)
		return ;
	config_fd = open(config_file, O_RDONLY);
	if (config_fd < 0)
		return ;
	line = get_next_line(config_fd);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = 0;
	set_exit(ft_atoi(line), 1);
	free (line);
	line = "tmp";
	dlist_config(line, config_fd, 1);
	dlist_config(line, config_fd, 0);
	close(config_fd);
	unlink(config_file);
}

// Fills up hist & exp with data from last reboot
void	dlist_config(char *line, int config_fd, char flag)
{
	line = "tmp";
	while (line)
	{
		line = get_next_line(config_fd);
		if (!line || line[0] == (char)-1)
		{
			if (line)
				free (line);
			return ;
		}
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		if (flag)
			add_hist(line);
		else
			addback_dlist(&var()->exp, new_dlist_node(ft_strdup(line), -1));
		free (line);
	}
}
