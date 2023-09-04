/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_setup.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:28:33 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/03 15:41:04 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_SETUP_H
# define MOD_SETUP_H

/* ====== LIBRARIES ====== */

# include "metadata.h"
# include "mod_err_handling.h"

/* ====== DECLARATIONS ====== */
int		ft_convert_str_to_num(char *str);

// import from mod_utils
long	ft_atoi(const char *str);

#endif
