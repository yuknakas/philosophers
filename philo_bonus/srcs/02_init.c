/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:41:59 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/27 16:00:21 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int			ph_init_all(t_data *all_data, int ac, char **av);
static int	_atoui_p(unsigned int *dest, char *str);
static int	_init_semaphore(t_data *data);
static int	_make_philos(t_data *all_data);
static int	_init_philo(t_philo *philo, unsigned int id, t_data *all_data);

int	ph_init_all(t_data *all_data, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (2);
	if (_atoui_p(&all_data->n_philo, av[1]) || _atoui_p(&all_data->t_die, av[2]) \
		|| _atoui_p(&all_data->t_eat, av[3]) \
		|| _atoui_p(&all_data->t_sleep, av[4]))
		return (2);
	all_data->consider_eat = NO;
	if (ac == 6)
	{
		if (_atoui_p(&all_data->n_eat, av[5]))
			return (1);
		all_data->consider_eat = YES;
	}
	all_data->start_time = ph_get_time_in_ms() + 100;
	if (_init_semaphore(all_data), _make_philos(all_data))
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

static int	_init_semaphore(t_data *data)
{
	sem_unlink("/sem_print");
	data->sem_print = sem_open("/sem_print", O_CREAT, O_RDWR, 1);
	sem_unlink("/sem_fork");
	data->sem_fork = sem_open("/sem_fork", O_CREAT, O_RDWR, data->n_philo);
	sem_unlink("/sem_full");
	data->sem_full = sem_open("/sem_full", O_CREAT, O_RDWR, 0);
	sem_unlink("/sem_end");
	data->sem_end = sem_open("/sem_end", O_CREAT, O_RDWR, 0);
	if (!data->sem_print || !data->sem_fork \
		|| !data->sem_full || !data->sem_end)
		return (ph_error_input(STR_SEM_ERR, STR_PRG_NAME));
	return (0);
}

static int	_make_philos(t_data *all_data)
{
	unsigned int	i;

	all_data->all_philos = malloc(sizeof(t_philo) * all_data->n_philo);
	if (!all_data->all_philos)
		return (ph_error_input(STR_MALLOC_ERR, STR_PRG_NAME));
	i = 0;
	while (i++ < all_data->n_philo)
	{
		if (_init_philo(&all_data->all_philos[i], (i + 1), all_data))
			return (1);
	}
	return (0);
}

static int	_init_philo(t_philo *philo, unsigned int id, t_data *all_data)
{
	philo->data = all_data;
	philo->id_philo = id;
	philo->meal_count = 0;
	philo->last_meal = all_data->start_time;
	sem_unlink("/sem_t_meal");
	philo->sem_t_meal = sem_open("/sem_t_meal", O_CREAT, O_RDWR);
	sem_unlink("/sem_n_meal");
	philo->sem_n_meal = sem_open("/sem_n_meal", O_CREAT, O_RDWR);
	if (!philo->sem_t_meal || !philo->sem_n_meal)
		return (ph_error_input(STR_SEM_ERR, STR_PRG_NAME));
	return (0);
}
