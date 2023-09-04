/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:07:06 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/04 10:31:43 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ====== LIBRARIES ====== */

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# include "metadata.h"

/* ====== DECLARATIONS ====== */

// input check
void	ft_check_input(int argc, char **argv);

// setup
void	ft_setup(int argc, char **argv, t_input *params);

#endif
