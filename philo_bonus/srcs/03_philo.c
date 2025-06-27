/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:35:25 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/27 15:54:59 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int			ph_philo(t_philo *philo);
static int	_eat_routine(t_philo *philo);
static int	_sleep_think_routine(t_philo *philo);
static void	*_check_death(void *arg);
static void	*_check_full(void *arg);

int	ph_philo(t_philo *philo)
{
	pthread_t	tmp;

	if (philo->data->consider_eat && philo->data->n_eat == 0)
		return (0);
	if (pthread_create(&tmp, NULL, _check_death, philo))
		return (ph_error_input(STR_THREAD_ERR, STR_PRG_NAME));
	pthread_detach(tmp);
	if (philo->data->consider_eat)
	{
		if (pthread_create(&tmp, NULL, _check_full, philo))
			return (ph_error_input(STR_THREAD_ERR, STR_PRG_NAME));
		pthread_detach(tmp);
	}
	ph_wait_until(philo->data->start_time);
	if (!(philo->id_philo % 2))
		usleep(1000);
	while (1)
	{
		if (_eat_routine(philo) || _sleep_think_routine((philo)))
			break ;
	}
	exit(0);
}

static int	_eat_routine(t_philo *philo)
{
	sem_wait(philo->data->sem_fork);
	ph_print_status(philo, TAKE_FORK);
	sem_wait(philo->data->sem_fork);
	ph_print_status(philo, TAKE_FORK);
	ph_print_status(philo, EAT);
	sem_wait(philo->sem_t_meal);
	philo->last_meal = ph_get_time_in_ms();
	sem_post(philo->sem_t_meal);
	usleep(philo->data->t_eat * 1000);
	sem_post(philo->data->sem_fork);
	sem_post(philo->data->sem_fork);
	sem_wait(philo->sem_n_meal);
	if (philo->data->consider_eat && philo->meal_count != UINT_MAX)
		philo->meal_count++;
	sem_post(philo->sem_n_meal);
	return (0);
}

static int	_sleep_think_routine(t_philo *philo)
{
	ph_print_status(philo, SLEEP);
	usleep(philo->data->t_sleep * 1000);
	ph_print_status(philo, THINK);
	usleep(philo->data->t_think * 1000);
	return (0);
}

static void	*_check_death(void *arg)
{
	t_philo	*philo;

	philo = arg;
	ph_wait_until(philo->data->start_time);
	while (1)
	{
		sem_wait(philo->sem_t_meal);
		if (ph_get_time_in_ms() - philo->last_meal >= philo->data->t_die)
		{
			ph_print_status(philo, DEAD);
			sem_post(philo->data->sem_end);
			return (NULL);
		}
		sem_post(philo->sem_t_meal);
	}
	return (NULL);
}

static void	*_check_full(void *arg)
{
	t_philo	*philo;

	philo = arg;
	ph_wait_until(philo->data->start_time);
	while (1)
	{
		sem_wait(philo->sem_n_meal);
		if (philo->meal_count >= philo->data->n_eat)
		{
			sem_post(philo->data->sem_full);
			return (NULL);
		}
		sem_post(philo->sem_n_meal);
	}
	return (NULL);
}
