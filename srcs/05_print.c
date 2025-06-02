/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:21:04 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/02 15:59:59 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ph_print_status(t_philo *philo, t_status status, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	if (philo->data->is_dead)
	{
		pthread_mutex_unlock(mutex);
		return (1);
	}
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
	else if (status == DEAD)
		printf("%lu %d %s\n", ph_time_since_start(philo->data->start_time),
			philo->id_philo, STR_DEAD);
	pthread_mutex_unlock(mutex);
	return (0);
}
