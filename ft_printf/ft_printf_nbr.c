/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:31:27 by cbouvet           #+#    #+#             */
/*   Updated: 2023/05/05 19:22:25 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count += ft_printf_chr('-');
		nb *= -1;
	}
	if (nb == 0)
		count += ft_printf_chr('0');
	else if (nb > 0 && nb < 10)
		count += ft_printf_chr(nb + '0');
	else if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_printf_chr(nb % 10 + '0');
	}
	return (count);
}

int	ft_base_print(unsigned long int nb, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
	{
		if (nb == i)
			return (ft_printf_chr(base[i]));
		i++;
	}
	return (0);
}

int	ft_uputnbr(unsigned long int nb, char *base, unsigned int mult)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		count += ft_printf_chr('0');
	}
	else if (nb > 0 && nb < mult)
		count += ft_base_print(nb, base);
	else if (nb > 9)
	{
		count = ft_uputnbr(nb / mult, base, mult);
		count += ft_base_print(nb % mult, base);
	}
	return (count);
}

int	ft_printf_nbr(long int nb, char c)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr((long)nb);
	else if (c == 'u')
		count += ft_uputnbr((unsigned int)nb, "0123456789", 10);
	else if (c == 'x')
		count += ft_uputnbr((unsigned int)nb, "0123456789abcdef", 16);
	else if (c == 'X')
		count += ft_uputnbr((unsigned int)nb, "0123456789ABCDEF", 16);
	else if (c == 'p')
		count += ft_uputnbr((unsigned long int)nb, "0123456789abcdef", 16);
	return (count);
}
