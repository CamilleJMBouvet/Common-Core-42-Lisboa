/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:30:41 by cbouvet           #+#    #+#             */
/*   Updated: 2023/05/26 17:27:30 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i +1);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && s2[j -1] != '\n')
		joined[i++] = s2[j++];
	joined[i] = 0;
	if (s1)
		free (s1);
	return (joined);
}

void	ft_buffclear(char *buff, int readerr)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!readerr)
	{
		j = 0;
		while (buff[j] && buff[j -1] != '\n')
			j++;
		while (buff[j])
			buff[i++] = buff[j++];
	}
	while (buff[i])
		buff[i++] = 0;
}
