/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_supervise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 01:01:15 by yuknakas          #+#    #+#             */
/*   Updated: 2025/08/15 07:08:53 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static t_status	_is_starved(t_philo *philo);
static void		_end_sim(t_philo *philo);

void	*check_starve(void *addr)
{
	t_philo	*philo;

	philo = (t_philo *)addr;
	ph_wait_until(philo->data->start_time + 10);
	while (!_is_starved(philo))
		usleep(300);
	_end_sim(philo);
	return (NULL);
}

static t_status	_is_starved(t_philo *philo)
{
	time_t	meal;

	sem_wait(philo->data->sem_meal_count);
	meal = ph_get_time_in_ms() - philo->last_meal;
	sem_post(philo->data->sem_meal_count);
	if (meal >= philo->data->t_die)
		return (YES);
	return (NO);
}

static void	_end_sim(t_philo *philo)
{
	int	is_active;

	is_active = YES;
	sem_wait(philo->data->sem_stop_meal);
	if (*(int *)philo->data->sem_is_dead)
		is_active = NO;
	sem_post(philo->data->sem_is_dead);
	sem_post(philo->data->sem_stop_meal);
	if (is_active && philo->meal_count != philo->data->n_eat)
		ph_print_status(philo, DEAD);
	return ;
}
