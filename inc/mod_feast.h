/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_feast.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:04:26 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/09 12:02:51 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_FEAST_H
# define MOD_FEAST_H

/* ====== LIBRARIES ====== */

# include "mod_err_handling.h"

/* ====== DECLARATIONS ====== */
void	ft_start_shot(t_meta *data);


// import from mod_utils
long	ft_get_time(t_meta *data);

#endif
