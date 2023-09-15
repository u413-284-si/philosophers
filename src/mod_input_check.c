/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_input_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:07:16 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/15 18:11:18 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_input_check.c
 * @brief Functions to verify correctness of input parameters.
 */

#include "mod_input_check.h"

/**
 * @brief General input check handler.
 * 
 * Check for number of arguments/parameters.
 * Check for empty strings.
 * Check for characters other than numeric values.
 * @param argc 		Amout of input arguments.
 * @param argv 		Array of strings containing the arguments.
 * @return t_err	ERR_ARGCOUNT, ERR_EMPTYSTR, ERR_NONNUMERIC, SUCCESS
 */
t_err	ft_check_input(int argc, char **argv)
{
	if (ft_check_argc(argc) == ERR_ARGCOUNT)
		return (ERR_ARGCOUNT);
	if (ft_check_empty_str(argc, argv) == ERR_EMPTYSTR)
		return (ERR_EMPTYSTR);
	if (ft_check_num(argc, argv) == ERR_NONNUMERIC)
		return (ERR_NONNUMERIC);
	return (SUCCESS);
}

/**
 * @brief Check for correct amount of input parameters.
 * 
 * Including the program name.
 * 5: number_of_philosophers, time_to_die, time_to_eat,
 * time_to_sleep
 * 6: above + optionally number_of_times_each_philosopher_must_eat
 * @param argc 		Amout of input arguments.
 * @return t_err	ERR_ARGCOUNT, SUCCESS
 */
t_err	ft_check_argc(int argc)
{
	if (argc != 5 && argc != 6)
		return (ft_print_err(ERR_ARGCOUNT, \
		"Expect 4, optionally 5 arguments. 🙄\n"));
	return (SUCCESS);
}

/**
 * @brief Check for empty string in input parameters.
 * 
 * Start from argument 1 (first parameter after program name).
 * End with argument argc - 1 (last parameter).
 * If empty string found, return err message and code.
 * @param argc 	Amout of input arguments.
 * @param argv 	Array of strings containing the arguments.
 * @return t_err	ERR_EMPTYSTR, SUCCESS
 */
t_err	ft_check_empty_str(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (argv[i][0] == '\0')
			return (ft_print_err(ERR_EMPTYSTR, \
				"Empty string encountered. 🥴\n"));
	return (SUCCESS);
}

/**
 * @brief Check for characters other than numeric values in input.
 * 
 * Start from argument 1 (first parameter after program name).
 * End with argument argc - 1 (last parameter).
 * If non-numeric char found, return err message and code. 
 * @param argc 
 * @param argv
 * @return t_err	ERR_NONNUMERIC, SUCCESS
 */
t_err	ft_check_num(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (ft_print_err(ERR_NONNUMERIC, \
				"Input contains non-numeric characters. 👽\n"));
	}
	return (SUCCESS);
}
