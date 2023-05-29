/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:58:04 by cbouvet           #+#    #+#             */
/*   Updated: 2023/05/26 18:57:39 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

char	*get_next_line(int fd);
int		ft_strlen_b(char *str);
char	*ft_strjoin_b(char *s1, char *s2);
void	ft_buffclear_b(char *buff, int readerr);
char	*ft_buffread(char *line, char *buff, int fd);

#endif
