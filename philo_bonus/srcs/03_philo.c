/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:41:25 by yuknakas          #+#    #+#             */
/*   Updated: 2025/08/15 07:17:29 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ph_philo(t_philo *philo);

int	ph_philo(t_philo *philo)
{
	if (philo->data->n_philo == 1)
	{
		ph_wait_until(philo->data->start_time);
		ph_print_status(philo, TAKE_FORK);
		ph_wait_until(philo->data->start_time + philo->data->t_die);
		return (0);
	}
	ph_wait_until(philo->data->start_time);
	usleep(philo->id_philo % 2 * 1000);
	while (!sim_alive(philo->data))
	{
		eating(philo);
		if (philo->meal_count == philo->data->n_eat)
			return (0);
		sleeping(philo);
		thinking(philo);
	}
	return (1);
}

int	sim_alive(t_data *data)
{
	sem_wait(data->sem_stop_meal);
	if (*(int *)data->sem_is_dead)
	{
		sem_post(data->sem_stop_meal);
		return (YES);
	}
	sem_post(data->sem_stop_meal);
	return (NO);
}
