/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:45:45 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 17:33:02 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	d;

	i = 0;
	ptr = (unsigned char *)s;
	d = c;
	while (i < n)
	{
		if (ptr[i] == d)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
