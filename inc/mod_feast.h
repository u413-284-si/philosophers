/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_feast.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:04:26 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/10 18:30:57 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_FEAST_H
# define MOD_FEAST_H

/* ====== LIBRARIES ====== */

# include "mod_err_handling.h"

/* ====== DECLARATIONS ====== */
void	ft_start_shot(t_meta *data);
void	ft_let_em_live(t_meta *data);
void	ft_bring_em_home(t_meta *data);

// import from mod_philo_routine
void	*ft_philo_routine(void *arg);

// import from mod_utils
long	ft_get_time(t_meta *data);

#endif
