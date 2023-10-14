/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:51:49 by cbouvet           #+#    #+#             */
/*   Updated: 2023/10/06 23:13:01 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int ac, char **av)
{
	static t_fract		fct;

	if (param_check(ac, av))
	{
		init_display(&fct);
		init_image(&fct);
		init_fract(av, &fct);
		fractal_maker(&fct);
		mlx_hook(fct.win, 17, 0, x_click, &fct);
		mlx_hook(fct.win, 2, 1L << 0, key_event, &fct);
		mlx_hook(fct.win, 4, 1L << 2, mouse_scroll, &fct);
		mlx_loop(fct.mlx);
	}
}
