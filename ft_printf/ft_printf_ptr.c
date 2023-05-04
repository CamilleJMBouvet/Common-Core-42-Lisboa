/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:10:42 by cbouvet           #+#    #+#             */
/*   Updated: 2023/05/04 19:42:06 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ptr(int *p)
{
	int					count;
	unsigned long int	tmp;
	char				*strp;

	if (!p)
		return (ft_printf_str("(nil)"));
	tmp = (unsigned long int)p;
	strp = ft_uitoa_base(tmp, "0123456789abcdef");
	count = ft_printf_str("0x") + ft_printf_str(strp);
	free (strp);
	return (count);
}
