/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:20:32 by cbouvet           #+#    #+#             */
/*   Updated: 2023/10/30 20:41:04 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// Main
int	main(int ac, char **av, char **env)
{
	static t_data	var;

	if (ac < 5)
	{
		ft_putstr_fd("Error: Insufficient arg number\n", 2);
		exit(EXIT_FAILURE);
	}
	init_struct(ac, av, env, &var);
	cmd_exec(env, &var);
	clean_exit(0, NULL, &var);
}

// Initialise the variable in struct
void	init_struct(int ac, char **av, char **env, t_data *var)
{
	var->ac = ac;
	var->cpid = malloc(sizeof(int) * ac -3);
	if (!var->cpid)
		clean_exit(1, "Malloc", var);
	pipe_arr(ac, av, var);
	store_cmds(av, var);
	store_paths(env, var);
	store_cmdpath(var);
}
