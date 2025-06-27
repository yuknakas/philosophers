/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:07:37 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/27 10:13:38 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void		*ph_philo(void *arg);
void		*ph_lone_philo(void *arg);
static int	_eat_routine(t_philo *philo);
static int	_sleep_think_routine(t_philo *philo);

void	*ph_philo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->data->consider_eat && philo->data->n_eat == 0)
		return (NULL);
	ph_wait_until(philo->data->start_time);
	if (!(philo->id_philo % 2))
		usleep(1000);
	while (1)
	{
		if (_eat_routine(philo) || _sleep_think_routine((philo)))
			break ;
	}
	return (NULL);
}

static int	_eat_routine(t_philo *philo)
{
	if (ph_check_sim_stop(philo->data, NO))
		return (1);
	pthread_mutex_lock(philo->fork1);
	ph_print_status(philo, TAKE_FORK);
	pthread_mutex_lock(philo->fork2);
	ph_print_status(philo, TAKE_FORK);
	ph_print_status(philo, EAT);
	pthread_mutex_lock(&philo->last_meal_key);
	philo->last_meal = ph_get_time_in_ms();
	pthread_mutex_unlock(&philo->last_meal_key);
	usleep(philo->data->t_eat * 1000);
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	pthread_mutex_lock(&philo->meal_count_key);
	if (philo->data->consider_eat && philo->meal_count != UINT_MAX)
		philo->meal_count++;
	pthread_mutex_unlock(&philo->meal_count_key);
	return (0);
}

static int	_sleep_think_routine(t_philo *philo)
{
	if (ph_check_sim_stop(philo->data, NO))
		return (1);
	ph_print_status(philo, SLEEP);
	usleep(philo->data->t_sleep * 1000);
	if (ph_check_sim_stop(philo->data, NO))
		return (1);
	ph_print_status(philo, THINK);
	usleep(philo->data->t_think * 1000);
	return (0);
}

void	*ph_lone_philo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	ph_wait_until(philo->data->start_time);
	ph_print_status(philo, TAKE_FORK);
	ph_wait_until(philo->data->start_time + philo->data->t_die);
	ph_print_status(philo, DEAD);
	return (NULL);
}
