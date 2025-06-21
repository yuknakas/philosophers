/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:31:22 by yuknakas          #+#    #+#             */
/*   Updated: 2025/06/21 16:16:12 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_LINE_H
# define PHILO_LINE_H

# define STR_PRG_NAME "./philo:"
# define STR_USG "how to use %s ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"


//status messages
# define STR_TAKE_FORK "has taken a fork"
# define STR_EAT "is eating"
# define STR_SLEEP "is sleeping"
# define STR_THINK "is thinking"
# define STR_DEAD "died"

//standard errors
# define STR_MALLOC_ERR "%s error with malloc"
# define STR_UINT_ERR "incorrect input for %s <number of philosopers> must \
be in the int rage.\nOther values must be in the unsigned \
int range (0 - 4294967295)\n"
# define STR_MUTEX_ERR "error in %s failed to initialize mutex\n"

#endif