/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:40:27 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/05 22:14:50 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Initializes variables struct
int	init_var(char **av)
{
	int				err;
	struct timeval	tv;

	err = 0;
	err = parse_params(av);
	if (err != 0)
	{
		var()->death = 0;
		var()->monitor = 0;
		var()->msg_mutex = create_mutexes();
		var()->death_mutex = create_mutexes();
		var()->monit_mutex = create_mutexes();
		if (!var()->msg_mutex || !var()->death_mutex || !var()->monit_mutex)
			err = MUTEX_ERR;
	}
	if (err < 0)
	{
		clean_all(err);
		return (0);
	}
	gettimeofday(&tv, NULL);
	var()->start_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (1);
}

// Parses param values into variable struct
int	parse_params(char **av)
{
	var()->philo_nb = ph_atoi(av[1]);
	var()->death_mls = ph_atoi(av[2]);
	var()->eat_mls = ph_atoi(av[3]);
	var()->sleep_mls = ph_atoi(av[4]);
	var()->meal_nb = -1;
	if (av[5])
		var()->meal_nb = ph_atoi(av[5]);
	if (var()->philo_nb > 200)
		return (PHILO_NB);
	if (var()->death_mls < 0 || var()->eat_mls < 0 || \
		var()->sleep_mls < 0 || var()->meal_nb == -5)
		return (OVERFLOW);
	if (!var()->philo_nb || !var()->death_mls || !var()->eat_mls || \
		!var()->sleep_mls || !var()->meal_nb)
		return (NULL_VAL);
	return (1);
}

// Creates + inits mutexes
pthread_mutex_t	*create_mutexes(void)
{
	pthread_mutex_t	*mutex;

	mutex = malloc(sizeof(pthread_mutex_t));
	if (!mutex)
		return (NULL);
	if (pthread_mutex_init(mutex, NULL))
	{
		free(var()->msg_mutex);
		return (NULL);
	}
	return (mutex);
}

// Philosopher's atoi
long	ph_atoi(char *str)
{
	int		i;
	long	res;

	if (!str)
		return (NULL_VAL);
	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (res > 2147483647)
		return (OVERFLOW);
	return ((int)res);
}
