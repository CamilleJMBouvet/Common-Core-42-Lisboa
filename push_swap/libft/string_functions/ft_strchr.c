/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:16:08 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 17:35:25 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*ptr;
	unsigned char	d;

	i = 0;
	ptr = (char *)s;
	d = c;
	if (d == 0)
		return (&ptr[ft_strlen(ptr)]);
	while (ptr[i])
	{
		if (ptr[i] == d)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
