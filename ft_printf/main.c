/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:19:28 by cbouvet           #+#    #+#             */
/*   Updated: 2023/05/05 19:19:32 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = printf(" %p ", -1);
	printf("\n");
	b = ft_printf(" %p ", -1);
	printf("\n");
	printf("a = %i | b = %i\n", a, b);
}
