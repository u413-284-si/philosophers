/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_mutex_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:07:42 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/08 12:08:27 by sqiu             ###   ########.fr       */
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
 */
void	ft_init_mutexes(t_meta *data)
{
	if (pthread_mutex_init(&data->mtx_speak, NULL) != 0)
		ft_err_mutex_init(data);
	ft_init_philo_mutexes(data, data->philos, data->params->num_philos);
}

void	ft_init_philo_mutexes(t_meta *data, t_philo *philos, int num_philos)
{
	int	i;

	i = -1;
	while (++i < num_philos)
	{
		if (pthread_mutex_init(&philos[i].mtx_status != 0, NULL))
			ft_err_mutex_init(data);
	}
}
