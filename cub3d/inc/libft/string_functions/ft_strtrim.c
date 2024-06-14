/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:06:33 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 17:36:01 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isthere(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j] >= 9 && s1[j] <= 13)
		j++;
	while (set[i])
	{
		while (set[i] == s1[j])
		{
			j++;
			i = 0;
		}
		i++;
	}
	return (j);
}

int	ft_isthererev(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) -1;
	while (s1[j] >= 9 && s1[j] <= 13)
		j--;
	while (set[i])
	{
		while (set[i] == s1[j])
		{
			j--;
			i = 0;
		}
		i++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = ft_isthere(s1, set);
	end = ft_isthererev(s1, set) + 1;
	if (end - start < 0)
	{
		str = ft_strdup("\0");
		return (str);
	}
	str = ft_substr(s1, start, end - start);
	return (str);
}
