/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:58:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/07 15:35:12 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Initialises window, img, hooks for display received
void	init_display(t_disp *disp, int code, char *name)
{
	disp->width = WIDTH;
	disp->height = HEIGHT;
	if (!code)
	{
		disp->width = var()->map.width * CELL_SIZE;
		disp->height = var()->map.height * CELL_SIZE;
	}
	disp->win = mlx_new_window(var()->mlx, disp->width, disp->height, name);
	if (!disp->win)
		clean_exit(WIN_ERR, 3);
	disp->img = mlx_new_image(var()->mlx, disp->width, disp->height);
	if (!disp->img)
		clean_exit(IMG_ERR, 3);
	if (disp->img_addr)
	{
		free(disp->img_addr);
		disp->img_addr = NULL;
	}
	init_hooks(disp);
}

// Sets hooks for window
void	init_hooks(t_disp *disp)
{
	mlx_hook(disp->win, 2, 1L << 0, key_press, NULL);
	mlx_hook(disp->win, 3, 1L << 1, key_release, NULL);
	mlx_hook(disp->win, 17, 1L << 17, mlx_loop_end, var()->mlx);
}

// Sets bool to true if key is pressed
int	key_press(int code)
{
	if (code == 65361)
		var()->left = true;
	if (code == 65363)
		var()->right = true;
	if (code == 'w' || code == 'W')
		var()->w_key = true;
	if (code == 'a' || code == 'A')
		var()->a_key = true;
	if (code == 's' || code == 'S')
		var()->s_key = true;
	if (code == 'd' || code == 'D')
		var()->d_key = true;
	if (code == 65307)
		clean_exit(NULL, 0);
	return (0);
}

// Sets bool to false if key is released
int	key_release(int code)
{
	if (code == 65361)
		var()->left = false;
	if (code == 65363)
		var()->right = false;
	if (code == 'w' || code == 'W')
		var()->w_key = false;
	if (code == 'a' || code == 'A')
		var()->a_key = false;
	if (code == 's' || code == 'S')
		var()->s_key = false;
	if (code == 'd' || code == 'D')
		var()->d_key = false;
	return (0);
}
