/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:26:22 by cbouvet           #+#    #+#             */
/*   Updated: 2023/09/13 17:35:22 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_size(const char *s, char c)
{
	size_t	i;
	int		size;

	size = 0;
	i = 0;
	if (s[0] != c)
	{
		size++;
		i++;
	}
	while (i < ft_strlen(s))
	{
		if (s[i] != c && s[i -1] == c)
			size++;
		i++;
	}
	return (size);
}

char	**ft_fill(char **arr, const char *s, char c, int size)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (j < size && s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != 0)
				i++;
			arr[j] = ft_substr(s, start, i - start);
			j++;
		}
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		size;

	if (!s[0])
	{
		arr = malloc(sizeof(char *));
		if (!arr)
		{
			free(arr);
			return (NULL);
		}
		arr[0] = 0;
		return (arr);
	}
	size = ft_size(s, c);
	arr = malloc(sizeof(char *) * (size +1));
	if (!arr)
	{
		free(arr);
		return (NULL);
	}
	arr[size] = NULL;
	ft_fill(arr, s, c, size);
	return (arr);
}
