/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:10:40 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/21 16:54:38 by yuknakas         ###   ########.fr       */
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

	if (data->print_key)
	{
		pthread_mutex_destroy(data->print_key);
		free(data->print_key);
	}
	i = 0;
	if (!data->fork_key)
		return (1);
	while (data->fork_key[i])
	{
		pthread_mutex_destroy(data->fork_key[i]);
		free(data->fork_key[i]);
		i++;
	}
	free(data->fork_key);
	return (1);
}
