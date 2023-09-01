/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_input_check.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:08:11 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/01 13:57:08 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_INPUT_CHECK_H
# define MOD_INPUT_CHECK_H

/* ====== LIBRARIES ====== */

# include "mod_err_handling.h"

/* ====== DECLARATIONS ====== */

void	ft_check_arg(int argc);
void	ft_check_empty_str(int argc, char **argv);
void	ft_check_num(int argc, char **argv);

// import from mod_utils
int		ft_isdigit(int c);

#endif
