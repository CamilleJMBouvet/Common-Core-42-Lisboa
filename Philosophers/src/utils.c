/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:41:29 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/05 22:33:53 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Philosopher's strlen
int	ph_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Gets timestamp since start of programme
long	get_mls(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - var()->start_time);
}

// Prints philo's activity
void	print_msg(t_philo *philo, int code)
{
	pthread_mutex_lock(var()->msg_mutex);
	if (death_checker())
	{
		if (code == FORK)
		{
			printf(TIME"%li"PHIL" %i "PINK"has taken a fork\n"R, \
				get_mls(), philo->nb);
			if (var()->philo_nb != 1)
				printf(TIME"%li"PHIL" %i "PINK"has taken a fork\n"R, \
				get_mls(), philo->nb);
		}
		if (code == EAT)
			printf(TIME"%li"PHIL" %i "PURPLE"is eating\n"R, \
				get_mls(), philo->nb);
		if (code == SLEEP)
			printf(TIME"%li"PHIL" %i "BLUE"is sleeping\n"R, \
				get_mls(), philo->nb);
		if (code == THINK)
			printf(TIME"%li"PHIL" %i "GREEN"is thinking\n", \
				get_mls(), philo->nb);
	}
	if (code == DIE)
		printf(TIME"%li"PHIL" %i "RED"died\n"R, \
				get_mls(), philo->nb);
	pthread_mutex_unlock(var()->msg_mutex);
}

// Philosopher's usleep
void	ph_usleep(long mls)
{
	mls += get_mls();
	while (get_mls() < mls)
	{
		if (!death_checker())
			return ;
		usleep(100);
	}
}

// Checks if 1 philo is dead
int	death_checker(void)
{
	pthread_mutex_lock(var()->death_mutex);
	if (var()->death)
	{
		pthread_mutex_unlock(var()->death_mutex);
		return (0);
	}
	pthread_mutex_unlock(var()->death_mutex);
	return (1);
}
