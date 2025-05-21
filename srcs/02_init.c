/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:14:27 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/21 16:55:16 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	_atoui_p(unsigned int *dest, char *str);
static int	_init_data_mutex(int ac, t_data *gen_data);
static int	_make_init_mutex(pthread_mutex_t *mutex);

int	ph_init_gen_data(int ac, char **av, t_data *gen_data)
{
	if (ac != 5 && ac != 6)
		return (ph_error_input(STR_USG, STR_PRG_NAME));
	if (_atoui_p(gen_data->n_philo, av[1])
		|| _atoui_p(gen_data->t_die, av[2])
		|| _atoui_p(gen_data->t_eat, av[3])
		|| _atoui_p(gen_data->t_sleep, av[4]))
		return (1);
	if (ac == 6)
		if (_atoui_p(gen_data->n_eat, av[5]))
			return (1);
	if (_init_data_mutex(ac, gen_data))
		return (1);
	return (0);
}

static int	_atoui_p(unsigned int *dest, char *str)
{
	while (ft_isspace(*str))
		str++;
	*dest = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			(*dest)++;
		str++;
	}
	if (*dest % 2)
		return (ph_error_input(STR_UINT_ERR, STR_PRG_NAME));
	*dest = 0;
	while (ft_isdigit(*str))
	{
		if (*dest > (UINT_MAX - (*str - '0')) / 10)
			return (ph_error_input(STR_UINT_ERR, STR_PRG_NAME));
		*dest = *dest * 10 + (*str - '0');
		str++;
	}
	if (*str)
		return (ph_error_input(STR_UINT_ERR, STR_PRG_NAME));
	return (0);
}

static int	_init_data_mutex(int ac, t_data *gen_data)
{
	unsigned int	i;

	if (_make_init_mutex(gen_data->print_key))
		return (1);
	i = 0;
	gen_data->fork_key = malloc((gen_data->n_philo + 1)
			* sizeof(pthread_mutex_t *));
	if (!gen_data->fork_key)
	{
		free(gen_data->print_key);
		return (ph_error_input(STR_MALLOC_ERR, STR_PRG_NAME));
	}
	while (i < gen_data->n_philo)
	{
		if (_make_init_mutex((gen_data->fork_key)[i]))
			return (ph_destroy_data(gen_data));
		i++;
	}
	gen_data->fork_key[i] = NULL;
	return (0);
}

static int	_make_init_mutex(pthread_mutex_t *mutex)
{
	mutex = malloc(sizeof(pthread_mutex_t));
	if (!mutex)
		return (ph_error_input(STR_MALLOC_ERR, STR_PRG_NAME));
	if (pthread_mutex_init(mutex, NULL))
	{
		free(mutex);
		return (1);
	}
	return (0);
}
