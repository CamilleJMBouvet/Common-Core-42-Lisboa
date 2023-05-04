/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:45:54 by cbouvet           #+#    #+#             */
/*   Updated: 2023/05/04 19:42:09 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_printf_chr(char c);
int		ft_printf_str(char *str);
int		ft_printf_int(int d);
int		ft_printf_uint(unsigned int x, char c);
int		ft_printf_ptr(int *p);
char	*ft_uitoa_base(unsigned long int n, char *base);

#endif
