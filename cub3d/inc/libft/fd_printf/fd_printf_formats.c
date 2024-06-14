/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:07:47 by cbouvet           #+#    #+#             */
/*   Updated: 2024/02/12 16:49:00 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Prints char to stderr
int	printf_chr(int fd, char c)
{
	ft_putchar_fd(c, fd);
	return (1);
}

// Prints string to stderr
int	printf_str(int fd, char *str)
{
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

// Prints ptr address to stderr
int	printf_ptr(int fd, int *p)
{
	unsigned long int	tmp;

	if (!p)
		return (printf_str(fd, "(nil)"));
	tmp = (unsigned long int)p;
	return (printf_str(fd, "0x") + printf_nbr(fd, tmp, 'p'));
}

// Prints digit to stderr
int	printf_nbr(int fd, long int nb, char c)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += fd_putnbr(fd, (long)nb);
	else if (c == 'u')
		count += uputnbr(fd, (unsigned int)nb, "0123456789", 10);
	else if (c == 'x')
		count += uputnbr(fd, (unsigned int)nb, "0123456789abcdef", 16);
	else if (c == 'X')
		count += uputnbr(fd, (unsigned int)nb, "0123456789ABCDEF", 16);
	else if (c == 'p')
		count += uputnbr(fd, (unsigned long int)nb, "0123456789abcdef", 16);
	return (count);
}
