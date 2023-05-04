/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:09:22 by cbouvet           #+#    #+#             */
/*   Updated: 2023/05/04 19:42:08 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(int d)
{
	char	*strd;
	int		count;

	strd = ft_itoa(d);
	count = ft_printf_str(strd);
	free (strd);
	return (count);
}
