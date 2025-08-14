/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:10:40 by yuknakas          #+#    #+#             */
/*   Updated: 2025/08/14 15:29:57 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = ft_strlen(src);
	if (size == 0)
		return (counter);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (counter);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
