/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:07:27 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/07 19:44:18 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Prints error message + frees variables + exits
void	clean_exit(char *err_msg, int err_code)
{
	if (err_msg)
		fd_printf(2, "Error\n%s\n", err_msg);
	if (err_code != 1)
	{
		if (var()->map.cmap)
			free_matrix(var()->map.cmap);
		free_texture(&var()->map.ntx);
		free_texture(&var()->map.etx);
		free_texture(&var()->map.wtx);
		free_texture(&var()->map.stx);
	}
	if (var()->disp_2d.win)
		free_display(&var()->disp_2d);
	if (var()->disp_3d.win)
		free_display(&var()->disp_3d);
	if (var()->mlx)
	{
		mlx_destroy_display(var()->mlx);
		mlx_loop_end(var()->mlx);
		free(var()->mlx);
	}
	exit(err_code);
}

// Frees disp struct contents
void	free_display(t_disp *disp)
{
	if (disp->img)
		mlx_destroy_image(var()->mlx, disp->img);
	if (disp->win)
	{
		mlx_clear_window(var()->mlx, disp->win);
		mlx_destroy_window(var()->mlx, disp->win);
	}
}

// Frees matrix of ints
void	free_texture(t_tex *tex)
{
	if (tex->name)
		free(tex->name);
	if (tex->pixel)
		free(tex->pixel);
	if (tex->img)
		mlx_destroy_image(var()->mlx, tex->img);
}

// Frees matrix
void	free_matrix(char **matrix)
{
	int	i;

	if (matrix)
	{
		i = 0;
		while (matrix[i])
			free(matrix[i++]);
		free(matrix);
	}
}
