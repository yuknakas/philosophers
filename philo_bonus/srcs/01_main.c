/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:41:43 by yuknakas          #+#    #+#             */
/*   Updated: 2025/08/15 07:16:32 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static void	clean_up(t_data *data);

int	main(int ac, char **av)
{
	t_data		all_data;
	int			err_val;

	err_val = ph_init_all(&all_data, ac, av);
	if (err_val == 2)
		return (ph_error_input(STR_USG, STR_PRG_NAME));
	if (err_val == 1)
	{
		clean_up(&all_data);
		return (1);
	}
	start_simulation(&all_data);
	clean_up(&all_data);
	return (0);
}

static void	clean_up(t_data *data)
{
	sem_close(data->sem_is_dead);
	sem_close(data->sem_print);
	sem_close(data->sem_fork);
	sem_close(data->sem_meal_count);
	sem_close(data->sem_stop_meal);
	sem_unlink("/sem_print");
	sem_unlink("/sem_fork");
	sem_unlink("/sem_meal_count");
	sem_unlink("/sem_is_dead");
	sem_unlink("/sem_stop_meal");
	free(data->all_philos);
}
