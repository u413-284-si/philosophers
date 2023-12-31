/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_mutex_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:07:42 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/15 16:57:37 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_mutex_init.c
 * @brief Functions to initialise mutexes
 */

#include "mod_mutex.h"

/**
 * @brief Initiates mutexes in data struct including those in substructs.
 * 
 * Mutex initialisation in array of substructs t_philo.
 * Mutex initialisation in subsubstruct t_fork.
 * @param data 		Struct with metadata of the program.
 * @return t_err	ERR_MUTEX_INIT, SUCCESS
 */
t_err	ft_init_mutexes(t_meta *data)
{
	if (pthread_mutex_init(&data->mtx_speak, NULL) != 0)
		return (ft_err_mutex_init(data));
	if (ft_init_philo_mutexes(data, data->philos,
			data->philos->params->num_philos) != SUCCESS)
		return (ERR_MUTEX_INIT);
	return (SUCCESS);
}

/**
 * @brief Initiates mutexes in philo structs.
 * 
 * @param data 			Struct with metadata of the program.
 * @param philos 		Array of philo structs.
 * @param num_philos 	Amount of philos.
 * @return t_err		ERR_MUTEX_INIT, SUCCESS
 */
t_err	ft_init_philo_mutexes(t_meta *data, t_philo *philos, int num_philos)
{
	int	i;

	i = -1;
	while (++i < num_philos)
	{
		if (pthread_mutex_init(&philos[i].mtx_status, NULL) != 0)
			return (ft_err_mutex_init(data));
		if (pthread_mutex_init(&philos[i].mtx_meal_stats, NULL) != 0)
			return (ft_err_mutex_init(data));
		if (pthread_mutex_init(&philos[i].left_fork.mtx_taken, NULL) != 0)
			return (ft_err_mutex_init(data));
	}
	return (SUCCESS);
}
