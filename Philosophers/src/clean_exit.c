/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:40:32 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/06 15:48:27 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Cleans + sends to error printer
int	clean_all(int err)
{
	if (err)
		err_message(err);
	if (var()->msg_mutex)
	{
		pthread_mutex_destroy(var()->msg_mutex);
		free(var()->msg_mutex);
	}
	if (var()->death_mutex)
	{
		pthread_mutex_destroy(var()->death_mutex);
		free(var()->death_mutex);
	}
	if (var()->death_mutex)
	{
		pthread_mutex_destroy(var()->monit_mutex);
		free(var()->monit_mutex);
	}
	destroy_forks();
	destroy_philos();
	return (err);
}

// Prints message according to error
void	err_message(int err)
{
	char	*msg;

	if (err == PARAM_NB)
		msg = "Error: Invalid number of parameters\n";
	if (err == PARAM_TYPE)
		msg = "Error: Parameters must be of numerical values\n";
	if (err == NEG_PARAM)
		msg = "Error: Negative values not allowed\n";
	if (err == PHILO_NB)
		msg = "Error: Too many philosophers!\n";
	if (err == OVERFLOW)
		msg = "Error: int overflow! Be reasonable!\n";
	if (err == NULL_VAL)
		msg = "Error: values must be superior to 0\n";
	if (err == NODE_ERR)
		msg = "Error: couldn't create node\n";
	if (err == MUTEX_ERR)
		msg = "Error: couldn't create mutex\n";
	if (err == THREAD_ERR)
		msg = "Error: couldn't launch thread\n";
	write(2, msg, ph_strlen(msg));
}

// Destroy fork mutexes + frees forks
void	destroy_forks(void)
{
	int	i;

	i = 1;
	if (!var()->philo)
		return ;
	while (i <= var()->philo->nb)
	{
		if (var()->philo->fork->mutex)
		{
			pthread_mutex_destroy(var()->philo->fork->mutex);
			free(var()->philo->fork->mutex);
			free(var()->philo->fork);
			var()->philo->fork = NULL;
			if (var()->philo_nb == 1)
				return ;
			var()->philo->next->prev_fork = NULL;
		}
		var()->philo = var()->philo->next;
		i++;
	}
}

// frees philo
void	destroy_philos(void)
{
	t_philo	*ptr;

	if (!var()->philo)
		return ;
	if (var()->philo_nb == 1)
	{
		free(var()->philo);
		return ;
	}
	var()->philo->prev->next = NULL;
	while (var()->philo)
	{
		ptr = var()->philo;
		var()->philo = var()->philo->next;
		free(ptr);
	}
}
