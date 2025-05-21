/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:14:27 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/21 09:24:06 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ph_init_gen_data(int ac, char **av, t_data *gen_data)
{
	if (ac != 5 && ac != 6)
		return (ph_error_input(STR_USG, STR_PRG_NAME));
	
}

