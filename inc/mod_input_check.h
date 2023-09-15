/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_input_check.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:08:11 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/15 17:15:00 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_INPUT_CHECK_H
# define MOD_INPUT_CHECK_H

/* ====== LIBRARIES ====== */

# include "mod_err_handling.h"

/* ====== DECLARATIONS ====== */

t_err	ft_check_argc(int argc);
t_err	ft_check_empty_str(int argc, char **argv);
t_err	ft_check_num(int argc, char **argv);

// import from mod_utils
int		ft_isdigit(int c);

#endif
