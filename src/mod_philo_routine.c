/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_philo_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:47:34 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/13 20:15:56 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_philo_routine.c
 * @brief Functions describing the philosophers routine.
 */

#include "mod_philo.h"

/**
 * @brief Defines behaviour of a philo thread.
 * 
 * If only one philo is simulated, a particular behaviour is called.
 * @param arg 		Pointer to argument given to the routine. Here it is
 * the data struct containing all information regarding the specific philo.
 * @return void* 	NULL pointer.
 */
void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->params->num_philos == 1)
		return (ft_so_lonely(philo));
	while (true)
	{
		if (ft_mangiare(philo) == -1)
			break ;
		if (ft_dormire(philo) == -1)
			break ;
		if (ft_pensare(philo) == -1)
			break ;
	}
	return (NULL);
}

/**
 * @brief The sad and lonely life of a single philo
 * not able to eat as there is only one fork.
 * 
 * Pick up fork and declare it.
 * Wait until he starved.
 * Release fork when dead.
 * @param philo 	Philo in question.
 * @return void* 	NULL pointer.
 */
void	*ft_so_lonely(t_philo *philo)
{
	ft_take_fork(philo, &philo->left_fork);
	ft_rest(philo->params->time_to_die + 1);
	while (!ft_starved(philo))
		ft_rest(1);
	ft_drop_fork(&philo->left_fork);
	return (NULL);
}

/**
 * @brief Eating process of a philo.
 * 
 * Check if philo has starved/is dead or is full. If yes, abort. 
 * All philos except the last first try to pick up the left fork
 * then the right. The last one does it the other way round to
 * avoid a dead lock.
 * While trying to pick up a fork the philo might starve in which
 * case the function is cancelled.
 * If both forks are successfully picked up, the last meal variable
 * is updated, a message printed and the thread rests for the 
 * appointed time necessary to eat.
 * @param philo 	Philo in question.
 * @return int 		0 on success, -1 on death of philo.
 */
int	ft_mangiare(t_philo *philo)
{
	if (ft_starved(philo) || ft_get_status(philo) >= FULL)
		return (-1);
	if (philo->id != philo->params->num_philos)
	{
		if (ft_take_fork(philo, &philo->left_fork) == -1)
			return (-1);
		if (ft_take_fork(philo, philo->right_fork) == -1)
			return (-1);
	}
	else
	{
		if (ft_take_fork(philo, philo->right_fork) == -1)
			return (-1);
		if (ft_take_fork(philo, &philo->left_fork) == -1)
			return (-1);
	}
	ft_set_meal_stats(philo);
	ft_declare(philo, EAT, false);
	ft_rest(philo->params->time_to_eat);
	return (0);
}

/**
 * @brief Sleep process of a philo.
 * 
 * After eating the philo drops its forks in the inverse order
 * it picked them up -> e.g. left, right, right, left.
 * A message is printed and the thread sleeps for the 
 * appointed time to sleep.
 * If the initial parameters result in a philo dying just after eating
 * or the status of the philo is set externally to DEAD or he is full,
 * the process is cancelled.
 * @param philo 	Philo in question.
 * @return int 		0 on success, -1 on death of philo.
 */
int	ft_dormire(t_philo *philo)
{
	if (ft_starved(philo) || ft_get_status(philo) >= FULL)
	{
		ft_drop_fork(philo->right_fork);
		ft_drop_fork(&philo->left_fork);
		return (-1);
	}
	if (philo->id != philo->params->num_philos)
	{
		ft_drop_fork(philo->right_fork);
		ft_drop_fork(&philo->left_fork);
	}
	else
	{
		ft_drop_fork(&philo->left_fork);
		ft_drop_fork(philo->right_fork);
	}
	ft_declare(philo, SLEEP, false);
	ft_rest(philo->params->time_to_sleep);
	return (0);
}

/**
 * @brief Think process of a philo.
 * 
 * If the initial parameters result in a philo dying just after sleeping
 * or the status of the philo is set externally to DEAD or he is full,
 * the process is cancelled.
 * @param philo 	Philo in question.
 * @return int 		0 on success, -1 on death of philo.
 */
int	ft_pensare(t_philo *philo)
{
	if (ft_starved(philo) || ft_get_status(philo) >= FULL)
		return (-1);
	ft_declare(philo, THINK, false);
	return (0);
}
