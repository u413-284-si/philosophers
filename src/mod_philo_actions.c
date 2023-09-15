/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_philo_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:14:40 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/15 11:47:32 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_philo_utils.c
 * @brief Functions that philosophers perform occasionally.
 */

#include "mod_philo.h"

/**
 * @brief Prints out message regarding philo status.
 * 
 * If Boolean speak is set to false by previous philo who died,
 * then no philo is able to print a status message anymore.
 * @param philo 	Philo that is speaking.
 * @param str 		Message stating philo status.
 * @param so_ded 	Boolean determining if philo is dead.
 */
void	ft_declare(t_philo *philo, char *str, bool so_ded)
{
	long	time_elapsed;

	time_elapsed = ft_get_time() - philo->params->start_time;
	pthread_mutex_lock(philo->mtx_speak);
	if (*philo->speak)
		printf("%ld %d %s\n", time_elapsed, philo->id, str);
	if (so_ded)
		*philo->speak = false;
	pthread_mutex_unlock(philo->mtx_speak);
}

/**
 * @brief Induces calling thread to sleep for specified
 * timespan (ms).
 * 
 * Allows values greater than 1s to be slept for (usleep
 * only accepts values up to 1.000.000 microsecs).
 * Approaching the specified timespan incrementally also
 * increases accuracy as usleep is not guaranteed to 
 * actually sleep for the demanded time.
 * @param timespan_to_wait 		Time in ms.
 */
void	ft_rest(long timespan_to_wait)
{
	long	start;
	long	elapsed;

	start = ft_get_time();
	elapsed = 0;
	while (timespan_to_wait - elapsed > 0)
	{
		usleep(10);
		elapsed = ft_get_time() - start;
	}
}
