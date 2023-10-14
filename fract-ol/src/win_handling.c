/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:54:41 by cbouvet           #+#    #+#             */
/*   Updated: 2023/10/09 17:07:56 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// Applies the fractal formulas to each pixel and creates the display
void	fractal_maker(t_fract *fct)
{
	int	x;
	int	y;
	int	clr;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (fct->set == 'M')
				clr = make_mandel(fct, x, y);
			else if (fct->set == 'J')
				clr = make_julia(fct, x, y);
			my_pixel_put(fct, x, y, clr);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fct->mlx, fct->win, fct->img, 0, 0);
}

// Creates images
void	my_pixel_put(t_fract *fct, int x, int y, int clr)
{
	char	*pxl;

	fct->addr = mlx_get_data_addr(fct->img, &fct->bit_pix, \
				&fct->line_len, &fct->endian);
	pxl = fct->addr + (y * fct->line_len + x * (fct->bit_pix / 8));
	*(unsigned int *)pxl = clr;
}

// Frees, destroy, says goodbye
int	clean_exit(t_fract *fct)
{
	if (fct->img)
		mlx_destroy_image(fct->mlx, fct->img);
	if (fct->win)
	{
		mlx_clear_window(fct->mlx, fct->win);
		mlx_destroy_window(fct->mlx, fct->win);
	}
	if (fct->mlx)
	{
		mlx_destroy_display(fct->mlx);
		mlx_loop_end(fct->mlx);
		free (fct->mlx);
	}
	ft_printf("See you soon :)\n");
	exit(EXIT_SUCCESS);
	return (0);
}
