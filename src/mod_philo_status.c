/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_philo_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:13:27 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/14 20:32:37 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_philo_status.c
 * @brief Functions to interact with a philosophers status.
 */

#include "mod_philo.h"

/**
 * @brief Set the status of the given philo.
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

/**
 * @brief Get the status of the given philo.
 * 
 * To ensure atomic getting of the status, its mutex is
 * first locked and unlocked after the operation.
 * @param philo 	Philo whose status is to be retrieved.
 * @return status 	Status retrieved.
 */
t_status	ft_get_status(t_philo *philo)
{
	t_status	status;

	pthread_mutex_lock(&philo->mtx_status);
	status = philo->status;
	pthread_mutex_unlock(&philo->mtx_status);
	return (status);
}

/**
 * @brief Set the status of all philos.
 * 
 * @param philos 	Pointer to array of philos.
 * @param status 	Status to be set in.
 */
void	ft_set_all(t_philo *philos, t_status status)
{
	int	i;

	i = -1;
	while (++i < philos->params->num_philos)
		ft_set_status(&philos[i], status);
}

/**
 * @brief Iterate through all philos and check their status.
 * 
 * Set appropriate Booleans if either
 * one philo has starved -> dead = true
 * all philos are fed -> fed = true
 * @param data 		Struct with metadata of the program.
 * @param dead 		Boolean to indicate whether a philo has died.
 * @param fed 		Boolean to indicate whether all philos are fed.
 */
void	ft_check_philo_status(t_meta *data, bool *dead, bool *fed)
{
	int		i;

	i = -1;
	while (++i < data->philos->params->num_philos)
	{
		if (ft_starved(&data->philos[i]))
		{
			*dead = true;
			break ;
		}
		if (data->philos->params->check_meals)
			ft_is_fed(&data->philos[i]);
	}
	if (data->philos->params->check_meals)
		if (ft_all_fed(data->philos))
			*fed = true;
}
