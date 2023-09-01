/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:28:21 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/01 15:48:23 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_setup.c
 * @brief Functions to prepare the program for its task to simulate the table
 * of philosphers.
 */

#include "mod_setup.h"

void	ft_setup(int argc, char **argv, t_input *params)
{
	ft_convert_str_to_num(argc, argv, params);
	ft_check_neg_num(params);
	ft_check_overflow(params);
	ft_check_zero(params);
}
