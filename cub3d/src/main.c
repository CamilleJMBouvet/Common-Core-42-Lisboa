/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:07 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/14 19:14:46 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Static struct containing all useful variables
t_var	*var(void)
{
	static t_var	var;

	return (&var);
}

// Main
int	main(int ac, char **av)
{
	if (ac != 2)
		clean_exit(PARAM_NB, 1);
	var()->mlx = mlx_init();
	if (!var()->mlx)
		clean_exit(WIN_ERR, 3);
	parser(av);
	init_player(var()->map.cmap);
	init_display(&var()->disp_2d, 0, "cub2d");
	init_display(&var()->disp_3d, 1, "cub3d");
	if (var()->disp_2d.win)
		cub2d_maker(var()->map.cmap);
	cub3d_maker(&var()->player);
	mlx_loop_hook(var()->mlx, hooks_handler, NULL);
	mlx_loop(var()->mlx);
	clean_exit(NULL, 0);
}
