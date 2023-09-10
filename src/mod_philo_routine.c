/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_philo_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:47:34 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/10 11:56:37 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod_philo_routine.h"

void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->params->num_philos == 1)
		return (ft_so_lonely(philo));
	while (true)
	{
		
	}
}

void	*ft_so_lonely(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork.mtx_taken);
	philo->left_fork.taken = true;
	
}