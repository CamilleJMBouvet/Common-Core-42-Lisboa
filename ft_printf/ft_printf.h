/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:45:54 by cbouvet           #+#    #+#             */
/*   Updated: 2023/05/05 19:14:57 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./Libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_printf_chr(char c);
int		ft_printf_str(char *str);
int		ft_printf_nbr(long int nb, char c);
int		ft_printf_ptr(int *p);

#endif
