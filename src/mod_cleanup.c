/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:33:37 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/15 16:58:12 by sqiu             ###   ########.fr       */
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
 * @param data		Struct with metadata of the program.
 * @return err
 */
t_err	ft_cleanup(t_meta *data)
{
	t_err	err;

	if (pthread_mutex_destroy(&data->mtx_speak) != 0)
		return (ft_print_err(ERR_MUTEX_DESTROY, \
		"Failed to destroy mtx_speak. 😵‍💫\n"));
	if (data->philos)
	{
		if (ft_destroy_philo_mutexes(data->philos, \
			data->philos->params->num_philos) == ERR_MUTEX_DESTROY)
			return (ERR_MUTEX_DESTROY);
		free(data->philos);
	}
	printf("\nSystem cleanup successful. ");
	printf("Can leave now with a peaceful mind. 🙏\n\n");
	return (SUCCESS);
}

/**
 * @brief Iterates through philos and destroys their mutexes.
 * 
 * @param philos 		Array of philo structs.
 * @param num_philos 	Amount of philos.
 * @return err			ERR_MUTEX_DESTROY, SUCCESS
 */
t_err	ft_destroy_philo_mutexes(t_philo *philos, int num_philos)
{
	int	i;

	i = -1;
	while (++i < num_philos)
	{
		if (pthread_mutex_destroy(&philos[i].mtx_status) != 0)
			return (ft_print_err(ERR_MUTEX_DESTROY, \
			"Failed to destroy mtx_status. 😵‍💫\n"));
		if (pthread_mutex_destroy(&philos[i].mtx_meal_stats) != 0)
			return (ft_print_err(ERR_MUTEX_DESTROY, \
			"Failed to destroy mtx_meal_stats. 😵‍💫\n"));
		if (pthread_mutex_destroy(&philos[i].left_fork.mtx_taken) != 0)
			return (ft_print_err(ERR_MUTEX_DESTROY, \
			"Failed to destroy mtx_fork_taken. 😵‍💫\n"));
	}
	return (SUCCESS);
}
