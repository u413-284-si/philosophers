/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_philo_routine.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:48:02 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/11 15:17:30 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_PHILO_ROUTINE_H
# define MOD_PHILO_ROUTINE_H

/* ====== LIBRARIES ====== */

# include "mod_err_handling.h"
# include "mod_philo_utils.h"

/* ====== DECLARATIONS ====== */
void	*ft_so_lonely(t_philo *philo);
int		ft_mangiare(t_philo *philo);
int		ft_dormire(t_philo *philo);
int		ft_pensare(t_philo *philo);

// import from mod_philo_check
bool	ft_starved(t_philo *philo);

// import from mod_forks
int		ft_take_fork(t_philo *philo, t_fork *fork);
void	ft_drop_fork(t_fork *fork);

#endif
