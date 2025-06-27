/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:40:28 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/27 10:56:00 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

//libraries to be included
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <semaphore.h>
# include "philo_line.h"

//structure to define values
typedef enum s_status
{
	NO			=	0,
	YES			=	1,
	TAKE_FORK	=	2,
	EAT			=	3,
	SLEEP		=	4,
	THINK		=	5,
	DEAD		=	6,
}	t_status;

//structure for overall data
typedef struct s_philo	t_philo;

typedef struct s_data
{
	unsigned int	n_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	t_think;
	unsigned int	n_eat;
	int				consider_eat;
	sem_t			sim_stop_key;
	sem_t			print_key;
	sem_t			fork_key;
	t_philo			*all_philos;
	time_t			start_time;
	pid_t			killer_id;
}	t_data;

typedef struct s_philo
{
	unsigned int	id_philo;
	unsigned int	meal_count;
	sem_t			meal_count_key;
	sem_t			last_meal_key;
	time_t			last_meal;
	pid_t			thread_id;
	t_data			*data;
}	t_philo;

//functions

//main
int		main(int ac, char **av);

//initalize s_data
int		ph_init_all(int ac, char **av, t_data *gen_data);

//philos
void	*ph_philo(void *arg);
void	*ph_lone_philo(void *arg);

//killer
void	*ph_killer(void *arg);
int		ph_check_sim_stop(t_data *data, int kill_switch);

//print
int		ph_print_status(t_philo *philo, t_status status);

//errors
int		ph_error_input(char *error_str, char *sub_str);

//utils
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ph_destroy_data(t_data *data);

//time
time_t	ph_get_time_in_ms(void);
time_t	ph_time_since_start(time_t start_time);
void	ph_wait_until(time_t start_time);

#endif