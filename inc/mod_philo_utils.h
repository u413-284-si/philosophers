/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_philo_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:15:01 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/11 11:18:56 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_PHILO_UTILS_H
# define MOD_PHILO_UTILS_H

/* ====== LIBRARIES ====== */
# include <unistd.h>

# include "metadata.h"

/* ====== DEFINITIONS ====== */
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DED "died"

/* ====== DECLARATIONS ====== */
void	ft_declare(t_philo *philo, char *str, bool so_ded);
void	ft_set_status(t_philo *philo, t_status status);
void	ft_rest(long timespan_to_wait);

//import from mod_utils
long	ft_get_time(void);

#endif
