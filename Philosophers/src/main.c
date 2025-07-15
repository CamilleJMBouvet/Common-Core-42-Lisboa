/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:39:34 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/05 16:52:40 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Declares static struct holding all programme key variables
t_var	*var(void)
{
	static t_var	var;

	return (&var);
}

// Main
int	main(int ac, char **av)
{
	if (!param_check(ac, av))
		return (-1);
	if (!init_var(av) || !init_philo() || !assign_fork())
		return (-1);
	return (clean_all(launch_threads()));
}
