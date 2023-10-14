/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:53:19 by cbouvet           #+#    #+#             */
/*   Updated: 2023/10/09 17:01:11 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// Checks whether params are the correct
int	param_check(int ac, char **av)
{
	if (ac < 2)
		exit_process(1);
	if (is_mandel(av[1]))
	{
		if (ac != 2)
			exit_process(2);
		return (1);
	}
	else if (is_julia(av[1]))
	{
		if (ac != 4 || !is_double(av[2]) || !is_double(av[3]))
			exit_process(3);
		return (1);
	}
	else
		exit_process(4);
	return (0);
}

// Checks if the 1st param refers to Mandelbrot
int	is_mandel(char *str)
{
	int	len;

	len = ft_strlen(str);
	if ((ft_strncmp(str, "Mandelbrot", len) == 0) \
			|| (ft_strncmp(str, "M", len) == 0) \
			|| (ft_strncmp(str, "1", len) == 0))
		return (1);
	return (0);
}

// Checks if the 1st param refers to Julia
int	is_julia(char *str)
{
	int	len;

	len = ft_strlen(str);
	if ((ft_strncmp(str, "Julia", len) == 0) \
			|| (ft_strncmp(str, "J", len) == 0) \
			|| (ft_strncmp(str, "2", len) == 0))
		return (1);
	return (0);
}

// Checks if the params after Julia are doubles (in terms of format)
int	is_double(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (i != ft_strlen(str))
		return (0);
	return (1);
}

// Puts error message and exits
void	exit_process(int code)
{
	if (code == 1)
		ft_putstr_fd("Error - Programme takes 2 parameters\n", 2);
	if (code == 2)
		ft_putstr_fd("Error - Mandelbrot doesn't take extra parameters\n", 2);
	if (code == 3)
		ft_putstr_fd("Error - Julia takes 2 extra parameters, format 0.0\n", 2);
	if (code == 4)
	{
		ft_putstr_fd("Error - Accepted parameters:\n\nMandelbrot\nM\n1\n", 2);
		ft_putstr_fd("\nJulia 0.0 0.0\nJ 0.0 0.0\n2 0.0 0.0\n", 2);
	}
	exit(EXIT_FAILURE);
}
