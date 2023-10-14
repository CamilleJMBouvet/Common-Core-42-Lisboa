/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:57:23 by cbouvet           #+#    #+#             */
/*   Updated: 2023/10/10 17:35:14 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// Mandelbrot formula
int	make_mandel(t_fract *fct, int x, int y)
{
	int		i;
	double	z_real;
	double	z_imag;
	double	tmp;

	i = 0;
	z_real = 0.0;
	z_imag = 0.0;
	fct->real = screen_adapt(fct->r_min, fct->r_max, x, 1);
	fct->imag = screen_adapt(fct->i_min, fct->i_max, y, 2);
	while (i < fct->iter)
	{
		if ((z_imag * z_imag) + (z_real * z_real) > 4.0)
			return (make_clr(i, fct));
		tmp = (z_real * z_real) - (z_imag * z_imag) + fct->real;
		z_imag = 2 * (z_imag * z_real) + fct->imag;
		z_real = tmp;
		i++;
	}
	return (make_clr(i, fct));
}

// Julia formula
int	make_julia(t_fract *fct, int x, int y)
{
	int		i;
	double	z_real;
	double	z_imag;
	double	tmp;

	i = 0;
	z_real = screen_adapt(fct->r_min, fct->r_max, x, 1);
	z_imag = screen_adapt(fct->i_min, fct->i_max, y, 2);
	while (i < fct->iter)
	{
		if ((z_imag * z_imag) + (z_real * z_real) > 4.0)
			return (make_clr(i, fct));
		tmp = (z_real * z_real) - (z_imag * z_imag) + fct->real;
		z_imag = 2 * (z_imag * z_real) + fct->imag;
		z_real = tmp;
		i++;
	}
	return (make_clr(i, fct));
}

// Colour calculations
int	make_clr(int i, t_fract *fct)
{
	int	j;
	int	clr;

	clr = 0xffffff;
	j = 0;
	if (i == fct->iter)
		return (0x000000);
	while (j < i)
	{
		clr -= fct->shading;
		j++;
	}
	if (clr < 0x000000)
		return (0x000000);
	return (clr);
}
