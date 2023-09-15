/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_setup.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:28:33 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/15 17:21:22 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_SETUP_H
# define MOD_SETUP_H

/* ====== LIBRARIES ====== */

# include "mod_err_handling.h"

/* ====== DECLARATIONS ====== */
t_err	ft_convert_str_to_num(char *str, int *num);
t_err	ft_init_var(t_meta *data, t_input *params);
void	ft_init_values(t_meta *data, t_input *params);

// import from mod_utils
long	ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);

// import from mod_mutex
t_err	ft_init_mutexes(t_meta *data);

#endif
