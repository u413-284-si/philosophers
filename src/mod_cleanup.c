/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:33:37 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/08 15:12:24 by sqiu             ###   ########.fr       */
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
		ft_print_err_and_exit(ERR_MUTEX_DESTROY, false, \
		"Failed to destroy mtx_speak. 😵‍💫\n");
	if (data->philos)
	{
		ft_destroy_philo_mutexes(data->philos, data->params->num_philos);
		free(data->philos);
	}
	printf("System cleanup successful. \
		Can leave now with a peaceful mind. 🙏\n");
}

/**
 * @brief Iterates through philos and destroys their mutexes.
 * 
 * @param philos 		Array of philo structs.
 * @param num_philos 	Amount of philos.
 */
void	ft_destroy_philo_mutexes(t_philo *philos, int num_philos)
{
	int	i;

	i = -1;
	while (++i < num_philos)
	{
		//Check
		if (pthread_mutex_destroy(&philos[i].mtx_status) != 0)
			ft_print_err_and_exit(ERR_MUTEX_DESTROY, false, \
			"Failed to destroy mtx_status. 😵‍💫\n");
		//Check
		if (pthread_mutex_destroy(&philos[i].mtx_meal_count) != 0)
			ft_print_err_and_exit(ERR_MUTEX_DESTROY, false, \
			"Failed to destroy mtx_meal_count. 😵‍💫\n");
		//Check
		if (pthread_mutex_destroy(&philos[i].mtx_last_meal) != 0)
			ft_print_err_and_exit(ERR_MUTEX_DESTROY, false, \
			"Failed to destroy mtx_last_meal. 😵‍💫\n");
		//Check
		if (pthread_mutex_destroy(&philos[i].left_fork.mtx_taken) != 0)
			ft_print_err_and_exit(ERR_MUTEX_DESTROY, false, \
			"Failed to destroy mtx_fork_taken. 😵‍💫\n");
	}
}

