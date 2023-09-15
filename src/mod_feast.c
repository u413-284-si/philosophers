/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_feast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:04:16 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/15 17:54:28 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_feast.c
 * @brief Functions to launch the simulation of feasting philosophers.
 */

#include "mod_feast.h"

/**
 * @brief Simulates the bacchanal life of philosophers.
 * 
 * Initially sets the starting time of the simulation.
 * @param data 		Struct with metadata of the program.
 * @return t_err	ERR_THREAD_CREATE, SUCCESS
 */
t_err	ft_feast(t_meta *data)
{
	ft_start_shot(data->philos);
	if (ft_let_em_live(data) == ERR_THREAD_CREATE)
		return (ERR_THREAD_CREATE);
	ft_manage_philos(data);
	ft_bring_em_home(data);
	return (SUCCESS);
}

/**
 * @brief Retrieves current time in ms.
 * 
 * Assigns timestamp to last_meal of each philo.
 * @param philos 		Pointer to array of philos.
 */
void	ft_start_shot(t_philo *philos)
{
	int	i;

	philos->params->start_time = ft_get_time();
	i = -1;
	while (++i < philos->params->num_philos)
		philos[i].last_meal = philos->params->start_time;
}

/**
 * @brief Create threads for each philo and pass the ft_philo_routine.
 * 
 * Upon thread creation error, call error handler which clean up and 
 * terminates the program.
 * @param data 		Struct with metadata of the program.
 * @return t_err	ERR_THREAD_CREATE, SUCCESS
 */
t_err	ft_let_em_live(t_meta *data)
{
	int	i;

	i = -1;
	while (++i < data->philos->params->num_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, ft_philo_routine, \
			&data->philos[i]) != 0)
			return (ft_err_thread_create(data, i));
		ft_declare(&data->philos[i], THINK, false);
	}
	return (SUCCESS);
}

/**
 * @brief Join all created threads.
 * 
 * Upon error while joining, print out an error message, but continue.
 * @param data 		Struct with metadata of the program.
 */
void	ft_bring_em_home(t_meta *data)
{
	int	i;

	i = -1;
	while (++i < data->philos->params->num_philos)
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			printf("Failed to join thread %d.\n", data->philos->id);
}
