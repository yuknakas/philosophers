/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:07:37 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/21 16:05:26 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void		*ph_philo(void *arg);
void		*ph_lone_philo(void *arg);

void	*ph_philo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	return (NULL);
}

void	*ph_lone_philo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	ph_print_status(philo, TAKE_FORK);
	ph_wait_until(philo->data->start_time + philo->data->t_die);
	ph_print_status(philo, DEAD);
	return (NULL);
}
