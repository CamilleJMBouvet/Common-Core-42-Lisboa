/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:13:59 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 17:33:47 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strsize(long int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_parse(long int nb, char *str, int size)
{
	while (nb > 0)
	{
		str[size -1] = (nb % 10) + '0';
		nb /= 10;
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			size;

	nb = n;
	if (nb == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	size = ft_strsize(nb);
	str = ft_calloc(size +1, sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	str = ft_parse(nb, str, size);
	return (str);
}
