/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mvts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:59:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/07 16:30:37 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Checks if hooks were triggered
int	hooks_handler(void)
{
	if (!var()->w_key && !var()->a_key && !var()->s_key && \
	!var()->d_key && !var()->right && !var()->left)
		return (0);
	hooks_mvt(var()->player.pos[0], var()->player.pos[1]);
	hooks_rot();
	return (0);
}

// Creates destination + sends to bound checker
void	hooks_mvt(double x_dest, double y_dest)
{
	if (var()->w_key)
	{
		x_dest += sin(var()->player.dir * PI / 180) * MV_SPEED;
		y_dest += -cos(var()->player.dir * PI / 180) * MV_SPEED;
	}
	if (var()->s_key)
	{
		x_dest -= sin(var()->player.dir * PI / 180) * MV_SPEED;
		y_dest -= -cos(var()->player.dir * PI / 180) * MV_SPEED;
	}
	if (var()->a_key)
	{
		x_dest -= cos(var()->player.dir * PI / 180) * MV_SPEED;
		y_dest -= sin(var()->player.dir * PI / 180) * MV_SPEED;
	}
	if (var()->d_key)
	{
		x_dest += cos(var()->player.dir * PI / 180) * MV_SPEED;
		y_dest += sin(var()->player.dir * PI / 180) * MV_SPEED;
	}
	bound_checker(x_dest, y_dest);
}

// Rotates direction + caps rotation + creates new image
void	hooks_rot(void)
{
	if (var()->left)
	{
		var()->player.dir -= ROT_DEG;
		if (var()->player.dir < 0)
			var()->player.dir = 360 - (var()->player.dir * (-1));
	}
	if (var()->right)
	{
		var()->player.dir += ROT_DEG;
		if (var()->player.dir > 360)
			var()->player.dir = (360 - var()->player.dir) * (-1);
	}
	if (var()->disp_2d.win)
		cub2d_maker(var()->map.cmap);
	cub3d_maker(&var()->player);
}

// Checks if destination is within bounds + creates new image
void	bound_checker(double dest_x, double dest_y)
{
	int	x;
	int	y;

	x = floor(dest_x);
	y = floor(dest_y);
	if (dest_x <= 0 || dest_x >= var()->map.width * CELL_SIZE \
	|| dest_y <= 0 || dest_y >= var()->map.height * CELL_SIZE \
	|| !var()->map.cmap[y] || !var()->map.cmap[y][x])
		return ;
	if (var()->map.cmap[y][x] != '1')
	{
		var()->player.pos[0] = dest_x;
		var()->player.pos[1] = dest_y;
	}
	else if (var()->map.cmap[y][(int)floor(var()->player.pos[0])] != '1')
		var()->player.pos[1] = dest_y;
	else if (var()->map.cmap[(int)floor(var()->player.pos[1])][x] != '1')
		var()->player.pos[0] = dest_x;
	else
		return ;
	if (var()->disp_2d.win)
		cub2d_maker(var()->map.cmap);
	cub3d_maker(&var()->player);
}

// Puts each pixel to the img address
void	my_pixel_put(t_disp *disp, int x, int y, int clr)
{
	char	*pxl;

	if (x < 0 || x >= disp->width || y < 0 || y >= disp->height)
		return ;
	disp->img_addr = mlx_get_data_addr(disp->img, &disp->bit_pix, \
	&disp->width, &disp->endian);
	pxl = disp->img_addr + (y * disp->width + x * (disp->bit_pix / 8));
	if (pxl)
		*(unsigned int *)pxl = clr;
}
