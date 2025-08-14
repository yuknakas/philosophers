/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_philo_sem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:13:29 by yuknakas          #+#    #+#             */
/*   Updated: 2025/08/14 15:28:31 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static int	_dignbr(long nb)
{
	int		count;

	count = 1;
	while (10 <= nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static char	*ft_uitoa(unsigned int n)
{
	int		i;
	char	*ans;

	i = _dignbr(n);
	ans = malloc((i + 1) * sizeof(char));
	if (ans == NULL)
		return (NULL);
	ans[i] = '\0';
	while (10 <= n)
	{
		ans[i - 1] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	ans[i - 1] = (n % 10) + '0';
	return (ans);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ans = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (ans == NULL)
		return (NULL);
	ft_strlcpy(ans, s1, (s1_len + 1));
	ft_strlcpy((ans + s1_len), s2, (s2_len + 1));
	return (ans);
}

int	name_sem_philo(char **dest_t, char **dest_n, unsigned int philo_id)
{
	char	*id_char;
	
	id_char = ft_uitoa(philo_id);
	if (!id_char)
		return (1);
	*dest_t = ft_strjoin("/sem_t_meal", id_char);
	*dest_n = ft_strjoin("/sem_n_meal", id_char);
	if (!dest_t || !dest_n)
		return (1);
	free(id_char);
	return (0);
}