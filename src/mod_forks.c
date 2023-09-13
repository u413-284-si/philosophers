/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:47:06 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/13 18:59:24 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_forks.c
 * @brief Functions to handle forks.
 */

#include "mod_forks.h"

/**
 * @brief Pick up fork and print according message.
 * 
 * If philo starved while trying to pick up the fork,
 * the process is cancelled.
 * Otherwise the bool is set and a message printed.
 * @param philo 	Philo trying to pick up the fork.
 * @param fork 		Fork in question.
 * @return int 		0 on success, -1 on death of philo.
 */
int	ft_take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mtx_taken);
	if (ft_starved(philo) || ft_get_status(philo) >= FULL)
	{
		pthread_mutex_unlock(&fork->mtx_taken);
		return (-1);
	}
	fork->taken = true;
	ft_declare(philo, FORK, false);
	return (0);
}

/**
 * @brief Drop fork.
 * 
 * @param fork 	Fork in question.
 */
void	ft_drop_fork(t_fork *fork)
{
	fork->taken = false;
	pthread_mutex_unlock(&fork->mtx_taken);
}
