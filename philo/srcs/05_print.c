/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:21:04 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/27 15:27:33 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int			ph_print_status(t_philo *philo, t_status status);
static void	_print_normal(t_philo *philo, t_status status);

int	ph_print_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->data->print_key);
	if (status == DEAD)
	{
		printf("%lu %d %s\n", ph_time_since_start(philo->data->start_time),
			philo->id_philo, STR_DEAD);
		pthread_mutex_unlock(&philo->data->print_key);
		return (0);
	}
	if (ph_check_sim_stop(philo->data, NO))
	{
		pthread_mutex_unlock(&philo->data->print_key);
		return (1);
	}
	_print_normal(philo, status);
	pthread_mutex_unlock(&philo->data->print_key);
	return (0);
}

static void	_print_normal(t_philo *philo, t_status status)
{
	if (status == TAKE_FORK)
		printf("%lu %d %s\n", ph_time_since_start(philo->data->start_time),
			philo->id_philo, STR_TAKE_FORK);
	else if (status == EAT)
		printf("%lu %d %s\n", ph_time_since_start(philo->data->start_time),
			philo->id_philo, STR_EAT);
	else if (status == SLEEP)
		printf("%lu %d %s\n", ph_time_since_start(philo->data->start_time),
			philo->id_philo, STR_SLEEP);
	else if (status == THINK)
		printf("%lu %d %s\n", ph_time_since_start(philo->data->start_time),
			philo->id_philo, STR_THINK);
	return ;
}