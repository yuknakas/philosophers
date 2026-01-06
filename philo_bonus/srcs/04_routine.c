/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:46:14 by yuknakas          #+#    #+#             */
/*   Updated: 2026/01/06 14:23:03 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	eating(t_philo *philo)
{
	sem_wait(philo->data->sem_fork);
	ph_print_status(philo, TAKE_FORK);
	sem_wait(philo->data->sem_fork);
	ph_print_status(philo, TAKE_FORK);
	if (sim_alive(philo->data))
	{
		sem_post(philo->data->sem_fork);
		sem_post(philo->data->sem_fork);
		return (1);
	}
	philo->meal_count++;
	ph_print_status(philo, EAT);
	usleep(philo->data->t_eat * 1000);
	sem_wait(philo->data->sem_meal_count);
	philo->last_meal = ph_get_time_in_ms();
	sem_post(philo->data->sem_meal_count);
	sem_post(philo->data->sem_fork);
	sem_post(philo->data->sem_fork);
	return (0);
}

void	sleeping(t_philo *philo)
{
	if (sim_alive(philo->data))
		return ;
	ph_print_status(philo, SLEEP);
	usleep(philo->data->t_sleep * 1000);
	return ;
}

void	thinking(t_philo *philo)
{
	if (sim_alive(philo->data))
		return ;
	ph_print_status(philo, THINK);
	usleep(philo->data->t_think * 1000);
	return ;
}
