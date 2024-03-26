/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:03:24 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/13 03:26:16 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_handler.h"

// Set path to directory + sets reboot programme name
void	set_basic_vars(char **av)
{
	int		vlgr;
	int		reboot;
	char	buff[VAR_LEN];

	reboot = 0;
	if (av[0][0] != '.' && av[0][1] != '/')
		reboot++;
	if (!reboot)
	{
		ft_bzero(buff, VAR_LEN);
		getcwd(buff, VAR_LEN);
		ft_strlcpy(var()->shell_path, buff, ft_strlen(buff) + 1);
	}
	else
		ft_strlcpy(var()->shell_path, av[0], ft_strlen(av[0]) - 9);
	vlgr = vlgr_launch(av);
	if (!reboot && !vlgr)
	{
		ft_strlcpy(var()->pgr[0], var()->shell_path, VAR_LEN);
		ft_strlcat(var()->pgr[0], &av[0][1], VAR_LEN);
	}
	else if (reboot && !vlgr)
		ft_strlcpy(var()->pgr[0], av[0], ft_strlen(av[0]) + 1);
	if (vlgr)
		set_vlgr_vars();
}

// Checks if programme was launched with valgrind (extra feature for eval ease)
int	vlgr_launch(char **av)
{
	int		vlgr;
	char	*readline_supp;

	vlgr = 0;
	readline_supp = ft_strjoin(var()->shell_path, RDL_SUPPR);
	if (access(readline_supp, F_OK) >= 0 && \
		(av[1] && ft_strncmp(av[1], "valgrind", 10) == 0))
		vlgr++;
	free(readline_supp);
	return (vlgr);
}

// Sets future reboots with valgrind if shell was launched with valgrind
void	set_vlgr_vars(void)
{
	ft_strlcpy(var()->pgr[0], "/usr/bin/valgrind", 19);
	ft_strlcpy(var()->pgr[1], "--leak-check=full", 19);
	ft_strlcpy(var()->pgr[2], "--show-leak-kinds=all", 23);
	ft_strlcpy(var()->pgr[3], "--track-fds=yes", 17);
	ft_strlcpy(var()->pgr[4], "--suppressions=", 17);
	ft_strlcat(var()->pgr[4], var()->shell_path, VAR_LEN);
	ft_strlcat(var()->pgr[4], RDL_SUPPR, VAR_LEN);
	ft_strlcpy(var()->pgr[5], var()->shell_path, VAR_LEN);
	ft_strlcat(var()->pgr[5], "/minishell", 1000);
	ft_strlcpy(var()->pgr[6], "valgrind", 10);
}
