/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:24:34 by cbouvet           #+#    #+#             */
/*   Updated: 2023/10/09 16:44:29 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// -LIBRARIES-
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "mlx_linux/mlx.h"

// -STATIC VALUES-
# define WIDTH		2000
# define HEIGHT		2000

// -MEGA STRUCT-
typedef struct s_fract
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bit_pix;
	int		line_len;
	int		endian;
	char	set;
	double	real;
	double	imag;
	double	r_min;
	double	r_max;
	double	r_centre;
	double	i_min;
	double	i_max;
	double	i_centre;
	double	zoom;
	int		iter;
	int		shading;
}	t_fract;

// -FUNCTIONS-
//Argument handling
int			param_check(int ac, char **av);
int			is_mandel(char *str);
int			is_julia(char *str);
int			is_double(char *str);
void		exit_process(int code);

//Initiate structs
void		init_display(t_fract *fct);
void		init_image(t_fract *fct);
void		init_fract(char **av, t_fract *fct);

//Display
void		fractal_maker(t_fract *fct);
void		my_pixel_put(t_fract *fct, int x, int y, int clr);
int			clean_exit(t_fract *fct);

//Fractal sets
int			make_mandel(t_fract *fct, int x, int y);
int			make_julia(t_fract *fct, int x, int y);
int			make_clr(int i, t_fract *fct);

//Events & hooks
int			x_click(t_fract *fct);
int			key_event(int keycode, t_fract *fct);
int			mouse_scroll(int keycode, int x, int y, t_fract *fct);
void		make_move(t_fract *fct, int keycode);
void		shade_intensity(int keycode, t_fract *fct);

//Tools
double		atod(char *str, double res);
double		screen_adapt(double min, double max, int axis, int id);

#endif
