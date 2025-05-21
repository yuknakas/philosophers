/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:17:31 by yuknakas          #+#    #+#             */
/*   Updated: 2025/05/21 09:22:53 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ph_error_input(char *error_str, char *sub_str)
{
	printf(error_str, sub_str);
	return (-1);
}
