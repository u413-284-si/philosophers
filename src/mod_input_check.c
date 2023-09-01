/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_input_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:07:16 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/01 13:14:45 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mod_input_check.h"

void	ft_check_arg(int argc)
{
	if (argc != 5 && argc != 6)
		ft_print_err_and_exit(ERR_ARGCOUNT, \
		"Expect 4, optionally 5 arguments.\n");
}

void	ft_check_input(int argc, char **argv)
{
	ft_check_argc(argc);
	ft_check_empty_str(argv);
	ft_check_num(argv);
}
