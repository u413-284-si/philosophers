/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_feast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:04:16 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/10 18:30:37 by sqiu             ###   ########.fr       */
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
 */
void	ft_feast(t_meta *data)
{
	ft_start_shot(data);
	ft_let_em_live(data);
	ft_manage_philos(data);
	ft_bring_em_home(data);
}

/**
 * @brief Retrieves current time in ms.
 * 
 * Assigns timestamp to last_meal of each philo.
 * @param data 		Struct with metadata of the program.
 */
void	ft_start_shot(t_meta *data)
{
	int	i;

	data->start_time = ft_get_time(data);
	i = -1;
	while (++i < data->philos->params->num_philos)
		data->philos[i].last_meal = data->start_time;
}

/**
 * @brief Create threads for each philo and pass the ft_philo_routine.
 * 
 * Upon thread creation error, call error handler which clean up and 
 * terminates the program.
 * @param data 		Struct with metadata of the program.
 */
void	ft_let_em_live(t_meta *data)
{
	int	i;

	i = -1;
	while (++i < data->philos->params->num_philos)
		if (pthread_create(data->philos[i].thread, NULL, ft_philo_routine, \
			&data->philos[i]) != 0)
			ft_err_thread_create(data);
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
