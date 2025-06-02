/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:07:37 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/02 16:32:59 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*_philo(void *arg);
static void	_lone_philo(t_data *gen_data);

int	ph_make_threads(t_data *gen_data)
{
	int	i;

	if (gen_data->n_philo = 1)
		return (_lone_philo(gen_data));
	i = 0;
	while (i < gen_data->n_philo)
	{
		if (pthread_create(&gen_data->all_philos[i].thread_id, NULL,
				_philo, &gen_data->all_philos[i]))
				return (1);
		i++;
	}
	return (0);
}

static void	*_philo(void *arg)
{
	t_philo	*philo;

	philo = arg;
}

static int	_lone_philo(t_philo *philo)
{
	ph_print_status(philo, TAKE_FORK, &philo->data->print_key);
	ph_print_status(philo, TAKE_FORK, &philo->data->print_key);
	return (0);
}
