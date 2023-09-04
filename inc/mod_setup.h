/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_setup.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:28:33 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/04 19:14:35 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_SETUP_H
# define MOD_SETUP_H

/* ====== LIBRARIES ====== */

# include "metadata.h"
# include "mod_err_handling.h"

/* ====== DECLARATIONS ====== */
int		ft_convert_str_to_num(char *str);
void	ft_initiate(t_meta *data, int num_philos);

// import from mod_utils
long	ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
