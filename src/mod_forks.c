/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:47:06 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/15 11:57:57 by sqiu             ###   ########.fr       */
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
 * @return int 		0 on success, -1 on death/satiation of philo.
 */
int	ft_take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mtx_taken);
	if (ft_get_status(philo) >= FULL)
	{
		pthread_mutex_unlock(&fork->mtx_taken);
		return (-1);
	}
	fork->taken = true;
	ft_declare(philo, FORK, false);
	return (0);
}

/**
 * @brief Take first the left fork, then the right one.
 * 
 * If picking up the right fork fails, the left one is
 * released.
 * @param philo 	Philo trying to pick up the forks.
 * @return int 		0 on success, -1 on death/satiation of philo.
 */
int	ft_left_right_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork.mtx_taken);
	if (ft_get_status(philo) >= FULL)
	{
		pthread_mutex_unlock(&philo->left_fork.mtx_taken);
		return (-1);
	}
	philo->left_fork.taken = true;
	ft_declare(philo, FORK, false);
	pthread_mutex_lock(&philo->right_fork->mtx_taken);
	if (ft_get_status(philo) >= FULL)
	{
		philo->left_fork.taken = false;
		pthread_mutex_unlock(&philo->left_fork.mtx_taken);
		pthread_mutex_unlock(&philo->right_fork->mtx_taken);
		return (-1);
	}
	philo->right_fork->taken = true;
	ft_declare(philo, FORK, false);
	return (0);
}

/**
 * @brief Take first the right fork, then the left one.
 * 
 * If picking up the left fork fails, the right one is
 * released.
 * @param philo 	Philo trying to pick up the forks.
 * @return int 		0 on success, -1 on death/satiation of philo.
 */
int	ft_right_left_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->mtx_taken);
	if (ft_get_status(philo) >= FULL)
	{
		pthread_mutex_unlock(&philo->right_fork->mtx_taken);
		return (-1);
	}
	philo->right_fork->taken = true;
	ft_declare(philo, FORK, false);
	pthread_mutex_lock(&philo->left_fork.mtx_taken);
	if (ft_get_status(philo) >= FULL)
	{
		philo->right_fork->taken = false;
		pthread_mutex_unlock(&philo->right_fork->mtx_taken);
		pthread_mutex_unlock(&philo->left_fork.mtx_taken);
		return (-1);
	}
	philo->left_fork.taken = true;
	ft_declare(philo, FORK, false);
	return (0);
}
