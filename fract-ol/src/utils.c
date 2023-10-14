/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:49:48 by cbouvet           #+#    #+#             */
/*   Updated: 2023/10/09 17:06:49 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// atoi for doubles
double	atod(char *str, double res)
{
	int		i;
	int		neg;
	double	div;
	double	fract;

	i = 0;
	neg = 1;
	fract = 0.0;
	div = 1.0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg *= -1;
	}
	while (ft_isdigit(str[i]))
		res = (res * 10) + (str[i++] - 48);
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		fract = (fract * 10) + (str[i++] - 48);
		div *= 10.0;
	}
	return ((res + fract / div) * neg);
}

// Adapts the complex number realm to the screen dimensions
double	screen_adapt(double min, double max, int axis, int id)
{
	if (id == 1)
		return (min + (double)axis * (max - min) / WIDTH);
	return (max + (double)axis * (min - max) / HEIGHT);
}
