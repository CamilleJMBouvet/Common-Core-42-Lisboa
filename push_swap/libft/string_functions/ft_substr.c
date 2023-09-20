/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:57:21 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 17:36:06 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (start >= ft_strlen(s))
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = 0;
	}
	else if (len >= (ft_strlen(s)-start))
		sub = ft_strdup(&s[start]);
	else
	{
		sub = malloc(sizeof(char) * (len +1));
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, &s[start], len +1);
	}
	return (sub);
}
