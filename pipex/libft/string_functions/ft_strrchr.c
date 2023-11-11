/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:46:39 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 17:35:58 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*ptr;
	unsigned char	d;

	d = c;
	ptr = (char *)s;
	i = ft_strlen(ptr) -1;
	if (d == 0)
		return (&ptr[i +1]);
	while (i >= 0)
	{
		if (ptr[i] == d)
			return (&ptr[i]);
		i--;
	}
	return (NULL);
}
