/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:25:23 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/27 15:57:33 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ph_print_status(t_philo *philo, t_status status)
{
	sem_wait(philo->data->sem_print);
	if (status == DEAD)
	{
		printf("%lu %d %s\n", ph_time_since_start(philo->data->start_time),
			philo->id_philo, STR_DEAD);
		return ;
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
	sem_post(philo->data->sem_print);
	return ;
}
