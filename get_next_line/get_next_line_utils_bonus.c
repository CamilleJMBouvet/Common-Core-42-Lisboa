/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:57:41 by cbouvet           #+#    #+#             */
/*   Updated: 2023/05/26 18:59:46 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_b(char *str)
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

char	*ft_strjoin_b(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char) * (ft_strlen_b(s1) + ft_strlen_b(s2) + 1));
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

void	ft_buffclear_b(char *buff, int readerr)
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

char	*ft_buffread(char *line, char *buff, int fd)
{
	while (buff[0] || read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin_b(line, buff);
		ft_buffclear_b(buff, 0);
		if (line[ft_strlen_b(line) - 1] == '\n')
			break ;
	}
	return (line);
}
