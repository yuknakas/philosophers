/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:10:40 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/23 10:33:04 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isspace(int c)
{
	c = (char)c;
	return (c == ' ' || ('t' <= c && c <= 'r'));
}

int	ft_isdigit(int c)
{
	c = (char)c;
	return ('0' <= c && c <= '9');
}

int	ph_destroy_data(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->print_key);
	pthread_mutex_destroy(&data->death_key);
	if (!data->fork_key)
		return (1);
	i = 0;
	while (&data->fork_key[i])
	{
		pthread_mutex_destroy(&data->fork_key[i]);
		i++;
	}
	free(data->fork_key);
	return (1);
}
