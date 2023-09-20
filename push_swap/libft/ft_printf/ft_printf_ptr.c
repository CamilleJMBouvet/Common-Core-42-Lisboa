/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:10:42 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 17:34:20 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf_ptr(int *p)
{
	unsigned long int	tmp;

	if (!p)
		return (ft_printf_str("(nil)"));
	tmp = (unsigned long int)p;
	return (ft_printf_str("0x") + ft_printf_nbr(tmp, 'p'));
}
