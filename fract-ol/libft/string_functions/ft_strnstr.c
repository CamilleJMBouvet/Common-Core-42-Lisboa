/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:01:18 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 17:35:56 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = (char *)big;
	if (little[0] == 0)
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while ((i + j) < len && (str[i + j] == little[j]))
		{
			if (little[j +1] == 0)
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
