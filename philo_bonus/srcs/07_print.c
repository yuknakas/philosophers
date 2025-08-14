/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:25:23 by yuknakas          #+#    #+#             */
/*   Updated: 2025/08/15 06:33:31 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ph_print_status(t_philo *philo, t_status status)
{
	sem_wait(philo->data->sem_print);
	if (status == DEAD)
	{
		printf("%-5lu %-2d %s\n", ph_time_since_start(philo->data->start_time),
			philo->id_philo, STR_DEAD);
		return ;
	}
	if (status == TAKE_FORK)
		printf("%-5lu %-2d %s\n", ph_time_since_start(philo->data->start_time),
			philo->id_philo, STR_TAKE_FORK);
	else if (status == EAT)
		printf("%-5lu %-2d %s\n", ph_time_since_start(philo->data->start_time),
			philo->id_philo, STR_EAT);
	else if (status == SLEEP)
		printf("%-5lu %-2d %s\n", ph_time_since_start(philo->data->start_time),
			philo->id_philo, STR_SLEEP);
	else if (status == THINK)
		printf("%-5lu %-2d %s\n", ph_time_since_start(philo->data->start_time),
			philo->id_philo, STR_THINK);
	sem_post(philo->data->sem_print);
	return ;
}
