/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_killer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:36:12 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/21 16:24:13 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int			ph_check_sim_stop(t_data *data, int kill_switch);
static void	_check_end_condition(t_data *data);

int	ph_check_sim_stop(t_data *data, int kill_switch)
{
	int	record;

	pthread_mutex_lock(&data->sim_stop_key);
	if (kill_switch == YES)
	data->sim_stop = 1;
	record = data->sim_stop;
	pthread_mutex_unlock(&data->sim_stop_key);
	return (record);
}

static void	_check_end_condition(t_data *data)
{
	t_philo			*current_philo;
	unsigned int	i;
	t_status		all_full;

	current_philo = data->all_philos;
	i = 0;
	all_full = YES;
	while (i++ < data->n_eat)
	{
		pthread_mutex_lock(&current_philo->last_meal_key);
		if ((ph_get_time_in_ms() - current_philo->last_meal) > data->t_die)
		{
			ph_print_status(current_philo, DEAD);
			ph_check_sim_stop(data, YES);
			pthread_mutex_unlock(&current_philo->last_meal_key);
			return;
		}
		pthread_mutex_unlock(&current_philo->last_meal_key);
		if (!(data->consider_eat && current_philo->meal_count > data->n_eat))
			all_full = NO;
		current_philo++;
	}
	if (all_full == YES)
		ph_check_sim_stop(data, YES);
}
