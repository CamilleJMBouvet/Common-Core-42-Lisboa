/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:19:06 by cbouvet           #+#    #+#             */
/*   Updated: 2023/10/09 17:05:47 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// Starts the graphical context
void	init_display(t_fract *fct)
{
	fct->mlx = mlx_init();
	if (!fct->mlx)
	{
		free(fct->mlx);
		ft_putstr_fd("mlx_init() malloc error\n", 2);
	}
	fct->win = mlx_new_window(fct->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!fct->win)
	{
		free(fct->mlx);
		free(fct->win);
		ft_putstr_fd("mlx_new_window malloc error\n", 2);
	}
}

// Init the image
void	init_image(t_fract *fct)
{
	fct->img = mlx_new_image(fct->mlx, WIDTH, HEIGHT);
	if (!fct->img)
	{
		free(fct->mlx);
		free(fct->win);
		free(fct->img);
		ft_putstr_fd("mlx_new_image malloc error\n", 2);
	}
	fct->addr = NULL;
	fct->bit_pix = sizeof(int);
	fct->line_len = WIDTH;
}

// Init the fractal-related values
void	init_fract(char **av, t_fract *fct)
{
	if (is_mandel(av[1]))
	{
		fct->set = 'M';
		fct->real = 0.0;
		fct->imag = 0.0;
	}
	else if (is_julia(av[1]))
	{
		fct->set = 'J';
		fct->real = atod(av[2], 0.0);
		fct->imag = atod(av[3], 0.0);
	}
	fct->r_min = -2.0;
	fct->r_max = 2.0;
	fct->i_min = -2.0;
	fct->i_max = 2.0;
	fct->zoom = 1;
	fct->iter = 50;
	fct->shading = 10000;
}
