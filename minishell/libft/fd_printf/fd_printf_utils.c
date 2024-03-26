/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:11:05 by cbouvet           #+#    #+#             */
/*   Updated: 2024/02/12 16:49:27 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Converts int to char + prints on stderr
int	fd_putnbr(int fd, long int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count += printf_chr(fd, '-');
		nb *= -1;
	}
	if (nb == 0)
		count += printf_chr(fd, '0');
	else if (nb > 0 && nb < 10)
		count += printf_chr(fd, nb + '0');
	else if (nb > 9)
	{
		count += fd_putnbr(fd, nb / 10);
		count += printf_chr(fd, nb % 10 + '0');
	}
	return (count);
}

// Converts unsinged int to char + prints to stderr
int	uputnbr(int fd, unsigned long int nb, char *base, unsigned int mult)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		count += printf_chr(fd, '0');
	}
	else if (nb > 0 && nb < mult)
		count += base_print(fd, nb, base);
	else if (nb > 9)
	{
		count = uputnbr(fd, nb / mult, base, mult);
		count += base_print(fd, nb % mult, base);
	}
	return (count);
}

// Conversion iterator
int	base_print(int fd, unsigned long int nb, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
	{
		if (nb == i)
			return (printf_chr(fd, base[i]));
		i++;
	}
	return (0);
}
