/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_philo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:01:51 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/14 19:55:58 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_PHILO_H
# define MOD_PHILO_H

/* ====== LIBRARIES ====== */
# include <unistd.h>
# include <stdio.h>

# include "mod_err_handling.h"

/* ====== DEFINITIONS ====== */
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DED "died"

/* ====== DECLARATIONS ====== */

// checks
bool		ft_starved(t_philo *philo);
bool		ft_is_fed(t_philo *philo);
bool		ft_all_fed(t_philo *philos);
bool		ft_check_for_dead(t_philo *philos);

// routines
void		*ft_so_lonely(t_philo *philo);
int			ft_mangiare(t_philo *philo);
int			ft_dormire(t_philo *philo);
int			ft_pensare(t_philo *philo);

// status
void		ft_set_status(t_philo *philo, t_status status);
t_status	ft_get_status(t_philo *philo);
void		ft_set_all(t_philo *philos, t_status status);
void		ft_check_philo_status(t_meta *data, bool *dead, bool *fed);

// actions
void		ft_declare(t_philo *philo, char *str, bool so_ded);
void		ft_rest(long timespan_to_wait);
void		ft_set_meal_stats(t_philo *philo);

// import from mod_forks
int			ft_take_fork(t_philo *philo, t_fork *fork);
void		ft_drop_fork(t_fork *fork);
int			ft_left_right_routine(t_philo *philo);
int			ft_right_left_routine(t_philo *philo);

//import from mod_utils.h
long		ft_get_time(void);


#endif
