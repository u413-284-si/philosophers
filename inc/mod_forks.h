/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_forks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:47:16 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/11 15:15:17 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_FORKS_H
# define MOD_FORKS_H

/* ====== LIBRARIES ====== */

# include "mod_err_handling.h"
# include "mod_philo_utils.h"

/* ====== DECLARATIONS ====== */

// import from mod_philo_check
bool	ft_starved(t_philo *philo);

#endif
