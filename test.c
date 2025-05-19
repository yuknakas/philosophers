/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:47:53 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/19 16:39:51 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*_thread_call(void *a)
{
	if (a)
		return (NULL);
	int b = 1000;
	while (b-- > 0)
	{
		write(1, "thread called", 13);
		write(1, "\n", 1);
	}
	printf("thread done\n");
	return (NULL);
}

int main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_create(&thread1, NULL, &_thread_call, NULL);
	usleep(1);
	pthread_create(&thread2, NULL, &_thread_call, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	return (0);
}
