/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_philo_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:47:34 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/10 16:54:22 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_philo_routine.c
 * @brief Functions describing the philosophers routine.
 */

#include "mod_philo_routine.h"

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

void	*ft_so_lonely(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork.mtx_taken);
	philo->left_fork.taken = true;
	return (NULL);
}

int	ft_mangiare(t_philo *philo)
{
	
}

int	ft_dormire(t_philo *philo)
{
	
}

int	ft_pensare(t_philo *philo)
{
	
}
