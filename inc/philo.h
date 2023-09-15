/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:07:06 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/15 17:04:34 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ====== LIBRARIES ====== */

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# include "mod_err_handling.h"

/* ====== DECLARATIONS ====== */

// import from mod_input_check
t_err	ft_check_input(int argc, char **argv);

// import from mod_setup
t_err	ft_setup(int argc, char **argv, t_input *params, t_meta *data);

// import from mod_feast
t_err	ft_feast(t_meta *data);

// import from mod_philo_check
bool	ft_check_for_dead(t_philo *philos);
bool	ft_all_fed(t_philo *philos);

#endif
