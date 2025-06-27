/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:12:02 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/27 10:50:06 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int			main(int ac, char **av);
static int	_make_threads(t_data *gen_data);
static int	_join_threads(t_data *gen_data);

int	main(int ac, char **av)
{
	t_data	gen_data;

	if (ph_init_all(ac, av, &gen_data))
		return (1);
	_make_threads(&gen_data);
	_join_threads(&gen_data);
	ph_destroy_data(&gen_data);
	return (0);
}

static int	_make_threads(t_data *gen_data)
{
	unsigned int	i;

	i = 0;
	if (gen_data->n_philo == 0)
		return (0);
	if (gen_data->n_philo == 1)
	{
		if (pthread_create(&gen_data->all_philos[i].thread_id, NULL,
				ph_lone_philo, &gen_data->all_philos[i]))
			return (1);
		return (0);
	}
	while (i < gen_data->n_philo)
	{
		if (pthread_create(&gen_data->all_philos[i].thread_id, NULL,
				ph_philo, &gen_data->all_philos[i]))
			return (1);
		i++;
	}
	if (pthread_create(&gen_data->killer_id, NULL, ph_killer, gen_data))
		return (1);
	return (0);
}

static int	_join_threads(t_data *gen_data)
{
	unsigned int	i;

	i = 0;
	while (i < gen_data->n_philo)
	{
		if (pthread_join(gen_data->all_philos[i].thread_id, NULL))
			return (1);
		i++;
	}
	if (gen_data->n_philo > 1)
	{
		if (pthread_join(gen_data->killer_id, NULL))
			return (1);
	}
	return (0);
}
