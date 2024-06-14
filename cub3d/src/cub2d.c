/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:18:28 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/14 19:01:02 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Recreate the display functions to see if they work out
void	cub2d_maker(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				draw_cell(&var()->disp_2d, j, i, 0x000000);
			else if (map[i][j] == '0' || ft_strchr("NEWS", map[i][j]))
				draw_cell(&var()->disp_2d, j, i, 0x1A1A1A);
			j++;
		}
		i++;
	}
	put_player(&var()->disp_2d, var()->player.pos[0], var()->player.pos[1]);
	mlx_put_image_to_window(var()->mlx, var()->disp_2d.win, \
	var()->disp_2d.img, 0, 0);
}

// Draws each cell and its bounds
void	draw_cell(t_disp *disp, int x, int y, int clr)
{
	int	i;
	int	j;

	i = 0;
	x *= CELL_SIZE;
	y *= CELL_SIZE;
	while (i < CELL_SIZE)
	{
		j = 0;
		while (j < CELL_SIZE)
		{
			my_pixel_put(disp, x + j, y + i, clr);
			if (clr == 0x1A1A1A && (j == CELL_SIZE -1 || i == CELL_SIZE -1 \
			|| !j || !i))
				my_pixel_put(disp, x + j, y + i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

// Puts the player in the map
void	put_player(t_disp *disp, double x, double y)
{
	int		i;
	int		j;

	i = -3;
	x *= CELL_SIZE;
	y *= CELL_SIZE;
	while (i < 4)
	{
		j = -3;
		while (j < 4)
		{
			my_pixel_put(disp, x + j, y + i, 0x9400D3);
			j++;
		}
		i++;
	}
	draw_fov(disp, x, y, -1);
	draw_fov(disp, x, y, 1);
}

// Draws player's field of view
void	draw_fov(t_disp *disp, double og_x, double og_y, double sign)
{
	double	i;
	double	x;
	double	y;
	double	fov_dir;

	i = 0;
	while (i <= (FOV * 100) / 2)
	{
		x = og_x;
		y = og_y;
		fov_dir = var()->player.dir + (i * sign);
		while (var()->map.cmap[(int)(y / CELL_SIZE)][(int)(x / CELL_SIZE)] \
		!= '1')
		{
			x += sin(fov_dir * PI / 180);
			y += -cos(fov_dir * PI / 180);
			my_pixel_put(disp, x, y, 0x9400D3);
		}
		i += 0.1;
	}
}
