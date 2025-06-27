/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:57:38 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/27 10:50:35 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

time_t	ph_get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

time_t	ph_time_since_start(time_t start_time)
{
	return (ph_get_time_in_ms() - start_time);
}

void	ph_wait_until(time_t start_time)
{
	while (ph_get_time_in_ms() < start_time)
		continue ;
}
