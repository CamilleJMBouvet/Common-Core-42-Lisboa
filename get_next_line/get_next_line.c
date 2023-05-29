/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:30:35 by cbouvet           #+#    #+#             */
/*   Updated: 2023/05/10 17:39:03 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	int			i;
	static int	start;
	static int	count;

	if (!fd || fd == -1)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff)
		return (NULL);
	read(fd, buff, BUFFER_SIZE);

	if (count == 1)
	{
		i = start;
		while (buff[i])
		{
			if (buff[i] == '\n')
			{
				start += i+1;
				return(ft_strdup(buff, i - start));
			}
			i++;
		}
	}
	else
	{
		i = 0;
		while (buff[i])
		{
			if (buff[i] == '\n')
			{
				count = 1;
				start = i +1;
				return (ft_strdup(buff, i));
			}
		}
	}
	return (NULL);
}
