/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:40:28 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/21 09:23:17 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//libraries to be included
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include "philo_line.h"

# define MAX_PHILOS 300
# define STR_MAX_PHILOS "300"

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
	pthread_mutex_t	*print_key;
	pthread_mutex_t	**fork_key;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	n_eat;
	unsigned int	is_active;
}	t_data;

typedef struct s_philo
{
	pthread_mutex_t	*print_key;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

//functions

//errors
int	ph_error_input(char *error_str, char *sub_str);


#endif