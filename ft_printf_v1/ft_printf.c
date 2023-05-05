/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:23:13 by cbouvet           #+#    #+#             */
/*   Updated: 2023/05/04 19:47:04 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_printf_chr(va_arg(args, int));
	else if (c == 's')
		len = ft_printf_str(va_arg(args, char *));
	else if (c == 'p')
		len = ft_printf_ptr(va_arg(args, int *));
	else if (c == 'd' || c == 'i')
		len = ft_printf_int(va_arg(args, int));
	else if (c == 'u' || c == 'x' || c == 'X')
		len = ft_printf_uint(va_arg(args, unsigned int), c);
	else if (c == '%')
		len = ft_printf_chr('%');
	return (len);
}

int	ft_printf(const char *str, ...)
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
				len += ft_format(str[i +1], args);
				i += 2;
			}
		}
		if (str[i] != 0)
		{
			len += ft_printf_chr(str[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}
