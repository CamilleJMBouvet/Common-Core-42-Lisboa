/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:17:26 by cbouvet           #+#    #+#             */
/*   Updated: 2023/05/04 19:22:55 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_size(unsigned long int n, int mult)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n /= mult;
		size++;
	}
	return (size);
}

char	ft_base(unsigned long int n, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
	{
		if (n == i)
			return (base[i]);
		i++;
	}
	return ('\0');
}

char	*ft_parse_base(unsigned long int n, char *base, int mult)
{
	char	*str;
	int		size;

	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	size = ft_str_size(n, mult);
	str = ft_calloc(size +1, sizeof(char));
	if (!str)
		return (NULL);
	while (n > 0)
	{
		str[size -1] = ft_base(n % mult, base);
		n /= mult;
		size--;
	}
	return (str);
}

char	*ft_uitoa_base(unsigned long int n, char *base)
{
	int		mult;
	char	*str;

	mult = ft_strlen(base);
	str = ft_parse_base(n, base, mult);
	return (str);
}
