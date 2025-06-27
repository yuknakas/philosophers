/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:13:47 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/27 15:58:25 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void		*ph_check_all_full(void *arg);
void		ph_finish_simulation(t_data *data);
void 		ph_clean_all(t_data *data);
static void	_sem_safe_close(sem_t *addr);

void	*ph_check_all_full(void *arg)
{
	unsigned int	i;
	t_data			*data;

	data = arg;
	i = 0;
	while (i < data->n_philo)
	{
		sem_wait(data->sem_full);
		i++;
	}
	sem_wait(data->sem_print);
	sem_post(data->sem_end);
	return (NULL);
}

void	ph_finish_simulation(t_data *data)
{
	unsigned int	i;

	i = 0;
	sem_wait(data->sem_end);
	while (i < data->n_philo)
	{
		kill(data->all_philos[i].process_id, SIGKILL);
		i++;
	}
	ph_clean_all(data);
}

void ph_clean_all(t_data *data)
{
	unsigned int	i;

	if (!data)
		return ;
	_sem_safe_close(data->sem_print);
	_sem_safe_close(data->sem_fork);
	_sem_safe_close(data->sem_full);
	_sem_safe_close(data->sem_end);
	i = 0;
	if (!data->all_philos)
		return ;
	while (i++ < data->n_philo)
	{
		_sem_safe_close(data->all_philos[i].sem_n_meal);
		_sem_safe_close(data->all_philos[i].sem_t_meal);
	}
	free(data->all_philos);
}

static void	_sem_safe_close(sem_t *addr)
{
	if (!addr)
		return ;
	sem_close(addr);
	return ;
}
