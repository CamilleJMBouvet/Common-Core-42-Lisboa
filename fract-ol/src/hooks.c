/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:43:02 by cbouvet           #+#    #+#             */
/*   Updated: 2023/10/09 20:33:45 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// Closes window when [x] button is clicked
int	x_click(t_fract *fct)
{
	clean_exit(fct);
	return (0);
}

// Manages different key events
int	key_event(int keycode, t_fract *fct)
{
	if (keycode == 65307)
		clean_exit(fct);
	else if (keycode >= 65361 && keycode <= 65364)
		make_move(fct, keycode);
	else if (keycode == 65451)
	{
		fct->iter += 20;
		if (fct->iter > INT_MAX)
			fct->iter = INT_MAX;
	}
	else if (keycode == 65453)
	{
		fct->iter -= 20;
		if (fct->iter < 0)
			fct->iter = 0;
	}
	else if (keycode == 115)
		fct->shading += 100;
	else if (keycode >= 65433 && keycode <= 65436)
		shade_intensity(keycode, fct);
	fractal_maker(fct);
	return (keycode);
}

// Handle zooming
int	mouse_scroll(int keycode, int x, int y, t_fract *fct)
{
	double	zoom;

	fct->r_centre = (fct->r_min + fct->r_max) / 2.0;
	fct->i_centre = (fct->i_min + fct->i_max) / 2.0;
	zoom = 0.9;
	x = y;
	if (keycode == 4)
	{
		fct->zoom += 0.9;
		fct->r_min = fct->r_centre - (fct->r_centre - fct->r_min) * zoom;
		fct->r_max = fct->r_centre + (fct->r_max - fct->r_centre) * zoom;
		fct->i_min = fct->i_centre - (fct->i_centre - fct->i_min) * zoom;
		fct->i_max = fct->i_centre + (fct->i_max - fct->i_centre) * zoom;
	}
	else if (keycode == 5)
	{
		fct->zoom -= 0.9;
		fct->r_min = fct->r_centre - (fct->r_centre - fct->r_min) / zoom;
		fct->r_max = fct->r_centre + (fct->r_max - fct->r_centre) / zoom;
		fct->i_min = fct->i_centre - (fct->i_centre - fct->i_min) / zoom;
		fct->i_max = fct->i_centre + (fct->i_max - fct->i_centre) / zoom;
	}
	fractal_maker(fct);
	return (keycode);
}

// Handles moving with keyboard arrows
void	make_move(t_fract *fct, int keycode)
{
	if (keycode == 65361)
	{
		fct->r_min = fct->r_min - (2 / (fct->zoom * fct->zoom));
		fct->r_max = fct->r_max - (2 / (fct->zoom * fct->zoom));
	}
	else if (keycode == 65362)
	{
		fct->i_min = fct->i_min + (2 / (fct->zoom * fct->zoom));
		fct->i_max = fct->i_max + (2 / (fct->zoom * fct->zoom));
	}
	else if (keycode == 65363)
	{
		fct->r_min = fct->r_min + (2 / (fct->zoom * fct->zoom));
		fct->r_max = fct->r_max + (2 / (fct->zoom * fct->zoom));
	}
	else if (keycode == 65364)
	{
		fct->i_min = fct->i_min - (2 / (fct->zoom * fct->zoom));
		fct->i_max = fct->i_max - (2 / (fct->zoom * fct->zoom));
	}
}

// Changes the shading
void	shade_intensity(int keycode, t_fract *fct)
{
	if (keycode == 65436)
		fct->shading = 500;
	else if (keycode == 65433)
		fct->shading = 1000;
	else if (keycode == 65435)
		fct->shading = 10000;
	fractal_maker(fct);
}
