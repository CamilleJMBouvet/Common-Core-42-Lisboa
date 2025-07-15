/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:44:44 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/05 22:18:47 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// -LIBRARIES-
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

// -CONSTANTS-
//Error codes
# define PARAM_NB	-1
# define PARAM_TYPE	-2
# define NEG_PARAM	-3
# define PHILO_NB	-4
# define OVERFLOW	-5
# define NULL_VAL	-6
# define NODE_ERR	-7
# define THREAD_ERR	-8
# define MUTEX_ERR	-9
//Message codes
# define FORK		1
# define EAT		2
# define SLEEP		3
# define THINK		4
# define DIE		5
//Colours
# define TIME		"\001\033[1;37m\002"
# define PHIL		"\001\033[0m\002\t\001\033[1m\002"
# define PINK		"\001\033[1;38;5;225m\002"
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define GREEN		"\001\033[1;38;2;174;231;202m\002"
# define RED		"\001\033[1;31m\002"
# define R			"\001\033[1;00m\002"

// -STRUCTS-
// Fork struct
typedef struct s_fork
{
	int				locked;
	pthread_mutex_t	*mutex;
}	t_fork;
// Philo circular linked list
typedef struct s_philo
{
	int				nb;
	int				meals;
	long			timer;
	pthread_t		thread;
	t_fork			*prev_fork;
	t_fork			*fork;
	struct s_philo	*prev;
	struct s_philo	*next;
}	t_philo;
// General variables struct
typedef struct s_var
{
	int				death;
	int				philo_nb;
	long			death_mls;
	long			eat_mls;
	long			sleep_mls;
	int				meal_nb;
	long			start_time;
	t_philo			*philo;
	pthread_t		monitor;
	pthread_mutex_t	*msg_mutex;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	*monit_mutex;
}	t_var;

// -FUNCTIONS-
// Starting up
t_var			*var(void);
int				main(int ac, char **av);
// Parameter checker
int				param_check(int ac, char **av);
int				format_check(char *arg);
// Var struct initialization
int				init_var(char **av);
int				parse_params(char **av);
pthread_mutex_t	*create_mutexes(void);
long			ph_atoi(char *str);
// Philo + fork structs initialization
int				init_philo(void);
t_philo			*create_philo(int nb);
int				insert_philo(t_philo *philo);
int				assign_fork(void);
t_fork			*create_fork(void);
// Routine
int				launch_threads(void);
void			monitor(void);
void			routine(t_philo *philo);
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
// Utils
int				ph_strlen(char *str);
long			get_mls(void);
void			print_msg(t_philo *philo, int code);
void			ph_usleep(long mls);
int				death_checker(void);
// Error handling
int				clean_all(int err);
void			err_message(int err);
void			destroy_forks(void);
void			destroy_philos(void);

#endif
