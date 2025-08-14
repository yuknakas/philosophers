/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:40:28 by yuknakas          #+#    #+#             */
/*   Updated: 2025/08/14 15:30:05 by yuknakas         ###   ########.fr       */
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
# include <sys/stat.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include "philo_line_bon.h"

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
	sem_t			*sem_print;
	sem_t			*sem_fork;
	sem_t			*sem_full;
	sem_t			*sem_end;
	t_philo			*all_philos;
	time_t			start_time;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	unsigned int	id_philo;
	unsigned int	meal_count;
	sem_t			*sem_n_meal;
	time_t			last_meal;
	sem_t			*sem_t_meal;
	pid_t			process_id;
}	t_philo;

//functions

//main
int		main(int ac, char **av);

//init
int		ph_init_all(t_data *all_data, int ac, char **av);

//philos
int		ph_philo(t_philo *philo);
int		name_sem_philo(char **dest_t, char **dest_n, unsigned int philo_id);

//finish
void	*ph_check_all_full(void *arg);
void	ph_finish_simulation(t_data *data);
void 	ph_clean_all(t_data *data);

//print
void	ph_print_status(t_philo *philo, t_status status);

//errors
int		ph_error_input(char *error_str, char *sub_str);

//utils
int		ft_isspace(int c);
int		ft_isdigit(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

//time
time_t	ph_get_time_in_ms(void);
time_t	ph_time_since_start(time_t start_time);
void	ph_wait_until(time_t start_time);

#endif