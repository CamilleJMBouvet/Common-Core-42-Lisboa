/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:05:34 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/14 01:05:44 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_handler.h"

// Adds all env variables to main structure for easier access
void	set_env(char **env, char *config_file, int env_i)
{
	int	i;

	i = 0;
	var()->env = env;
	if (env_i)
	{
		var()->env = malloc(sizeof(char *) * 3);
		if (!var()->env)
			return ;
		while (i < 2)
		{
			var()->env[i] = malloc(sizeof(char) * VAR_LEN);
			if (!var()->env[i])
				return ;
			ft_bzero(var()->env[i], VAR_LEN);
			i++;
		}
		ft_strlcpy(var()->env[0], "PWD=", ft_strlen("PWD=") + 1);
		ft_strlcpy(var()->env[1], "SHLVL=1", ft_strlen("SHLVL=1") + 1);
		var()->env[2] = NULL;
	}
	set_shlvl(config_file, env_i);
	edit_start_env(env_i);
}

// Edits shell lvl depending on case
void	set_shlvl(char *config_file, int env_i)
{
	int		lvl;
	int		index;
	char	*tmp;

	if (config_file || env_i)
		return ;
	index = find_index("SHLVL=");
	if (index == -1 || ft_strncmp(getenv("SHELL"), "GC-Shell", 13) \
		|| config_file)
		return ;
	lvl = ft_atoi(&var()->env[index][6]) + 1;
	tmp = ft_itoa(lvl);
	ft_strlcpy(&var()->env[index][6], tmp, ft_strlen(tmp) +1);
	free(tmp);
}

// Adds pwd to env -i env variable, add Shell name to non env -i shell
void	edit_start_env(int env_i)
{
	int	index;

	index = find_index("SHELL=");
	if (index != -1)
		ft_strlcpy(&var()->env[find_index("SHELL=")][6], "GC-Shell", 10);
	if (env_i)
		ft_strlcpy(&var()->env[0][4], var()->shell_path, VAR_LEN);
}

// Returns nb of indexes of a **array
int	index_nb(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}
