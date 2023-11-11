/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:51:44 by cbouvet           #+#    #+#             */
/*   Updated: 2023/10/30 19:56:19 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// -LIBRARIES-
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>

// -STRUCTS-
typedef struct s_data
{
	int		ac;
	int		*cpid;
	int		**pipe_fd;
	char	***cmds;
	char	**env_path;
	char	**cmd_path;
}	t_data;

// -FUNCTIONS-
//Init
void	init_struct(int ac, char **av, char **env, t_data *var);
void	pipe_arr(int ac, char **av, t_data *var);
void	store_cmds(char **av, t_data *var);
void	store_paths(char **env, t_data *var);
void	store_cmdpath(t_data *var);
char	*find_cmd(char *cmd, t_data var);

//Command execution
void	cmd_exec(char **env, t_data *var);
void	child_process(int i, char **env, t_data *var);
void	close_unused_fds(int i_fd, int o_fd, t_data *var);

//Error management
void	clean_exit(int err, char *msg, t_data *var);
void	err_message(int err, char *msg);
void	free_all(t_data *var);
void	free_matrix(char **matrix);
void	close_all(t_data *var);

#endif
