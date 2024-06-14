/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:23:35 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/08 13:18:17 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// colours column based on pixel y position + texture
void	rendering(t_player *player, int i, int top, int bottom)
{
	int		j;
	int		clr;

	j = 0;
	clr = -1;
	while (j < top && j < HEIGHT)
		my_pixel_put(&var()->disp_3d, i, j++, var()->map.c_clr);
	while (j < bottom && j < HEIGHT)
	{
		if (player->side && player->wall[1] < player->pos[1])
			clr = texture_clr(player, &var()->map.ntx, j);
		else if (player->side && player->wall[1] > player->pos[1])
			clr = texture_clr(player, &var()->map.stx, j);
		else if (!player->side && player->wall[0] < player->pos[0])
			clr = texture_clr(player, &var()->map.wtx, j);
		else
			clr = texture_clr(player, &var()->map.etx, j);
		if (clr != -1)
			my_pixel_put(&var()->disp_3d, i, j, clr);
		j++;
	}
	while (j < HEIGHT)
		my_pixel_put(&var()->disp_3d, i, j++, var()->map.f_clr);
}

// Calculates colour corresponding to appropriate texture pixel
int	texture_clr(t_player *player, t_tex *tex, int j)
{
	int		tex_pos[2];
	int		y_scaled;
	double	wall_x;

	wall_x = player->pos[0] + player->perp_dist * player->ray[0];
	if (!player->side)
		wall_x = player->pos[1] + player->perp_dist * player->ray[1];
	wall_x -= floor(wall_x);
	tex_pos[0] = (int)(wall_x * (double)tex->width);
	if ((!player->side && player->ray[0] < 0) || \
		(player->side && player->ray[1] > 0))
		tex_pos[0] = tex->width - tex_pos[0] - 1;
	y_scaled = j * 256 - HEIGHT * 128 + player->wall_height * 128;
	tex_pos[1] = ((y_scaled * tex->height) / player->wall_height) / 256;
	if (tex_pos[0] < 0)
		tex_pos[0] = 0;
	if (tex_pos[0] >= tex->width)
		tex_pos[0] = tex->width - 1;
	if (tex_pos[1] < 0)
		tex_pos[1] = 0;
	if (tex_pos[1] >= tex->height)
		tex_pos[1] = tex->height - 1;
	return (((int *)tex->pixel)[tex->width * tex_pos[1] + tex_pos[0]]);
}
