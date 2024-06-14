/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:20:41 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/16 19:16:28 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE];

	line = NULL;
	if (fd < 0 || fd > FOPEN_MAX || !BUFFER_SIZE)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		buffclear(buff, 1);
		return (NULL);
	}
	while (buff[0] || read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = gnl_strjoin(line, buff);
		buffclear(buff, 0);
		if (line[gnl_strlen(line) - 1] == '\n')
			break ;
	}
	return (line);
}

int	gnl_strlen(char *str)
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

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
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

void	buffclear(char *buff, int readerr)
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
