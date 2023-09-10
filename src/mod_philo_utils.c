/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_philo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:14:40 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/10 23:34:38 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_philo_utils.c
 * @brief Helper functions to handle philosophers.
 */

#include "mod_philo_utils.h"

/**
 * @brief Prints out message regarding philo status.
 * 
 * If Boolean speak is set to false by previous philo who died,
 * then no philo is able to print a status message anymore.
 * @param philo 	Philo that is speaking.
 * @param data 		Struct with metadata of the program.
 * @param str 		Message stating philo status.
 * @param so_ded 	Boolean determining if philo is dead.
 */
void	ft_declare(t_philo *philo, t_meta *data, char *str, bool so_ded)
{
	long	time_elapsed;

	time_elapsed = ft_get_time(data) - data->start_time;
	pthread_mutex_unlock(&data->mtx_speak);
	if (data->speak)
		printf("%ld %d %s", time_elapsed, philo->id, str);
	if (so_ded)
		data->speak = false;
	pthread_mutex_unlock(&data->mtx_speak);
}

/**
 * @brief Sets the status of the given philo.
 * 
 * To ensure atomic setting of the status, its mutex is
 * first locked and unlocked after the operation.
 * @param philo 	Philo whose status is to be set.
 * @param status 	Status to be set in.
 */
void	ft_set_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->mtx_status);
	philo->status = status;
	pthread_mutex_unlock(&philo->mtx_status);
}
