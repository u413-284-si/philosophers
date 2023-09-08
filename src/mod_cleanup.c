/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:33:37 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/08 12:12:06 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_cleanup.c
 * @brief Functions to clean up the program and reset the system.
 */

#include "mod_cleanup.h"

/**
 * @brief Cleans up program if cancelled or finished.
 * 
 * Frees malloced space for philos and forks.
 * @param data 
 */
void	ft_cleanup(t_meta *data)
{
	//Check if mutex existent
	if (pthread_mutex_destroy(&data->mtx_speak) != 0)
		ft_print_err_and_exit(ERR_MUTEX_DESTROY, \
		"Failed to destroy mtx_speak. 😵‍💫\n");
	if (data->philos)
	{
		ft_destroy_philo_mutexes(data->philos, data->params->num_philos);
		free(data->philos);
	}
}

void	ft_destroy_philo_mutexes(t_philo *philos, int num_philos)
{
	
}
