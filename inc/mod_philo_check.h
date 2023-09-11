/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_philo_check.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:01:51 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/11 11:27:17 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_PHILO_CHECK_H
# define MOD_PHILO_CHECK_H

/* ====== LIBRARIES ====== */
# include "mod_err_handling.h"
# include "mod_philo_utils.h"

/* ====== DECLARATIONS ====== */
bool	ft_starved(t_philo *philo);
void	ft_is_fed(t_philo *philo);
bool	ft_all_fed(t_philo *philos);

//import from mod_utils.h
long	ft_get_time(void);


#endif
