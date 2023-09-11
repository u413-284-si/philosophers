/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:47:06 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/11 15:17:11 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod_forks.h"

int	ft_take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mtx_taken);
	if (ft_starved(philo))
	{
		pthread_mutex_unlock(&fork->mtx_taken);
		return (-1);
	}
	fork->taken = true;
	ft_declare(philo, FORK, false);
	return (0);
}

void	ft_drop_fork(t_fork *fork)
{
	fork->taken = false;
	pthread_mutex_unlock(&fork->mtx_taken);
}
