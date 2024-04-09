/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:41:21 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/06 14:39:26 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Sends threads to their respective routines + joins them later
int	launch_threads(void)
{
	int			i;
	t_philo		*ptr;

	i = 1;
	ptr = var()->philo;
	if (pthread_create(&var()->monitor, NULL, (void *)monitor, NULL))
		return (THREAD_ERR);
	while (i <= var()->philo_nb)
	{
		if (pthread_create(&ptr->thread, NULL, (void *)routine, ptr))
			return (THREAD_ERR);
		ptr = ptr->next;
		i++;
	}
	ptr = var()->philo;
	pthread_join(var()->monitor, NULL);
	i = 1;
	while (i <= var()->philo_nb)
	{
		pthread_join(ptr->thread, NULL);
		ptr = ptr->next;
		i++;
	}
	return (0);
}

// Monitoring routine
void	monitor(void)
{
	int		i;
	t_philo	*ptr;

	ptr = var()->philo;
	i = 0;
	while (ptr && i != var()->philo_nb)
	{
		pthread_mutex_lock(var()->monit_mutex);
		if (ptr->meals == var()->meal_nb)
			i++;
		if (get_mls() >= ptr->timer && ptr->meals != var()->meal_nb)
		{
			pthread_mutex_unlock(var()->monit_mutex);
			pthread_mutex_lock(var()->death_mutex);
			var()->death = 1;
			pthread_mutex_unlock(var()->death_mutex);
			print_msg(ptr, DIE);
			return ;
		}
		pthread_mutex_unlock(var()->monit_mutex);
		if (var()->philo_nb != 1)
			ptr = ptr->next;
	}
}

// Philosophers' routine
void	routine(t_philo *philo)
{
	if (var()->philo_nb == 1)
	{
		print_msg(philo, FORK);
		ph_usleep(var()->death_mls);
		return ;
	}
	if (philo->nb % 2 != 0)
		ph_usleep((var()->eat_mls * 2) - var()->sleep_mls);
	while (death_checker() && philo->meals != var()->meal_nb)
	{
		philo_eat(philo);
		if (var()->philo_nb % 2 == 0 && var()->eat_mls == var()->sleep_mls)
			continue ;
		if (death_checker() && philo->meals != var()->meal_nb)
		{
			print_msg(philo, THINK);
			ph_usleep((var()->eat_mls * 2) - var()->sleep_mls);
		}
	}
	if (death_checker() && (philo->meals == var()->meal_nb))
		print_msg(philo, THINK);
}

// Locks forks + eats
void	philo_eat(t_philo *philo)
{
	pthread_mutex_t	*fork_one;
	pthread_mutex_t	*fork_two;

	if (!death_checker())
		return ;
	fork_one = philo->prev_fork->mutex;
	fork_two = philo->fork->mutex;
	if (philo->nb % 2 != 0)
	{
		fork_one = philo->fork->mutex;
		fork_two = philo->prev_fork->mutex;
	}
	pthread_mutex_lock(fork_one);
	pthread_mutex_lock(fork_two);
	pthread_mutex_lock(var()->monit_mutex);
	philo->timer = get_mls() + var()->death_mls;
	philo->meals++;
	pthread_mutex_unlock(var()->monit_mutex);
	print_msg(philo, FORK);
	print_msg(philo, EAT);
	ph_usleep(var()->eat_mls);
	pthread_mutex_unlock(fork_two);
	pthread_mutex_unlock(fork_one);
	philo_sleep(philo);
}

// Goes to sleep
void	philo_sleep(t_philo *philo)
{
	if (!death_checker())
		return ;
	print_msg(philo, SLEEP);
	ph_usleep(var()->sleep_mls);
}
