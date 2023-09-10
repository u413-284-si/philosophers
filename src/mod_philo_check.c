/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_philo_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:01:35 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/10 23:39:27 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_philo_check.c
 * @brief Functions to check the state of the philosophers.
 */

#include "mod_philo_check.h"

/**
 * @brief Driver function for constant surveillance until a breaking condition
 * has been reached.
 * 
 * Breaking conditions: Philosopher has died or all philosophers are FULL (in
 * case a required amount of meals has been specified for this condition).
 * @param data 		Struct with metadata of the program.
 */
void	ft_manage_philos(t_meta *data)
{
	bool	abort;
	int		i;

	if (data->philos->params->num_philos == 1)
		return ;
	abort = false;
	while (!abort)
	{
		i = -1;
		while (++i < data->philos->params->num_philos)
		{
			if (ft_starved(&data->philos[i], data))
			{
				abort = true;
				break ;
			}
			if (data->philos->params->check_meals)
				ft_is_fed(&data->philos[i]);
		}
		if (ft_all_fed(data->philos))
			abort = true;
	}
}

/**
 * @brief 
 * 
 * @param philo 
 * @param data 
 * @return true 
 * @return false 
 */
bool	ft_starved(t_philo *philo, t_meta *data)
{
	bool	ded;

	ded = false;
	pthread_mutex_lock(&philo->mtx_last_meal);
	if (ft_get_time(data) - philo->last_meal > philo->params->time_to_die)
		ded = true;
	pthread_mutex_unlock(&philo->mtx_last_meal);
	if (ded)
	{
		ft_set_status(philo, DEAD);
		ft_declare(philo, data, DED, true);
	}
	return (ded);
}

void	ft_is_fed(t_philo *philo)
{
	bool	fed;

	fed = false;
	pthread_mutex_lock(&philo->mtx_meal_count);
	if (philo->meal_count >= philo->params->req_meals)
		fed = true;
	pthread_mutex_unlock(&philo->mtx_meal_count);
	if (fed && philo->status != FULL)
		ft_set_status(philo, FULL);
}

bool	ft_all_fed(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->params->num_philos)
		if (philos[i].status != FULL)
			return (false);
	return (true);
}
