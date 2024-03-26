/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:06:26 by cbouvet           #+#    #+#             */
/*   Updated: 2024/02/27 15:51:16 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//Iterates through string + sends to format function when % is found
int	fd_printf(int fd, const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start (args, str);
	while (str[i])
	{
		while (str[i] == '%' && str[i +1] != 0)
		{
			if (ft_strchr("cspdiu%xX", str[i +1]))
			{
				len += printf_format(fd, str[i +1], args);
				i += 2;
			}
		}
		if (str[i] != 0)
		{
			len += printf_chr(fd, str[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}

// Sends to relevant printing functions
int	printf_format(int fd, char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = printf_chr(fd, va_arg(args, int));
	else if (c == 's')
		len = printf_str(fd, va_arg(args, char *));
	else if (c == 'p')
		len = printf_ptr(fd, va_arg(args, int *));
	else if (c == 'd' || c == 'i')
		len = printf_nbr(fd, va_arg(args, int), c);
	else if (c == 'u' || c == 'x' || c == 'X')
		len = printf_nbr(fd, va_arg(args, unsigned int), c);
	else if (c == '%')
		len = printf_chr(fd, '%');
	return (len);
}
