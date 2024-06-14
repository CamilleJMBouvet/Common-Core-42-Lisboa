/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:15:44 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/07 18:38:29 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Launches raycasting process
void	cub3d_maker(t_player *player)
{
	int		i;
	int		top;
	int		bottom;
	int		step[2];

	i = 0;
	while (i < WIDTH)
	{
		set_variables(player, (double)(2 * i / (double)WIDTH -1));
		step[0] = step_incr(player, 0);
		step[1] = step_incr(player, 1);
		player->perp_dist = raycaster(player, step[0], step[1]);
		player->wall_height = (int)((double)HEIGHT / player->perp_dist);
		top = (-player->wall_height + HEIGHT) / 2;
		if (top < 0)
			top = 0;
		bottom = (player->wall_height + HEIGHT) / 2;
		if (bottom >= HEIGHT)
			bottom = HEIGHT;
		rendering(player, i, top, bottom);
		i++;
	}
	mlx_put_image_to_window(var()->mlx, var()->disp_3d.win, \
		var()->disp_3d.img, 0, 0);
}

// Sets raycasting variables
void	set_variables(t_player *player, double cam)
{
	double	new_dir;
	double	plane[2];
	double	dir_vector[2];

	new_dir = player->dir + 270;
	if (new_dir > 360)
		new_dir -= 360;
	dir_vector[0] = cos(new_dir * PI / 180);
	dir_vector[1] = sin(new_dir * PI / 180);
	plane[0] = -dir_vector[1] * FOV;
	plane[1] = dir_vector[0] * FOV;
	player->ray[0] = dir_vector[0] + plane[0] * cam;
	player->ray[1] = dir_vector[1] + plane[1] * cam;
	player->wall[0] = (int)player->pos[0];
	player->wall[1] = (int)player->pos[1];
	player->delta[0] = fabs(1.0 / player->ray[0]);
	player->delta[1] = fabs(1.0 / player->ray[1]);
}

// Returns the value of the step to increase raycast for each axis
int	step_incr(t_player *player, int axis)
{
	if (player->ray[axis] < 0)
	{
		player->side_dist[axis] = (player->pos[axis] - \
		(double)player->wall[axis]) * player->delta[axis];
		return (-1);
	}
	player->side_dist[axis] = ((double)player->wall[axis] + 1.0 - \
	player->pos[axis]) * player->delta[axis];
	return (1);
}

double	raycaster(t_player *player, int step_x, int step_y)
{
	while (var()->map.cmap[player->wall[1]][player->wall[0]] != '1')
	{
		if (player->side_dist[0] < player->side_dist[1])
		{
			player->side_dist[0] += player->delta[0];
			player->wall[0] += step_x;
			player->side = 0;
		}
		else
		{
			player->side_dist[1] += player->delta[1];
			player->wall[1] += step_y;
			player->side = 1;
		}
	}
	if (!player->side)
		return (player->side_dist[0] - player->delta[0]);
	return (player->side_dist[1] - player->delta[1]);
}
