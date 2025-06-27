/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:41:43 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/27 16:03:27 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static int	_p_philos(t_data *data);

int	main(int ac, char **av)
{
	t_data		all_data;
	pthread_t	tmp;
	int			err_val;
	
	err_val = ph_init_all(&all_data, ac, av);
	if (err_val == 2)
		return (1);
	if (err_val ==11)
	{
		ph_clean_all(&all_data);
		return (1);
	}
	if (_p_philos(&all_data))
		return (1);
	pthread_create(&tmp, NULL, ph_check_all_full, &all_data);
	pthread_detach(tmp);
	ph_finish_simulation(&all_data);
	return (0);
}

static int	_p_philos(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->all_philos[i].process_id = fork();
		if (data->all_philos[i].process_id == -1)
			ph_error_input(STR_FORK_ERR, STR_PRG_NAME);
		if (data->all_philos[i].process_id == 0)
			ph_philo(&data->all_philos[i]);
		i++;
	}
	return (0);
}
