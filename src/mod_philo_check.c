/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_philo_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:01:35 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/15 12:19:31 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_philo_check.c
 * @brief Functions to check the state of the philosophers.
 */

#include "mod_philo.h"

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
	bool	dead;
	bool	fed;

	if (data->philos->params->num_philos == 1)
		return ;
	dead = false;
	fed = false;
	while (!(dead || fed))
		ft_check_philo_status(data, &dead, &fed);
	if (dead)
		ft_set_all(data->philos, DEAD);
}

/**
 * @brief Check whether the philosopher has starved due
 * to the period since the last meal was consumed is
 * greater than the time to die.
 * 
 * A philo can only starve, if he is not full yet.
 * @param philo 	Philo in question.
 * @return true 	Philo has starved.
 * @return false 	Philo is still kicking it.
 */
bool	ft_starved(t_philo *philo)
{
	bool	ded;

	ded = false;
	pthread_mutex_lock(&philo->mtx_meal_stats);
	if (ft_get_time() - philo->last_meal > philo->params->time_to_die
		&& ft_get_status(philo) != FULL)
		ded = true;
	pthread_mutex_unlock(&philo->mtx_meal_stats);
	if (ded)
	{
		ft_set_status(philo, DEAD);
		ft_declare(philo, DED, true);
	}
	return (ded);
}

/**
 * @brief Check whether the philo has eaten enough meals
 * to be declared as fed.
 * 
 * @param philo 	Philo in question.
 */
bool	ft_is_fed(t_philo *philo)
{
	bool	fed;

	fed = false;
	pthread_mutex_lock(&philo->mtx_meal_stats);
	if (philo->meal_count >= philo->params->req_meals)
		fed = true;
	pthread_mutex_unlock(&philo->mtx_meal_stats);
	if (fed)
		ft_set_status(philo, FULL);
	return (fed);
}

/**
 * @brief Check whether all philos have attained the status FULL.
 * 
 * @param philos 	Pointer to array of philos.
 * @return true 	All philos are fed.
 * @return false 	Not all philos are fed.
 */
bool	ft_all_fed(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->params->num_philos)
		if (ft_get_status(&philos[i]) != FULL)
			return (false);
	return (true);
}

/**
 * @brief Check whether a philo died.
 * 
 * @param philos 	Pointer to array of philos.
 * @return true 	A philo died.
 * @return false 	None died.
 */
bool	ft_check_for_dead(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->params->num_philos)
		if (ft_get_status(&philos[i]) == DEAD)
			return (true);
	return (false);
}
