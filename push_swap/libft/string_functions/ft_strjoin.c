/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:40:50 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 17:35:35 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(str, s1, ft_strlen(s1) +1);
	ft_strlcat(&str[ft_strlen(s1)], s2, ft_strlen(s2)+1);
	return (str);
}
