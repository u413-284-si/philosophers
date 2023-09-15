/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_philo_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:47:34 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/15 11:46:06 by sqiu             ###   ########.fr       */
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
		if (ft_vivere(philo) == -1)
			break ;
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
	philo->left_fork.taken = false;
	pthread_mutex_unlock(&philo->left_fork.mtx_taken);
	return (NULL);
}

/**
 * @brief Life process of a philo.
 * 
 * Check if philo has starved/is dead or is full. If yes, abort.
 * 
 * All philos except the last first try to pick up the left fork
 * then the right. The last one does it the other way round to
 * avoid a dead lock.
 * 
 * While trying to pick up a fork the philo might starve in which
 * case the function is cancelled.
 * If both forks are successfully picked up, the last meal variable
 * is updated, a message printed and the thread rests for the 
 * appointed time necessary to eat.
 * After eating the forks are dropped.
 * The philo declares he is going to sleep and rests for the designated time.
 * Afterwards he declares that he is thinking.
 * @param philo 	Philo in question.
 * @return int 		0 on success, -1 on death of philo.
 */
int	ft_vivere(t_philo *philo)
{
	if (ft_get_status(philo) >= FULL)
		return (-1);
	if (philo->id != philo->params->num_philos)
	{
		if (ft_left_right_routine(philo) == -1)
			return (-1);
	}
	else
		if (ft_right_left_routine(philo) == -1)
			return (-1);
	pthread_mutex_lock(&philo->mtx_meal_stats);
	philo->last_meal = ft_get_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->mtx_meal_stats);
	ft_declare(philo, EAT, false);
	ft_rest(philo->params->time_to_eat);
	philo->left_fork.taken = false;
	pthread_mutex_unlock(&philo->left_fork.mtx_taken);
	philo->right_fork->taken = false;
	pthread_mutex_unlock(&philo->right_fork->mtx_taken);
	ft_declare(philo, SLEEP, false);
	ft_rest(philo->params->time_to_sleep);
	ft_declare(philo, THINK, false);
	return (0);
}
