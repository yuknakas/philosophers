/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:40:28 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/23 10:47:18 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//libraries to be included
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>
# include "philo_line.h"

//structure to define values
typedef enum s_status
{
	YES	= 1,
	NO	= 0
}	t_status;

//structure for overall data
typedef struct s_data
{
	unsigned int	n_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	n_eat;
	int				is_dead;
	pthread_mutex_t	print_key;
	pthread_mutex_t	death_key;
	pthread_mutex_t	*fork_key;
	t_philo			*all_philos;
	time_t			start_time;
}	t_data;

typedef struct s_philo
{
	int				id_philo;
	pthread_mutex_t	fork[2];
	pthread_mutex_t	last_meal_key;
	time_t			last_meal;
	t_data			*data;
}	t_philo;

//functions

//main
int		main(int ac, char **av);

//initalize s_data
int		ph_init_gen_data(int ac, char **av, t_data *gen_data);
//errors
int		ph_error_input(char *error_str, char *sub_str);
//utils
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ph_destroy_data(t_data *data);

#endif