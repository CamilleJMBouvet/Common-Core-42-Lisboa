/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:19:38 by cbouvet           #+#    #+#             */
/*   Updated: 2023/05/04 19:42:02 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_uint(unsigned int x, char c)
{
	char	*strx;
	int		count;

	if (c == 'u')
		strx = ft_uitoa_base(x, "0123456789");
	else if (c == 'x')
		strx = ft_uitoa_base(x, "0123456789abcdef");
	else if (c == 'X')
		strx = ft_uitoa_base(x, "0123456789ABCDEF");
	count = ft_printf_str(strx);
	free (strx);
	return (count);
}
