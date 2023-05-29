/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:57:21 by cbouvet           #+#    #+#             */
/*   Updated: 2023/05/26 19:03:20 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];

	line = NULL;
	if (fd < 0 || !BUFFER_SIZE || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
	{
		if (fd > 0 && fd <= FOPEN_MAX)
			ft_buffclear_b(buff[fd], 1);
		return (NULL);
	}
	line = ft_buffread(line, buff[fd], fd);
	return (line);
}
