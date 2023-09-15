/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:34:01 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/15 11:36:39 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METADATA_H
# define METADATA_H

	/* ====== LIBRARIES ====== */

# include <pthread.h>
# include <stdbool.h>

/* ====== DEFINITIONS ====== */

typedef struct s_input
{
	int		num_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		req_meals;
	bool	check_meals;
	long	start_time;
}	t_input;

typedef struct s_fork
{
	bool			taken;
	pthread_mutex_t	mtx_taken;
}	t_fork;

typedef enum e_status {
	ACTIVE,
	FULL,
	DEAD
}	t_status;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	t_fork			left_fork;
	t_fork			*right_fork;
	t_status		status;
	pthread_mutex_t	mtx_status;
	long			last_meal;
	int				meal_count;
	pthread_mutex_t	mtx_meal_stats;
	t_input			*params;
	bool			*speak;
	pthread_mutex_t	*mtx_speak;
}	t_philo;

typedef struct s_meta
{
	t_philo			*philos;
	bool			speak;
	pthread_mutex_t	mtx_speak;
}	t_meta;

#endif
