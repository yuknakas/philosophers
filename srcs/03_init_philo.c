/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:21:54 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/23 10:26:26 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ph_init_philo(t_data *gen_data)
{
	
}

static void	_philo_make(t_data *gen_data, t_philo *philo, int nb_philo)
{
	philo->id_philo = nb_philo;
	philo->fork[0] = gen_data->fork_key[nb_philo - (nb_philo % 2)];
	philo->fork[1] = gen_data->fork_key[nb_philo + (nb_philo % 2 - 1)];
	philo->data = gen_data;
}