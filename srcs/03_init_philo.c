/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:21:54 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/23 10:49:05 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	_philo_make(t_data *gen_data, t_philo *philo, int nb_philo);

int	ph_init_philo(t_data *gen_data)
{
	int	i;

	gen_data->all_philos = malloc((gen_data->n_philo + 1) * sizeof(t_philo));
	if (!gen_data->all_philos)
		return (1);
	i = 1;
	while (i < gen_data->n_philo + 1)
	{
		_philo_make(gen_data, &gen_data->all_philos[i], i);
		i++;
	}
	return (0);
}

static void	_philo_make(t_data *gen_data, t_philo *philo, int nb_philo)
{
	philo->id_philo = nb_philo;
	philo->fork[0] = gen_data->fork_key[nb_philo - (nb_philo % 2)];
	philo->fork[1] = gen_data->fork_key[nb_philo + (nb_philo % 2 - 1)];
	if (pthread_mutex_init(&philo->last_meal_key))
	return (1);
	philo->data = gen_data;
}
