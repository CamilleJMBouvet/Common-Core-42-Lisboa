/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:40:42 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/05 22:18:36 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Creates philo circle
int	init_philo(void)
{
	int	i;
	int	err;

	i = 1;
	err = 0;
	while (i <= var()->philo_nb)
		if (!insert_philo(create_philo(i++)))
			err = NODE_ERR;
	if (err)
	{
		clean_all(err);
		return (0);
	}
	return (1);
}

// Creates new philo node
t_philo	*create_philo(int nb)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->meals = 0;
	new->timer = get_mls() + var()->death_mls;
	new->thread = 0;
	new->prev_fork = NULL;
	new->fork = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

// Inserts node in a circled linked list
int	insert_philo(t_philo *philo)
{
	t_philo	*ptr;

	if (!philo)
		return (0);
	if (!var()->philo)
	{
		var()->philo = philo;
		return (1);
	}
	ptr = var()->philo;
	while (ptr->next)
		ptr = ptr->next;
	philo->prev = ptr;
	ptr->next = philo;
	if (philo->nb == var()->philo_nb)
	{
		var()->philo->prev = philo;
		philo->next = var()->philo;
	}
	return (1);
}

// Assign reachable forks for each philosopher
int	assign_fork(void)
{
	int		i;

	if (!var()->philo)
		return (0);
	i = 1;
	while (i <= var()->philo_nb)
	{
		if (!var()->philo->fork)
		{
			var()->philo->fork = create_fork();
			if (!var()->philo->fork)
			{
				clean_all(NODE_ERR);
				return (0);
			}
			if (var()->philo_nb == 1)
				break ;
			var()->philo->next->prev_fork = var()->philo->fork;
		}
		var()->philo = var()->philo->next;
		i++;
	}
	return (1);
}

// Creates fork node
t_fork	*create_fork(void)
{
	t_fork	*new;

	new = malloc(sizeof(t_fork));
	if (!new)
		return (NULL);
	new->locked = 0;
	new->mutex = malloc(sizeof(pthread_mutex_t));
	if (!new->mutex)
	{
		free(new);
		return (NULL);
	}
	if (pthread_mutex_init(new->mutex, NULL))
	{
		free(new->mutex);
		free(new);
		return (NULL);
	}
	return (new);
}
