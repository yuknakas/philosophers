/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 02:09:48 by yuknakas          #+#    #+#             */
/*   Updated: 2025/08/15 07:18:19 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static int	make_process(t_philo *philo);
static int	join_process(t_data *data);
static void	exit_child(t_data *data);

int	start_simulation(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->n_philo)
	{
		make_process(&data->all_philos[i]);
		i++;
	}
	join_process(data);
	return (0);
}

static int	make_process(t_philo *philo)
{
	int	ret_val;

	philo->process_id = fork();
	if (!philo->process_id)
	{
		pthread_create(&philo->checker_id, NULL, check_starve, philo);
		ret_val = ph_philo(philo);
		pthread_join(philo->checker_id, NULL);
		exit_child(philo->data);
		exit(ret_val);
	}
	return (0);
}

static int	join_process(t_data *data)
{
	unsigned int	i;
	int				exit_status;

	exit_status = 0;
	i = 0;
	while (i < data->n_philo && exit_status == 0)
	{
		waitpid(-1, &exit_status, 0);
		exit_status = WEXITSTATUS(exit_status);
		i++;
	}
	if (exit_status)
	{
		i = 0;
		while (i < data->n_philo)
		{
			kill(data->all_philos[i].process_id, SIGKILL);
			i++;
		}
	}
	return (exit_status);
}

static void	exit_child(t_data *data)
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
