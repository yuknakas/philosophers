/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:14:27 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/23 12:07:15 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int			ph_init_gen_data(int ac, char **av, t_data *gen_data);
static int	_atoui_p(unsigned int *dest, char *str);
static int	_init_data_mutex(int ac, t_data *gen_data);
static int	_init_philos(t_data *gen_data);
static int	_philo_make(t_data *gen_data, t_philo *philo, int nb_philo);

int	ph_init_gen_data(int ac, char **av, t_data *gen_data)
{
	if (ac != 5 && ac != 6)
		return (ph_error_input(STR_USG, STR_PRG_NAME));
	if (_atoui_p(gen_data->n_philo, av[1])
		|| _atoui_p(gen_data->t_die, av[2])
		|| _atoui_p(gen_data->t_eat, av[3])
		|| _atoui_p(gen_data->t_sleep, av[4]))
		return (1);
	gen_data->consider_eat = NO;
	if (ac == 6)
	{
		if (_atoui_p(gen_data->n_eat, av[5]))
			return (1);
		gen_data->consider_eat = YES;
	}
	if (_init_data_mutex(ac, gen_data) || _init_philos(gen_data))
		return (1);
	gen_data->is_dead = 0;
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

	if (pthread_mutex_init(&gen_data->print_key, NULL))
		return (1);
	if (pthread_mutex_init(&gen_data->death_key, NULL))
		return (1);
	i = 0;
	gen_data->fork_key = malloc((gen_data->n_philo) * sizeof(pthread_mutex_t));
	if (!gen_data->fork_key)
		return (ph_error_input(STR_MALLOC_ERR, STR_PRG_NAME));
	while (i < gen_data->n_philo)
	{
		if (pthread_mutex_init(&(gen_data->fork_key[i]), NULL))
			return (1);
		i++;
	}
	return (0);
}

static int	_init_philos(t_data *gen_data)
{
	int	i;

	gen_data->all_philos = malloc((gen_data->n_philo + 1) * sizeof(t_philo));
	if (!gen_data->all_philos)
		return (1);
	i = 1;
	while (i < gen_data->n_philo + 1)
	{
		if (_philo_make(gen_data, &gen_data->all_philos[i], i))
			return (1);
		i++;
	}
	return (0);
}

static int	_philo_make(t_data *gen_data, t_philo *philo, int nb_philo)
{
	philo->id_philo = nb_philo;
	philo->fork[0] = (nb_philo - (nb_philo % 2)) % gen_data->n_philo;
	philo->fork[1] = (nb_philo + (nb_philo % 2 - 1)) % gen_data->n_philo;
	philo->meal_count = 0;
	if (pthread_mutex_init(&philo->meal_count_key, NULL)
		|| pthread_mutex_init(&philo->last_meal_key, NULL))
		return (1);
	philo->data = gen_data;
	return (0);
}
