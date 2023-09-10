/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_philo_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:15:01 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/10 23:34:50 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_PHILO_UTILS_H
# define MOD_PHILO_UTILS_H

/* ====== LIBRARIES ====== */
# include "metadata.h"

/* ====== DEFINITIONS ====== */
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DED "died"

/* ====== DECLARATIONS ====== */
void	ft_declare(t_philo *philo, t_meta *data, char *str, bool so_ded);
void	ft_set_status(t_philo *philo, t_status status);

//import from mod_utils
long	ft_get_time(t_meta *data);

#endif
